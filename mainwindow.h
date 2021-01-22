#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "plot.h"
#include <QTimer>
#include "settingparameter.h"
#include "settingcenterparameters.h"
#include "settingmodes.h"
#include "settingieratio.h"
#include "butterworthlowpassfilter.h"
#include "messagedialog.h"
#include "datetimewidget.h"
#include "keyboard.h"
#include "keynumbers.h"
#include "screen_logo.h"
#include "screen_calibration.h"
#include "screen_pacient_data.h"
#include "readtempds18b20class.h"

#include "widget_options.h"

#include "tcp_server_controller.h"

//#define MAX_Y_LEVEL_BAR 35//no se usa
//#define MIN_Y_LEVEL_BAR 270//no se usa
#define MAX_P_MAX_LEVEL 38
#define MAX_P_MAX_LEVEL_BAR 40//linea roja
#define MIN_P_MAX_LEVEL_BAR 0
#define MIN_Y_LEVEL_BAR_POS 277
#define MAX_VOLUMEN_TIDAL 700
#define MIN_VOLUMEN_TIDAL 200
#define MAX_BPM 40
#define MIN_BPM 8

#define SWIPE_MAGNITUD_THRESHOLD 50

#define RECEIVED_TIMING 500 //esta es el tiempo que demora el pipo para enviarme
#define TIMER_GRAPH_INTERVAL 25 ///max 500
#define DATA_TO_ADD_EACH_INTERVAL static_cast<int>(static_cast<float>(UART_READ_DATA_FUNCTION_SIZE) * (static_cast<float>(TIMER_GRAPH_INTERVAL)/ RECEIVED_TIMING))

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    enum{PRIMARY_WIDGET, SECUNDARY_WIDGET, TERCIARY_WIDGET};

    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    static bool capnography_active;

    SerialPort *getSerialPortInstance();
    void setSerialPortState(SerialPort::ProgramStateType state);
    void setPressureFromFluke(float pressure);
    float getPressureBeforeFluke();
    float getVolumenBeforeFluke();
    void setVolumenFromFluke(float vol);
    void setCapnographyActive(bool active);
    bool getCapnographyActive();
    float getMaxVolumen();
    void setMaxVolumen(float max_vol);
    void salvarConfiguraciondeCapnografia(int max_vol);
    int checkifMaxVolumenActive();
    void chequearConfiguracionMaxVolumen();
    void chequearConfiguracionCapnografia();
    bool checkifCapnographyActive();
    void salvarConfiguraciondeCapnografia(bool activa);
signals:
    void hideAdvanceMenu();
    void ventilationStarted(bool);

public slots:
    bool parseInformation(const QByteArray &dataReceived);

