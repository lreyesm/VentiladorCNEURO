#ifndef VT_COMMUNICATION_INTERFACE_WRAPPER_H
#define VT_COMMUNICATION_INTERFACE_WRAPPER_H

#include <QObject>
#include <QMap>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QIODevice>

//El objetivo de la clase es encapsular la comunicación con el fluke
//OJO
//incluir struct para almacenar todos los datos del analizador de flujo

class vt_communication_interface_wrapper : public QObject
{
    Q_OBJECT
public:

    enum COMMAND_TYPES {
        GENERAL,
        SETUP,
        MEASUREMENT,
        ANESTHESIA
    };

    struct SerialPortSettings {
        QString name;
        qint32 baudRate;
        QString stringBaudRate;
        QSerialPort::DataBits dataBits;
        QString stringDataBits;
        QSerialPort::Parity parity;
        QString stringParity;
        QSerialPort::StopBits stopBits;
        QString stringStopBits;
        QSerialPort::FlowControl flowControl;
        QString stringFlowControl;
        bool localEchoEnabled;
    };

    QMap<QString, QString> GeneralCommandMap;
    QMap<QString, QString> SetupCommandMap;
    QMap<QString, QString> MeasurementCommandMap;
    QMap<QString, QString> AnesthesiaCommandMap;

    QMap<QString, QString> MeasurementModeMap;

    //struct para almacenar todos los datos del analizador de flujo

    explicit vt_communication_interface_wrapper(QObject *parent = nullptr);
    ~vt_communication_interface_wrapper();

    void initCommandMaps();
    bool openSerialPort(QIODevice::OpenMode mode);
    bool closeSerialPort();
    bool setSerialPortParity(QSerialPort::Parity parity);
    bool setSerialPortDataBits(QSerialPort::DataBits data_bits);
    bool setSerialPortBaudRate(qint32 baudRate);
    bool setSerialPortStopBits(QSerialPort::StopBits stopBits);
    bool setSerialPortFlowControl(QSerialPort::FlowControl flowControl);
    bool isSerialPortOpen();
    qint64 writeToSerialPort(const QByteArray &data);
    void printSerialPortInfo(QSerialPortInfo info);
    void printSerialPortConfigParameters();
    bool checkProductAndVendorIdMatch(QSerialPortInfo &info);

    bool sendCommand(QByteArray command);
    bool sendCommand(QByteArray command, QString parameter);
    bool sendCommand(QByteArray command, QStringList parameters);
    void setPackageCount(unsigned char c){package_count = c;};

    bool enableRemoteMode();
    bool setMeasurementMode(QString);
    bool getOxygen();
    bool getFlow();
    bool getPressure();
    bool getVolume();
    bool getAllBreathsParameters();

    //añadir comandos para recibir correctamente los valores enviados por el fluke
    //IDEA hacer una helper function que determine si el comando a enviar debe recibir respuesta de
    //parametros o solo */r/n. Usar esta funcion antes de enviar el comando para saber el formato de
    //la respuesta.

    QList<QByteArray> getParameters();
    QList<QByteArray> getPressureMeasurement();
    QList<QByteArray> getVolumeMeasurement();
    bool setMeasurementLowPressureUnit();
    bool setMeasurementModeLowPressure();
    bool setMeasurementModeAirWay();
    bool setMeasurementVolumenUnit();
private:
    QSerialPort *serialPort;
    QByteArray ba_toSend;
    QByteArray ba_received;
    QList <QByteArray> received_packages;
    unsigned char package_count;

    void constructSerialPort();
private slots:
    void onDataAvailable();
    void processPackage(QByteArray);
    void clearReceivedPackages();
    void receptiontimeout();

signals:
    void packageReady(QByteArray);
    void commanExecuted(bool);
    void allPackagesReceived();
    void timeoutSignal(int);

};

#endif // VT_COMMUNICATION_INTERFACE_WRAPPER_H
