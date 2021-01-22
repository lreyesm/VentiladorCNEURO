#include "vt_communication_interface_wrapper.h"
#include <QSerialPortInfo>
#include <QtSerialPort>
#include <QIODevice>
#include <QEventLoop>

#define MAX_SIZE 50

#define VID /*9025*/ 1027
#define PID /*61*/ 24577

vt_communication_interface_wrapper::vt_communication_interface_wrapper(QObject *parent) : QObject(parent),
    serialPort(new QSerialPort(this))
{
    initCommandMaps();

    //    QList<QSerialPortInfo> puertos_disponibles = QSerialPortInfo::availablePorts();
    //    qDebug() << "VID: " << puertos_disponibles[0].vendorIdentifier() << "PID: " << puertos_disponibles[0].productIdentifier();
    //    for (int i = 0; i < puertos_disponibles.count(); i++) {
    //        if(checkProductAndVendorIdMatch(puertos_disponibles[i]))
    //        {
    /*serialPort->setPort(puertos_disponibles[i]);*/

    //            printSerialPortInfo(puertos_disponibles[i]);
    //            break;
    //        }
    //    }
    constructSerialPort();
}
void vt_communication_interface_wrapper::constructSerialPort()
{
    if(serialPort){
        if(serialPort->isOpen()){
            serialPort->close();
        }
    }
    delete serialPort;
    serialPort = new QSerialPort(this);
    serialPort->setPortName("/dev/ttyUSB0");
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setBaudRate(QSerialPort::Baud115200);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::HardwareControl);

    package_count = 0;

    connect(serialPort, &QSerialPort::readyRead, this, &vt_communication_interface_wrapper::onDataAvailable);
    connect(this, SIGNAL(packageReady(QByteArray)), this, SLOT(processPackage(QByteArray)));
}

vt_communication_interface_wrapper::~vt_communication_interface_wrapper()
{
    if(serialPort->isOpen()){
        serialPort->close();
    }
    delete serialPort;
}

