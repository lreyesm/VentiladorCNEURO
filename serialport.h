#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QDateTime>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QTimer>
#include "checkserialmessage.h"
#include "ieee_754_class.h"

#define MAX_ERROR_ADMITED 30 //TIMEOUT_ERROR_COMMUNICATION * MAX_ERROR_ADMITED milliseconds //800*30 = 24000 milliseconds -> 24 seconds
#define TIMEOUT_ERROR_COMMUNICATION 800 //milliseconds

class SerialPort : public QSerialPort
{
    Q_OBJECT
public:
    enum{NONE, BUFFER0, BUFFER1};

    enum{ERROR_MESSAGE = 0, OK, TURN_OFF, CALIBRACION_OK_MOTOR, CALIBRACION_OK_PRESION, ERROR_CALIBRACION/*5*/,
         CALIBRACION_OXIGENO_ONGOING/*6*/, CALIBRACION_OXIGENO_OK/*7*/, CALIBRACION_OXIGENO_ERROR/*8*/,
         CALIBRACION_PRESION_ONGOING/*9*/, CALIBRACION_PRESION_OK/*10*/, CALIBRACION_PRESION_ERROR/*11*/,
         CALIBRACION_VOLUMEN_ONGOING/*12*/, CALIBRACION_VOLUMEN_OK/*13*/, CALIBRACION_VOLUMEN_ERROR/*14*/,
         CONFIGURAR_PARAMETROS/*15*/
        }typedef AnswerType; //lo q envia el pipo

    enum{ERROR_CMD =0, STANDBY/*1*/, CALIBRACION_PRESION/*2*/, CALIBRACION_MOTOR/*3*/, VENTILACION/*4*/, APAGADO/*5*/,
         CALIBRACION_OXIGENO_21/*6*/, CALIBRACION_OXIGENO_100/*7*/,
         CALIBRACION_PRESION_S1_T0/*8*/, CALIBRACION_PRESION_S1_T1/*9*/,
         CALIBRACION_PRESION_S2_T0/*10*/, CALIBRACION_PRESION_S2_T1/*11*/,
         CALIBRACION_VOLUMEN/*12*/}typedef ProgramStateType;//el estado que envio desde la raspi

    enum{OMIT = 0, SET_FROM_RASPI, GET_FROM_ARDUINO}typedef Cmd_dateTime_Type;
    ///(0-Omitir)  (1-SETEAR desde Arduino (Sin Error))  (2-Error)  (3-SETEAR desde Arduino (Error))
    enum{OMIT_CLOCK = 0, SET_FROM_ARDUINO, ERROR_CLOCK, SET_FROM_ARDUINO_ERROR_CLOCK}typedef Cmd_dateTimeReceived_Type;

    explicit SerialPort(QObject *parent = nullptr);

    void write_State_Data(float state);
    void disableTimeOutErrorTimer();
    void enableTimeOutErrorTimer();
signals:
    void dataAvailable(QByteArray);
    void calibracion_exitosa_motor();
    void calibracion_exitosa_presion(int);
    void calibracion_fallida();
    void calibracion_exitosa_oxigeno();
    void calibracion_fallida_oxigeno();

    void calibracion_exitosa_presion_modo_at();
    void calibracion_fallida_presion_modo_at();

    void calibracion_exitosa_volumen();
    void calibracion_fallida_volumen();

    void error_transmiting();
    void turn_off_program();
    void conexion_encontrada(QStringList);
    void comunicacionCaida();

    void configurar_parametros(QByteArray);

public slots:
    void write_Data(const QByteArray &data);
    bool openPort(QString portname = "");
    void resetVariables();
    void closePort();
    QStringList searchDevices();
    bool check_message(qint64 bytes_size = UART_READ_TOTAL_SIZE);

    void write_Data_Error();

    void setState(ProgramStateType state){
        program_state = state;
    }
    ProgramStateType getState(){
        return program_state;
    }

private slots:
    void readSerial();

    void emitConexionEncontrado();
    void puertoRaspberryEncontrado();
    void timeOutConection();
    bool write_file_log_Error(QString log_error);
    void sendDataWithDelay();
private:

    int counter_error=0;
    bool timer_error_enable = true;

    const quint16 ftdiVendorID=0x403;
    const quint16 ftdiProductID=0x6014;

    const quint16 arduinoVendorID=0x1A86;
    const quint16 arduinoProductID=0x7523;

    const quint16 arduinoMegaVendorID=0x2341;
    const quint16 arduinoMegaProductID=0x42;

    QList<quint16> vendorIDs;
    QList<quint16> producIDs;

    bool Conexion_is_available;
    QStringList Conexion_port_names;

    bool valid_receive_data = false;
    QByteArray buffer0;
    QByteArray buffer1;
    QByteArray receive_bytes, lastSendBuffer;
    uint8_t buffer_received[UART_READ_TOTAL_SIZE];
    int currentFilledBuffer = NONE;

    int last_bad_receive_pos=0;

    QTimer timerComunication;

    QByteArray decodeMessage(QByteArray bytesArray);

    ProgramStateType program_state = STANDBY;

    QString serial_log_file = "serial_log_"+QDateTime::currentDateTime().toString("dd_MM_yyyy_hh_mm_ss")+".txt";


};

#endif // SERIALPORT_H
