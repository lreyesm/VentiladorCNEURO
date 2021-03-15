#include "serialport.h"

#include <QDebug>
#include <QFile>


SerialPort::SerialPort(QObject *parent) : QSerialPort(parent)
{
    vendorIDs << ftdiVendorID << arduinoVendorID << arduinoMegaVendorID;
    producIDs << ftdiProductID << arduinoProductID << arduinoMegaProductID;
    connect(&timerComunication, &QTimer::timeout, this, &SerialPort::timeOutConection);
}

QStringList SerialPort::searchDevices(){
    Conexion_is_available=false;
    Conexion_port_names.clear();
    foreach (const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()) {
        if(serialPortInfo.hasProductIdentifier() && serialPortInfo.hasVendorIdentifier()){
            if(producIDs.contains(serialPortInfo.productIdentifier()) && vendorIDs.contains(serialPortInfo.vendorIdentifier())){
                Conexion_is_available=true;
                Conexion_port_names << serialPortInfo.portName();
            }
        }
    }
    if(!Conexion_port_names.isEmpty()){
        emitConexionEncontrado();
    }
    return Conexion_port_names;
}
bool SerialPort::openPort(QString portname){
    bool openOk = false;

//    QStringList portnames = searchDevices();

//    if(Conexion_port_names.isEmpty()){ //si no encuentra ningun puerto esta variable esta vacia
        this->setPortName("/dev/serial0");
//    }else {
//        if(portname.isEmpty()){
//            this->setPortName(portnames.at(0));
//        }else{
//            this->setPortName(portname);
//        }
//    }
    openOk = this->open(QSerialPort::ReadWrite);
    if(openOk && Conexion_port_names.isEmpty()){
        puertoRaspberryEncontrado();
    }
    this->setBaudRate(QSerialPort::Baud115200);
    this->setDataBits(QSerialPort::Data8);
    this->setFlowControl(QSerialPort::NoFlowControl);
    this->setParity(QSerialPort::NoParity);
    this->setStopBits(QSerialPort::OneStop);
    QObject::connect(this,SIGNAL(readyRead()),this,SLOT(readSerial()));

    return openOk;
}

void SerialPort::emitConexionEncontrado(){
    emit conexion_encontrada(Conexion_port_names);
}
void SerialPort::puertoRaspberryEncontrado(){
    emit conexion_encontrada(Conexion_port_names);
}
void SerialPort::closePort(){
    resetVariables();
    if(this->isOpen()){
        this->close();
    }
}
void SerialPort::resetVariables(){
    last_bad_receive_pos = 0;
    for(int i=0; i < UART_READ_TOTAL_SIZE; i++){
        receive_bytes[i] = 0;
        receive_bytes.clear();
    }
    if(this->isOpen()){
        this->flush();
    }
}

void SerialPort::readSerial(){
    QByteArray serialData=this->read(UART_READ_TOTAL_SIZE);
    qint64 bytes_size = serialData.size();

    for(int i=0; i < bytes_size; i++){ //el elemento i = serialData.size() no existe y da error al correr
        receive_bytes[i + last_bad_receive_pos] = serialData.at(i);
    }
    last_bad_receive_pos += bytes_size;

    this->flush();
//    qDebug()<<"Received data------------------------";
    do{
        if(check_message(bytes_size)){

            last_bad_receive_pos -= UART_READ_TOTAL_SIZE;
            counter_error = 0;

            decodeMessage(receive_bytes); //modifica received bytes

            if(last_bad_receive_pos > 0){
                 write_file_log_Error("last_bad_receive_pos > 0 luego de remover datos recibidos");
            }
            else{
                if(last_bad_receive_pos < 0){
                    write_file_log_Error("last_bad_receive_pos menor que 0 luego de remover datos recibidos");
                }
                for(int i=0; i < receive_bytes.size(); i++){
                    receive_bytes[i] = 0;
                    receive_bytes.clear();
                }
            }
        }
    }while(last_bad_receive_pos >= UART_READ_TOTAL_SIZE);
}