void vt_communication_interface_wrapper::initCommandMaps()
{
    //GENERAL COMMANDS
    GeneralCommandMap.insert("IDENTIFICATION","IDENT");
    GeneralCommandMap.insert("SERIAL_NUMBER","SN");
    GeneralCommandMap.insert("LOCAL","LOCAL");
    GeneralCommandMap.insert("REMOTE","REMOTE");
    GeneralCommandMap.insert("QUERY_MODE","QMODE");
    GeneralCommandMap.insert("RESET","RESET");
    GeneralCommandMap.insert("CALIBRATION_INFO","CALINFO");

    //SETUP COMMANDS
    SetupCommandMap.insert("DATE","DATE=");
    SetupCommandMap.insert("TIME","TIME=");
    SetupCommandMap.insert("DATE_FORMAT","DF=");
    SetupCommandMap.insert("QUERY_DATE_FORMAT","QDF");
    SetupCommandMap.insert("TIME_FORMAT","TF=");
    SetupCommandMap.insert("QUERY_TIME_FORMAT","QTF");
    SetupCommandMap.insert("QUERY_DATE_TIME","QDT");
    SetupCommandMap.insert("SET_AIRFLOW_USER_UNIT","UFLAW=");
    SetupCommandMap.insert("QUERY_AIRFLOW_USER_UNIT","QUFLAW");
    SetupCommandMap.insert("SET_ULTRA_LOW_FLOW_USER_UNIT","UFLULO=");
    SetupCommandMap.insert("QUERY_ULTRA_LOW_FLOW_USER_UNIT","QUFLULO");
    SetupCommandMap.insert("SET_VOLUME_USER_UNIT","UVOL=");
    SetupCommandMap.insert("QUERY_VOLUME_USER_UNIT","QUVOL");
    SetupCommandMap.insert("SET_AIRWAY_PRESSURE_USER_UNIT","UPRAW=");
    SetupCommandMap.insert("QUERY_AIRWAY_PRESSURE_USER_UNIT","QUPRAW");
    SetupCommandMap.insert("SET_LOW_PRESSURE_USER_UNIT","UPRLO=");
    SetupCommandMap.insert("QUERY_LOW_PRESSURE_USER_UNIT","QUPRLO");
    SetupCommandMap.insert("SET_ULTRA_LOW_PRESSURE_USER_UNIT","UPRULO=");
    SetupCommandMap.insert("QUERY_ULTRA_LOW_PRESSURE_USER_UNIT","QUPRULO");
    SetupCommandMap.insert("SET_HIGH_PRESSURE_USER_UNIT","UPRHI=");
    SetupCommandMap.insert("QUERY_HIGH_PRESSURE_USER_UNIT","QUPRHI");
    SetupCommandMap.insert("SET_BAROMETRIC_PRESSURE_USER_UNIT","UPRBA=");
    SetupCommandMap.insert("QUERY_BAROMETRIC_PRESSURE_USER_UNIT","QUPRBA");
    SetupCommandMap.insert("SET_TEMPERATURE_USER_UNIT","UTMP=");
    SetupCommandMap.insert("QUERY_TEMPERATUREE_USER_UNIT","QUTMP");
    SetupCommandMap.insert("SET_AIRWAY_FLOW_CORRECTION_MODE","FLCM=");
    SetupCommandMap.insert("QUERY_AIRWAY_FLOW_CORRECTION_MODE","QFLCM");
    SetupCommandMap.insert("SET_CUSTOM_AIRWAY_FLOW_CORRECTION_MODE","CFLCM=");
    SetupCommandMap.insert("QUERY_CUSTOM_AIRWAY_FLOW_CORRECTION_MODE","QCFLCM");
    SetupCommandMap.insert("SET_BREATH_DETECTION_MODE","BDM=");
    SetupCommandMap.insert("QUERY_BREATH_DETECTION_MODE","QBDM");
    SetupCommandMap.insert("SET_BREATH_DETECTION_TRIGGER_SOURCE","BDTS=");
    SetupCommandMap.insert("QUERY_BREATH_DETECTION_TRIGGER_SOURCE","QBDTS");
    SetupCommandMap.insert("SET_BREATH_DETECTION_PATIENT","BDP=");
    SetupCommandMap.insert("QUERY_BREATH_DETECTION_PATIENT","QBDP");
    SetupCommandMap.insert("SET_BREATH_DETECTION_THRESHOLD","BDTH=");
    SetupCommandMap.insert("QUERY_BREATH_DETECTION_THRESHOLD","QBDTH");
    SetupCommandMap.insert("SET_GAS_TYPE","GAS=");
    SetupCommandMap.insert("QUERY_GAS_TYPE","QGAS");

    //MEASUREMENT COMMANDS
    MeasurementCommandMap.insert("SET_MEASUREMENT_MODE","MEAS=");
    MeasurementCommandMap.insert("QUERY_MEASUREMENT_MODE","QMEAS");
    MeasurementCommandMap.insert("CLEAR_ACTIVE_MEASUREMENT","MCLEAR");
    MeasurementCommandMap.insert("ZERO_AIRFLOW_MEASUREMENT","ZFLAW");
    MeasurementCommandMap.insert("ZERO_ULTRA_LOW_FLOW_MEASUREMENT","ZFLULO");
    MeasurementCommandMap.insert("ZERO_VOLUME_MEASUREMENT","ZVOL");
    MeasurementCommandMap.insert("ZERO_AIRWAY_PRESSURE_MEASUREMENT","ZPRAW");
    MeasurementCommandMap.insert("ZERO_LOW_PRESSURE_MEASUREMENT","ZPRLO");
    MeasurementCommandMap.insert("ZERO_ULTRA_LOW_PRESSURE_MEASUREMENT","ZPRULO");
    MeasurementCommandMap.insert("ZERO_HIGH_PRESSURE_MEASUREMENT","ZPRHI");
    MeasurementCommandMap.insert("CLEAR_ALL_USER_ZEROS","ZZS");
    MeasurementCommandMap.insert("GET_AIRWAY_FLOW_MEASUREMENT","FLAW");
    MeasurementCommandMap.insert("GET_AIRWAY_FLOW_MINIMUM_MEASUREMENT","FLAWMIN");
    MeasurementCommandMap.insert("GET_AIRWAY_FLOW_MAXIMUM_MEASUREMENT","FLAWMAX");
    MeasurementCommandMap.insert("GET_AIRWAY_FLOW_AVERAGE_MEASUREMENT","FLAWAVG");
    MeasurementCommandMap.insert("GET_ULTRA_LOW_FLOW_MEASUREMENT","FLULO");
    MeasurementCommandMap.insert("GET_ULTRA_LOW_FLOW_MINIMUM_MEASUREMENT","FLULOMIN");
    MeasurementCommandMap.insert("GET_ULTRA_LOW_FLOW_MAXIMUM_MEASUREMENT","FLULOMAX");
    MeasurementCommandMap.insert("GET_ULTRA_LOW_FLOW_AVERAGE_MEASUREMENT","FLULOAVG");
    MeasurementCommandMap.insert("GET_VOLUME_MEASUREMENT","VOL");
    MeasurementCommandMap.insert("GET_AIRWAY_PRESSURE_MEASUREMENT","PRAW");
    MeasurementCommandMap.insert("GET_AIRWAY_PRESSURE_MINIMUM_MEASUREMENT","PRAWMIN");
    MeasurementCommandMap.insert("GET_AIRWAY_PRESSURE_MAXIMUM_MEASUREMENT","PRAWMAX");
    MeasurementCommandMap.insert("GET_AIRWAY_PRESSURE_AVERAGE_MEASUREMENT","PRAWAVG");
    MeasurementCommandMap.insert("GET_LOW_PRESSURE_MEASUREMENT","PRLO");
    MeasurementCommandMap.insert("GET_LOW_PRESSURE_MINIMUM_MEASUREMENT","PRLOMIN");
    MeasurementCommandMap.insert("GET_LOW_PRESSURE_MAXIMUM_MEASUREMENT","PRLOMAX");
    MeasurementCommandMap.insert("GET_LOW_PRESSURE_AVERAGE_MEASUREMENT","PRLOAVG");
    MeasurementCommandMap.insert("GET_ULTRA_LOW_PRESSURE_MEASUREMENT","PRULO");
    MeasurementCommandMap.insert("GET_ULTRA_LOW_PRESSURE_MINIMUM_MEASUREMENT","PRULOMIN");
    MeasurementCommandMap.insert("GET_ULTRA_LOW_PRESSURE_MAXIMUM_MEASUREMENT","PRULOMAX");
    MeasurementCommandMap.insert("GET_ULTRA_LOW_PRESSURE_AVERAGE_MEASUREMENT","PRULOAVG");
    MeasurementCommandMap.insert("GET_HIGH_PRESSURE_MEASUREMENT","PRHI");
    MeasurementCommandMap.insert("GET_HIGH_PRESSURE_MINIMUM_MEASUREMENT","PRHIMIN");
    MeasurementCommandMap.insert("GET_HIGH_PRESSURE_MAXIMUM_MEASUREMENT","PRHIMAX");
    MeasurementCommandMap.insert("GET_HIGH_PRESSURE_AVERAGE_MEASUREMENT","PRHIAVG");
    MeasurementCommandMap.insert("GET_BAROMETRIC_PRESSURE_MEASUREMENT","PRBA");
    MeasurementCommandMap.insert("GET_OXYGEN_MEASUREMENT","OXY");
    MeasurementCommandMap.insert("GET_OXYGEN_MINIMUM_MEASUREMENT","OXYMIN");
    MeasurementCommandMap.insert("GET_OXYGEN_MAXIMUM_MEASUREMENT","OXYMAX");
    MeasurementCommandMap.insert("GET_OXYGEN_AVERAGE_MEASUREMENT","OXYAVG");
    MeasurementCommandMap.insert("GET_TEMPERATURE_MEASUREMENT","TEMP");
    MeasurementCommandMap.insert("GET_HUMIDITY_MEASUREMENT","HUM");
    MeasurementCommandMap.insert("GET_ALL_BREATH_PARAMETER_MEASUREMENTS","BRP");

    //ANESTHESIA COMMANDS
    AnesthesiaCommandMap.insert("QUERY_VAPOR_CONNECTION","ANQCONN");
    AnesthesiaCommandMap.insert("SET_VAPOR_POWER","ANPWR=");
    AnesthesiaCommandMap.insert("QUERY_VAPOR_POWER","ANQPWR");
    AnesthesiaCommandMap.insert("QUERY_VAPOR_STATUS","ANQST");
    AnesthesiaCommandMap.insert("GET_MEASUREMENT_DATA","ANM");
    AnesthesiaCommandMap.insert("PUT_VAPOR_SLEEP","ANSL");
    AnesthesiaCommandMap.insert("WAKE_UP_VAPOR","ANWK");
    AnesthesiaCommandMap.insert("PERFORM_LOOP_TEST_VAPOR","ANLOOP");
    AnesthesiaCommandMap.insert("QUERY_VAPOR_ERROR","ANQER");

    //MEASUREMENT MODE
    MeasurementModeMap.insert("NONE","NONE");
    MeasurementModeMap.insert("AIRWAY:","AW");
    MeasurementModeMap.insert("ULTRALOW_FLOW","FLULO");
    MeasurementModeMap.insert("LOW PRESSURE","PRLO");
    MeasurementModeMap.insert("ULTRALOW_PRESSURE","PRULO");
    MeasurementModeMap.insert("HIGH PRESSURE","PRHI");
    MeasurementModeMap.insert("ANESTHESIA","AN");
}

