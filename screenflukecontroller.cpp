#include "screenflukecontroller.h"
#include "ui_screenflukecontroller.h"
#include <QDebug>

#define MAX_SIZE 50

ScreenFlukeController::ScreenFlukeController(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ScreenFlukeController),
    wrapper(new vt_communication_interface_wrapper)
{
    ui->setupUi(this);

    setWindowFlags(Qt::CustomizeWindowHint);


    QStringList toPopulateCommandMenu = {"General Commands","Setup Commands","Measurement Commands","Anesthesia Commands"};
    ui->TypeOfCommandToSend_CB->insertItems(0,toPopulateCommandMenu);
    ui->CommandToSend_CB->insertItems(0,wrapper->GeneralCommandMap.keys());

    connect(wrapper, SIGNAL(packageReady(QByteArray)), this, SLOT(updateTextEdit(QByteArray)));
}

ScreenFlukeController::~ScreenFlukeController()
{
    delete wrapper;
    delete ui;
}

void ScreenFlukeController::on_OpenSerialPort_PB_clicked()
{
    wrapper->openSerialPort(QIODevice::ReadWrite);
    wrapper->enableRemoteMode();
    wrapper->setMeasurementMode("AW");//only for testing porpouse
}

void ScreenFlukeController::on_Parity_CB_activated(const QString &arg1)
{
    if(arg1 == "Even")
        wrapper->setSerialPortParity(QSerialPort::EvenParity);
    if(arg1 == "Odd")
        wrapper->setSerialPortParity(QSerialPort::OddParity);
    if(arg1 == "None")
        wrapper->setSerialPortParity(QSerialPort::NoParity);
}

void ScreenFlukeController::on_DataBits_CB_activated(const QString &arg1)
{
    if(arg1 == "5")
        wrapper->setSerialPortDataBits(QSerialPort::Data5);
    if(arg1 == "6")
        wrapper->setSerialPortDataBits(QSerialPort::Data6);
    if(arg1 == "7")
        wrapper->setSerialPortDataBits(QSerialPort::Data7);
    if(arg1 == "8")
        wrapper->setSerialPortDataBits(QSerialPort::Data8);
}


void ScreenFlukeController::on_Baudrate_CB_activated(const QString &arg1)
{
    if(arg1 == "115200")
        wrapper->setSerialPortBaudRate(QSerialPort::Baud115200);
    if(arg1 == "9600")
        wrapper->setSerialPortBaudRate(QSerialPort::Baud9600);
}

void ScreenFlukeController::on_StopBits_CB_activated(const QString &arg1)
{
    if(arg1 == "1")
        wrapper->setSerialPortStopBits(QSerialPort::OneStop);
    if(arg1 == "1.5")
        wrapper->setSerialPortStopBits(QSerialPort::OneAndHalfStop);
    if(arg1 == "2")
        wrapper->setSerialPortStopBits(QSerialPort::TwoStop);
}

void ScreenFlukeController::on_FlowControl_CB_activated(const QString &arg1)
{
    if(arg1 == "None")
        wrapper->setSerialPortFlowControl(QSerialPort::NoFlowControl);
    if(arg1 == "Hardware")
        wrapper->setSerialPortFlowControl(QSerialPort::HardwareControl);
}

void ScreenFlukeController::on_SendCommand_PB_clicked()
{
    if(wrapper->isSerialPortOpen())
    {
        //        wrapper->setMeasurementMode("AW");
        //        QStringList list = {"A", "B", "C"};
        //        ba_toSend = wrapper->GeneralCommandMap.value(ui->CommandToSend_CB->currentText()).toUtf8();
        //        bool test = wrapper->sendCommand(ba_toSend);
    }
    else
        qDebug() << "El puerto " << " está cerrado.";

    //    if(wrapper->isSerialPortOpen())
    //    {
    ////        serialPort.clear();
    //        ba_toSend = ui->CommandToSend_CB->currentText().toUtf8();
    //        char count = ba_toSend.count();

    //        //Para fijar el tamaño de lo que se envia y recibe a MAX_SIZE caracteres
    //        if(count < MAX_SIZE)
    //            for (int i = 0; i < (MAX_SIZE - count); i++) {
    //                ba_toSend.append('*');
    //            }

    //        int bytes_written = wrapper->writeToSerialPort(ba_toSend);
    //        bytes_written == MAX_SIZE ? cout << "Escritos " << MAX_SIZE << " bytes satisfactoriamente."<< endl : cout << "No se puedieron escribir todos los bytes. Se escribieron " << bytes_written << endl;
    ////        serialPort.waitForReadyRead(1000) ? ui->textEdit->append("Data available"): ui->textEdit->append("No data available");
    ////        cout << "Bytes disponibles " << serialPort.bytesAvailable() << endl;
    ////        ba_received = serialPort.readAll();
    ////        cout << "Bytes leídos " << ba_received.count() << endl;
    ////        ui->textEdit->append(QString::fromUtf8(ba_received));
    //    }
    //    else
    //        cout << "El puerto " << " está cerrado." << endl;
}

