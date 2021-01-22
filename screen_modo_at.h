#ifndef SCREEN_MODO_AT_H
#define SCREEN_MODO_AT_H

#include <QWidget>
#include "screenflukecontroller.h"

class MainWindow;
class SerialPort;

namespace Ui {
class Screen_Modo_AT;
}

class Screen_Modo_AT : public QWidget
{
    Q_OBJECT

public:
    explicit Screen_Modo_AT(QWidget *parent = nullptr);
    ~Screen_Modo_AT();

    MainWindow *getMainWindowInstance();
    SerialPort *getSerialPortInstance();

    void setDelay(QWidget *parent, int delayMs, QString text);
    void salvarConfiguraciondeCapnografia(bool activa);
    bool checkifCapnographyActive();

    int checkifMaxVolumenActive();
    void salvarConfiguraciondeCapnografia(int max_vol);
private slots:
    void chequearConfiguracionMaxVolumen();
    void chequearConfiguracion();
    void on_pb_update_clicked();
    void on_pb_calibrate_pressure_s1_clicked();
    void on_pb_calibrate_pressure_s2_clicked();
    void on_pb_calibrate_volumen_clicked();

    void on_pb_cerrar_clicked();

    void closeApplication();
    void on_cb_capnography_state_toggled(bool checked);

    void requestPressureS1Calibration();
    void startPressureS1Point1Calibration(int ok);
    void requestPressureS1Point1Calibration(int ok);
    void requestPressureS1Point2Calibration();
    void startPressureS1Point2Calibration(int ok);
    void errorPressureCalibration();
    void successPressureCalibration();

    void closeFlukeConnection();

    void on_pb_fluke_controller_clicked();

    void deleteFlukeController(QObject *obj);
    void getPressure();
    void requestPressureS2Calibration();
    void requestPressureS2Point1Calibration(int ok);
    void startPressureS2Point1Calibration(int ok);
    void requestPressureS2Point2Calibration();
    void startPressureS2Point2Calibration(int ok);
    void requestVolumenCalibration();
    void startVolumenCalibration(int ok);
    void errorVolumenCalibration();
    void successVolumenCalibration();
    void requestStartVolumenCalibration(int ok);
    void getVolumen();

    void on_rb_mark_4_toggled(bool checked);
    void on_rb_ambu_silicona_toggled(bool checked);

    void openUpdateApp();
private:
    Ui::Screen_Modo_AT *ui;
    ScreenFlukeController *fluke_controller = nullptr;
    bool calibration_pressure_active = false;
    bool calibration_volumen_active = false;
    QTimer timer;
    float previousPmax = 35;
    float previousVolumen= 350;

    bool closeTCP_IP_ClientAplication(QString pid);
    bool checkIfClosed(QString &pid);
    QStringList searchIntoDrives(QStringList list_Drives, QDir &dir);
    QStringList searchIntoFolders(QStringList list_folders, QDir &dir);
    bool searchFilesAndLoadUpdateQt(QStringList list_files, QDir &dir, QString dir_destiny);
    void updateVentilatorQt(QString dir_source, QString dir_destiny);
};

#endif // SCREEN_MODO_AT_H