bool SerialPort::check_message(qint64 bytes_size)
{
    Q_UNUSED(bytes_size);
    if(last_bad_receive_pos >= UART_READ_TOTAL_SIZE){

        timerComunication.stop();

        for(int i=0; i < UART_READ_TOTAL_SIZE; i++){ //el elemento i = serialData.size() no existe y da error al correr
            buffer_received[i] = static_cast<uint8_t>(receive_bytes.at(i));
        }
        if(CheckSerialMessage::checkMessage(buffer_received)){
//            qDebug()<<"check_message: ok";
            return true;
        }else {
            qDebug()<<"check_message: error";
            write_file_log_Error("CRC check fail");
            QTimer::singleShot(100, this, SLOT(write_Data_Error()));
            return false;
        }

    }
    return false;
}

bool SerialPort::write_file_log_Error(QString log_error){ //escribir informacion de paciente
//    QFile data_base("Error_Log/"+ serial_log_file); // ficheros .txt se puede usar para visualizar log

//    if(data_base.open(QIODevice::Append | QIODevice::Text))
//    {
//        data_base.seek(0);
//        data_base.write(QString("----------------------------------------------------------------\n").toUtf8());
//        data_base.write(QString("Error : " + log_error +  "\n").toUtf8());
//        data_base.write(QString("Hora : " + QDateTime::currentDateTime().toString("dd/MM/yyyy HH:mm:ss ")+ "\n").toLatin1());
//        data_base.write(QString("----------------------------------------------------------------\n").toUtf8());

//        data_base.close();
        return true;
//    }
//    return false;
}

QByteArray SerialPort::decodeMessage(QByteArray bytesArray){
    QByteArray temp = bytesArray.mid(RESPUESTA_POS, WORD_SIZE_BYTES); ///Respuesta (word 2)
    int answer = static_cast<int>(IEEE_754_class::convertirDesde_754_32(
                                      IEEE_754_class::convert_Bytes_To_Uint32(IEEE_754_class::changeEndianess(temp))));
    if(answer == CONFIGURAR_PARAMETROS){
        emit configurar_parametros(bytesArray);
    }
    else if(answer == OK){
        emit dataAvailable(bytesArray);
    }     
    else if(answer == CALIBRACION_VOLUMEN_ONGOING){
        emit dataAvailable(bytesArray);
    }
    else if(answer == CALIBRACION_VOLUMEN_OK){
        emit dataAvailable(bytesArray);
        emit calibracion_exitosa_volumen();
    }
    else if(answer == CALIBRACION_VOLUMEN_ERROR){
        emit dataAvailable(bytesArray);
        void calibracion_fallida_volumen();
    }
    else if(answer == CALIBRACION_PRESION_ONGOING){
        emit dataAvailable(bytesArray);
    }
    else if(answer == CALIBRACION_PRESION_OK){
        emit dataAvailable(bytesArray);
        emit calibracion_exitosa_presion_modo_at();
    }
    else if(answer == CALIBRACION_PRESION_ERROR){
        emit dataAvailable(bytesArray);
        emit calibracion_fallida_presion_modo_at();
    }
    else if(answer == CALIBRACION_OXIGENO_ONGOING){
        emit dataAvailable(bytesArray);
    }
    else if(answer == CALIBRACION_OXIGENO_OK){
        emit dataAvailable(bytesArray);
        calibracion_exitosa_oxigeno();
    }
    else if(answer == CALIBRACION_OXIGENO_ERROR){
        emit dataAvailable(bytesArray);
        calibracion_fallida_oxigeno();
    }
    else if(answer == CALIBRACION_OK_MOTOR){
        emit dataAvailable(bytesArray);
        emit calibracion_exitosa_motor();
    }
    else if(answer == CALIBRACION_OK_PRESION){
        emit dataAvailable(bytesArray);
        emit calibracion_exitosa_presion(100); //100 para el fin de calibracion, se pone en la barra de progreso
    }
    else if(answer == ERROR_CALIBRACION){
        emit dataAvailable(bytesArray);
        emit calibracion_fallida();
    }
    else if(answer == TURN_OFF){
        emit dataAvailable(bytesArray);
        emit turn_off_program();
    }
    else if (answer == ERROR_MESSAGE) {
        QTimer::singleShot(100, this, SLOT(sendDataWithDelay()));
        emit error_transmiting();
    }else{
        //emit dataAvailable(bytesArray);
    }
    return bytesArray;
}

