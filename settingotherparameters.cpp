#include "settingotherparameters.h"
#include "ui_settingotherparameters.h"

SettingOtherParameters::SettingOtherParameters(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingOtherParameters)
{
    ui->setupUi(this);
}

SettingOtherParameters::~SettingOtherParameters()
{
    delete ui;
}

void SettingOtherParameters::setTitle(QString title)
{
    ui->l_title->setText(title);
}

void SettingOtherParameters::setConfigs(int trigger, double plateu, int step_trigger, double step_Plateu)
{
    ui->l_value_trigger->setText(QString::number(trigger));
    QString plat = QString::number(plateu, 'f', 2);
    if(plat.at(plat.size()-1)== "0"){
       plat.remove(plat.size()-1, 1);
    }
    ui->l_value_plateau->setText(plat);
    value_trigger = trigger;
    value_Plateu = plateu;
    m_step_trigger = step_trigger;
    m_step_Plateu = step_Plateu;

}

void SettingOtherParameters::on_l_up_trigger_clicked()
{
    bool ok;
    int value = ui->l_value_trigger->text().toInt(&ok);
    if(ok){
        value += m_step_trigger;
        if(value > m_max_value_trigger){
            value = m_max_value_trigger;
        }
        value_trigger = value;
        ui->l_value_trigger->setText(QString::number(value));
    }
}

void SettingOtherParameters::on_l_down_trigger_clicked()
{
    bool ok;
    int value = ui->l_value_trigger->text().toInt(&ok);

    if(ok){
        value -= m_step_trigger;
        if(value < m_min_value_trigger){
            value = m_min_value_trigger;
        }
        value_trigger = value;
        ui->l_value_trigger->setText(QString::number(value));
    }
}

void SettingOtherParameters::on_l_ok_clicked()
{
    bool ok;
    int trigger = ui->l_value_trigger->text().toInt(&ok);
    double plateu = ui->l_value_plateau->text().toDouble(&ok);
    emit settedTrigger(trigger);
    emit settedPlateu(plateu);
    emit closing();
    this->close();
}


void SettingOtherParameters::on_l_up_plateau_clicked()
{
    bool ok;
    double value = ui->l_value_plateau->text().toDouble(&ok);

    if(ok){
        value += m_step_Plateu;
        if(value > m_max_value_Plateu){
            value = m_max_value_Plateu;
        }
        value_Plateu = value;
        ui->l_value_plateau->setText(QString::number(value));
    }
}

void SettingOtherParameters::on_l_down_plateau_clicked()
{
    bool ok;
    double value = ui->l_value_plateau->text().toDouble(&ok);
    if(ok){
        value -= m_step_Plateu;
        if(value < m_min_value_Plateu){
            value = m_min_value_Plateu;
        }
        value_Plateu = value;
        ui->l_value_plateau->setText(QString::number(value));
    }
}