protected slots:
    void closeEvent(QCloseEvent *event);   
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
private slots:
    void disableAlarmButton();
    void on_newConnection(QString);
    void readTCPData(QByteArray bytes);
    void write_TCP_Data();

    void inicialState();
    void hideMenu();

    void on_l_power_clicked();
    void on_l_menu_clicked();

    void on_l_p_max_clicked();
    void on_l_ie_clicked();
    void on_l_bpm_clicked();
    void on_l_modo_clicked();
    void on_l_volumen_clicked();
    void on_l_alarma_clicked();

    void readSerialPort(const QByteArray &data);

    void setPmax(int value);
    QByteArray sendData(float state = 1);

    void testGraphFunction();
    void setVolumen_Tidal(int value);
    void setBPM(int value);

    void on_l_hide_menu_clicked();

    void setMode(int value);
    void setRelacionIE(float value);
    void setTi(double);
    void conexion_encontrada(QStringList puertos);
    bool decodificarInformacion(const QByteArray &dataReceived);

    void onTimeOutAlarm();
    void comunicacionCaida();
    void on_close_Alarm();
    void afterMinutesAlarmCheck();
    void setPmin(int value);
    bool decodeAlarm(float a = 0);
    void showMessageAlarm(float alarm);
    void closeMessageAlarm();
    void setFechaHora();

    void on_closed_Screen_logo();
    void on_close_Screen_Calibration();
    void on_close_Screen_Pacient_Data(PacientClass &pacient);
    void readSerialPortStandby(const QByteArray &dataReceived);
    void setStandByState();

    void readTempSensor(double temp_received);

    void menuClosed();
    void setFechaHoraReceived(QDateTime date_time);

    void setPacient(PacientClass &p);
    void on_l_background_blur_clicked();

    void soundBuzzer();
    void turnOffBuzzer();
    void resetGPIO();
    void turnOffMotor();
    void enableMotor();
    void closeApplication();
    void turnOffRaspi(int ok = 1);
    void questionTurnOff();
    void updateDateTime();

    void write_LOG(QString evento);

    void requestPauseGraph();
    void errorDeCalibracion();
    void changeCalibrationState();
    void sendDataWithDelay();
    void setTriggerAsistido(int value);
    void setTplateau(double value);
    void on_accept_Calibation_Error(int res);
    bool clearAlarmsNotifications();
    void alarmMenuShown(bool shown);
    void disconnectSignalsWidgetOptions();
    void setFiO2(int value);
    void setETCO2(int value);
    void requestOxygenCalibration();
    void startOxygenCalibration(int ok);
    void startOxygenCalibration21Porcentyle(int ok);
    void startOxygenCalibration100Porcentyle(int ok);
    void requestOxygenCalibration100Porcentyle();
    void successOxygenCalibration();
    void errorOxygenCalibration();
