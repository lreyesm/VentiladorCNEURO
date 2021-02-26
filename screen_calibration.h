#ifndef SCREEN_CALIBRATION_H
#define SCREEN_CALIBRATION_H

#include <QWidget>
#include <serialport.h>

namespace Ui {
class Screen_Calibration;
}

class Screen_Calibration : public QWidget
{
    Q_OBJECT

public:
    explicit Screen_Calibration(QWidget *parent = nullptr);
    ~Screen_Calibration();

    void setCalibationErrorText(QString text);
public slots:
    void initPresureCalibration();
    void incrementProgressBar(int value);

    void end_Screen_Calibration();
signals:
    void closed_screen_calibration();

private slots:
    void on_progressBar_calibracion_valueChanged(int value);
    void close_Screen_Calibration();

    void on_pb_continue_clicked();

    void updateProgresBarCalibrationMotor();
    void updateProgresBarCalibrationPresion();

    void on_pb_modo_at_clicked();

    void fatalErrorApp();
    void soundBuzzer();
private:
    Ui::Screen_Calibration *ui;
    QTimer timer, timerFatalError;
    bool  modo_AT_active = false;
};

#endif // SCREEN_CALIBRATION_H
