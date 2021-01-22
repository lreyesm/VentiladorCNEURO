#ifndef WIDGET_OPTIONS_H
#define WIDGET_OPTIONS_H

#include <QWidget>

#include "datetimewidget.h"
#include "pacient_data_in_menu.h"

namespace Ui {
class Widget_Options;
}

class Widget_Options : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_Options(QWidget *parent = nullptr);
    ~Widget_Options();
    void setCurrentOptions(QString option);
    bool menu_expanded = false;

signals:
    void closed_previous_option();
    void settedFiO2(int);
    void settedETCO2(int);
    void settedPEEP(int);
    void settedPmax(int);
    void settedTriggerAsistido(int);
    void settedPlateau(double);
    void menu_closing();
    void settedFechaHora(QDateTime);
    void sendPacient(PacientClass &);

    void requestOxygenCalibration();

public slots:
    void showInPos();
    void closeWithAnimation();
    void setMinPEEP(int value);
    void setMaxPeak(int value);
    void setFiO2(int value);

    void setConfigs(int value_pmax, int value_peep, int step, int max,
                    int min, int trigger, double plateau, int fio2, int etco2);
    void setLogMessage(QStringList list);

    void setPacientData(PacientClass &paciente);

    void setVentilationState(bool state);

private slots:
    void on_l_hide_menu_clicked();

    void on_l_config_fecha_hora_clicked();
    void on_l_pacient_data_clicked();
    void on_l_config_alarms_clicked();
    void on_l_log_information_clicked();
    void on_l_download_data_clicked();
    void on_l_otros_ajustes_clicked();
    void on_l_calibracion_oxigeno_clicked();

    void close_previous_option();
    void sendFechaHora(QDateTime datetime);
    void send_Pacient(PacientClass &paciente);
    void on_pb_power_off_clicked();

    void setTriggerAsistido(int value);
    void setTplateau(double value);

    void setETCO2(int value);

private:
    Ui::Widget_Options *ui;
    void animateHideWidgetRightToLeft(QWidget *widget, int anim_time = 300);
    void animateWidgetLeftToRight(QWidget *widget, int anim_time);
    int trigger_asistido, peep, pmax, m_step, m_max_value, m_min_value, m_fio2, m_etco2;
    double t_plateau;
    QStringList log_list;
    PacientClass pacient;
    bool started_ventilation = false;
};

#endif // WIDGET_OPTIONS_H
