#include "settingparameter.h"
#include "ui_settingparameter.h"
#include "mainwindow.h"

SettingParameter::SettingParameter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingParameter)
{
    ui->setupUi(this);
    setWindowFlags(Qt::CustomizeWindowHint);
    if(MainWindow::capnography_active){
        ui->widget_capnography->show();
    }else{
        ui->widget_capnography->hide();
    }
}

SettingParameter::~SettingParameter()
{
    delete ui;
}

void SettingParameter::setTitle(QString title)
{
    ui->l_title->setText(title);
    this->title = title;
}

void SettingParameter::setConfigs(int value, int value_min, int fio2, int etco2, int step, int max, int min)
{
    ui->l_value->setText(QString::number(value));
    ui->l_value_min->setText(QString::number(value_min));
    ui->l_value_fio2->setText(QString::number(fio2));
    ui->l_value_etco2->setText(QString::number(etco2));
    value_pmax = value;
    value_peep = value_min;
    value_fio2 = fio2;
    value_etco2 = etco2;
    m_step = step;
    m_max_value = max;
    m_min_value = min;

}
void SettingParameter::on_l_up_clicked()
{
    bool ok;
    int value = ui->l_value->text().toInt(&ok);
    if(ok){
        value += m_step;
        if(value > m_max_value){
            value = m_max_value;
        }
        value_pmax = value;
        ui->l_value->setText(QString::number(value));
    }
}
void SettingParameter::on_l_down_clicked()
{
    bool ok;
    int value = ui->l_value->text().toInt(&ok);
    if(value <= value_peep){
        return;
    }
    if(ok){
        if(value == 38){
            value -= 3;
        }else {
            value -= m_step;
        }

        if(value < m_min_value){
            value = m_min_value;
        }
        value_pmax = value;
        ui->l_value->setText(QString::number(value));
    }
}

void SettingParameter::on_l_down_etco2_clicked()
{
    bool ok;
    int value = ui->l_value_etco2->text().toInt(&ok);
    if(ok){
        value -= m_step_etco2;
        if(value < m_min_etco2){
            value = m_min_etco2;
        }
        value_etco2 = value;
        ui->l_value_etco2->setText(QString::number(value));
    }
}
void SettingParameter::on_l_up_etco2_clicked()
{
    bool ok;
    int value = ui->l_value_etco2->text().toInt(&ok);
    if(ok){
        value += m_step_etco2;
        if(value > m_max_etco2){
            value = m_max_etco2;
        }
        value_etco2 = value;
        ui->l_value_etco2->setText(QString::number(value));
    }
}

void SettingParameter::on_l_down_fio2_clicked()
{
    bool ok;
    int value = ui->l_value_fio2->text().toInt(&ok);
    if(ok){
        value -= m_step_fio2;
        if(value < m_min_fio2){
            value = m_min_fio2;
        }
        value_fio2 = value;
        ui->l_value_fio2->setText(QString::number(value));
    }
}
void SettingParameter::on_l_up_fio2_clicked()
{
    bool ok;
    int value = ui->l_value_fio2->text().toInt(&ok);
    if(ok){
        value += m_step_fio2;
        if(value > m_max_fio2){
            value = m_max_fio2;
        }
        value_fio2 = value;
        ui->l_value_fio2->setText(QString::number(value));
    }
}



void SettingParameter::on_l_ok_clicked()
{
    bool ok;
    int value = ui->l_value->text().toInt(&ok);
    int value_min = ui->l_value_min->text().toInt(&ok);
    emit setted(value);
    emit settedMin(value_min);
    emit settedFiO2(value_fio2);
    emit settedETCO2(value_etco2);
    emit closing();
    this->close();
}


void SettingParameter::on_l_up_min_clicked()
{
    bool ok;
    int value = ui->l_value_min->text().toInt(&ok);
    if(value >= value_pmax){
        return;
    }
    if(ok){
        value += m_peep_step;
        if(value > m_max_peep_value){
            value = m_max_peep_value;
        }
        value_peep = value;
        ui->l_value_min->setText(QString::number(value));
    }
}

void SettingParameter::on_l_down_min_clicked()
{
    bool ok;
    int value = ui->l_value_min->text().toInt(&ok);
    if(ok){
        value -= m_peep_step;
        if(value < m_min_peep_value){
            value = m_min_peep_value;
        }
        value_peep = value;
        ui->l_value_min->setText(QString::number(value));
    }
}