private:
    Ui::MainWindow *ui;
    void setFechaHoraReceivedFromArduino(QDateTime date_time);
    TCP_Server_Controller tcp_controller;
    bool menu_shown = false;
    double arratDataBuffer[UART_READ_DATA_FUNCTION_SIZE*10];
    int bufferPos = 0;
    ReadTempDS18B20Class *sensor;
    double data_to_write_in_file[UART_READ_DATA_FUNCTION_SIZE*2*HOLDING_BUFFERS_TO_WRITE_IN_FILE];
    int pos_in_buffer_to_write_in_file = 0;
    PacientClass paciente;
    MessageDialog *mensajeAlarma = nullptr;
    bool conexion_pc = false;
    bool started_ventilation = false;
    Plot *customPlot;
    void setupGraph();
    SerialPort *serialPort= nullptr;
    QByteArray dataReceived;
    QByteArray lastSendedData;
    QTimer timer;
    QTimer timer_alarm;
    bool label_alarm_blinking = false;
    int x=0, z=0;
    void showMenu();//show_power_alarm - muestra boton de alarma y encendido o no
    void adjustBarLevels(int level_p_max=-1, int level_pinst=-1, int level_peep=-1);

    float MAX_VOLUMEN = MAX_VOLUMEN_TIDAL;
    float VolumenTidal = 150;
    float BPM = 25;
    float Relacion_IE = 0.5;
    float Tplat = 2;
    float Pmax = MAX_P_MAX_LEVEL_BAR;
    float Pmin = 0; //peep configurada
    float ModoVentilacion = 1;
    float EstadoAlarmas = 0;
    float EstadoBocinas = 0;

    float PEEP = 0;
    float Ppla = 0;
    float PIP = 0;
    float Alimentacion = 0; ////Bateria, Fuente
    float Estado_Bateria = 0;

    float Pmed = 0;
    float Rinsp = 0;//Resistencia
    float Cest = 0; //compliance

    float fio2 = 0;//real recibido de arduino
    float etco2 = 0;
    float alarma_fio2 = static_cast<float>(21);//configurado
    float alarma_etco2 = static_cast<float>(40);
    float t_plateau = static_cast<float>(0.1);
    float trigger_asistido = 2;
    float Ti = static_cast<float>(0.3);

    bool lastVentState = false; //Ultimo estado de ventlacion antes de cerrar app

    bool high_priority_activation = false;
    float lastActiveAlarm =0;
    float previous_alarm_state = 0;
    int lastPriorityActiveAlarm = none_priority;

    QString date_time = "";
    QDateTime lastSavedDateTime;
    QDateTime datetime;
    SerialPort::Cmd_dateTime_Type clock_state = SerialPort::GET_FROM_ARDUINO;

    bool calibration_motor_active = false;
    bool calibration_presion_active = false;
    bool calibration_oxigeno_active = false;
    bool alarmActivated = true;
    bool silence_activated = false;

    bool first_received = true;

    void graficarDatos(double *doubleArray, int size = UART_READ_DATA_FUNCTION_SIZE);

    SettingIERatio *parameters_ie = nullptr;
    SettingParameter *parameters = nullptr;
    SettingCenterParameters *parameters_center = nullptr;
    SettingModes *parameters_modes = nullptr;
    void adjust_p_max(int level_p_max);
    void adjust_pinst(int level_pinst);
    void adjust_peep(int level_peep);
    double calcularPromedio(double *doubleArray);
    bool writeSavedConfig(QJsonArray jsonArray);
    QJsonObject jsonObjectConfiguracion;
    QJsonArray readSavedConfig();
    QJsonObject readSavedConfig(int index);
    bool writeSavedConfig(QJsonObject jsonObject);


    bool loadLastConfiguration();
    bool saveLastConfiguration();
    void iniciateFiles();
    void adjustRangeToBPM(float ciclos_en_grafica);
    int picar_frecuencia=0;//REDUCE LA FRCUENCIA DE VISUALIZACION  PARA DISP MENOS POTENTES
    double buffer_graphics[2000];
    int pos_in_buffer = 0;
    void rescaleYAxis(int p_max, bool replot = false);
    void graficarDatosFiltrados(double *doubleArray);

    ButterworthLowPassFilter filtro;
    void showAlarm();
    void addAlarmLabel(QString objectName, QString toolTip, QString icon);
    bool isActivedAlarm(QString alarm_name);
    void clearWidgets(QLayout *layout);
    void showAlarm(QString title, QString description);
    bool deleteAlarmLabel(QString name_label);
    void setAlarmText(QStringList texts = QStringList(), bool activated = true, QColor color = color_high_priority, QColor text_color = QColor(Qt::black));
    unsigned long eeprom_crc(uint8_t *ptr, uint32_t size);
    QString fillLogMessage(QString cabecera);
    void openSerialPort();
    void stopVentilation();


    QJsonObject fillLogJsonObject(QString cabecera);

    int init_pos_x=0, init_pos_y=0;
    bool swipe_area_pressed= false;
    bool menu_area_pressed= false;
    int currentWidget = PRIMARY_WIDGET;
    void animateWidgetLeftToRight(QWidget *widget, int anim_time = 200);
    void animateWidgetRightToLeft(QWidget *widget, int anim_time = 200);
    void swipeDataWidget(int swipe_magnitud);
    void swipeMenuWidget(int swipe_magnitud);
    void fillSecundaryData();
    void animateHideWidgetRightToLeft(QWidget *widget, int anim_time = 200);


    QStringList log_list;
    void removeAlarm(QString text);

    int currentState = SerialPort::STANDBY;
    bool buzzer_active = false, motor_deactivate = false;

    Screen_Pacient_Data *screen_Pacient_Data = nullptr;
    Screen_Calibration *screen_calibration = nullptr;
    Screen_Logo *screen_logo = nullptr;
    Widget_Options *options = nullptr;
    void fillMapAlarms();
    QMap<int, QString> mapaAlarmas;
    int getPriorityOfAlarm(int alarm_code);
    void conectarSignalsCalibracion(bool);
    void enableAlarm();

    bool checkForceClosed(QString &pacient_name);
    void writeInitialConfigurationLog();

    bool ventilation_screen = false;
};

#endif // MAINWINDOW_H
