#include "widget_options.h"
#include "ui_widget_options.h"
#include <QPropertyAnimation>

#include "settingparameter.h"
#include "settingotherparameters.h"
#include "log_information.h"
#include "download_data.h"
#include "processesclass.h"

Widget_Options::Widget_Options(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_Options)
{
    ui->setupUi(this);
}

Widget_Options::~Widget_Options()
{
    delete ui;
}

void Widget_Options::setCurrentOptions(QString option)
{
    ui->label->setPixmap(QPixmap(":/icons/menu_on.png"));
    ui->label->setFixedSize(585, 408);
    this->setFixedSize(585, 415);

    menu_expanded = true;

    if(option == "ajuste_alarmas"){
        SettingParameter *parameters = new SettingParameter(this);
        parameters->setConfigs(pmax, peep, m_fio2, m_etco2, m_step, m_max_value, m_min_value);
        parameters->move(270,5);
        parameters->show();
        QObject::connect(parameters, &SettingParameter::settedFiO2, this, &Widget_Options::setFiO2);
        QObject::connect(parameters, &SettingParameter::settedETCO2, this, &Widget_Options::setETCO2);

        QObject::connect(parameters, &SettingParameter::setted, this, &Widget_Options::setMaxPeak);
        QObject::connect(parameters, &SettingParameter::settedMin, this, &Widget_Options::setMinPEEP);
        QObject::connect(parameters, &SettingParameter::closing, this, &Widget_Options::closeWithAnimation);
        QObject::connect(this, &Widget_Options::closed_previous_option, parameters, &SettingParameter::close);
//        QObject::connect(this, &Widget_Options::menu_closing, parameters, &SettingParameter::deleteLater);

    }
    if(option == "otros_ajustes"){
        SettingOtherParameters *other_parameters = new SettingOtherParameters(this);
        other_parameters->setConfigs(trigger_asistido, t_plateau, 1, 0.05);
        other_parameters->move(270,5);
        other_parameters->show();
        QObject::connect(other_parameters, &SettingOtherParameters::settedTrigger, this, &Widget_Options::setTriggerAsistido);
        QObject::connect(other_parameters, &SettingOtherParameters::settedPlateu, this, &Widget_Options::setTplateau);
        QObject::connect(other_parameters, &SettingOtherParameters::closing, this, &Widget_Options::closeWithAnimation);
        QObject::connect(this, &Widget_Options::closed_previous_option, other_parameters, &SettingOtherParameters::close);
//        QObject::connect(this, &Widget_Options::menu_closing, other_parameters, &SettingOtherParameters::deleteLater);
    }
    else if(option == "ajuste_fecha_hora"){
        DateTimeWidget *dt = new DateTimeWidget(this);
        dt->move(270,5);
        dt->show();
        QObject::connect(dt, &DateTimeWidget::settedFecha, this, &Widget_Options::closeWithAnimation);
        QObject::connect(dt, &DateTimeWidget::fechaHora, this, &Widget_Options::sendFechaHora);
        QObject::connect(this, &Widget_Options::closed_previous_option, dt, &DateTimeWidget::close);
//        QObject::connect(this, &Widget_Options::menu_closing, dt, &DateTimeWidget::deleteLater);
    }
    else if(option == "pacient_data"){
        ui->widget_buttons->hide();
        Pacient_Data_in_Menu *pacient_screen = new Pacient_Data_in_Menu(this);
        pacient_screen->setPacientData(pacient);
        pacient_screen->move(0,60);
        pacient_screen->show();
        QObject::connect(pacient_screen, &Pacient_Data_in_Menu::aceptedChanges, this, &Widget_Options::closeWithAnimation);
        QObject::connect(pacient_screen, &Pacient_Data_in_Menu::sendPacient, this, &Widget_Options::send_Pacient);
        QObject::connect(this, &Widget_Options::closed_previous_option, pacient_screen, &Pacient_Data_in_Menu::close);
//        QObject::connect(this, &Widget_Options::menu_closing, pacient_screen, &Pacient_Data_in_Menu::deleteLater);
    }
    else if(option == "log_information"){
        ui->widget_buttons->hide();
        Log_Information *logs = new Log_Information(this, log_list);
        logs->move(0,30);
        logs->show();
        QObject::connect(this, &Widget_Options::closed_previous_option, logs, &Log_Information::close);
//        QObject::connect(this, &Widget_Options::menu_closing, logs, &Log_Information::deleteLater);
    }
    else if(option == "l_download_data"){
        ui->widget_buttons->hide();
        Download_Data *data = new Download_Data(this);
        data->move(0,30);
        data->show();
        QObject::connect(this, &Widget_Options::closed_previous_option, data, &Download_Data::close);
//        QObject::connect(this, &Widget_Options::menu_closing, data, &Download_Data::deleteLater);
    }

    ui->l_hide_menu->raise();
}

void Widget_Options::sendFechaHora(QDateTime datetime){
    emit settedFechaHora(datetime);
}

void Widget_Options::send_Pacient(PacientClass &paciente){
    emit sendPacient(paciente);
}

void Widget_Options::setPacientData(PacientClass &paciente){
    pacient.operator_equal(paciente);
    log_list = pacient.read_LOG_parameters_in_DAT_file();
}