void ScreenFlukeController::on_CheckFTDI_PB_clicked()
{
    //OJO MODIFICAR LUEGO
    ui->textEdit->clear();
}

void ScreenFlukeController::on_CLoseSerialPort_PB_clicked()
{
    if(wrapper->isSerialPortOpen())
    {
        wrapper->closeSerialPort();
        qDebug() << "Puerto fue"  << " cerrado exitosamente.";
    }
    else
        qDebug() << "El puerto ya está cerrado.";
}

void ScreenFlukeController::on_TypeOfCommandToSend_CB_activated(const QString &arg1)
{
    ui->CommandToSend_CB->clear();
    if(arg1 == "General Commands")
        ui->CommandToSend_CB->insertItems(0,wrapper->GeneralCommandMap.keys());
    if(arg1 == "Setup Commands")
        ui->CommandToSend_CB->insertItems(0,wrapper->SetupCommandMap.keys());
    if(arg1 == "Measurement Commands")
        ui->CommandToSend_CB->insertItems(0,wrapper->MeasurementCommandMap.keys());
    if(arg1 == "Anesthesia Commands")
        ui->CommandToSend_CB->insertItems(0,wrapper->AnesthesiaCommandMap.keys());
}

void ScreenFlukeController::updateTextEdit(QByteArray ba)
{
    ui->textEdit->append(QString::fromUtf8(ba));
}

void ScreenFlukeController::on_GetOxygenCB_clicked()
{
    wrapper->getOxygen();
}

void ScreenFlukeController::on_GetVolumeCB_clicked()
{
    wrapper->getVolume();
}

void ScreenFlukeController::on_GetPressureCB_clicked()
{
    wrapper->getPressure();
}

void ScreenFlukeController::on_GetFlowCB_destroyed(QObject *arg1)
{
    Q_UNUSED(arg1);
}

void ScreenFlukeController::on_GetFlowCB_clicked()
{
    wrapper->getFlow();
}

void ScreenFlukeController::on_GetAllBreathParametersCB_2_clicked()
{
    wrapper->getAllBreathsParameters();
}
bool ScreenFlukeController::setMeasurementModeVolumen(){ //para medicion de volumen
    return wrapper->setMeasurementModeAirWay();
}
bool ScreenFlukeController::setMeasurementVolumenMilimeterUnit(){
    return wrapper->setMeasurementVolumenUnit();
}
bool ScreenFlukeController::setMeasurementModeLowPressure(){
    return wrapper->setMeasurementModeLowPressure();
}
bool ScreenFlukeController::setMeasurementLowPressureUnit(){
    return wrapper->setMeasurementLowPressureUnit();
}
bool ScreenFlukeController::isOpenFlukeCommunication(){
    return wrapper->isSerialPortOpen();
}
void ScreenFlukeController::on_pb_close_clicked()
{
    wrapper->closeSerialPort();
//    wrapper->deleteLater();
    this->close();
}
QList<QByteArray> ScreenFlukeController::getPressure(){
    QList<QByteArray> res = wrapper->getPressureMeasurement();
    return res;
}
QList<QByteArray> ScreenFlukeController::getVolume(){
    QList<QByteArray> res = wrapper->getVolumeMeasurement();
    return res;
}
QList<QByteArray> ScreenFlukeController::getAllBreathParameters(){
    QList<QByteArray> res = wrapper->getParameters();
    return res;
}
bool ScreenFlukeController::openFlukeCommunication(){
    bool open = false;
    open = wrapper->openSerialPort(QIODevice::ReadWrite);
    wrapper->enableRemoteMode();
//    wrapper->setMeasurementMode("AW");//only for testing
    return open;
}
void ScreenFlukeController::closeFlukeCommunication(){
    on_pb_close_clicked();
}