bool vt_communication_interface_wrapper::openSerialPort(QIODevice::OpenMode mode)
{
    bool toReturn = false;
    if(!serialPort->isOpen())
    {
        toReturn = serialPort->open(mode);
        printSerialPortConfigParameters();
        qDebug() << "Puerto " << serialPort->portName() << " abierto exitosamente.";
    }
    else
        qDebug() << "El puerto " << serialPort->portName() << " ya está abierto.";
    return toReturn;
}

bool vt_communication_interface_wrapper::closeSerialPort()
{
    if(serialPort){
        if(serialPort->isOpen()){
            serialPort->close();
            return true;
        }
    }
    return false;
}

bool vt_communication_interface_wrapper::setSerialPortParity(QSerialPort::Parity parity)
{
    if(serialPort){
        return serialPort->setParity(parity);
    }else{
        return false;
    }
}

bool vt_communication_interface_wrapper::setSerialPortDataBits(QSerialPort::DataBits data_bits)
{
    if(serialPort){
        return serialPort->setDataBits(data_bits);
    }else{
        return false;
    }
}

bool vt_communication_interface_wrapper::setSerialPortBaudRate(qint32 baudRate)
{
    if(serialPort){
        return serialPort->setBaudRate(baudRate);
    }else{
        return false;
    }
}