void SerialPort::sendDataWithDelay(){
    write_Data(lastSendBuffer);
}

void SerialPort::disableTimeOutErrorTimer(){
    timer_error_enable = false;
    timerComunication.stop();
    disconnect(&timerComunication, &QTimer::timeout, this, &SerialPort::timeOutConection);
}

void SerialPort::enableTimeOutErrorTimer()
{
    connect(&timerComunication, &QTimer::timeout, this, &SerialPort::timeOutConection);
    timer_error_enable = true;
}

void SerialPort::timeOutConection(){
    write_file_log_Error("timeOutConection error 800ms sin recibir");
    QTimer::singleShot(100, this, SLOT(write_Data_Error()));
}

void SerialPort::write_Data_Error()
{
    //    qDebug()<<"counter_error: "+QString::number(counter_error);
    counter_error++;
    if(counter_error >= MAX_ERROR_ADMITED){
        counter_error = 0;
        emit comunicacionCaida();
        timerComunication.stop();
        disconnect(&timerComunication, &QTimer::timeout, this, &SerialPort::timeOutConection);
    }
    resetVariables();
    write_State_Data(ERROR_CMD);
}

void SerialPort::write_State_Data(float state){

    if(!this->isOpen()){
        return;
    }

    this->flush();

    QByteArray buffer;

    ////    12 palabras de 32bits incluyendo CRC (1 word Header + 10 words info + 1 word CRC)
    for (int i=0; i<4 ;++i){
        buffer.append(static_cast<char>(HEADER_ID));////word 1 - Header 0xAAAAAAAA
    }

    buffer.append(IEEE_754_class::changeEndianess(IEEE_754_class::convert_Uint32To_Bytes(  ////word 2 - Estados: Standby (1), Calibración de presión (2), Calibración del motor (3), Ventilación (4), Apagado (5), ErrorCmd(0)
                                                                                           IEEE_754_class::convertirA_754_32(state))));

    for (int i =0; i < UART_SEND_TO_ARDUINO_SIZE - WORD_SIZE_BYTES*3/*descontando el Header, el estado y CRC*/; i++) {
        buffer.append(static_cast<char>(0));
    }

    unsigned int size = static_cast<unsigned int>(buffer.size());
    uint8_t *buff_int = new uint8_t[size];
    IEEE_754_class::convertByteArrayToUintArray(buffer, buff_int);

    uint32_t crcValue = CheckSerialMessage::crc32(buff_int, size);
    uint8_t buf_8b[4];
    IEEE_754_class::convertUint32ToUintArray(crcValue, buf_8b);

    buffer.append(IEEE_754_class::changeEndianess(
                      IEEE_754_class::convertUintArrayToByteArray(buf_8b, 4)));

    this->write_Data(buffer);
}


void SerialPort::write_Data(const QByteArray &data)
{
    timerComunication.stop();
    timerComunication.setInterval(TIMEOUT_ERROR_COMMUNICATION); //Si cae la comunicacion emito señal
    if(timer_error_enable){
        timerComunication.start();
    }
    lastSendBuffer = data;
    if(this->isOpen()){
//        qDebug()<<"Sended data------------------------"<<" state: "<< IEEE_754_class::convertirDesde_754_32(
//                      IEEE_754_class::convert_Bytes_To_Uint32(
//                          IEEE_754_class::changeEndianess(
//                              data.mid(4, WORD_SIZE_BYTES)))); //posicion de el estado
        this->write(data);
    }
}
