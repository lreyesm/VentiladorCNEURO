
#ifndef MESSAGEDIALOG_H
#define MESSAGEDIALOG_H

#include <QDialog>

namespace Ui {
class MessageDialog;
}

class MessageDialog : public QWidget
{
    Q_OBJECT

    enum{LEAK_PRESION, OVER_PRESION, LOW_PRESION};


public:
    explicit MessageDialog(QWidget *parent = nullptr, QString title = "Información", QString text = "?");
    ~MessageDialog();
    QString getAlarma(){ return alarma;}
    QString getDescripcion(){ return descripcion;}
    void setAlarma(QString alarm);
    void setDescripcion(QString des);
    void setAlarmAndDescription(QString alarm, QString des);

    bool checkedAlarmActiva(uint32_t alarma_l);
    bool clearAlarm(uint32_t alarma_l);
    void clearAlarms();
    bool decodeAlarm(float alarma_l);
    bool addAlarm(uint32_t alarma_l);
public slots:
    void showCenter();
signals:
    void checkedAlarm(bool);
    void aceptado();

private slots:
    void on_pb_ok_clicked();

private:
    Ui::MessageDialog *ui;
    QString alarma;
    QString descripcion;
    QList<uint32_t> alarmas_activas;
};

#endif // MESSAGEDIALOG_H