bool vt_communication_interface_wrapper::setSerialPortStopBits(QSerialPort::StopBits stopBits)
{
    if(serialPort){
        return serialPort->setStopBits(stopBits);
    }else{
        return false;
    }
}

bool vt_communication_interface_wrapper::setSerialPortFlowControl(QSerialPort::FlowControl flowControl)
{
    if(serialPort){
        return serialPort->setFlowControl(flowControl);
    }else{
        return false;
    }
}

bool vt_communication_interface_wrapper::isSerialPortOpen()
{
    if(serialPort){
        return serialPort->isOpen();
    }else{
        return false;
    }
}

qint64 vt_communication_interface_wrapper::writeToSerialPort(const QByteArray &data)
{
    if(serialPort){
        return serialPort->write(data);
    }else{
        return -1;
    }
}

void vt_communication_interface_wrapper::printSerialPortInfo(QSerialPortInfo info)
{
    //    QString cadena = "Identificador: " + info.portName() + '\n';
    //    cadena += "Descripcion: " + info.portName();

    //    ui->textEdit->setText(cadena);
    qDebug() << "Identificador: " << info.portName();
    qDebug() << "Descripcion: " << info.description();
    qDebug() << "Fabricante: " << info.manufacturer();
    qDebug() << "Numero de Serie: " << info.serialNumber();
    qDebug() << "System Location: " << info.systemLocation();
    qDebug() << "Vendor Id: " << info.vendorIdentifier();
    qDebug() << "Product Id: " << info.productIdentifier() << endl;
}

