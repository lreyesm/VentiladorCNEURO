#ifndef SETTINGPARAMETER_H
#define SETTINGPARAMETER_H

#include <QDialog>

namespace Ui {
class SettingParameter;
}

class SettingParameter : public QWidget
{
    Q_OBJECT

public:
    explicit SettingParameter(QWidget *parent = nullptr);
    ~SettingParameter();
    void setConfigs(int value =38, int value_min = 0, int fio2 = 21, int etco2 = 35, int step=5,
                    int max=100, int min=0);

    void setTitle(QString title);
signals:
    void settedFiO2(int);
    void settedETCO2(int);
    void setted(int);
    void settedMin(int);
    void closing();

private slots:
    void on_l_up_clicked();
    void on_l_down_clicked();
    void on_l_ok_clicked();

    void on_l_up_min_clicked();

    void on_l_down_min_clicked();

    void on_l_down_fio2_clicked();
    void on_l_up_fio2_clicked();

    void on_l_down_etco2_clicked();
    void on_l_up_etco2_clicked();

private:
    Ui::SettingParameter *ui;
    int m_max_value = 100;
    int m_min_value =0;
    int m_max_fio2 = 100;
    int m_min_fio2 = 21;
    int m_max_etco2 = 50;
    int m_min_etco2 = 30;

    int m_max_peep_value = 20;
    int m_min_peep_value =0;
    int m_step_fio2 = 1, m_step_etco2 = 1, m_step = 5;
    int m_peep_step = 1;
    int m_fio2_step = 1;
    QString title = "";
    int value_pmax;
    int value_peep;
    int value_fio2, value_etco2;

};

#endif // SETTINGPARAMETER_H
