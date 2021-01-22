#ifndef SCREENFLUKECONTROLLER_H
#define SCREENFLUKECONTROLLER_H

#include <QMainWindow>
#include <QSerialPortInfo>
#include <QtSerialPort>
#include <vt_communication_interface_wrapper.h>

namespace Ui {
class ScreenFlukeController;
}

class ScreenFlukeController : public QMainWindow
{
    Q_OBJECT

public:
    explicit ScreenFlukeController(QWidget *parent = nullptr);
    ~ScreenFlukeController();
    void printSerialPortInfo(QSerialPortInfo info);
    void printSerialPortConfigParameters();

    void closeFlukeCommunication();
    bool openFlukeCommunication();
    QList<QByteArray> getAllBreathParameters();

    bool isOpenFlukeCommunication();
    QList<QByteArray> getVolume();
    QList<QByteArray> getPressure();
    bool setMeasurementLowPressureUnit();
    bool setMeasurementModeLowPressure();
    bool setMeasurementVolumenMilimeterUnit();
    bool setMeasurementModeVolumen();
private slots:

    void on_OpenSerialPort_PB_clicked();

    void on_Parity_CB_activated(const QString &arg1);

    void on_DataBits_CB_activated(const QString &arg1);

    void on_Baudrate_CB_activated(const QString &arg1);

    void on_StopBits_CB_activated(const QString &arg1);

    void on_FlowControl_CB_activated(const QString &arg1);

    void on_SendCommand_PB_clicked();

    void on_CheckFTDI_PB_clicked();

    void on_CLoseSerialPort_PB_clicked();

    void on_TypeOfCommandToSend_CB_activated(const QString &arg1);

    void updateTextEdit(QByteArray ba);

    void on_GetOxygenCB_clicked();

    void on_GetVolumeCB_clicked();

    void on_GetPressureCB_clicked();

    void on_GetFlowCB_destroyed(QObject *arg1);

    void on_GetFlowCB_clicked();

    void on_GetAllBreathParametersCB_2_clicked();

    void on_pb_close_clicked();

private:
    Ui::ScreenFlukeController *ui;
    vt_communication_interface_wrapper *wrapper;
    QByteArray ba_toSend;
    QByteArray ba_received;

};

#endif // SCREENFLUKECONTROLLER_H