void vt_communication_interface_wrapper::printSerialPortConfigParameters()
{
    qDebug() << "Parity: " << serialPort->parity();
    qDebug() << "Data Bits: " << serialPort->dataBits();
    qDebug() << "Baudrate: " << serialPort->baudRate();
    qDebug() << "Stop Bits: " << serialPort->stopBits();
    qDebug() << "Flow Control: " << serialPort->flowControl()<< endl;
}

bool vt_communication_interface_wrapper::checkProductAndVendorIdMatch(QSerialPortInfo &info)
{
    return ((info.vendorIdentifier() == VID) && (info.productIdentifier() == PID)) ? true : false;
}

bool vt_communication_interface_wrapper::sendCommand(QByteArray command)
{
    QByteArray local_ba = command;
    local_ba.append(0x0D).append(0x0A);
    bool test = writeToSerialPort(local_ba) == local_ba.count() ? true : false;
    return test;
    //return writeToSerialPort(local_ba) == local_ba.count() ? true : false;
}

bool vt_communication_interface_wrapper::sendCommand(QByteArray command, QString parameter)
{
    QByteArray local_ba = command;
    local_ba.append(parameter);
    local_ba.append(0x0D).append(0x0A);
    return writeToSerialPort(local_ba) == local_ba.count() ? true : false;
}

bool vt_communication_interface_wrapper::sendCommand(QByteArray command, QStringList parameters)
{
    QByteArray local_ba = command;
    //local_ba.append("=");
    //int character_count = local_ba.count();
    for (int i = 0; i < parameters.count()-1; i++) {
        local_ba.append(parameters[i].toLocal8Bit()).append(",");
    }
    local_ba.append(parameters[parameters.count() - 1].toLocal8Bit());
    local_ba.append(0x0D).append(0x0A);
    return writeToSerialPort(local_ba) == local_ba.count() ? true : false;
}

bool vt_communication_interface_wrapper::enableRemoteMode()
{
    if(!serialPort->isOpen())
        return false;
    setPackageCount(1);
    sendCommand("REMOTE");
    QEventLoop *loop = new QEventLoop(this);
    connect(this, SIGNAL(allPackagesReceived()), loop, SLOT(quit()));
    connect(this, &vt_communication_interface_wrapper::timeoutSignal, loop, &QEventLoop::exit);
    QTimer::singleShot(1000, this, SLOT(receptiontimeout()));
    if(!loop->exec())
    {
        qDebug() << received_packages[0];
        received_packages.removeAt(0);
        return true;
    }
    else
        return false;
}

bool vt_communication_interface_wrapper::setMeasurementVolumenUnit()
{
    if(!serialPort->isOpen())
        return false;
    setPackageCount(1);
    sendCommand(SetupCommandMap.value("SET_VOLUME_USER_UNIT").toUtf8(), "ML");
    QEventLoop *loop = new QEventLoop(this);
    connect(this, SIGNAL(allPackagesReceived()), loop, SLOT(quit()));
    connect(this, &vt_communication_interface_wrapper::timeoutSignal, loop, &QEventLoop::exit);
    QTimer::singleShot(1000, this, SLOT(receptiontimeout()));
    if(!loop->exec())
    {
        qDebug() << received_packages[0];
        received_packages.removeAt(0);
        return true;
    }
    else
        return false;
}