void Widget_Options::setVentilationState(bool state)
{
    started_ventilation = state;
    if(started_ventilation){
        ui->l_config_fecha_hora->setThirdState(false);
        ui->l_download_data->setThirdState(false);
        ui->l_calibracion_oxigeno->setThirdState(false);
    }else{
        ui->l_config_fecha_hora->setChecked(false);
        ui->l_download_data->setChecked(false);
        ui->l_calibracion_oxigeno->setChecked(false);
    }
}

void Widget_Options::setLogMessage(QStringList list){
    log_list = list;
}

void Widget_Options::on_l_config_alarms_clicked()
{
    close_previous_option();
    ui->l_config_alarms->setChecked(true);
    setCurrentOptions("ajuste_alarmas");
}
void Widget_Options::on_l_otros_ajustes_clicked()
{
    close_previous_option();
    ui->l_otros_ajustes->setChecked(true);
    setCurrentOptions("otros_ajustes");
}
void Widget_Options::on_l_config_fecha_hora_clicked()
{
    close_previous_option();
    ui->l_config_fecha_hora->setChecked(true);
    setCurrentOptions("ajuste_fecha_hora");
}
void Widget_Options::on_l_pacient_data_clicked()
{
    close_previous_option();
    ui->l_pacient_data->setChecked(true);
    setCurrentOptions("pacient_data");
}

void Widget_Options::on_l_download_data_clicked()
{
    close_previous_option();
    ui->l_download_data->setChecked(true);
    setCurrentOptions("l_download_data");
}

void Widget_Options::on_l_log_information_clicked()
{
    close_previous_option();
    ui->l_log_information->setChecked(true);
    setCurrentOptions("log_information");
}

void Widget_Options::on_l_calibracion_oxigeno_clicked()
{
    close_previous_option();
    ui->l_calibracion_oxigeno->setChecked(true);
    emit requestOxygenCalibration();
}

void Widget_Options::close_previous_option()
{
    ui->l_config_alarms->setChecked(false);
    ui->l_otros_ajustes->setChecked(false);
    ui->l_config_fecha_hora->setChecked(false);
    ui->l_pacient_data->setChecked(false);
    ui->l_log_information->setChecked(false);
    ui->l_download_data->setChecked(false);
    ui->l_calibracion_oxigeno->setChecked(false);

    if(started_ventilation){
        ui->l_config_fecha_hora->setThirdState(false);
        ui->l_download_data->setThirdState(false);
        ui->l_calibracion_oxigeno->setThirdState(false);
    }

    emit closed_previous_option();
}

void Widget_Options::setConfigs(int value_pmax, int value_peep, int step, int max,
                                int min, int trigger, double plateau, int fio2, int etco2)
{
    pmax = value_pmax;
    peep = value_peep;
    m_step = step;
    m_max_value = max;
    m_min_value = min;

    trigger_asistido = trigger;
    t_plateau = plateau;

    m_fio2 = fio2;
    m_etco2 = etco2;
}

void Widget_Options::setETCO2(int value)
{
    m_etco2 = value;
    emit settedETCO2(m_etco2);
}
void Widget_Options::setFiO2(int value)
{
    m_fio2 = value;
    emit settedFiO2(m_fio2);
}
void Widget_Options::setMinPEEP(int value)
{
    peep = value;
    emit settedPEEP(peep);
}

void Widget_Options::setMaxPeak(int value)
{
    pmax = value;
    emit settedPmax(pmax);
}

void Widget_Options::setTriggerAsistido(int value)
{
    trigger_asistido = value;
    emit settedTriggerAsistido(trigger_asistido);
}

void Widget_Options::setTplateau(double value)
{
    t_plateau = value;
    emit settedPlateau(t_plateau);
}

void Widget_Options::showInPos()
{
    ui->label->setPixmap(QPixmap(":/icons/menu_off.png"));
    ui->label->setFixedSize(321, 408);
    this->setFixedSize(321, 415);
    this->move(0, 58);
    this->show();
}

void Widget_Options::closeWithAnimation()
{
    menu_expanded = false;
    emit menu_closing();
    animateHideWidgetRightToLeft(this);
}

void Widget_Options::animateWidgetLeftToRight(QWidget *widget, int anim_time){
    QRect endValue = widget->geometry();
    QRect startValue = QRect(endValue.x() - endValue.width(),endValue.y()
                             ,endValue.width(),endValue.height());


    QPropertyAnimation *animation = new QPropertyAnimation(widget, "geometry");
    animation->setDuration(anim_time);
    animation->setStartValue(startValue);
    animation->setEndValue(endValue);
    animation->start();
}

void Widget_Options::animateHideWidgetRightToLeft(QWidget *widget, int anim_time){

    QRect startValue = widget->geometry();
    QRect endValue = QRect(startValue.x() - startValue.width(),startValue.y()
                           ,startValue.width(),startValue.height());

    QPropertyAnimation *animation = new QPropertyAnimation(widget, "geometry");
    animation->setDuration(anim_time);
    animation->setStartValue(startValue);
    animation->setEndValue(endValue);
    QObject::connect(animation, &QPropertyAnimation::finished, widget, &QWidget::close);
    animation->start();
}

void Widget_Options::on_l_hide_menu_clicked()
{
    closeWithAnimation();
}

void Widget_Options::on_pb_power_off_clicked()
{
    QApplication::closeAllWindows();
//    ProcessesClass::executeProcess(this, "sudo shutdown now", ProcessesClass::LINUX, 300);
}
