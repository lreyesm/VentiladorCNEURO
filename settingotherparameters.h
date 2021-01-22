#ifndef SETTINGOTHERPARAMETERS_H
#define SETTINGOTHERPARAMETERS_H

#include <QWidget>
#define MAX_PLATEU 0.3
#define MIN_PLATEU 0.1
#define MAX_TRIGGER 5
#define MIN_TRIGGER 1


namespace Ui {
class SettingOtherParameters;
}

class SettingOtherParameters : public QWidget
{
    Q_OBJECT

public:
    explicit SettingOtherParameters(QWidget *parent = nullptr);
    ~SettingOtherParameters();

public slots:
    void setConfigs(int trigger, double Plateu, int step_trigger, double step_Plateu);
    void setTitle(QString title);
signals:
    void settedTrigger(int);
    void settedPlateu(double);
    void closing();
private slots:
    void on_l_ok_clicked();
    void on_l_up_trigger_clicked();
    void on_l_down_trigger_clicked();
    void on_l_down_plateau_clicked();
    void on_l_up_plateau_clicked();
private:
    Ui::SettingOtherParameters *ui;
    int value_trigger = 2;
    double value_Plateu = 0.1;
    int m_step_trigger = 1;
    double m_step_Plateu = 0.05;
    int m_max_value_trigger = MAX_TRIGGER;
    int m_min_value_trigger = MIN_TRIGGER;
    double m_max_value_Plateu = MAX_PLATEU;
    double m_min_value_Plateu = MIN_PLATEU;
};

#endif // SETTINGOTHERPARAMETERS_H