bool vt_communication_interface_wrapper::setMeasurementLowPressureUnit()
{
    if(!serialPort->isOpen())
        return false;
    setPackageCount(1);
    sendCommand(SetupCommandMap.value("SET_LOW_PRESSURE_USER_UNIT").toUtf8(), "CMH2O");
    QEventLoop *loop = new QEventLoop(this);
    connect(this, SIGNAL(allPackagesReceived()), loop, SLOT(quit()));
    connect(this, &vt_communication_interface_wrapper::timeoutSignal, loop, &QEventLoop::exit);
    QTimer::singleShot(1000, this, SLOT(receptiontimeout()));
    if(!loop->exec())
    {
        qDebug() << received_packages[0];
        received_packages.removeAt(0);
        return true;
    }
    else
        return false;
}
bool vt_communication_interface_wrapper::setMeasurementModeAirWay() // for volumen measurement
{
    if(!serialPort->isOpen())
        return false;
    return setMeasurementMode("AW");
}
bool vt_communication_interface_wrapper::setMeasurementModeLowPressure()
{
    if(!serialPort->isOpen())
        return false;
    return setMeasurementMode("PRLO");
}
bool vt_communication_interface_wrapper::setMeasurementMode(QString mode)
{
    if(!serialPort->isOpen())
        return false;
    setPackageCount(1);
    sendCommand(MeasurementCommandMap.value("SET_MEASUREMENT_MODE").toUtf8(), mode);
    QEventLoop *loop = new QEventLoop(this);
    connect(this, SIGNAL(allPackagesReceived()), loop, SLOT(quit()));
    connect(this, &vt_communication_interface_wrapper::timeoutSignal, loop, &QEventLoop::exit);
    QTimer::singleShot(1000, this, SLOT(receptiontimeout()));
    if(!loop->exec())
    {
        qDebug() << received_packages[0];
        received_packages.removeAt(0);
        return true;
    }
    else
        return false;
}

bool vt_communication_interface_wrapper::getOxygen()
{
    if(!serialPort->isOpen())
        return false;
    setPackageCount(1);
    sendCommand("OXY");
    QEventLoop *loop = new QEventLoop(this);
    connect(this, SIGNAL(allPackagesReceived()), loop, SLOT(quit()));
    connect(this, &vt_communication_interface_wrapper::timeoutSignal, loop, &QEventLoop::exit);
    QTimer::singleShot(1000, this, SLOT(receptiontimeout()));
    if(!loop->exec())
    {
        qDebug() << received_packages[0];
        received_packages.removeAt(0);
        return true;
    }
    else
        return false;
}

bool vt_communication_interface_wrapper::getFlow()
{
    if(!serialPort->isOpen())
        return false;
    setPackageCount(1);
    sendCommand("FLAW");
    QEventLoop *loop = new QEventLoop(this);
    connect(this, SIGNAL(allPackagesReceived()), loop, SLOT(quit()));
    connect(this, &vt_communication_interface_wrapper::timeoutSignal, loop, &QEventLoop::exit);
    QTimer::singleShot(1000, this, SLOT(receptiontimeout()));
    if(!loop->exec())
    {
        qDebug() << received_packages[0];
        received_packages.removeAt(0);
        return true;
    }
    else
        return false;
}

bool vt_communication_interface_wrapper::getPressure()
{
    if(!serialPort->isOpen())
        return false;
    setPackageCount(1);
    sendCommand("PRAW");
    QEventLoop *loop = new QEventLoop(this);
    connect(this, SIGNAL(allPackagesReceived()), loop, SLOT(quit()));
    connect(this, &vt_communication_interface_wrapper::timeoutSignal, loop, &QEventLoop::exit);
    QTimer::singleShot(1000, this, SLOT(receptiontimeout()));
    if(!loop->exec())
    {
        qDebug() << received_packages[0];
        received_packages.removeAt(0);
        return true;
    }
    else
        return false;
}
QList<QByteArray> vt_communication_interface_wrapper::getPressureMeasurement()//Get the low pressure measurement
{
    QList <QByteArray> respuesta;
    if(!serialPort->isOpen())
        return respuesta;
    setPackageCount(1);
    sendCommand("PRLO");
    QEventLoop *loop = new QEventLoop(this);
    connect(this, SIGNAL(allPackagesReceived()), loop, SLOT(quit()));
    connect(this, &vt_communication_interface_wrapper::timeoutSignal, loop, &QEventLoop::exit);
    QTimer::singleShot(1000, this, SLOT(receptiontimeout()));
    if(!loop->exec())
    {
        qDebug() << received_packages[0];
        respuesta = received_packages;
        received_packages.removeAt(0);
        return respuesta;
    }
    else
        return respuesta;
}
bool vt_communication_interface_wrapper::getVolume()
{
    if(!serialPort->isOpen())
        return false;
    setPackageCount(1);
    sendCommand("VOL");
    QEventLoop *loop = new QEventLoop(this);
    connect(this, SIGNAL(allPackagesReceived()), loop, SLOT(quit()));
    connect(this, &vt_communication_interface_wrapper::timeoutSignal, loop, &QEventLoop::exit);
    QTimer::singleShot(1000, this, SLOT(receptiontimeout()));
    if(!loop->exec())
    {
        qDebug() << received_packages[0];
        received_packages.removeAt(0);
        return true;
    }
    else
        return false;
}
QList<QByteArray> vt_communication_interface_wrapper::getVolumeMeasurement()
{
    QList <QByteArray> respuesta;
    if(!serialPort->isOpen())
        return respuesta;
    setPackageCount(1);
    sendCommand("BRP");
    QEventLoop *loop = new QEventLoop(this);
    connect(this, SIGNAL(allPackagesReceived()), loop, SLOT(quit()));
    connect(this, &vt_communication_interface_wrapper::timeoutSignal, loop, &QEventLoop::exit);
    QTimer::singleShot(1000, this, SLOT(receptiontimeout()));
    if(!loop->exec())
    {
        respuesta = received_packages;
        received_packages.clear();
        return respuesta;
    }
    else
        return respuesta;
}
bool vt_communication_interface_wrapper::getAllBreathsParameters()
{
    if(!serialPort->isOpen())
        return false;
    QList <QByteArray> respuesta;
    setPackageCount(4);
    sendCommand("BRP");
    QEventLoop *loop = new QEventLoop(this);
    connect(this, SIGNAL(allPackagesReceived()), loop, SLOT(quit()));
    connect(this, &vt_communication_interface_wrapper::timeoutSignal, loop, &QEventLoop::exit);
    QTimer::singleShot(1000, this, SLOT(receptiontimeout()));
    if(!loop->exec())
    {
        qDebug() << received_packages[0];
        qDebug() << received_packages[1];
        qDebug() << received_packages[2];
        qDebug() << received_packages[3];

        respuesta = received_packages;
        received_packages.removeAt(0);
        received_packages.removeAt(1);
        received_packages.removeAt(2);
        received_packages.removeAt(3);
        return true;
    }
    else
        return false;
}
QList<QByteArray> vt_communication_interface_wrapper::getParameters(){
    QList <QByteArray> respuesta;
    if(!serialPort->isOpen())
        return respuesta;

    setPackageCount(4);
    sendCommand("BRP");
    QEventLoop *loop = new QEventLoop(this);
    connect(this, SIGNAL(allPackagesReceived()), loop, SLOT(quit()));
    connect(this, &vt_communication_interface_wrapper::timeoutSignal, loop, &QEventLoop::exit);
    QTimer::singleShot(5000, this, SLOT(receptiontimeout()));
    if(!loop->exec())
    {
        qDebug() << received_packages[0];
        qDebug() << received_packages[1];
        qDebug() << received_packages[2];
        qDebug() << received_packages[3];

        respuesta = received_packages;
        received_packages.removeAt(0);
        received_packages.removeAt(1);
        received_packages.removeAt(2);
        received_packages.removeAt(3);
        return respuesta;
    }
    else
        return respuesta;
}

void vt_communication_interface_wrapper::onDataAvailable()
{
    ba_received.append(serialPort->readAll());
    emit packageReady(ba_received);
}

void vt_communication_interface_wrapper::processPackage(QByteArray ba)
{
    //package validation before adding to list of received packages
    //OJO comentar antes de que se me olvide lo que hice
    if(ba.contains("\r\n"))
    {
        received_packages.clear();

        received_packages.append(ba.split('\n'));

        if(!received_packages.last().endsWith('\r'))
            ba_received = received_packages.last();//ultima respuesta, incompleta
        else
            ba_received.clear();//todas las respuestas recibidas estan completas

        for(int i = 0; i < received_packages.count(); i++)
        {
            if(!received_packages[i].endsWith('\r'))//eliminar las respuestas invalidas
                received_packages.removeAt(i);
        }
        if(received_packages.count() >= package_count)
            emit allPackagesReceived();
    }
}

void vt_communication_interface_wrapper::clearReceivedPackages()
{
    received_packages.clear();
}

void vt_communication_interface_wrapper::receptiontimeout()
{
    emit timeoutSignal(1);
}
