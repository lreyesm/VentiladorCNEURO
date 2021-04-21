#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <cstdlib>
#include "math.h"
#include <QDesktopWidget>
#include "pacientclass.h"
#include "processesclass.h"
#include <QEventLoop>
#include "dialog_question.h"
#include "screen_apagado_sistema.h"
#include "loadinganimation.h"

bool MainWindow::capnography_active=false;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //    this->showFullScreen();
    ProcessesClass::executeProcess(this, "sudo nice -n-20 /home/pi/TCP_IP_Client/TCP_IP_Client", ProcessesClass::LINUX, 1000, false);

    fillMapAlarms();

    inicialState();

    //    timer.setInterval(TIMER_GRAPH_INTERVAL);
    //    connect(&timer, SIGNAL(timeout()), this, SLOT(testGraphFunction()));
    //    sensor = new ReadTempDS18B20Class(this);
    //connect(sensor, &ReadTempDS18B20Class::tempReady, this, &MainWindow::readTempSensor);

    connect(&tcp_controller, &TCP_Server_Controller::connected,this,&MainWindow::on_newConnection);
    connect(&tcp_controller, &TCP_Server_Controller::dataAvailableTCP,this,&MainWindow::readTCPData);

    connect(ui->widget_alarms, &MyWidgetAlarmAnimated::nuevaAlarma, this, &MainWindow::write_LOG);
    connect(ui->widget_alarms, &MyWidgetAlarmAnimated::removidaAlarma, this, &MainWindow::write_LOG);
    connect(ui->widget_alarms, &MyWidgetAlarmAnimated::alarm_count, ui->l_alarm_icon, &QLabel::setText);
    connect(ui->widget_alarms, &MyWidgetAlarmAnimated::changedColor, ui->l_alarm_icon, &MyLabelAlarmPhotoTextAnimated::setPhotoColor);
    connect(ui->widget_alarms, &MyWidgetAlarmAnimated::hidingWidgetAlarms, this, &MainWindow::clearAlarmsNotifications);

    connect(ui->widget_alarms, &MyWidgetAlarmAnimated::showing_menu_alarms, this, &MainWindow::alarmMenuShown);

    QString pacient_name;
    if(checkForceClosed(pacient_name)){
        paciente.setName(pacient_name);
        paciente.setFolderPacient();
        paciente.read_file();//lee informacione de paciente

        ventilation_screen = true;

        if(lastVentState){
            ui->l_power->setChecked(true);
            on_l_power_clicked();
        }
    }else{
        screen_logo = new Screen_Logo(this);
        connect(this, &MainWindow::skipToVentilationScreen, screen_logo, &Screen_Logo::end_screen_logo);
        screen_logo->show();
        connect(screen_logo, &Screen_Logo::setFechaHoraReceived, this, &MainWindow::setFechaHoraReceived);
        connect(screen_logo, &Screen_Logo::closed_screen_logo, this, &MainWindow::on_closed_Screen_logo);
    }

    //Si estas señales dan problemas volver a la forma vieja -> startAlarm() para los ui->l_PIP... etc en decodeAlarm();
    //    connect(ui->widget_alarms, &MyWidgetAlarmAnimated::changedColor, ui->l_PIP, &MyLabelAlarmAnimated::setBackgroundColor);
    //    connect(ui->widget_alarms, &MyWidgetAlarmAnimated::changedColor, ui->l_PIP_label, &MyLabelAlarmAnimated::setBackgroundColor);
    //    connect(ui->widget_alarms, &MyWidgetAlarmAnimated::changedColor, ui->l_PIP_secundary, &MyLabelAlarmAnimated::setBackgroundColor);
    //    connect(ui->widget_alarms, &MyWidgetAlarmAnimated::changedColor, ui->l_PIP_label_secundary, &MyLabelAlarmAnimated::setBackgroundColor);

    //    connect(ui->widget_alarms, &MyWidgetAlarmAnimated::changedColor, ui->l_PEEP, &MyLabelAlarmAnimated::setBackgroundColor);
    //    connect(ui->widget_alarms, &MyWidgetAlarmAnimated::changedColor, ui->l_PEEP_label, &MyLabelAlarmAnimated::setBackgroundColor);
    //    connect(ui->widget_alarms, &MyWidgetAlarmAnimated::changedColor, ui->l_PEEP_secundary, &MyLabelAlarmAnimated::setBackgroundColor);
    //    connect(ui->widget_alarms, &MyWidgetAlarmAnimated::changedColor, ui->l_PEEP_label_secundary, &MyLabelAlarmAnimated::setBackgroundColor);
    //    connect(ui->widget_alarms, &MyWidgetAlarmAnimated::changedColor, ui->l_p_min, &MyLabelAlarmAnimated::setBackgroundColor);
    //    connect(ui->widget_alarms, &MyWidgetAlarmAnimated::changedColor, ui->l_pulso0, &MyLabelAlarmPhotoAnimated::setBackgroundColor);
    //    connect(ui->widget_alarms, &MyWidgetAlarmAnimated::changedColor, ui->l_sin_pulso, &MyLabelAlarmPhotoAnimated::setBackgroundColor);
}

bool MainWindow::checkForceClosed(QString &pacient_name){ //Returna true si fue anteriormente cerrada forzada
    QFile *data_base = new QFile("/home/pi/Ventilador/Ventilador/force_closed.dat"); // ficheros .dat se puede usar para cargar despues
    if(data_base->exists()){
        if(data_base->open(QIODevice::ReadOnly))
        {
            QByteArray bytes = data_base->readAll();
            QString n = QString::fromLatin1(bytes);
            pacient_name = n;
            data_base->close();
            data_base->remove();
            return true;
        }
    }
    return false;
}

void MainWindow::fillMapAlarms(){
    mapaAlarmas.insert(presure_leak, "!!! Baja presión en la vía aérea");
    mapaAlarmas.insert(over_presure, "!!! Alta presión en la vía aérea");
    mapaAlarmas.insert(low_presure, "!!! Ventilacion no detectada");
    mapaAlarmas.insert(low_battery, "!!! Batería baja: 5 min restantes");
    mapaAlarmas.insert(peep_range, "!! PEEP fuera de rango");
    mapaAlarmas.insert(low_volumen, "!! Volumen tidal bajo");
    mapaAlarmas.insert(raise_resistence, "!! Alta resistencia de la vía aérea");
    mapaAlarmas.insert(low_battery_medium, "!! Batería baja: 10 min restante");
    mapaAlarmas.insert(no_intern_battery, "!! Fallo de batería interna");
    mapaAlarmas.insert(pressure_error_measurement, "!! Error en medicion de presión");
    mapaAlarmas.insert(high_energy_consumption, "!! Fallo de funcionamiento del motor");
    mapaAlarmas.insert(high_oxigen_level, "!! FiO2 fuera de rango");
    mapaAlarmas.insert(high_temperature, "!! Alta temperatura");
    mapaAlarmas.insert(apnea_detected, "!! Ventilación en Apnea");
    mapaAlarmas.insert(oxygen_sensor_error, "!! Error en sensor de oxígeno");
    mapaAlarmas.insert(high_co2_level, "!! Alto nivel de ETCO2");
    mapaAlarmas.insert(co2_sensor_error, "!! Error en sensor de capnografía");
    mapaAlarmas.insert(low_co2_level, "!! Bajo nivel de ETCO2");
    mapaAlarmas.insert(no_extern_source, "! Batería interna activada");
    mapaAlarmas.insert(clock_error, "! Reloj del sistema desactualizado");
}

void MainWindow::requestPauseGraph(){

}

MainWindow::~MainWindow()
{
    if(serialPort != nullptr)
        serialPort->close();
    delete ui;
}

SerialPort* MainWindow::getSerialPortInstance(){
    return this->serialPort;
}
void MainWindow::conectarSignalsCalibracion(bool connect_disconnect){
    if(connect_disconnect){
        connect(screen_calibration, &Screen_Calibration::closed_screen_calibration, this, &MainWindow::on_close_Screen_Calibration);
        connect(serialPort, &SerialPort::calibracion_exitosa_motor, this, &MainWindow::changeCalibrationState);
        connect(serialPort, &SerialPort::calibracion_exitosa_motor, screen_calibration, &Screen_Calibration:: initPresureCalibration);
        connect(serialPort, &SerialPort::calibracion_exitosa_presion, screen_calibration, &Screen_Calibration::incrementProgressBar);
        connect(serialPort, &SerialPort::calibracion_fallida, this, &MainWindow::errorDeCalibracion);
    }else{
        disconnect(screen_calibration, &Screen_Calibration::closed_screen_calibration, this, &MainWindow::on_close_Screen_Calibration);
        disconnect(serialPort, &SerialPort::calibracion_exitosa_motor, this, &MainWindow::changeCalibrationState);
        disconnect(serialPort, &SerialPort::calibracion_exitosa_motor, screen_calibration, &Screen_Calibration:: initPresureCalibration);
        disconnect(serialPort, &SerialPort::calibracion_exitosa_presion, screen_calibration, &Screen_Calibration::incrementProgressBar);
        disconnect(serialPort, &SerialPort::calibracion_fallida, this, &MainWindow::errorDeCalibracion);
    }
}
//Funcion de estado de la app--------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------
void MainWindow::on_closed_Screen_logo(){
    screen_logo->deleteLater();
    calibration_motor_active = true;
    screen_calibration = new Screen_Calibration(this);
    connect(this, &MainWindow::skipToVentilationScreen, screen_calibration, &Screen_Calibration::end_Screen_Calibration);
    screen_calibration->show();
    conectarSignalsCalibracion(true);
    currentState = SerialPort::CALIBRACION_MOTOR;
    serialPort->disableTimeOutErrorTimer();
}

void MainWindow::changeCalibrationState(){
    calibration_motor_active = false;
    calibration_presion_active = true;
    currentState = SerialPort::CALIBRACION_PRESION;
}

void MainWindow::errorDeCalibracion(){
    disconnect(serialPort, &SerialPort::calibracion_fallida, this, &MainWindow::errorDeCalibracion);
    if(calibration_presion_active){
        screen_calibration->setCalibationErrorText("Calibración de presíon fallida");
        Dialog_Question *dialog = new Dialog_Question(this, "Error de Calibración", "¿Desea continuar?");
        dialog->showCenter();
        QObject::connect(dialog, &Dialog_Question::accepted, this, &MainWindow::on_accept_Calibation_Error);

    }else if(calibration_motor_active){

        screen_calibration->setCalibationErrorText("Calibración de motor fallida");
        showAlarm("Error", "Calibración fallida");
    }

}
void MainWindow::on_accept_Calibation_Error(int res){
    if(res==1){
        on_close_Screen_Calibration();
    }else{

    }
}
void MainWindow::on_close_Screen_Calibration(){
    calibration_presion_active = false;
    conectarSignalsCalibracion(false);
    screen_calibration->deleteLater();
    currentState = SerialPort::STANDBY;
    serialPort->enableTimeOutErrorTimer();
    screen_Pacient_Data = new Screen_Pacient_Data(this);
    connect(this, &MainWindow::skipToVentilationScreen, screen_Pacient_Data, &Screen_Pacient_Data::close);
    screen_Pacient_Data->show();
    connect(screen_Pacient_Data, &Screen_Pacient_Data::closed_Screen_Pacient_Data, this, &MainWindow::on_close_Screen_Pacient_Data);
    connect(screen_Pacient_Data, &Screen_Pacient_Data::settedFechaHora, this, &MainWindow::setFechaHoraReceived);
}
void MainWindow::on_close_Screen_Pacient_Data(PacientClass &pacient){
    paciente.operator_equal(pacient);

    writeInitialConfigurationLog();

    setVolumen_Tidal(Screen_Pacient_Data::estimateVolumen(
                         Screen_Pacient_Data::fitHeightMaleWithData(
                             paciente.height.toInt())));

    //    decodeAlarm(oxygen_sensor_error); //estado para probar alarmas

    //    ui->l_PEEP_terciary->setActiveColor(color_medium_priority);
    //    ui->l_PEEP_label_terciary->startAlarm();
    //    ui->l_PEEP_terciary->startAlarm();
    //    ui->l_sin_pulso_peep_terciary->startAlarm();

    //    ui->l_PIP_label_terciary->startAlarm();
    //    ui->l_PIP_terciary->startAlarm();

    //    ui->l_fio2->setActiveColor(color_medium_priority);
    //    ui->l_fio2_configured->setActiveColor(color_medium_priority);
    //    ui->l_fio2_configured->startAlarm();
    //    ui->l_fio2->startAlarm();
    //    ui->l_fio2_label->startAlarm();
    //    ui->l_p_max_porcentage_terciary->startAlarm();

    if(screen_Pacient_Data){
        screen_Pacient_Data->deleteLater();
    }
    ventilation_screen = true;
}
//Funcion ejecutada al cerrar app--------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------
void MainWindow::closeEvent(QCloseEvent *event)
{
    if(serialPort != nullptr && serialPort->isOpen()){
        serialPort->close();
    }
    saveLastConfiguration();

    QWidget::closeEvent(event);
}
//---------------------------------------------------------------------------------------------------------------------------


//Funciones de conexion TCPIP-------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------
void MainWindow::on_newConnection(QString n){
    Q_UNUSED(n);
    ui->statusBar->showMessage("Conectado TCP/IP", 3000);
    //    MessageDialog *mess = new MessageDialog(this, "TCP/IP", "Conectado");
    //    mess->showCenter();
}
void MainWindow::readTCPData(QByteArray bytes){

    QString n = QString::fromLatin1(bytes);
    ui->statusBar->showMessage(n, 3000);
    qDebug()<<n;
    if(n.contains("request")){
        write_TCP_Data();
    }
}
void MainWindow::write_TCP_Data(){

    if(!tcp_controller.is_Connected()){
        return;
    }
    QJsonDocument d;
    QJsonObject jsonObject;

    for (int i = pos_in_buffer_to_write_in_file, c=0; i < pos_in_buffer_to_write_in_file+UART_READ_DATA_FUNCTION_SIZE; i++) {
        jsonObject.insert("Function_"+QString::number(c), QString::number(static_cast<double>(data_to_write_in_file[i]), 'f', 2));
        c++;
    }

    jsonObject.insert("Nombre", paciente.name_pacient);

    jsonObject.insert("VolumenTidal", QString::number(static_cast<double>(VolumenTidal), 'f', 0));
    jsonObject.insert("BPM", QString::number(static_cast<double>(BPM), 'f', 0));
    jsonObject.insert("Relacion_IE", QString::number(static_cast<double>(Relacion_IE), 'f', 2));
    jsonObject.insert("Tplat", QString::number(static_cast<double>(t_plateau), 'f', 0));
    jsonObject.insert("Pmax", QString::number(static_cast<double>(Pmax), 'f', 0));
    jsonObject.insert("Pmin", QString::number(static_cast<double>(Pmin), 'f', 0));
    jsonObject.insert("ModoVentilacion", ui->l_modo->getText());
    jsonObject.insert("EstadoAlarmas", QString::number(static_cast<double>(EstadoAlarmas), 'f', 0));
    jsonObject.insert("EstadoBocinas", QString::number(static_cast<double>(EstadoBocinas), 'f', 0));

    if(started_ventilation){
        jsonObject.insert("Estado", "on");
    }else{
        jsonObject.insert("Estado", "off");
    }

    jsonObject.insert("PEEP", QString::number(static_cast<double>(PEEP), 'f', 0));
    jsonObject.insert("Ppla", QString::number(static_cast<double>(Ppla), 'f', 0));
    jsonObject.insert("PIP", QString::number(static_cast<double>(PIP), 'f', 0));
    jsonObject.insert("Alimentacion", QString::number(static_cast<double>(Alimentacion), 'f', 0));
    jsonObject.insert("Estado_Bateria", QString::number(static_cast<double>(Estado_Bateria), 'f', 0));
    jsonObject.insert("Pmed", QString::number(static_cast<double>(Pmed), 'f', 0));
    jsonObject.insert("Rinsp", QString::number(static_cast<double>(Rinsp), 'f', 0));
    jsonObject.insert("Cest", QString::number(static_cast<double>(Cest), 'f', 0));

    d.setObject(jsonObject);
    tcp_controller.write_data(d.toJson(QJsonDocument::Compact));
    tcp_controller.write_data("\n");
    qDebug()<<"Compact****";
    //    qDebug()<<QString::fromLatin1(d.toJson(QJsonDocument::Compact));
}
//---------------------------------------------------------------------------------------------------------------------------


//Funciones de eventos (Swipe emulation)--------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------
void MainWindow::mousePressEvent(QMouseEvent *event){
    Q_UNUSED(event);
    if(QApplication::mouseButtons()==Qt::LeftButton && ventilation_screen){
        init_pos_x = (QWidget::mapFromGlobal(QCursor::pos())).x();
        init_pos_y = (QWidget::mapFromGlobal(QCursor::pos())).y();
        //        qDebug()<<"mousePressEvent ->    x: " + QString::number(init_pos_x) + "   y: "+QString::number(init_pos_y);
        if(menu_shown){
            if(init_pos_x > 315 || init_pos_y < 58){ //Area fuera del menu en forma sencilla
                if(options){
                    if(!options->menu_expanded){
                        hideMenu();
                    }
                }
            }
            if(init_pos_x > 580 || init_pos_y < 58){ //Area fuera del menu en forma sencilla
                if(options){
                    if(options->menu_expanded){
                        hideMenu();
                    }
                }
            }
        }
        if(init_pos_x > 570 && init_pos_y < 380 && !ui->widget_data->isHidden()){ //area del widget data
            swipe_area_pressed = true;
            //            qDebug()<<"swipe_area_pressed = true";
        }else{
            swipe_area_pressed = false;
            //            qDebug()<<"swipe_area_pressed = false";
        }
        if((init_pos_x <= 570 || ui->widget_data->isHidden()) && init_pos_y < 420){//area del widget menu //probar esto nuevo si no hay ventilacion el area de swipe es toda la pantalla
            //            qDebug()<<"menu_area_pressed = true";
            menu_area_pressed = true;
        }else{
            //            qDebug()<<"menu_area_pressed = false";
            menu_area_pressed = false;
        }
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event){
    Q_UNUSED(event);
    //    qDebug()<<"mouseReleaseEvent ->    x: " + QString::number(event->x()) + "   y: "+QString::number(event->y());
    int current_pos_x = (QWidget::mapFromGlobal(QCursor::pos())).x();
    //        int current_pos_y = (QWidget::mapFromGlobal(QCursor::pos())).y();

    if(swipe_area_pressed){
        int swipe_magnitud = init_pos_x - current_pos_x;
        swipeDataWidget(swipe_magnitud);
    }
    if(menu_area_pressed){
        int swipe_magnitud = init_pos_x - current_pos_x;
        swipeMenuWidget(swipe_magnitud);
    }
    swipe_area_pressed = false;
    menu_area_pressed = false;
}
void MainWindow::swipeMenuWidget(int swipe_magnitud){
    if(swipe_magnitud < 0){ ///swipe de izquierda a derecha
        if(qAbs(swipe_magnitud) > SWIPE_MAGNITUD_THRESHOLD*2){
            qDebug()<<"swipeMenuWidget Hacia izquierda swipe_magnitud ->  " + QString::number(swipe_magnitud);
            if(!menu_shown){
                showMenu();
            }
        }
    }
    else{
        if(qAbs(swipe_magnitud) > SWIPE_MAGNITUD_THRESHOLD*2){
            qDebug()<<"swipeMenuWidget Hacia derecha swipe_magnitud ->  " + QString::number(swipe_magnitud);
            hideMenu();
        }
    }
}
void MainWindow::swipeDataWidget(int swipe_magnitud){
    if(swipe_magnitud < 0){ ///swipe de izquierda a derecha
        if(qAbs(swipe_magnitud) > SWIPE_MAGNITUD_THRESHOLD){
            qDebug()<<"Hacia derecha swipe_magnitud ->  " + QString::number(swipe_magnitud);
            if(currentWidget == PRIMARY_WIDGET){
                currentWidget = TERCIARY_WIDGET;
                qDebug()<<"TERCIARY_WIDGET";
                ui->l_currentData_showing->setPixmap(QPixmap(":/icons/info_point_terciary.png"));
                ui->widget_data_primary->hide();
                if(capnography_active){
                    ui->widget_data_terciary_capnography->move(0, 0);
                    ui->widget_data_terciary_capnography->show();
                    animateWidgetLeftToRight(ui->widget_data_terciary_capnography);
                }else{
                    ui->widget_data_terciary->move(0, 0);
                    ui->widget_data_terciary->show();
                    animateWidgetLeftToRight(ui->widget_data_terciary);
                }
            }else if(currentWidget == SECUNDARY_WIDGET){
                qDebug()<<"PRIMARY_WIDGET";
                currentWidget = PRIMARY_WIDGET;
                ui->l_currentData_showing->setPixmap(QPixmap(":/icons/info_point_primary.png"));
                ui->widget_data_secundary->hide();
                ui->widget_data_primary->move(0, 0);
                ui->widget_data_primary->show();
                animateWidgetLeftToRight(ui->widget_data_primary);
            }else if(currentWidget == TERCIARY_WIDGET){
                qDebug()<<"SECUNDARY_WIDGET";
                currentWidget = SECUNDARY_WIDGET;
                ui->l_currentData_showing->setPixmap(QPixmap(":/icons/info_point_secundary.png"));
                ui->widget_data_terciary->hide();
                ui->widget_data_terciary_capnography->hide();
                ui->widget_data_secundary->move(0, 0);
                ui->widget_data_secundary->show();
                animateWidgetLeftToRight(ui->widget_data_secundary);
            }
        }
    }else if(swipe_magnitud > 0){ ///swipe de derecha a izquierda
        if(qAbs(swipe_magnitud) > SWIPE_MAGNITUD_THRESHOLD){
            qDebug()<<"Hacia izquierda swipe_magnitud ->  " + QString::number(swipe_magnitud);
            if(currentWidget == PRIMARY_WIDGET){
                qDebug()<<"SECUNDARY_WIDGET";
                currentWidget = SECUNDARY_WIDGET;
                ui->l_currentData_showing->setPixmap(QPixmap(":/icons/info_point_secundary.png"));
                ui->widget_data_primary->hide();
                ui->widget_data_secundary->move(0, 0);
                ui->widget_data_secundary->show();
                animateWidgetRightToLeft(ui->widget_data_secundary);
            }else if(currentWidget == SECUNDARY_WIDGET){
                qDebug()<<"TERCIARY_WIDGET";
                currentWidget = TERCIARY_WIDGET;
                ui->l_currentData_showing->setPixmap(QPixmap(":/icons/info_point_terciary.png"));
                ui->widget_data_secundary->hide();
                if(capnography_active){
                    ui->widget_data_terciary_capnography->move(0, 0);
                    ui->widget_data_terciary_capnography->show();
                    animateWidgetRightToLeft(ui->widget_data_terciary_capnography);
                }else{
                    ui->widget_data_terciary->move(0, 0);
                    ui->widget_data_terciary->show();
                    animateWidgetRightToLeft(ui->widget_data_terciary);
                }

            }else if(currentWidget == TERCIARY_WIDGET){
                qDebug()<<"PRIMARY_WIDGET";
                currentWidget = PRIMARY_WIDGET;
                ui->l_currentData_showing->setPixmap(QPixmap(":/icons/info_point_primary.png"));
                ui->widget_data_terciary->hide();
                ui->widget_data_terciary_capnography->hide();
                ui->widget_data_primary->move(0, 0);
                ui->widget_data_primary->show();
                animateWidgetRightToLeft(ui->widget_data_primary);
            }
        }
    }
}
void MainWindow::animateWidgetLeftToRight(QWidget *widget, int anim_time){
    QRect endValue = widget->geometry();
    QRect startValue = QRect(endValue.x() - endValue.width(),endValue.y()
                             ,endValue.width(),endValue.height());


    QPropertyAnimation *animation = new QPropertyAnimation(widget, "geometry");
    animation->setDuration(anim_time);
    animation->setStartValue(startValue);
    animation->setEndValue(endValue);
    animation->start();
}
void MainWindow::animateWidgetRightToLeft(QWidget *widget, int anim_time){
    QRect endValue = widget->geometry();
    QRect startValue = QRect(endValue.x() + endValue.width(),endValue.y()
                             ,endValue.x(),endValue.height());


    QPropertyAnimation *animation = new QPropertyAnimation(widget, "geometry");
    animation->setDuration(anim_time);
    animation->setStartValue(startValue);
    animation->setEndValue(endValue);
    animation->start();
}
void MainWindow::animateHideWidgetRightToLeft(QWidget *widget, int anim_time){

    QRect startValue = widget->geometry();
    QRect endValue = QRect(startValue.x() - startValue.width(),startValue.y()
                           ,startValue.width(),startValue.height());

    QPropertyAnimation *animation = new QPropertyAnimation(widget, "geometry");
    animation->setDuration(anim_time);
    animation->setStartValue(startValue);
    animation->setEndValue(endValue);
    QObject::connect(animation, &QPropertyAnimation::finished, widget, &QWidget::hide);
    animation->start();
}
//---------------------------------------------------------------------------------------------------------------------------


//Funcion de fecha y hora de app--------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------
QString MainWindow::fillLogMessage(QString cabecera)
{
    QString log = "";

    QString time = QDateTime::currentDateTime().toString(formato_fecha_hora_log);
    log += time + " - ";

    QString info = cabecera + "     ";
    info += "VolumenTidal = " + QString::number(static_cast<double>(VolumenTidal) , 'f', 0) + "    ";
    info += "BPM = " + QString::number(static_cast<double>(BPM) , 'f', 0)+ "    ";
    info += "Relacion_IE = " + QString::number(static_cast<double>(Relacion_IE) , 'f', 0)+ "    ";
    info += "Tplat = " + QString::number(static_cast<double>(t_plateau) , 'f', 0)+ "    ";
    info += "Pmax = " + QString::number(static_cast<double>(Pmax) , 'f', 0)+ "    ";
    info += "Pmin = " + QString::number(static_cast<double>(Pmin) , 'f', 0)+ "    ";
    info += "ModoVentilacion = " + QString::number(static_cast<double>(Pmin) , 'f', 0)+ "    ";
    info += "EstadoAlarmas = " + QString::number(static_cast<double>(EstadoAlarmas) , 'f', 0)+ "    ";
    info += " = " + QString::number(static_cast<double>(EstadoBocinas) , 'f', 0)+ "    ";

    info += "Ppla = " + QString::number(static_cast<double>(Ppla) , 'f', 0)+ "    ";
    info += "PEEP = " + QString::number(static_cast<double>(PEEP) , 'f', 0)+ "    ";
    info += "PIP = " + QString::number(static_cast<double>(PIP) , 'f', 0)+ "    ";

    log += "    " + info;

    return log;
}
QJsonObject MainWindow::fillLogJsonObject(QString cabecera){
    QJsonObject jsonObjectConfiguracion;

    jsonObjectConfiguracion.insert("Evento", cabecera);
    jsonObjectConfiguracion.insert(date_time_key, QDateTime::currentDateTime().toString("dd-MM-yyyy hh:mm:ss"));

    jsonObjectConfiguracion.insert(Pmax_key, QString::number(static_cast<double>(Pmax), 'f', 2));
    jsonObjectConfiguracion.insert(Relacion_IE_key, QString::number(static_cast<double>(Relacion_IE), 'f', 2));
    jsonObjectConfiguracion.insert(BPM_key, QString::number(static_cast<double>(  BPM ), 'f', 2));
    jsonObjectConfiguracion.insert(VolumenTidal_key, QString::number(static_cast<double>(  VolumenTidal ), 'f', 2));
    jsonObjectConfiguracion.insert(ModoVentilacion_key, QString::number(static_cast<double>(  ModoVentilacion ), 'f', 2));
    jsonObjectConfiguracion.insert(t_plateau_key, QString::number(static_cast<double>(  t_plateau ), 'f', 2));
    jsonObjectConfiguracion.insert(Pmin_key, QString::number(static_cast<double>(  Pmin ), 'f', 2));
    jsonObjectConfiguracion.insert(EstadoAlarmas_key, QString::number(static_cast<double>( EstadoAlarmas  ), 'f', 2));
    jsonObjectConfiguracion.insert(EstadoBocinas_key, QString::number(static_cast<double>( EstadoBocinas  ), 'f', 2));

    jsonObjectConfiguracion.insert(Ppla_key, QString::number(static_cast<double>( Ppla  ), 'f', 2));
    jsonObjectConfiguracion.insert(PEEP_key, QString::number(static_cast<double>( PEEP  ), 'f', 2));
    jsonObjectConfiguracion.insert(PIP_key, QString::number(static_cast<double>( PIP  ), 'f', 2));

    return jsonObjectConfiguracion;
}
//---------------------------------------------------------------------------------------------------------------------------


//Funcion de fecha y hora de app--------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------
void MainWindow::setFechaHora()
{
    DateTimeWidget *dt = new DateTimeWidget(this);
    connect(dt, &DateTimeWidget::settedFecha, this, &MainWindow::hideMenu);
    dt->showCenter();
}
//---------------------------------------------------------------------------------------------------------------------------


//Funciones de alarmas de app------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------
void MainWindow::clearWidgets(QLayout * layout) {
    if (! layout)
        return;
    while (auto item = layout->takeAt(0)) {
        delete item->widget();
        clearWidgets(item->layout());
    }
}
bool MainWindow::isActivedAlarm(QString alarm_name){ //true si ya esta en el widget
    return ui->widget_alarms->isActiveAlarm(alarm_name);
}
void MainWindow::alarmMenuShown(bool shown){
    if(shown){
        ui->l_alarm_text->setText("Alarmas");
    }else{
        ui->l_alarm_text->setText(ui->widget_alarms->getActiveAlarm());
    }
}
void MainWindow::setAlarmText(QStringList texts, bool activated, QColor color/*background*/, QColor text_color){
    if(texts.isEmpty()){
        if(!ui->widget_alarms->isChecked()){
            ui->l_alarm_text->setText("");
        }
        ui->widget_alarms->setActiveAlarm("");
    }else{
        if(!ui->widget_alarms->isChecked()){
            ui->l_alarm_text->setText(texts.last());
        }
        ui->widget_alarms->setActiveAlarm(texts.last());
        QString text;
        foreach(text, texts){
            ui->widget_alarms->setText(text);
        }
    }

    if(activated){
        ui->l_alarm_icon->show();
        ui->widget_alarms->setActiveColor(color, text_color);
        if(color != color_low_priority){
            ui->widget_alarms->startAlarm();
        }else{
            ui->widget_alarms->changeColor();
        }
    }else{
        ui->widget_alarms->stopAlarm();
        if(!ui->widget_alarms->isChecked()){
            ui->l_alarm_text->setText("");
        }
        ui->widget_alarms->setActiveAlarm("");
        ui->l_alarm_icon->hide();
    }
}
void MainWindow::removeAlarm(QString text){
    ui->widget_alarms->removeAlarm(text);
}

bool MainWindow::decodeAlarm(float a){ //retona true si una alarma se activa
    uint32_t alarma = static_cast<uint32_t>(a);
    bool alarm_activated = false;
    float previous_alarm = lastActiveAlarm;

    QStringList final_text;
    QColor final_color = color_high_priority;
    QColor final_text_active_color = QColor(Qt::black); //por defecto

    if((alarma & clock_error) == clock_error){///Alarmas Baja prioridad--------------------------------------------------------------------------------------------
        QString name_alarm = "clock_error";
        if(!isActivedAlarm(name_alarm)){
            alarm_activated = true;
            final_text.append(mapaAlarmas.value(clock_error)); final_color = color_low_priority;
            lastActiveAlarm = clock_error;
            ui->l_clock_error->show();
        }
    }else{
        QString alarm_string = mapaAlarmas.value(clock_error);
        removeAlarm(alarm_string);
        ui->l_clock_error->hide();
    }
    if((alarma & no_extern_source) == no_extern_source){
        QString name_alarm = "no_extern_source";
        if(!isActivedAlarm(name_alarm)){
            alarm_activated = true;
            final_text.append(mapaAlarmas.value(no_extern_source)); final_color = color_low_priority;
            lastActiveAlarm = no_extern_source;
        }
    }else{
        QString alarm_string = mapaAlarmas.value(no_extern_source);
        removeAlarm(alarm_string);
    }
    if((alarma & high_temperature) == high_temperature){///Alarmas Media prioridad--------------------------------------------------------------------------------------------

        QString name_alarm = "high_temperature";
        if(!isActivedAlarm(name_alarm)){
            alarm_activated = true;
            final_text.append(mapaAlarmas.value(high_temperature)); final_color = color_medium_priority;
            lastActiveAlarm = high_temperature;
        }
    }else{
        QString alarm_string = mapaAlarmas.value(high_temperature);
        removeAlarm(alarm_string);
    }
    if((alarma & high_oxigen_level) == high_oxigen_level){
        QString name_alarm = "high_oxigen_level";
        if(!isActivedAlarm(name_alarm)){
            alarm_activated = true;

            if(capnography_active){
                ui->l_fio2_capnography->setActiveColor(color_medium_priority);
                ui->l_fio2_configured_capnography->setActiveColor(color_medium_priority);
                ui->l_fio2_capnography->startAlarm();
                ui->l_fio2_configured_capnography->startAlarm();
                ui->l_fio2_label_capnography->startAlarm();
                ui->l_p_max_porcentage_terciary_capnography->startAlarm();
            }else{
                ui->l_fio2->setActiveColor(color_medium_priority);
                ui->l_fio2_configured->setActiveColor(color_medium_priority);
                ui->l_fio2->startAlarm();
                ui->l_fio2_configured->startAlarm();
                ui->l_fio2_label->startAlarm();
                ui->l_p_max_porcentage_terciary->startAlarm();
            }

            final_text.append(mapaAlarmas.value(high_oxigen_level)); final_color = color_medium_priority;
            lastActiveAlarm = high_oxigen_level;
        }
    }else{
        QString alarm_string = mapaAlarmas.value(high_oxigen_level);
        removeAlarm(alarm_string);
        if((alarma & oxygen_sensor_error) != oxygen_sensor_error){

            if(capnography_active){
                ui->l_fio2_capnography->stopAlarm();
                ui->l_fio2_label_capnography->stopAlarm();
                ui->l_fio2_configured_capnography->stopAlarm();
                ui->l_p_max_porcentage_terciary_capnography->stopAlarm();
            }else{
                ui->l_fio2->stopAlarm();
                ui->l_fio2_label->stopAlarm();
                ui->l_fio2_configured->stopAlarm();
                ui->l_p_max_porcentage_terciary->stopAlarm();
            }
        }
    }
    if((alarma & high_energy_consumption) == high_energy_consumption){
        QString name_alarm = "high_energy_consumption";
        if(!isActivedAlarm(name_alarm)){
            alarm_activated = true;
            final_text.append(mapaAlarmas.value(high_energy_consumption)); final_color = color_medium_priority;
            lastActiveAlarm = high_energy_consumption;
        }
    }else{
        QString alarm_string = mapaAlarmas.value(high_energy_consumption);
        removeAlarm(alarm_string);
    }
    if((alarma & pressure_error_measurement) == pressure_error_measurement){
        QString name_alarm = "pressure_error_measurement";
        if(!isActivedAlarm(name_alarm)){
            alarm_activated = true;
            final_text.append(mapaAlarmas.value(pressure_error_measurement)); final_color = color_medium_priority;
            lastActiveAlarm = pressure_error_measurement;
        }
    }else{
        QString alarm_string = mapaAlarmas.value(pressure_error_measurement);
        removeAlarm(alarm_string);
    }
    if((alarma & no_intern_battery) == no_intern_battery){
        QString name_alarm = "no_intern_battery";
        if(!isActivedAlarm(name_alarm)){
            alarm_activated = true;
            final_text.append(mapaAlarmas.value(no_intern_battery)); final_color = color_medium_priority;
            lastActiveAlarm = no_intern_battery;
        }
    }else{
        QString alarm_string = mapaAlarmas.value(no_intern_battery);
        removeAlarm(alarm_string);
    }
    if((alarma & low_battery_medium) == low_battery_medium){
        QString name_alarm = "low_battery_medium";
        if(!isActivedAlarm(name_alarm)){
            alarm_activated = true;
            final_text.append(mapaAlarmas.value(low_battery_medium)); final_color = color_medium_priority;
            lastActiveAlarm = low_battery_medium;
        }
    }else{
        QString alarm_string = mapaAlarmas.value(low_battery_medium);
        removeAlarm(alarm_string);
    }
    if((alarma & raise_resistence) == raise_resistence){
        QString name_alarm = "raise_resistence";
        if(!isActivedAlarm(name_alarm)){
            alarm_activated = true;
            final_text.append(mapaAlarmas.value(raise_resistence)); final_color = color_medium_priority;
            lastActiveAlarm = raise_resistence;
        }
    }else{
        QString alarm_string = mapaAlarmas.value(raise_resistence);
        removeAlarm(alarm_string);
    }
    if((alarma & low_volumen) == low_volumen){
        QString name_alarm = "low_volumen";
        if(!isActivedAlarm(name_alarm)){
            alarm_activated = true;
            final_text.append(mapaAlarmas.value(low_volumen)); final_color = color_medium_priority;
            lastActiveAlarm = low_volumen;
        }
    }else{
        QString alarm_string = mapaAlarmas.value(low_volumen);
        removeAlarm(alarm_string);
    }
    if((alarma & peep_range) == peep_range){
        QString name_alarm = "peep_range";
        if(!isActivedAlarm(name_alarm)){
            alarm_activated = true;

            ui->l_PEEP->setActiveColor(color_medium_priority);
            ui->l_PEEP_label->setActiveColor(color_medium_priority);
            ui->l_PEEP_secundary->setActiveColor(color_medium_priority);
            ui->l_PEEP_label_secundary->setActiveColor(color_medium_priority);
            ui->l_p_min->setActiveColor(color_medium_priority);
            ui->l_PEEP->startAlarm();
            ui->l_PEEP_label->startAlarm();
            ui->l_PEEP_secundary->startAlarm();
            ui->l_PEEP_label_secundary->startAlarm();

            if(capnography_active){
                ui->l_PEEP_terciary_capnography->setActiveColor(color_medium_priority);
                ui->l_PEEP_label_terciary_capnography->startAlarm();
                ui->l_PEEP_terciary_capnography->startAlarm();
                ui->l_sin_pulso_peep_terciary_capnography->startAlarm();
            }else{
                ui->l_PEEP_terciary->setActiveColor(color_medium_priority);
                ui->l_PEEP_label_terciary->startAlarm();
                ui->l_PEEP_terciary->startAlarm();
                ui->l_sin_pulso_peep_terciary->startAlarm();
            }
            ui->l_p_min->startAlarm();
            ui->l_pulso0->startAlarm();
            ui->l_sin_pulso->startAlarm();
            final_text.append(mapaAlarmas.value(peep_range)); final_color = color_medium_priority;
            lastActiveAlarm = peep_range;
        }
    }else{
        QString alarm_string = mapaAlarmas.value(peep_range);
        removeAlarm(alarm_string);

        ui->l_PEEP->stopAlarm();
        ui->l_PEEP_label->stopAlarm();
        ui->l_PEEP_secundary->stopAlarm();
        ui->l_PEEP_label_secundary->stopAlarm();
        if(capnography_active){
            ui->l_sin_pulso_peep_terciary_capnography->stopAlarm();
            ui->l_PEEP_terciary_capnography->stopAlarm();
            ui->l_PEEP_label_terciary_capnography->stopAlarm();
        }else{
            ui->l_sin_pulso_peep_terciary->stopAlarm();
            ui->l_PEEP_terciary->stopAlarm();
            ui->l_PEEP_label_terciary->stopAlarm();
        }

        ui->l_p_min->stopAlarm();
        ui->l_pulso0->stopAlarm();
        ui->l_sin_pulso->stopAlarm();



    }
    if(capnography_active){
        if((alarma & low_co2_level) == low_co2_level){
            QString name_alarm = "low_co2_level";
            if(!isActivedAlarm(name_alarm)){
                alarm_activated = true;

                ui->l_PCO2_value->setActiveColor(color_medium_priority);
                ui->l_etco2_configured_capnography->setActiveColor(color_medium_priority);
                ui->l_PCO2_label->startAlarm();
                ui->l_PCO2_value->startAlarm();
                ui->l_mmHg->startAlarm();
                ui->l_etco2_configured_capnography->startAlarm();

                final_text.append(mapaAlarmas.value(low_co2_level)); final_color = color_medium_priority;
                lastActiveAlarm = low_co2_level;
            }
        }else{
            QString alarm_string = mapaAlarmas.value(low_co2_level);
            removeAlarm(alarm_string);

            ui->l_PCO2_label->stopAlarm();
            ui->l_PCO2_value->stopAlarm();
            ui->l_mmHg->stopAlarm();
            ui->l_etco2_configured_capnography->stopAlarm();
        }
        if((alarma & co2_sensor_error) == co2_sensor_error){
            QString name_alarm = "co2_sensor_error";
            if(!isActivedAlarm(name_alarm)){
                alarm_activated = true;

                if((alarma & low_co2_level) != low_co2_level){
                    ui->l_PCO2_value->setActiveColor(color_medium_priority);
                    ui->l_etco2_configured_capnography->setActiveColor(color_medium_priority);
                    ui->l_PCO2_label->startAlarm();
                    ui->l_PCO2_value->startAlarm();
                    ui->l_mmHg->startAlarm();
                    ui->l_etco2_configured_capnography->startAlarm();
                }

                final_text.append(mapaAlarmas.value(co2_sensor_error)); final_color = color_medium_priority;
                lastActiveAlarm = co2_sensor_error;
            }
        }else{
            QString alarm_string = mapaAlarmas.value(co2_sensor_error);
            removeAlarm(alarm_string);

            if((alarma & low_co2_level) != low_co2_level){
                ui->l_PCO2_label->stopAlarm();
                ui->l_PCO2_value->stopAlarm();
                ui->l_mmHg->stopAlarm();
                ui->l_etco2_configured_capnography->stopAlarm();
            }
        }
        if((alarma & high_co2_level) == high_co2_level){
            QString name_alarm = "high_co2_level";
            if(!isActivedAlarm(name_alarm)){
                alarm_activated = true;

                if(((alarma & low_co2_level) != low_co2_level) && ((alarma & co2_sensor_error) != co2_sensor_error)){
                    ui->l_PCO2_value->setActiveColor(color_medium_priority);
                    ui->l_etco2_configured_capnography->setActiveColor(color_medium_priority);
                    ui->l_PCO2_label->startAlarm();
                    ui->l_PCO2_value->startAlarm();
                    ui->l_mmHg->startAlarm();
                    ui->l_etco2_configured_capnography->startAlarm();
                }

                final_text.append(mapaAlarmas.value(high_co2_level)); final_color = color_medium_priority;
                lastActiveAlarm = high_co2_level;
            }
        }else{
            QString alarm_string = mapaAlarmas.value(high_co2_level);
            removeAlarm(alarm_string);

            if(((alarma & low_co2_level) != low_co2_level) && ((alarma & co2_sensor_error) != co2_sensor_error)){
                ui->l_PCO2_label->stopAlarm();
                ui->l_PCO2_value->stopAlarm();
                ui->l_mmHg->stopAlarm();
                ui->l_etco2_configured_capnography->stopAlarm();
            }
        }
    }


    if((alarma & oxygen_sensor_error) == oxygen_sensor_error){
        QString name_alarm = "oxygen_sensor_error";
        if(!isActivedAlarm(name_alarm)){
            alarm_activated = true;
            if((alarma & high_oxigen_level) != high_oxigen_level){
                if(capnography_active){
                    ui->l_fio2_capnography->setActiveColor(color_medium_priority);
                    ui->l_fio2_configured_capnography->setActiveColor(color_medium_priority);
                    ui->l_fio2_capnography->startAlarm();
                    ui->l_fio2_configured_capnography->startAlarm();
                    ui->l_fio2_label_capnography->startAlarm();
                    ui->l_p_max_porcentage_terciary_capnography->startAlarm();
                }else{
                    ui->l_fio2->setActiveColor(color_medium_priority);
                    ui->l_fio2_configured->setActiveColor(color_medium_priority);
                    ui->l_fio2->startAlarm();
                    ui->l_fio2_configured->startAlarm();
                    ui->l_fio2_label->startAlarm();
                    ui->l_p_max_porcentage_terciary->startAlarm();
                }
            }
            final_text.append(mapaAlarmas.value(oxygen_sensor_error)); final_color = color_medium_priority;
            lastActiveAlarm = oxygen_sensor_error;
        }
    }else{
        QString alarm_string = mapaAlarmas.value(oxygen_sensor_error);
        removeAlarm(alarm_string);

        if((alarma & high_oxigen_level) != high_oxigen_level){
            if(capnography_active){
                ui->l_fio2_capnography->stopAlarm();
                ui->l_fio2_label_capnography->stopAlarm();
                ui->l_fio2_configured_capnography->stopAlarm();
                ui->l_p_max_porcentage_terciary_capnography->stopAlarm();
            }else{
                ui->l_fio2->stopAlarm();
                ui->l_fio2_label->stopAlarm();
                ui->l_fio2_configured->stopAlarm();
                ui->l_p_max_porcentage_terciary->stopAlarm();
            }
        }
    }
    if((alarma & apnea_detected) == apnea_detected){
        QString name_alarm = "apnea_detected";
        if(!isActivedAlarm(name_alarm)){
            alarm_activated = true;
            final_text.append(mapaAlarmas.value(apnea_detected)); final_color = color_medium_priority;
            lastActiveAlarm = apnea_detected;
        }
    }else{
        QString alarm_string = mapaAlarmas.value(apnea_detected);
        removeAlarm(alarm_string);
    }
    if((alarma & low_battery) == low_battery){    //////Alarmas Alta prioridad--------------------------------------------------------------------------------------------
        QString name_alarm = "low_battery";
        if(!isActivedAlarm(name_alarm)){
            alarm_activated = true;
            final_text.append(mapaAlarmas.value(low_battery)); final_color = color_high_priority; final_text_active_color = QColor(Qt::white);
            lastActiveAlarm = low_battery;
        }
    }else{
        QString alarm_string = mapaAlarmas.value(low_battery);
        removeAlarm(alarm_string);
    }
    if((alarma & over_presure) == over_presure){
        QString name_alarm = "over_presure";
        if(!isActivedAlarm(name_alarm)){
            alarm_activated = true;

            ui->l_PIP->startAlarm();
            ui->l_PIP_label->startAlarm();
            ui->l_PIP_secundary->startAlarm();
            ui->l_PIP_label_secundary->startAlarm();
            if(capnography_active){
                ui->l_PIP_label_terciary_capnography->startAlarm();
                ui->l_PIP_terciary_capnography->startAlarm();
            }else {
                ui->l_PIP_label_terciary->startAlarm();
                ui->l_PIP_terciary->startAlarm();
            }


            final_text.append(mapaAlarmas.value(over_presure)); final_color = color_high_priority; final_text_active_color = QColor(Qt::white);
            lastActiveAlarm = over_presure;
        }
    }
    else{
        QString alarm_string = mapaAlarmas.value(over_presure);
        removeAlarm(alarm_string);
        ui->l_PIP->stopAlarm();
        ui->l_PIP_label->stopAlarm();
        ui->l_PIP_secundary->stopAlarm();
        ui->l_PIP_label_secundary->stopAlarm();
        if(capnography_active){
            ui->l_PIP_label_terciary_capnography->stopAlarm();
            ui->l_PIP_terciary_capnography->stopAlarm();
        }else {
            ui->l_PIP_label_terciary->stopAlarm();
            ui->l_PIP_terciary->stopAlarm();
        }

    }
    if((alarma & low_presure) == low_presure){
        QString name_alarm = "low_presure";
        if(!isActivedAlarm(name_alarm)){
            alarm_activated = true;
            final_text.append(mapaAlarmas.value(low_presure)); final_color = color_high_priority; final_text_active_color = QColor(Qt::white);
            lastActiveAlarm = low_presure;
        }
    }else{
        QString alarm_string = mapaAlarmas.value(low_presure);
        removeAlarm(alarm_string);
    }
    if((alarma & presure_leak) == presure_leak){
        QString name_alarm = "presure_leak";
        if(!isActivedAlarm(name_alarm)){
            alarm_activated = true;
            final_text.append(mapaAlarmas.value(presure_leak)); final_color = color_high_priority; final_text_active_color = QColor(Qt::white);
            lastActiveAlarm = presure_leak;
        }
    }
    else{
        QString alarm_string = mapaAlarmas.value(presure_leak);
        removeAlarm(alarm_string); //En las de alta prioridad no remuevo alarma
    }

    if(static_cast<int>(previous_alarm_state) != static_cast<int>(a)){ //si el estado de la alrma es igual anterior no hago nada
        if(!alarm_activated){ //Activacion local de alarmas desactivada
            setAlarmText(QStringList(), false);
            qDebug()<<"Bocina desactivada********************************";
            EstadoBocinas = 0;  //Si no hay alarmas apago bocinas
        }
        else{//Activacion local de alarmas activada
            if(getPriorityOfAlarm(static_cast<int>(lastActiveAlarm)) == high_priority){
                high_priority_activation = true;
                qDebug()<<"Activar escoba********************************";
            }
            setAlarmText(final_text, true, final_color, final_text_active_color);

            if(alarmActivated){//variable de Habilitacion de bocinas de alarma
                EstadoBocinas = lastActiveAlarm;
                qDebug()<<"Bocina activada";
            }else{
                if(  ( getPriorityOfAlarm(static_cast<int>(lastActiveAlarm)) <= lastPriorityActiveAlarm )
                     && ( getPriorityOfAlarm(static_cast<int>(lastActiveAlarm)) != high_priority )  ){
                    qDebug()<<"Bocina desactivada********************************";
                    EstadoBocinas = 0;
                }
                else{
                    if(static_cast<int>(previous_alarm) != static_cast<int>(lastActiveAlarm)){
                        enableAlarm();
                        EstadoBocinas = lastActiveAlarm;
                    }
                }
            }
        }
    }
    lastPriorityActiveAlarm = getPriorityOfAlarm(static_cast<int>(lastActiveAlarm));
    previous_alarm_state = a;

    return alarm_activated;
}

int MainWindow::getPriorityOfAlarm(int alarm_code){
    if(alarm_code <= low_battery){//ultima de alta prioridad
        return high_priority;
    }else if (alarm_code <= low_co2_level) { //ultima de media prioridad
        return medium_priority;
    }else{
        return low_priority;
    }
}

bool MainWindow::deleteAlarmLabel(QString name_label){//devuelve falso si no encontro el label a borrar
    int c= ui->widget_graph->children().size();
    for (int i=0; i < c; i++) {
        QString name = ui->widget_graph->
                children().at(i)->objectName();
        if(name.contains(name_label)){

            static_cast<QCheckBox*>((ui->widget_graph->
                                     children().at(i)))->deleteLater();
            return true;
        }
    }
    return false;
}

void MainWindow::addAlarmLabel(QString objectName, QString toolTip, QString icon){
    QLabel *l_alarma_x = new QLabel(ui->widget_alarms);
    l_alarma_x->setObjectName("l_" + objectName);
    l_alarma_x->setToolTip(toolTip);
    l_alarma_x->setScaledContents(true);
    l_alarma_x->setFixedSize(40, 40);
    l_alarma_x->setPixmap(QPixmap(icon));
    ui->widget_alarms->layout()->addWidget(l_alarma_x);
}

void MainWindow::afterMinutesAlarmCheck(){
    ui->l_alarma->setChecked(false);
    enableAlarm();
    previous_alarm_state = none_alarm;
}
void MainWindow::enableAlarm(){
    silence_activated = false;
    EstadoBocinas = 0;
    alarmActivated = true;
    disconnect(&timer_alarm, SIGNAL(timeout()), this, SLOT(afterMinutesAlarmCheck()));
    timer_alarm.stop();
}
void MainWindow::disableAlarmButton(){
    ui->l_alarma->setChecked(false);
    ui->l_alarma->set_Enabled(false);
    label_alarm_blinking = false;
}
void MainWindow::onTimeOutAlarm()
{
    ui->l_alarma->startAnimation(false, 10, 80);
}
bool MainWindow::clearAlarmsNotifications(){
    if(ui->l_alarma->isFourthState()){
        high_priority_activation = false;
        ui->widget_alarms->cleanHighPriorityAlarms();
        ui->l_alarma->setChecked(false);
        setAlarmText(QStringList(), false);
        ui->l_alarm_icon->hide();
        return true;
    }
    return false;
}
void MainWindow::on_close_Alarm(){

    //    turnOffBuzzer();
    if(clearAlarmsNotifications()){ //Si estaba en cuarto estado no hago mas nada, solo limpio notificaciones
        return;
    }
    label_alarm_blinking = false;
    EstadoBocinas = 0;
    alarmActivated = false;
    silence_activated = true;

    timer_alarm.stop();
    disconnect(&timer_alarm, SIGNAL(timeout()), this, SLOT(onTimeOutAlarm()));

    connect(&timer_alarm, SIGNAL(timeout()), this, SLOT(afterMinutesAlarmCheck()));
    timer_alarm.setInterval(120000); //2minutos  120000
    timer_alarm.start();

    ui->l_alarma->setThirdState(false);
}
void MainWindow::showAlarm(){ //////////**********************************************************
    if(alarmActivated){
        if(!ui->l_alarma->isChecked() && !label_alarm_blinking){
            label_alarm_blinking = true;
            ui->l_alarma->setChecked(true);
            ui->l_alarma->set_Enabled(true);
        }
    }
}

void MainWindow::closeMessageAlarm(){
    mensajeAlarma->close();
    hideMenu();
}

void MainWindow::showAlarm(QString title, QString description){

    if(alarmActivated){
        EstadoBocinas = 0xFFFF;
    }

    if(!label_alarm_blinking){
        label_alarm_blinking = true;
        timer_alarm.stop();
        timer_alarm.setInterval(2000);
        ui->l_alarma->set_Enabled(true);
        ui->l_alarma->setChecked(true);
        connect(&timer_alarm, SIGNAL(timeout()), this, SLOT(onTimeOutAlarm()));
        timer_alarm.start();
    }

    if(mensajeAlarma == nullptr){
        mensajeAlarma = new MessageDialog(this);
        connect(mensajeAlarma, &MessageDialog::checkedAlarm, this, &MainWindow::closeMessageAlarm);
    }
    if(mensajeAlarma != nullptr){
        mensajeAlarma->setAlarmAndDescription(title, description);
        mensajeAlarma->showCenter();
    }
}

void MainWindow::showMessageAlarm(float alarm){
    if(mensajeAlarma == nullptr){
        mensajeAlarma = new MessageDialog(this);
        connect(mensajeAlarma, &MessageDialog::checkedAlarm, this, &MainWindow::closeMessageAlarm);
    }
    if(mensajeAlarma != nullptr){
        if(mensajeAlarma->decodeAlarm(alarm)){
            showMenu();
        }
    }
}
//---------------------------------------------------------------------------------------------------------------------------


//Funcion de boton de estado inicial de app-----------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------
void MainWindow::inicialState()
{
    resetGPIO();

    if(QApplication::desktop()->width() < 1366){
        setWindowFlags(Qt::CustomizeWindowHint);
        this->setCursor(Qt::BlankCursor);
    }
    qDebug()<<"Ancho de screen "+QString::number(QApplication::desktop()->width());
    this->move(-1,-1);

    ui->l_clock_error->hide();

    ui->l_alarma->set_Enabled(false); //si no se ha conectado deshabilito el boton
    ui->l_alarm_icon->hide();

    setupGraph();

    iniciateFiles(); //crea el archivo si no existe

    loadLastConfiguration();

    if(static_cast<int>(ModoVentilacion) == 1){
        ui->l_modo->setTextString("VCV"); // asistido y VCV
    }
    else if(static_cast<int>(ModoVentilacion) == 2){
        ui->l_modo->setTextString("VAC"); // asistido y VCV
    }
    ui->l_modo->setTextColor(color_modo);

    ui->l_p_max_configured->setText(QString::number(static_cast<int>(Pmax)));
    ui->l_p_min->setText(QString::number(static_cast<int>(Pmin)));

    ui->l_volumen->setTextString(QString::number(static_cast<int>(VolumenTidal)));
    ui->l_volumen->setDefautTextString(QString::number(static_cast<int>(VolumenTidal)));
    ui->l_volumen->setActiveTextColor(color_active_alarm, color_Vt);
    ui->l_volumen->setTextColor(color_Vt);
    ui->l_bpm->setTextString(QString::number(static_cast<int>(BPM))); //max 30
    ui->l_bpm->setDefautTextString(QString::number(static_cast<int>(BPM)));
    ui->l_bpm->setActiveTextColor(color_active_alarm, color_Fr);
    ui->l_bpm->setTextColor(color_Fr);
    ui->l_ie->setTextString(QString::number(static_cast<double>(Ti), 'f', 1));
    ui->l_ie->setTextColor(color_IE);
    ui->l_fio2_configured->setText(QString::number(static_cast<double>(alarma_fio2), 'f', 0));
    ui->l_fio2_configured_capnography->setText(QString::number(static_cast<double>(alarma_fio2), 'f', 0));
    ui->l_etco2_configured_capnography->setText(QString::number(static_cast<double>(alarma_etco2), 'f', 0));
    ui->l_max_vol->setText(QString::number(static_cast<double>(MAX_VOLUMEN), 'f', 0) + "ml");
    //   ui->l_p_max->setTextString(QString::number(static_cast<int>(Pmax)));
    adjust_p_max(static_cast<int>(Pmax));
    adjust_peep(static_cast<int>(0));
    adjust_pinst(static_cast<int>(0));
    adjustRangeToBPM(CICLOS_EN_GRAFICA);
    rescaleYAxis(static_cast<int>(Pmax), true);

    openSerialPort();

    hideMenu();

    ui->widget_data_secundary->hide();
    ui->widget_data_terciary->hide();
    ui->widget_data_terciary_capnography->hide();

    //conectar señales de mouse de grafica a esta
    connect(ui->l_bpm, &MyLabelStateTextAlarmAnimated::pressEvent, this , &MainWindow::mousePressEvent);
    connect(ui->l_ie, &MyLabelStateTextAnimated::pressEvent, this , &MainWindow::mousePressEvent);
    connect(ui->widget_alarms, &MyWidgetAlarmAnimated::pressEvent, this , &MainWindow::mousePressEvent);
    connect(customPlot, &Plot::pressEvent, this , &MainWindow::mousePressEvent);
    connect(customPlot, &Plot::releaseEvent, this , &MainWindow::mouseReleaseEvent);

    chequearConfiguracionMaxVolumen();
    chequearConfiguracionCapnografia();
}
void MainWindow::chequearConfiguracionMaxVolumen(){
    int max_vol = checkifMaxVolumenActive();
    if(max_vol == MARK_4){
        MAX_VOLUMEN = MARK_4;
    }else if(max_vol == AMBU_SILICONA){
        MAX_VOLUMEN = AMBU_SILICONA;
    }
}

int MainWindow::checkifMaxVolumenActive(){
    QFile file("maxVolumen.dat");
    if(file.exists()){
        if(file.open(QIODevice::ReadOnly))
        {
            QDataStream in(&file);
            int max_vol;
            in >> max_vol;

            file.close();
            return max_vol;
        }
    }
    return MARK_4;
}
void MainWindow::salvarConfiguraciondeCapnografia(int max_vol){

    QFile file("maxVolumen.dat");
    if(file.open(QIODevice::WriteOnly))
    {
        QDataStream out(&file);
        out << max_vol;
        file.close();
    }
}
void MainWindow::chequearConfiguracionCapnografia(){
    capnography_active = checkifCapnographyActive();
}

bool MainWindow::checkifCapnographyActive(){
    QFile file("capnographyConfig.dat");
    if(file.exists()){
        return true;
    }
    return false;
}
void MainWindow::salvarConfiguraciondeCapnografia(bool activa){
    if(activa){
        QFile file("capnographyConfig.dat");
        if(file.open(QIODevice::WriteOnly))
        {

        }
    }else{
        QFile file("capnographyConfig.dat");
        if(file.exists()){
            file.remove();
        }
    }
}
void MainWindow::conexion_encontrada(QStringList puertos){
    if(puertos.isEmpty()){
        conexion_pc = false;
        //        this->setCursor(Qt::BlankCursor);
    }else{
        conexion_pc = true;
        ui->statusBar->showMessage("Dispositivo conectado a PC encontrado", 6000);
    }
    ui->l_power->set_Enabled(true);
}
void MainWindow::comunicacionCaida(){
    //    serialPort->close();
    serialPort->resetVariables();
    //    delete serialPort;
    started_ventilation = false;
    //    serialPort = nullptr;
    ui->l_power->setChecked(false);
    ui->l_ventilation_state->hide();
    ui->widget_data->hide();
    ui->statusBar->showMessage("Se ha caido la comunicacion, se ha cerrado el puerto", 6000);
    showAlarm("Error fatal", "Contacte con asistencia técnica");
    qDebug()<<"Se ha caido la comunicacion, se ha cerrado el puerto*************************";

    soundBuzzer();//Hacer esto una sola vez
    turnOffMotor();
}
//---------------------------------------------------------------------------------------------------------------------------


//Funciones de salva y carga de configuracion--------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------
bool MainWindow::loadLastConfiguration(){//Carga el archivo de configuracion
    jsonObjectConfiguracion = readSavedConfig(0); //leer la primera guardada
    if(jsonObjectConfiguracion.isEmpty()){
        return false;
    }else{
        Pmax = jsonObjectConfiguracion.value(Pmax_key).toString().toFloat();
        Relacion_IE = jsonObjectConfiguracion.value(Relacion_IE_key).toString().toFloat();
        BPM = jsonObjectConfiguracion.value(BPM_key).toString().toFloat();
        VolumenTidal = jsonObjectConfiguracion.value(VolumenTidal_key).toString().toFloat();
        ModoVentilacion = jsonObjectConfiguracion.value(ModoVentilacion_key).toString().toFloat();
        EstadoAlarmas = jsonObjectConfiguracion.value(EstadoAlarmas_key).toString().toFloat();
        EstadoAlarmas = 0;
        EstadoBocinas = jsonObjectConfiguracion.value(EstadoBocinas_key).toString().toFloat();
        EstadoBocinas = 0;
        Pmin = jsonObjectConfiguracion.value(Pmin_key).toString().toFloat();
        trigger_asistido = jsonObjectConfiguracion.value(trigger_asistido_key).toString().toFloat();
        t_plateau = jsonObjectConfiguracion.value(t_plateau_key).toString().toFloat();
        Ti = jsonObjectConfiguracion.value(Ti_key).toString().toFloat();
        alarma_fio2 = jsonObjectConfiguracion.value(FiO2_key).toString().toFloat();
        alarma_etco2 = jsonObjectConfiguracion.value(ETCO2_key).toString().toFloat();
        date_time = jsonObjectConfiguracion.value(date_time_key).toString();
        lastSavedDateTime = QDateTime::fromString(date_time, "dd-MM-yyyy hh:mm:ss");
        lastVentState = jsonObjectConfiguracion.value(ventilationState_key).toBool();
        capnography_active = jsonObjectConfiguracion.value(capnographyState_key).toBool();
        MAX_VOLUMEN = jsonObjectConfiguracion.value(MAX_VOLUMEN_key).toString().toFloat();
        return true;
    }
}
void MainWindow::writeInitialConfigurationLog(){
    QString evento = "Configuracion Inicial Pmax -> " + QString::number(static_cast<double>(Pmax), 'f', 0);
    write_LOG(evento);
    evento = "Configuracion Inicial Relacion IE -> " + QString::number(static_cast<double>(Relacion_IE), 'f', 0);
    write_LOG(evento);
    evento = "Configuracion Inicial BPM -> " + QString::number(static_cast<double>(BPM), 'f', 0);
    write_LOG(evento);
    evento = "Configuracion Inicial Volumen Tidal -> " + QString::number(static_cast<double>(VolumenTidal), 'f', 0);
    write_LOG(evento);
    QString value_modo="";
    if(static_cast<int>(ModoVentilacion) == 1){
        value_modo = "VCV";
    }else if(static_cast<int>(ModoVentilacion) == 2){
        value_modo = "VAC";
    }
    evento = "Configuracion Inicial Modo Ventilacion -> " + value_modo;
    write_LOG(evento);
    evento = "Configuracion Inicial T plateau -> " + QString::number(static_cast<double>(t_plateau), 'f', 0);
    write_LOG(evento);
    evento = "Configuracion Inicial PEEP -> " + QString::number(static_cast<double>(Pmin), 'f', 0);
    write_LOG(evento);
    evento = "Configuracion Inicial Trigger asistido -> " + QString::number(static_cast<double>(trigger_asistido), 'f', 0);
    write_LOG(evento);
    evento = "Configuracion Inicial Ti -> " + QString::number(static_cast<double>(Ti), 'f', 0);
    write_LOG(evento);
    evento = "Configuracion Inicial FiO2 -> " + QString::number(static_cast<double>(alarma_fio2), 'f', 0);
    write_LOG(evento);
    evento = "Configuracion Inicial BPM -> " + QString::number(static_cast<double>(BPM), 'f', 0);
    write_LOG(evento);

    evento = "Configuracion Capnografia -> " + ((capnography_active)?QString("Activada"):QString("Desactivada"));
    write_LOG(evento);
    if(capnography_active){
        evento = "Configuracion Inicial ETCO2 -> " + QString::number(static_cast<double>(alarma_etco2), 'f', 0);
        write_LOG(evento);
    }
    evento = "Configuracion Max Volumen -> " + QString::number(static_cast<double>(MAX_VOLUMEN), 'f', 0);
    write_LOG(evento);
}

bool MainWindow::saveLastConfiguration(){//Salva en archivo de configuracion
    jsonObjectConfiguracion.insert(Pmax_key, QString::number(static_cast<double>(Pmax), 'f', 2));
    jsonObjectConfiguracion.insert(Relacion_IE_key, QString::number(static_cast<double>(Relacion_IE), 'f', 2));
    jsonObjectConfiguracion.insert(BPM_key, QString::number(static_cast<double>(  BPM ), 'f', 2));
    jsonObjectConfiguracion.insert(VolumenTidal_key, QString::number(static_cast<double>(  VolumenTidal ), 'f', 2));
    jsonObjectConfiguracion.insert(ModoVentilacion_key, QString::number(static_cast<double>(  ModoVentilacion ), 'f', 2));
    jsonObjectConfiguracion.insert(Pmin_key, QString::number(static_cast<double>(  Pmin ), 'f', 2));
    jsonObjectConfiguracion.insert(EstadoAlarmas_key, QString::number(static_cast<double>( EstadoAlarmas  ), 'f', 2));
    jsonObjectConfiguracion.insert(EstadoBocinas_key, QString::number(static_cast<double>( EstadoBocinas  ), 'f', 2));
    jsonObjectConfiguracion.insert(Pmin_key, QString::number(static_cast<double>( Pmin  ), 'f', 2));
    jsonObjectConfiguracion.insert(trigger_asistido_key, QString::number(static_cast<double>( trigger_asistido  ), 'f', 2));
    jsonObjectConfiguracion.insert(t_plateau_key, QString::number(static_cast<double>( t_plateau ), 'f', 2));
    jsonObjectConfiguracion.insert(Ti_key, QString::number(static_cast<double>( Ti ), 'f', 2));
    jsonObjectConfiguracion.insert(FiO2_key, QString::number(static_cast<double>( alarma_fio2 ), 'f', 2));
    jsonObjectConfiguracion.insert(ETCO2_key, QString::number(static_cast<double>( alarma_etco2 ), 'f', 2));
    jsonObjectConfiguracion.insert(ventilationState_key, started_ventilation);
    jsonObjectConfiguracion.insert(capnographyState_key, capnography_active);
    jsonObjectConfiguracion.insert(MAX_VOLUMEN_key, QString::number(static_cast<double>( MAX_VOLUMEN ), 'f', 2));
    jsonObjectConfiguracion.insert(date_time_key, QDateTime::currentDateTime().toString("dd-MM-yyyy hh:mm:ss"));

    return writeSavedConfig(jsonObjectConfiguracion);
}

void MainWindow::iniciateFiles(){//Crea el archivo para salvar
    QFile file(saved_configuration); // ficheros .dat se puede utilizar formato txt tambien
    if(!file.exists()){
        if(file.open(QIODevice::WriteOnly)){
            QDataStream out(&file);
            file.close();
        }
    }
    file.setFileName(function_data_file); // ficheros .dat se puede utilizar formato txt tambien
    if(!file.exists()){
        if(file.open(QIODevice::WriteOnly)){
            QDataStream out(&file);
            file.close();
        }
    }
}

bool MainWindow::writeSavedConfig(QJsonArray jsonArray){//Escribe un JsonArray en el Archivo
    QJsonDocument d;
    d.setArray(jsonArray);
    QFile *data_base = new QFile(saved_configuration); // ficheros .dat se puede utilizar formato txt tambien
    if(data_base->exists()) {
        if(data_base->open(QIODevice::WriteOnly))
        {
            data_base->seek(0);
            QDataStream out(data_base);
            out<<d.toJson();
            data_base->close();
            return true;
        }
    }
    return false;
}
bool MainWindow::writeSavedConfig(QJsonObject jsonObject){ //Solo guarda una borra todas las anteriores guardadas
    QJsonArray jsonArray;
    jsonArray.append(jsonObject);
    return writeSavedConfig(jsonArray);
}

QJsonArray MainWindow::readSavedConfig(){//Lee un QJsonArray del Archivo
    QJsonDocument d;
    QByteArray bytes;
    QJsonArray jsonArray;
    QFile *data_base = new QFile(saved_configuration); // ficheros .dat se puede utilizar formato txt tambien
    if(data_base->exists()) {
        if(data_base->open(QIODevice::ReadOnly))
        {
            QDataStream in(data_base);
            in>>bytes;
            data_base->close();

            d = QJsonDocument::fromJson(bytes);
            jsonArray = d.array();
        }
    }
    return jsonArray;
}
QJsonObject MainWindow::readSavedConfig(int index){//Lee un JsonObject del Archivo
    QJsonArray jsonArray = readSavedConfig();
    if(index < jsonArray.size()){
        return jsonArray.at(index).toObject();
    }else{
        return QJsonObject();
    }
}
//---------------------------------------------------------------------------------------------------------------------------
void MainWindow::setCapnographyActive(bool active){
    capnography_active = active;
    saveLastConfiguration();
}
bool MainWindow::getCapnographyActive(){
    return capnography_active;
}
float MainWindow::getPressureBeforeFluke(){
    return Pmax;
}
void MainWindow::setPressureFromFluke(float pressure){
    Pmax = pressure;
}
float MainWindow::getVolumenBeforeFluke(){
    return VolumenTidal;
}
void MainWindow::setVolumenFromFluke(float vol){
    VolumenTidal = vol;
}
float MainWindow::getMaxVolumen(){
    return VolumenTidal;
}
float MainWindow::getCopyingState(){
    return copyingState;
}
void MainWindow::setCopyingState(float copyState){
    copyingState = copyState;
}
void MainWindow::setMaxVolumen(float max_vol){
    MAX_VOLUMEN = max_vol;
    ui->l_max_vol->setText(QString::number(static_cast<double>(MAX_VOLUMEN), 'f', 0) + "ml");
}
//Funcion de envio de datos--------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------
QByteArray MainWindow::sendData(float state){

    if(serialPort != nullptr){
        if(!serialPort->isOpen()){
            return "";
        }
    }else{
        return "";
    }
    if(static_cast<int>(state) == SerialPort::CALIBRACION_MOTOR
            || static_cast<int>(state) == SerialPort::CALIBRACION_PRESION){
        currentState = SerialPort::STANDBY;
    }
    float set_date_time = 0;
    if(clock_state != SerialPort::OMIT){
        set_date_time = clock_state;
        clock_state = SerialPort::OMIT;
    }
    float d, M, y, h, m, s;
    d = datetime.date().day();
    M = datetime.date().month();
    y = datetime.date().year();
    
    h = datetime.time().hour();
    m = datetime.time().minute();
    s = datetime.time().second();
    

    //    qDebug()<<"Estado: -> " + QString::number(static_cast<int>(state));
    saveLastConfiguration();

    QByteArray buffer;

    ////    12 palabras de 32bits incluyendo CRC (1 word Header + 10 words info + 1 word CRC)
    for (int i=0; i<4 ;++i){
        buffer.append(static_cast<char>(HEADER_ID));////word 1 - Header 0xAAAAAAAA
    }

    buffer.append(IEEE_754_class::changeEndianess(IEEE_754_class::convert_Uint32To_Bytes(  ////word 2 - Estados: Standby (1), Calibración de presión (2), Calibración del motor (3), Ventilación (4), Apagado (5), ErrorCmd(0)
                                                                                           IEEE_754_class::convertirA_754_32(state))));

    buffer.append(IEEE_754_class::changeEndianess(IEEE_754_class::convert_Uint32To_Bytes(  ////word 3 - Volumen Tidal Vt.
                                                                                           IEEE_754_class::convertirA_754_32(VolumenTidal))));

    buffer.append(IEEE_754_class::changeEndianess(IEEE_754_class::convert_Uint32To_Bytes(////word 4 - Respiraciones por minuto BPM.
                                                                                         IEEE_754_class::convertirA_754_32(BPM))));

    buffer.append(IEEE_754_class::changeEndianess(IEEE_754_class::convert_Uint32To_Bytes(////word 5 - Relación Inspiración/Expiración IE.
                                                                                         IEEE_754_class::convertirA_754_32(Relacion_IE))));

    buffer.append(IEEE_754_class::changeEndianess(IEEE_754_class::convert_Uint32To_Bytes(////word 6 - copyingState if copying or not files //copying blocks UI
                                                                                         IEEE_754_class::convertirA_754_32(copyingState))));

    buffer.append(IEEE_754_class::changeEndianess(IEEE_754_class::convert_Uint32To_Bytes(////word 7 - Presión máxima permitida Pmax
                                                                                         IEEE_754_class::convertirA_754_32(Pmax))));

    buffer.append(IEEE_754_class::changeEndianess(IEEE_754_class::convert_Uint32To_Bytes(////word 8 - Presión mínima permitida PEEP
                                                                                         IEEE_754_class::convertirA_754_32(Pmin))));

    buffer.append(IEEE_754_class::changeEndianess(IEEE_754_class::convert_Uint32To_Bytes(////word 9 - Modo de ventilación (controlado o asistido) Mode.
                                                                                         IEEE_754_class::convertirA_754_32(ModoVentilacion))));

    buffer.append(IEEE_754_class::changeEndianess(IEEE_754_class::convert_Uint32To_Bytes(////word 10 - Estado de las alarmas Alarm
                                                                                         IEEE_754_class::convertirA_754_32(0))));

    buffer.append(IEEE_754_class::changeEndianess(IEEE_754_class::convert_Uint32To_Bytes(////word 11 - Estado de la bocina (On /Off) Buzzer
                                                                                         IEEE_754_class::convertirA_754_32(EstadoBocinas))));

    buffer.append(IEEE_754_class::changeEndianess(IEEE_754_class::convert_Uint32To_Bytes(////word 12 - Estado reloj - (0 omitir) - (1 setear desde RASPI) - (2 pedir hora a Arduino)
                                                                                         IEEE_754_class::convertirA_754_32(set_date_time))));
    
    buffer.append(IEEE_754_class::changeEndianess(IEEE_754_class::convert_Uint32To_Bytes(////word 13 - Estado reloj segundos
                                                                                         IEEE_754_class::convertirA_754_32(s))));
    buffer.append(IEEE_754_class::changeEndianess(IEEE_754_class::convert_Uint32To_Bytes(////word 14 - Estado reloj minutos
                                                                                         IEEE_754_class::convertirA_754_32(m))));
    buffer.append(IEEE_754_class::changeEndianess(IEEE_754_class::convert_Uint32To_Bytes(////word 15 - Estado reloj horas
                                                                                         IEEE_754_class::convertirA_754_32(h))));
    buffer.append(IEEE_754_class::changeEndianess(IEEE_754_class::convert_Uint32To_Bytes(////word 16 - Estado reloj dia
                                                                                         IEEE_754_class::convertirA_754_32(d))));
    buffer.append(IEEE_754_class::changeEndianess(IEEE_754_class::convert_Uint32To_Bytes(////word 17 - Estado reloj mes
                                                                                         IEEE_754_class::convertirA_754_32(M))));
    buffer.append(IEEE_754_class::changeEndianess(IEEE_754_class::convert_Uint32To_Bytes(////word 18 - Estado reloj año
                                                                                         IEEE_754_class::convertirA_754_32(y))));
    
    buffer.append(IEEE_754_class::changeEndianess(IEEE_754_class::convert_Uint32To_Bytes(////word 19 - Trigger de asistido
                                                                                         IEEE_754_class::convertirA_754_32(trigger_asistido))));
    buffer.append(IEEE_754_class::changeEndianess(IEEE_754_class::convert_Uint32To_Bytes(////word 20 - Tiempo de Plateau
                                                                                         IEEE_754_class::convertirA_754_32(t_plateau))));

    buffer.append(IEEE_754_class::changeEndianess(IEEE_754_class::convert_Uint32To_Bytes(////word 21 - Alarm FIO2
                                                                                         IEEE_754_class::convertirA_754_32(alarma_fio2))));
    buffer.append(IEEE_754_class::changeEndianess(IEEE_754_class::convert_Uint32To_Bytes(////word 21 - Alarm CO2
                                                                                         IEEE_754_class::convertirA_754_32(alarma_etco2))));


    unsigned int size = static_cast<unsigned int>(buffer.size());
    uint8_t *buff_int = new uint8_t[size];
    IEEE_754_class::convertByteArrayToUintArray(buffer, buff_int);

    uint32_t crcValue = CheckSerialMessage::crc32(buff_int, size);
    uint8_t buf_8b[4];
    IEEE_754_class::convertUint32ToUintArray(crcValue, buf_8b);

    buffer.append(IEEE_754_class::changeEndianess(
                      IEEE_754_class::convertUintArrayToByteArray(buf_8b, 4)));

    serialPort->write_Data(buffer);

    lastSendedData = buffer;

    write_TCP_Data();

    return buffer;
}
//---------------------------------------------------------------------------------------------------------------------------


//Funcion de lectura de puerto serie-----------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------
void MainWindow::readSerialPort(const QByteArray &data)
{
    //Decodificar informacion recibida por serie-------------------------------------------------
    dataReceived = data;

    if(first_received){
        first_received=false;
    }
    if(decodificarInformacion(data)){
        QTimer::singleShot(100, this, SLOT(sendDataWithDelay()));
    }
}
void MainWindow::readSerialPortStandby(const QByteArray &dataReceived){
    if(dataReceived.size() >= UART_READ_TOTAL_SIZE){
        parseInformation(dataReceived);

        QTimer::singleShot(100, this, SLOT(sendDataWithDelay()));
    }
}
void MainWindow::sendDataWithDelay(){
    QByteArray bytesSended = sendData(currentState);//Enviar datos
}
//---------------------------------------------------------------------------------------------------------------------------


//Funcion de decodificacion de datos-----------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------
bool MainWindow::decodificarInformacion(const QByteArray &dataReceived)
{
    if(dataReceived.size() >= UART_READ_TOTAL_SIZE){
        parseInformation(dataReceived);

        fillSecundaryData();

        QByteArray temp;

        double functionData[UART_READ_DATA_FUNCTION_SIZE], functionData_s2[UART_READ_DATA_FUNCTION_SIZE] /*Sensor de presion 2*/,
                *functionData_filtered, data_i;
        for(int i=0; i < (UART_READ_DATA_FUNCTION_SIZE * 2); i++){
            temp = dataReceived.mid(BUFFER_DATA_POS + i*WORD_SIZE_BYTES, WORD_SIZE_BYTES);
            data_i = static_cast<double>(IEEE_754_class::convertirDesde_754_32(IEEE_754_class::convert_Bytes_To_Uint32(IEEE_754_class::changeEndianess(temp))));
            if(i < UART_READ_DATA_FUNCTION_SIZE){
                functionData[i]= data_i;
            }else{
                functionData_s2[i-UART_READ_DATA_FUNCTION_SIZE]= data_i;
            }
        }

        //Filtro activado---------------------------------------------------------------------------------------------------------------------------------------------------
        //                functionData_filtered = filtro.filter(functionData); ///Filtro activado
        //                graficarDatos(functionData_filtered);///Filtro activado
        //        memcpy(&data_to_write_in_file[pos_in_buffer_to_write_in_file], functionData_filtered, sizeof (double) * UART_READ_DATA_FUNCTION_SIZE);///Filtro activado
        //        memcpy(&data_to_write_in_file[pos_in_buffer_to_write_in_file + UART_READ_DATA_FUNCTION_SIZE],
        //                functionData_s2, sizeof (double) * UART_READ_DATA_FUNCTION_SIZE);///Sin filtro
        //End Filtro activado---------------------------------------------------------------------------------------------------------------------------------------------------


        //Sin filtro---------------------------------------------------------------------------------------------------------------------------------------------------
        Q_UNUSED(functionData_filtered);
        //        graficarDatosFiltrados(functionData_s2); //para mostrar segundo grafica, sensor 2
        graficarDatos(functionData);///Sin filtro
        memcpy(&data_to_write_in_file[pos_in_buffer_to_write_in_file], functionData, sizeof (double) * UART_READ_DATA_FUNCTION_SIZE);///Sin filtro
        memcpy(&data_to_write_in_file[pos_in_buffer_to_write_in_file + UART_READ_DATA_FUNCTION_SIZE],
                functionData_s2, sizeof (double) * UART_READ_DATA_FUNCTION_SIZE);///Sin filtro
        //End Sin filtro---------------------------------------------------------------------------------------------------------------------------------------------------

        ///Guardando datos de funcion en archivo---------------------------------------------------------------------------------------------------------
        ///------------------------------------------------------------------------------------------------------------------------------------------------
        pos_in_buffer_to_write_in_file += UART_READ_DATA_FUNCTION_SIZE*2;
        if(pos_in_buffer_to_write_in_file >= UART_READ_DATA_FUNCTION_SIZE*2*HOLDING_BUFFERS_TO_WRITE_IN_FILE){
            pos_in_buffer_to_write_in_file = 0;
            paciente.write_file_function_data(data_to_write_in_file, UART_READ_DATA_FUNCTION_SIZE*2*HOLDING_BUFFERS_TO_WRITE_IN_FILE);
        }
        ///End Guardando datos de funcion en archivo------------------------------------------------------------------------------------------------------------
        return true;
    }
    return false;
}

void MainWindow::testGraphFunction(){
    double buffer[DATA_TO_ADD_EACH_INTERVAL];

    for(int i= bufferPos, c=0; i < bufferPos + DATA_TO_ADD_EACH_INTERVAL; i++){
        buffer[c] = data_to_write_in_file[i];
        c++;
    }
    bufferPos+=DATA_TO_ADD_EACH_INTERVAL;

    if(bufferPos >= UART_READ_DATA_FUNCTION_SIZE*HOLDING_BUFFERS_TO_WRITE_IN_FILE){
        bufferPos = 0;
    }

    graficarDatos(buffer, DATA_TO_ADD_EACH_INTERVAL);
}

void MainWindow::fillSecundaryData(){

    //    Cest = VolumenTidal / (Ppla - PEEP); //esto me lo envia el pipo ahora
    if(VolumenTidal < Cest || Cest < 0){
        Cest = 0;
    }
    double Tt = 60/static_cast<double>(BPM);
    double Ti = Tt/(1 + (1/static_cast<double>(Relacion_IE))) - static_cast<double>(t_plateau);
    //    double insp_flow = (static_cast<double>(VolumenTidal)/Ti) / 1000;

    Pmed = static_cast<float>((0.5 * static_cast<double>(PIP - PEEP) * (Ti/Tt)) + static_cast<double>(PEEP));
    if(Pmed < 0){
        Pmed = 0;
    }
    //    Rinsp = static_cast<float>(static_cast<double>(PIP - Ppla)/insp_flow); //esto me lo enviara el pipo en futuro
    //    ui->l_Rinsp->setText(QString::number(static_cast<int>(Rinsp), 'f', 0));

    ui->l_Cest->setText(QString::number(static_cast<int>(Cest), 'f', 0));
    ui->l_Pmed->setText(QString::number(static_cast<int>(Pmed), 'f', 0));

    ui->l_PIP_secundary->setText(QString::number(static_cast<double>(PIP), 'f', 0));
    ui->l_Ppla_secundary->setText(QString::number(static_cast<double>(Ppla), 'f', 0));
    ui->l_PEEP_secundary->setText(QString::number(static_cast<double>(PEEP), 'f', 0));

    ui->l_PIP_terciary->setText(QString::number(static_cast<double>(PIP), 'f', 0));
    ui->l_Ppla_terciary->setText(QString::number(static_cast<double>(Ppla), 'f', 0));
    ui->l_PEEP_terciary->setText(QString::number(static_cast<double>(PEEP), 'f', 0));

    ui->l_PIP_terciary_capnography->setText(QString::number(static_cast<double>(PIP), 'f', 0));
    ui->l_PEEP_terciary_capnography->setText(QString::number(static_cast<double>(PEEP), 'f', 0));
}

double MainWindow::calcularPromedio(double *doubleArray){
    double sum=0;
    for(int i=0; i < 100; i++){
        sum+=doubleArray[i];
    }
    double prom = sum/100;
    return prom;
}


//Parsear informacion recivida de serialport----------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------
bool MainWindow::parseInformation(const QByteArray &dataReceived){

    updateDateTime();

    QByteArray temp;

    temp = dataReceived.mid(ALIMENTACION_POS, WORD_SIZE_BYTES);
    Alimentacion = IEEE_754_class::convertirDesde_754_32(IEEE_754_class::convert_Bytes_To_Uint32(IEEE_754_class::changeEndianess(temp)));
    if(Alimentacion < 0){
        Alimentacion =0;
    }
    if(static_cast<int>(Alimentacion) == 1){
        ui->l_source_ac_dc->setPixmap(QPixmap(":/icons/icon_fuente_ac.png"));
    }else if(static_cast<int>(Alimentacion) == 2){
        ui->l_source_ac_dc->setPixmap(QPixmap(":/icons/icon_fuente_dc.png"));
    }
    temp = dataReceived.mid(ESTADO_BATERIA_POS, WORD_SIZE_BYTES);
    Estado_Bateria = IEEE_754_class::convertirDesde_754_32(IEEE_754_class::convert_Bytes_To_Uint32(IEEE_754_class::changeEndianess(temp)));
    if(Estado_Bateria < 0){
        Estado_Bateria =0;
    }
    //    qDebug()<<"Estado_Bateria received: -> "+QString::number(static_cast<int>(Estado_Bateria));
    float bat = Estado_Bateria/10;
    if(Estado_Bateria > 5){
        bat = ceil(bat);
        bat*=10;
    }else {
        if(Estado_Bateria > 0){
            bat = 5;
        }else{
            bat = 0;
        }
    }
    //    qDebug()<<"Bat set: -> "+QString::number(static_cast<int>(bat));
    ui->l_battery->setPixmap(QPixmap(":/icons/bat_"+QString::number(static_cast<int>(bat))+".png"));
    temp = dataReceived.mid(PIP_POS, WORD_SIZE_BYTES);
    PIP = IEEE_754_class::convertirDesde_754_32(IEEE_754_class::convert_Bytes_To_Uint32(IEEE_754_class::changeEndianess(temp)));
    if(PIP < 0){
        PIP =0;
    }
    PIP = floor(PIP);
    temp = dataReceived.mid(PPLAT_POS, WORD_SIZE_BYTES);
    Ppla = IEEE_754_class::convertirDesde_754_32(IEEE_754_class::convert_Bytes_To_Uint32(IEEE_754_class::changeEndianess(temp)));
    if(Ppla < 0){
        Ppla =0;
    }
    Ppla = floor(Ppla);
    temp = dataReceived.mid(PEEP_POS, WORD_SIZE_BYTES);
    PEEP = IEEE_754_class::convertirDesde_754_32(IEEE_754_class::convert_Bytes_To_Uint32(IEEE_754_class::changeEndianess(temp)));
    if(PEEP < 0){
        PEEP =0;
    }
    PEEP = floor(PEEP);
    temp = dataReceived.mid(ALARMAS_POS, WORD_SIZE_BYTES);
    EstadoAlarmas = IEEE_754_class::convertirDesde_754_32(IEEE_754_class::convert_Bytes_To_Uint32(IEEE_754_class::changeEndianess(temp)));

    temp = dataReceived.mid(CMD_STATE_CLOCK_POS, WORD_SIZE_BYTES);
    float cmd_state_hora = IEEE_754_class::convertirDesde_754_32(IEEE_754_class::convert_Bytes_To_Uint32(IEEE_754_class::changeEndianess(temp)));

    //    ui->l_clock_state->setText(QString::number(static_cast<double>(cmd_state_hora), 'f', 0));
    if(static_cast<int>(cmd_state_hora) != SerialPort::OMIT_CLOCK){
        if(static_cast<int>(cmd_state_hora) == SerialPort::SET_FROM_ARDUINO
                || static_cast<int>(cmd_state_hora) == SerialPort::SET_FROM_ARDUINO_ERROR_CLOCK){
            QDateTime dateTime;
            float d, M, y, h, m, s;

            temp = dataReceived.mid(SECONDS_CLOCK_POS, WORD_SIZE_BYTES);
            s = IEEE_754_class::convertirDesde_754_32(IEEE_754_class::convert_Bytes_To_Uint32(IEEE_754_class::changeEndianess(temp)));

            temp = dataReceived.mid(MINUTES_CLOCK_POS, WORD_SIZE_BYTES);
            m = IEEE_754_class::convertirDesde_754_32(IEEE_754_class::convert_Bytes_To_Uint32(IEEE_754_class::changeEndianess(temp)));

            temp = dataReceived.mid(HOUR_CLOCK_POS, WORD_SIZE_BYTES);
            h = IEEE_754_class::convertirDesde_754_32(IEEE_754_class::convert_Bytes_To_Uint32(IEEE_754_class::changeEndianess(temp)));

            temp = dataReceived.mid(DAY_CLOCK_POS, WORD_SIZE_BYTES);
            d = IEEE_754_class::convertirDesde_754_32(IEEE_754_class::convert_Bytes_To_Uint32(IEEE_754_class::changeEndianess(temp)));

            temp = dataReceived.mid(MONTH_CLOCK_POS, WORD_SIZE_BYTES);
            M = IEEE_754_class::convertirDesde_754_32(IEEE_754_class::convert_Bytes_To_Uint32(IEEE_754_class::changeEndianess(temp)));

            temp = dataReceived.mid(YEAR_CLOCK_POS, WORD_SIZE_BYTES);
            y = IEEE_754_class::convertirDesde_754_32(IEEE_754_class::convert_Bytes_To_Uint32(IEEE_754_class::changeEndianess(temp)));

            dateTime.setDate(QDate(static_cast<int>(y), static_cast<int>(M), static_cast<int>(d)));
            dateTime.setTime(QTime(static_cast<int>(h), static_cast<int>(m), static_cast<int>(s)));

            if(dateTime < lastSavedDateTime){
                setFechaHoraReceived(lastSavedDateTime);
            }else{
                setFechaHoraReceivedFromArduino(dateTime);
            }

        }
    }

    temp = dataReceived.mid(VOLUMEN_REAL_POS, WORD_SIZE_BYTES);
    float volumen_real = IEEE_754_class::convertirDesde_754_32(IEEE_754_class::convert_Bytes_To_Uint32(IEEE_754_class::changeEndianess(temp)));
    if(volumen_real > 0){
        ui->l_volumen->setActiveTextString(QString::number(static_cast<double>(volumen_real), 'f', 0));
        ui->l_volumen->startAlarm();
    }else{
        ui->l_volumen->stopAlarm();
    }

    temp = dataReceived.mid(BPM_REAL_POS, WORD_SIZE_BYTES);
    float bpm_real = IEEE_754_class::convertirDesde_754_32(IEEE_754_class::convert_Bytes_To_Uint32(IEEE_754_class::changeEndianess(temp)));
    if(bpm_real > 0){
        ui->l_bpm->setActiveTextString(QString::number(static_cast<double>(bpm_real), 'f', 0));
        ui->l_bpm->startAlarm();
    }else{
        ui->l_bpm->stopAlarm();
    }

    temp = dataReceived.mid(COMPLIANCE, WORD_SIZE_BYTES);
    Cest = IEEE_754_class::convertirDesde_754_32(IEEE_754_class::convert_Bytes_To_Uint32(IEEE_754_class::changeEndianess(temp)));

    temp = dataReceived.mid(FIO2_POS, WORD_SIZE_BYTES);
    fio2 = IEEE_754_class::convertirDesde_754_32(IEEE_754_class::convert_Bytes_To_Uint32(IEEE_754_class::changeEndianess(temp)));

    temp = dataReceived.mid(ETCO2_POS, WORD_SIZE_BYTES);
    etco2 = IEEE_754_class::convertirDesde_754_32(IEEE_754_class::convert_Bytes_To_Uint32(IEEE_754_class::changeEndianess(temp)));


    if(static_cast<int>(EstadoAlarmas) >= presure_leak){
        //Aqui va funcion de decodificacion de alarmas
        if(static_cast<int>(previous_alarm_state) != static_cast<int>(EstadoAlarmas)){
            if(decodeAlarm(EstadoAlarmas)){
                showAlarm();
            }
        }
    }else{
        if(static_cast<int>(previous_alarm_state) != 0){
            decodeAlarm(0);
        }

        //        if(!silence_activated){
        if(high_priority_activation && !ui->l_alarma->isFourthState() && !ui->widget_alarms->getLastAlarm().isEmpty()){
            ui->l_alarma->setFourthState(true);
            qDebug()<<"Seteando 4to estado -> "<<ui->l_alarma->currentState();
            label_alarm_blinking = false;
            enableAlarm();
            ui->widget_alarms->show();
            ui->widget_alarms->setBlankState();
            ui->l_alarm_icon->show();
            if(!ui->widget_alarms->isChecked()){
                ui->l_alarm_text->setText(ui->widget_alarms->getLastAlarm());
            }
            //                qDebug()<<ui->widget_alarms->getLastAlarm();
        }
        if(ui->l_alarma->is_Enabled() && !ui->l_alarma->isFourthState()){
            disableAlarmButton();
            qDebug()<<"state l_alarma: -> "<<ui->l_alarma->currentState();
        }
        //        }
    }

    //    ui->l_alarm_values->setText(QString::number(static_cast<double>(EstadoAlarmas), 'f', 0));

    ui->l_PIP->setText(QString::number(static_cast<double>(PIP), 'f', 0));
    ui->l_Ppla->setText(QString::number(static_cast<double>(Ppla), 'f', 0));
    ui->l_PEEP->setText(QString::number(static_cast<double>(PEEP), 'f', 0));

    if(fio2 < 0){
        ui->l_fio2->setText("--");
        ui->l_fio2_capnography->setText("--");
    }else{
        ui->l_fio2->setText(QString::number(static_cast<double>(fio2), 'f', 0));
        ui->l_fio2_capnography->setText(QString::number(static_cast<double>(fio2), 'f', 0));
    }

    if(etco2 < 0){
        ui->l_PCO2_value->setText("--");
    }else{
        ui->l_PCO2_value->setText(QString::number(static_cast<double>(etco2), 'f', 0));
    }
    //    ui->l_PIP->setText(QString::number(PIP));

    return true;
}
//---------------------------------------------------------------------------------------------------------------------------

//Fucniones de seteo de Hora-------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------
void MainWindow::setFechaHoraReceived(QDateTime date_time){
    QString time = date_time.toString("hh:mmap");
    this->datetime = date_time;
    ui->l_clock_error->hide();

    clock_state = SerialPort::SET_FROM_RASPI;

    ui->l_fecha_hora->setText(time);
    DateTimeWidget::dateTimeProcessInRaspi(date_time, this);
}
void MainWindow::setFechaHoraReceivedFromArduino(QDateTime date_time){
    QString time = date_time.toString("hh:mmap");
    this->datetime = date_time;
    ui->l_clock_error->hide();
    ui->l_fecha_hora->setText(time);
    DateTimeWidget::dateTimeProcessInRaspi(date_time, this);
}
void MainWindow::updateDateTime(){
    QDateTime dt = QDateTime::currentDateTime();
    QString time = dt.toString("hh:mmap");
    ui->l_fecha_hora->setText(time);
}
//---------------------------------------------------------------------------------------------------------------------------


//Funcion de graficacion-----------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------
void MainWindow::graficarDatosFiltrados(double *doubleArray){
    double array[UART_READ_DATA_FUNCTION_SIZE];
    for(int i=0; i < UART_READ_DATA_FUNCTION_SIZE; i++){
        x++;
        array[i]= doubleArray[i];
        customPlot->add_Data(4, x, doubleArray[i]);
    }
    x-=UART_READ_DATA_FUNCTION_SIZE;
}
void MainWindow::graficarDatos(double *doubleArray, int size){
    for(int i=0; i < size; i++){
        if(x >= customPlot->x_axis_Range().upper){
            x=0;
        }
        x++;
        customPlot->add_Data(0, x, doubleArray[i]);
    }
    customPlot->updateGraph();
}
//---------------------------------------------------------------------------------------------------------------------------


//Funcion de boton de inicio de ventilacion----------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------
void MainWindow::write_LOG(QString evento){    
    QString event_view = QDateTime::currentDateTime().toString("dd/MM/yyyy HH:mm") +
            "     " + evento;
    paciente.write_LOG(fillLogMessage(evento));
    paciente.write_LOG_parameters_in_DAT_file((event_view));
}

void MainWindow::on_l_power_clicked()
{
    if(!ui->l_power->isEnabled()){
        qDebug()<<"Desabilitada ventilacion";
        return;
    }
    if(ui->l_power->isChecked()){
        if(serialPort != nullptr){
            if(!serialPort->isOpen()){
                serialPort->openPort();
            }
            paciente.setFileFunctionNameCurrentTime();

            write_LOG("Inicio de Ventilación");
            qDebug()<<"Inicio de Ventilación";

            ui->l_cartel_inicio->hide();
            ui->widget_data_out->hide();

            disconnect(serialPort, &SerialPort::dataAvailable, this , &MainWindow::readSerialPortStandby);
            connect(serialPort, &SerialPort::dataAvailable, this , &MainWindow::readSerialPort);
            connect(serialPort, &SerialPort::comunicacionCaida, this , &MainWindow::comunicacionCaida);
            currentState = SerialPort::VENTILACION;
            //            sendData(SerialPort::VENTILACION);
            started_ventilation = true;
            emit ventilationStarted(true);
            ui->statusBar->showMessage("Se ha iniciado ventilacion", 4000);
            ui->l_ventilation_state->show();
            ui->widget_data->show();

            customPlot->setHorizontalLimitLine(static_cast<int>(Pmax));

            saveLastConfiguration();
        }

    }else{
        Dialog_Question *dialog = new Dialog_Question(this, "Deteniendo", "¿Seguro desea detener ventilación?");
        dialog->showCenter();

        QEventLoop loop;
        connect(dialog, &Dialog_Question::accepted, &loop, &QEventLoop::exit);

        int res = loop.exec();

        if(res == 1){
            write_LOG("Detenida Ventilación");
            qDebug()<<"Detenida de Ventilación";
            stopVentilation();
            setStandByState();

            saveLastConfiguration();
        }else{
            ui->l_power->setChecked(true);
        }
    }
}
void MainWindow::setSerialPortState(SerialPort::ProgramStateType state){
    currentState = state;
}
void MainWindow::openSerialPort(){
    if(serialPort == nullptr){
        serialPort = new SerialPort(this);
    }
    if(!serialPort->isOpen()){
        serialPort->openPort();
    }
    connect(serialPort, &SerialPort::conexion_encontrada, this , &MainWindow::conexion_encontrada);
    connect(serialPort, &SerialPort::turn_off_program, this , &MainWindow::questionTurnOff);
    connect(serialPort, &SerialPort::configurar_parametros, this, &MainWindow::configureStateAndParameters);
    //    connect(serialPort, &SerialPort::conexion_encontrada, this , &MainWindow::conexion_encontrada);

    if(serialPort->isOpen()){
        setStandByState();
        sendData(currentState);
        ui->statusBar->showMessage("Se ha abierto el puerto", 4000);
    }else{
        //Problemas al arir puerto notificar aqui------------------------------------------
        //            QMessageBox::information(this, "No hay conexion", "No se pudo abrir el puerto, puede que no haya dispositivo conectado");
        showAlarm("Sin Conexión", "No hay dispositivo conectado");
        ui->l_power->setChecked(false);
        ui->l_ventilation_state->hide();
        ui->widget_data->hide();
    }
}

//Configure state and parameters-----------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------
void MainWindow::configureStateAndParameters(const QByteArray &data)
{
    //Decodificar informacion recibida por serie-------------------------------------------------
    dataReceived = data;

    if(first_received){
        first_received=false;
    }
    if(decodeStateAndParameters(data)){
        QTimer::singleShot(100, this, SLOT(sendDataWithDelay()));
    }
}
//---------------------------------------------------------------------------------------------------------------------------

//Decode parameters and state received-----------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------
bool MainWindow::decodeStateAndParameters(const QByteArray &dataReceived)
{
    if(dataReceived.size() >= UART_READ_TOTAL_SIZE){

        QByteArray temp;

        temp = dataReceived.mid(BUFFER_DATA_POS + CONFIGURE_STATE_POS, WORD_SIZE_BYTES);
        int state = static_cast<int>(IEEE_754_class::convertirDesde_754_32(IEEE_754_class::convert_Bytes_To_Uint32(IEEE_754_class::changeEndianess(temp))));

        temp = dataReceived.mid(BUFFER_DATA_POS + CONFIGURE_TIDAL_VOLUME_POS, WORD_SIZE_BYTES);
        VolumenTidal = IEEE_754_class::convertirDesde_754_32(IEEE_754_class::convert_Bytes_To_Uint32(IEEE_754_class::changeEndianess(temp)));
        setVolumen_Tidal(static_cast<int>(VolumenTidal));

        temp = dataReceived.mid(BUFFER_DATA_POS + CONFIGURE_BPM_POS, WORD_SIZE_BYTES);
        BPM = IEEE_754_class::convertirDesde_754_32(IEEE_754_class::convert_Bytes_To_Uint32(IEEE_754_class::changeEndianess(temp)));
        setBPM(static_cast<int>(BPM));

        temp = dataReceived.mid(BUFFER_DATA_POS + CONFIGURE_IE_POS, WORD_SIZE_BYTES);
        Relacion_IE = IEEE_754_class::convertirDesde_754_32(IEEE_754_class::convert_Bytes_To_Uint32(IEEE_754_class::changeEndianess(temp)));
        setRelacionIE(Relacion_IE);

        temp = dataReceived.mid(BUFFER_DATA_POS + CONFIGURE_TPLAT_POS, WORD_SIZE_BYTES);
        t_plateau = IEEE_754_class::convertirDesde_754_32(IEEE_754_class::convert_Bytes_To_Uint32(IEEE_754_class::changeEndianess(temp)));
        setTplateau(static_cast<double>(t_plateau));

        temp = dataReceived.mid(BUFFER_DATA_POS + CONFIGURE_PMAX_POS, WORD_SIZE_BYTES);
        Pmax = IEEE_754_class::convertirDesde_754_32(IEEE_754_class::convert_Bytes_To_Uint32(IEEE_754_class::changeEndianess(temp)));
        setPmax(static_cast<int>(Pmax));

        temp = dataReceived.mid(BUFFER_DATA_POS + CONFIGURE_PMIN_POS, WORD_SIZE_BYTES);
        Pmin = IEEE_754_class::convertirDesde_754_32(IEEE_754_class::convert_Bytes_To_Uint32(IEEE_754_class::changeEndianess(temp)));
        setPmin(static_cast<int>(Pmin));

        temp = dataReceived.mid(BUFFER_DATA_POS + CONFIGURE_VENTILATION_MODE_POS, WORD_SIZE_BYTES);
        ModoVentilacion = IEEE_754_class::convertirDesde_754_32(IEEE_754_class::convert_Bytes_To_Uint32(IEEE_754_class::changeEndianess(temp)));
        setMode(static_cast<int>(ModoVentilacion));

        temp = dataReceived.mid(BUFFER_DATA_POS + CONFIGURE_ASSIST_TRIGGER_POS, WORD_SIZE_BYTES);
        trigger_asistido = IEEE_754_class::convertirDesde_754_32(IEEE_754_class::convert_Bytes_To_Uint32(IEEE_754_class::changeEndianess(temp)));
        setTriggerAsistido(static_cast<int>(trigger_asistido));

        temp = dataReceived.mid(BUFFER_DATA_POS + CONFIGURE_FIO2_ALARM_POS, WORD_SIZE_BYTES);
        alarma_fio2 = IEEE_754_class::convertirDesde_754_32(IEEE_754_class::convert_Bytes_To_Uint32(IEEE_754_class::changeEndianess(temp)));
        setFiO2(static_cast<int>(alarma_fio2));

        temp = dataReceived.mid(BUFFER_DATA_POS + CONFIGURE_CO2_ALARM_POS, WORD_SIZE_BYTES);
        alarma_etco2 = IEEE_754_class::convertirDesde_754_32(IEEE_754_class::convert_Bytes_To_Uint32(IEEE_754_class::changeEndianess(temp)));
        setETCO2(static_cast<int>(alarma_etco2));

        bool lastVentState = false;
        if(state == SerialPort::VENTILACION){
            currentState = SerialPort::VENTILACION;
            lastVentState = true;
        }
        QString pacient_name;
        if(checkForceClosed(pacient_name)){
            paciente.setName(pacient_name);
            paciente.setFolderPacient();
            paciente.read_file();//lee informacione de paciente
        }
        if(lastVentState){
            ventilation_screen = true;
            ui->l_power->setChecked(true);
            on_l_power_clicked();
        }
        emit skipToVentilationScreen();
        return true;
    }
    return false;
}

void MainWindow::stopVentilation(){
    if(silence_activated){
        afterMinutesAlarmCheck();
    }
    disconnect(serialPort, &SerialPort::dataAvailable, this , &MainWindow::readSerialPort);
    emit ventilationStarted(false);
    ui->l_cartel_inicio->show();
    ui->widget_data_out->show();

    serialPort->resetVariables();
    started_ventilation = false;

    customPlot->clear_Data();
    x = 0;
}
void MainWindow::setStandByState(){
    ui->l_ventilation_state->hide();
    ui->widget_data->hide();
    disconnect(serialPort, &SerialPort::dataAvailable, this , &MainWindow::readSerialPort);
    connect(serialPort, &SerialPort::dataAvailable, this , &MainWindow::readSerialPortStandby);
    //    serialPort->setState(SerialPort::STANDBY);
    currentState = SerialPort::STANDBY;
}
//---------------------------------------------------------------------------------------------------------------------------

//Funciones de menu desplegable----------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------
void MainWindow::on_l_menu_clicked()
{
    showMenu();
}
void MainWindow::on_l_hide_menu_clicked()
{
    hideMenu();
}
void MainWindow::showMenu()
{
    //        decodeAlarm(0); //para probar alarmas------------------------------------------
    menu_shown = true;
    if(options != nullptr){
        delete options;
    }
    options = new Widget_Options(this);
    connect(options, &Widget_Options::settedFechaHora, this , &MainWindow::setFechaHoraReceived);
    connect(options, &Widget_Options::sendPacient, this , &MainWindow::setPacient);
    connect(options, &Widget_Options::settedPmax, this , &MainWindow::setPmax);
    connect(options, &Widget_Options::settedPEEP, this , &MainWindow::setPmin);
    connect(options, &Widget_Options::settedFiO2, this , &MainWindow::setFiO2);
    connect(options, &Widget_Options::settedETCO2, this , &MainWindow::setETCO2);
    connect(options, &Widget_Options::settedTriggerAsistido, this , &MainWindow::setTriggerAsistido);
    connect(options, &Widget_Options::settedPlateau, this , &MainWindow::setTplateau);
    connect(this, &MainWindow::ventilationStarted, options , &Widget_Options::setVentilationState);
    connect(options, &Widget_Options::requestOxygenCalibration, this , &MainWindow::requestOxygenCalibration);
    options->setVentilationState(started_ventilation);
    options->setConfigs(static_cast<int>(Pmax), static_cast<int>(Pmin), 5, MAX_P_MAX_LEVEL, MIN_P_MAX_LEVEL_BAR,
                        static_cast<int>(trigger_asistido), static_cast<double>(t_plateau),
                        static_cast<int>(alarma_fio2), static_cast<int>(alarma_etco2));

    options->setPacientData(paciente);

    options->showInPos();
    animateWidgetLeftToRight(options, 300);
    QObject::connect(this, &MainWindow::hideAdvanceMenu, options, &Widget_Options::closeWithAnimation);
    QObject::connect(options, &Widget_Options::menu_closing, this, &MainWindow::menuClosed);
    ui->l_menu->hide();
}

void MainWindow::setPacient(PacientClass &p){
    paciente.operator_equal(p);

    if(!started_ventilation){
        setVolumen_Tidal(Screen_Pacient_Data::estimateVolumen(
                             Screen_Pacient_Data::fitHeightMaleWithData(
                                 paciente.height.toInt())));
    }
}

void MainWindow::requestOxygenCalibration(){
    hideMenu();
    Dialog_Question *question = new Dialog_Question(this, "Calibración de Oxígeno", "Siga las instrucciones para la calibración"
                                                                                    "\ndel 21% y 100% de Oxígeno."
                                                                                    ""
                                                                                    "\n- Presione \"Aceptar\" para continuar.");
    question->resizeWidgetQuestion(600, 250);
    question->raise();
    connect(question, &Dialog_Question::accepted, this, &MainWindow::startOxygenCalibration);
}

void MainWindow::startOxygenCalibration(int ok){
    if(ok == 1){ //Aceptado
        Dialog_Question *question = new Dialog_Question(this, "Calibración del 21% de Oxígeno",
                                                        "- Desconecte la fuente de Oxígeno de la toma"
                                                        "\n de O2 en el panel trasero del equipo"
                                                        "\n\n- Presione \"Aceptar\" para iniciar la "
                                                        "\ncalibración y espere por el fin de calibración");
        question->resizeWidgetQuestion(600, 350);
        question->raise();
        connect(question, &Dialog_Question::accepted, this, &MainWindow::startOxygenCalibration21Porcentyle);
    }
    else if(ok == 0){//Cancelado
        Dialog_Question *question = new Dialog_Question(this, "Saliendo de Calibración", "¿Desea cancelar calibración de oxígeno?");
        question->resizeWidgetQuestion(600, 200);
        question->raise();
        connect(question, &Dialog_Question::cancelado, this, &MainWindow::requestOxygenCalibration);
    }
}
void MainWindow::startOxygenCalibration21Porcentyle(int ok){
    if(ok == 1){ //Aceptado
        calibration_oxigeno_active = true;
        currentState = SerialPort::CALIBRACION_OXIGENO_21;
        connect(serialPort, &SerialPort::calibracion_exitosa_oxigeno, this, &MainWindow::requestOxygenCalibration100Porcentyle);
        connect(serialPort, &SerialPort::calibracion_fallida_oxigeno, this, &MainWindow::errorOxygenCalibration);

        LoadingAnimation *animation = new LoadingAnimation(this, "Calibrando Oxígeno al 21%");
        animation->showAnimation();
        connect(serialPort, &SerialPort::calibracion_exitosa_oxigeno, animation, &LoadingAnimation::stopAnimation);
        connect(serialPort, &SerialPort::calibracion_fallida_oxigeno, animation, &LoadingAnimation::stopAnimation);
    }
    else if(ok == 0){//Cancelado
        Dialog_Question *question = new Dialog_Question(this, "Saliendo de Calibración", "¿Desea cancelar calibración de oxígeno?");
        question->resizeWidgetQuestion(600, 200);
        question->raise();
        connect(question, &Dialog_Question::rejected, this, &MainWindow::startOxygenCalibration);
    }
}
void MainWindow::requestOxygenCalibration100Porcentyle(){
    disconnect(serialPort, &SerialPort::calibracion_exitosa_oxigeno, this, &MainWindow::requestOxygenCalibration100Porcentyle);
    calibration_oxigeno_active = false;
    currentState = SerialPort::STANDBY;
    Dialog_Question *question = new Dialog_Question(this, "Calibración del 100% de Oxígeno",
                                                    "- Conecte la fuente de Oxígeno a la toma"
                                                    "\n de O2 en el panel trasero del equipo"
                                                    "\n\n- Configure un flujo de 15L/min en el Medidor"
                                                    "\n de Flujo (flowmeter) acoplado a la línea de O2"
                                                    "\n\n- Presione \"Aceptar\" para iniciar la "
                                                    "\ncalibración y espere por el fin de calibración");
    question->resizeWidgetQuestion(600, 400);
    question->raise();
    connect(question, &Dialog_Question::accepted, this, &MainWindow::startOxygenCalibration100Porcentyle);
}
void MainWindow::startOxygenCalibration100Porcentyle(int ok){
    if(ok == 1){ //Aceptado
        calibration_oxigeno_active = true;
        currentState = SerialPort::CALIBRACION_OXIGENO_100;

        //        QTimer::singleShot(3000, this, &MainWindow::successOxygenCalibration);
        connect(serialPort, &SerialPort::calibracion_exitosa_oxigeno, this, &MainWindow::successOxygenCalibration);
        connect(serialPort, &SerialPort::calibracion_fallida_oxigeno, this, &MainWindow::errorOxygenCalibration);

        LoadingAnimation *animation = new LoadingAnimation(this, "Calibrando Oxígeno al 100%");
        animation->showAnimation();
        connect(serialPort, &SerialPort::calibracion_exitosa_oxigeno, animation, &LoadingAnimation::stopAnimation);
        connect(serialPort, &SerialPort::calibracion_fallida_oxigeno, animation, &LoadingAnimation::stopAnimation);
    }
    else if(ok == 0){//Cancelado
        Dialog_Question *question = new Dialog_Question(this, "Saliendo de Calibración", "¿Desea cancelar calibración de oxígeno?");
        question->resizeWidgetQuestion(600, 200);
        question->raise();
        connect(question, &Dialog_Question::cancelado, this, &MainWindow::requestOxygenCalibration100Porcentyle);
    }
}
void MainWindow::errorOxygenCalibration(){
    calibration_oxigeno_active = false;
    currentState = SerialPort::STANDBY;
    disconnect(serialPort, &SerialPort::calibracion_exitosa_oxigeno, this, &MainWindow::successOxygenCalibration);
    disconnect(serialPort, &SerialPort::calibracion_exitosa_oxigeno, this, &MainWindow::requestOxygenCalibration100Porcentyle);
    MessageDialog *mess = new MessageDialog(this, "Error", "Calibración de oxígeno fallida");
    mess->showCenter();
}
void MainWindow::successOxygenCalibration(){
    calibration_oxigeno_active = false;
    currentState = SerialPort::STANDBY;
    disconnect(serialPort, &SerialPort::calibracion_exitosa_oxigeno, this, &MainWindow::successOxygenCalibration);
    disconnect(serialPort, &SerialPort::calibracion_exitosa_oxigeno, this, &MainWindow::requestOxygenCalibration100Porcentyle);
    MessageDialog *mess = new MessageDialog(this, "Éxito", "Calibración de oxígeno finalizada");
    mess->showCenter();
}

void MainWindow::hideMenu()
{
    emit hideAdvanceMenu();
}

void MainWindow::menuClosed(){
    //    decodeAlarm(1); //para probar alarmas------------------------------------------
    menu_shown = false;
    ui->l_menu->show();

    //    QTimer::singleShot(350, this, SLOT(disconnectSignalsWidgetOptions()));
}
void MainWindow::disconnectSignalsWidgetOptions()
{
    disconnect(options, &Widget_Options::settedFechaHora, this , &MainWindow::setFechaHoraReceived);
    disconnect(options, &Widget_Options::sendPacient, this , &MainWindow::setPacient);
    disconnect(options, &Widget_Options::settedPmax, this , &MainWindow::setPmax);
    disconnect(options, &Widget_Options::settedPEEP, this , &MainWindow::setPmin);
    disconnect(options, &Widget_Options::settedTriggerAsistido, this , &MainWindow::setTriggerAsistido);
    disconnect(options, &Widget_Options::settedPlateau, this , &MainWindow::setTplateau);
    disconnect(this, &MainWindow::ventilationStarted, options , &Widget_Options::setVentilationState);

    QObject::disconnect(this, &MainWindow::hideAdvanceMenu, options, &Widget_Options::closeWithAnimation);
    QObject::disconnect(options, &Widget_Options::menu_closing, this, &MainWindow::menuClosed);
}

void MainWindow::on_l_background_blur_clicked()
{
    ui->l_background_blur->hide();
    if(parameters != nullptr){
        parameters->close();
        delete parameters;
        parameters = nullptr;
    }
    if(parameters_center != nullptr){
        parameters_center->close();
        delete parameters_center;
        parameters_center = nullptr;
    }
    if(parameters_modes != nullptr){
        parameters_modes->close();
        delete parameters_modes;
        parameters_modes = nullptr;
    }
    if(parameters_ie != nullptr){
        parameters_ie->close();
        delete parameters_ie;
        parameters_ie = nullptr;
    }
}
//---------------------------------------------------------------------------------------------------------------------------


//Funciones de botones de configuracion--------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------
void MainWindow::on_l_alarma_clicked()
{
    on_close_Alarm();
}

void MainWindow::on_l_p_max_clicked()
{
    if(parameters!=nullptr){
        delete parameters;
    }
    parameters = new SettingParameter(this);
    parameters->setTitle("Pmax");
    parameters->move(395, 100);
    parameters->show();
}
void MainWindow::setETCO2(int value){

    QString evento = "Cambios de Parámetros (ETCO2) " + QString::number(static_cast<int>(alarma_etco2)) + " -> " + QString::number(value);
    ui->l_etco2_configured_capnography->setText(QString::number(value)); //aqui poner el valor del fio2 configurado
    if(static_cast<int>(alarma_etco2) != value){
        write_LOG(evento);
    }
    alarma_etco2 = value;

    saveLastConfiguration();
}
void MainWindow::setFiO2(int value){

    QString evento = "Cambios de Parámetros (FiO2) " + QString::number(static_cast<int>(alarma_fio2)) + " -> " + QString::number(value);
    ui->l_fio2_configured->setText(QString::number(value)); //aqui poner el valor del fio2 configurado
    ui->l_fio2_configured_capnography->setText(QString::number(value));
    if(static_cast<int>(alarma_fio2) != value){
        write_LOG(evento);
    }
    alarma_fio2 = value;

    saveLastConfiguration();
}
void MainWindow::setPmin(int value){

    QString evento = "Cambios de Parámetros (Pmin) " + QString::number(static_cast<int>(Pmin)) + " -> " + QString::number(value);
    ui->l_p_min->setText(QString::number(value));
    if(static_cast<int>(Pmin) != value){
        write_LOG(evento);
    }
    Pmin = value;

    saveLastConfiguration();
}
void MainWindow::setPmax(int value){
    //   ui->l_p_max->setTextString(QString::number(value));
    QString evento = "Cambios de Parámetros (Pmax) " + QString::number(static_cast<int>(Pmax)) + " -> " + QString::number(value);
    adjustBarLevels(value);
    ui->l_p_max_configured->setText(QString::number(static_cast<int>(value)));
    if(static_cast<int>(Pmax) != value){
        write_LOG(evento);
    }
    Pmax = value;
    rescaleYAxis(value, true);

    saveLastConfiguration();
}
void MainWindow::setTriggerAsistido(int value){
    QString evento = "Cambios de Parámetros (Disparo) " + QString::number(static_cast<int>(trigger_asistido)) + " -> " + QString::number(value);
    if(static_cast<int>(trigger_asistido) != value){
        write_LOG(evento);
    }
    trigger_asistido = value;

    saveLastConfiguration();
}
void MainWindow::setTplateau(double value){
    QString evento = "Cambios de Parámetros (Tplateau) " + QString::number(static_cast<double>(t_plateau), 'f', 2)
            + " -> " + QString::number(value, 'f', 2);

    if(t_plateau != static_cast<float>(value)){
        write_LOG(evento);
    }
    t_plateau = static_cast<float>(value);

    saveLastConfiguration();
}

void MainWindow::on_l_ie_clicked()
{
    ui->l_background_blur->show();
    ui->l_background_blur->raise();
    if(parameters_ie!=nullptr){
        delete parameters_ie;
    }
    parameters_ie = new SettingIERatio(this);
    parameters_ie->setTitle("RelacionIE");
    parameters_ie->setShadow(QColor(194, 153, 209));
    parameters_ie->setConfigs(Relacion_IE, static_cast<double>(Ti), static_cast<double>(BPM));
    parameters_ie->move(ui->l_ie->pos().x() + ui->l_ie->width()/2
                        - parameters_ie->width()/2, 115);
    parameters_ie->show();
    connect(parameters_ie, SIGNAL(setted(float)), this, SLOT(setRelacionIE(float)));
    connect(parameters_ie, SIGNAL(setted_Ti(double)), this, SLOT(setTi(double)));
    ui->l_ie->highlight();
}
void MainWindow::setTi(double value){

    disconnect(parameters_ie, SIGNAL(setted_Ti(double)), this, SLOT(setTi(double)));
    QString evento = "Cambios de Parámetros (Ti) " + ui->l_ie->getText() + " -> " + QString::number(value);
    if(Ti != static_cast<float>(value)){
        write_LOG(evento);
    }
    Ti = static_cast<float>(value);
    ui->l_ie->setTextString(QString::number(value, 'f', 1));

    saveLastConfiguration();
}

void MainWindow::setRelacionIE(float value){
    disconnect(parameters_ie, SIGNAL(setted(float)), this, SLOT(setRelacionIE(float)));
    ui->l_background_blur->hide();
    Relacion_IE = value;
}

void MainWindow::on_l_bpm_clicked()
{
    ui->l_background_blur->show();
    ui->l_background_blur->raise();
    if(parameters_center!=nullptr){
        delete parameters_center;
    }
    parameters_center = new SettingCenterParameters(this);
    parameters_center->setTitle("BPM");
    parameters_center->setShadow(QColor(255, 222, 98));
    parameters_center->setConfigs(ui->l_bpm->getDefaultText().toInt(), 1, MAX_BPM, MIN_BPM);
    parameters_center->move(ui->l_bpm->pos().x() + ui->l_bpm->width()/2
                            - parameters_center->width()/2, 100);
    parameters_center->show();
    connect(parameters_center, SIGNAL(setted(int)), this, SLOT(setBPM(int)));
    ui->l_bpm->highlight();
}
void MainWindow::setBPM(int value){
    disconnect(parameters_center, SIGNAL(setted(int)), this, SLOT(setBPM(int)));
    QString evento = "Cambios de Parámetros (BPM) " + QString::number(static_cast<int>(BPM)) + " -> " + QString::number(value);
    ui->l_background_blur->hide();
    ui->l_bpm->setTextString(QString::number(value));
    ui->l_bpm->setDefautTextString(QString::number(value));
    if(static_cast<int>(BPM) != value){
        write_LOG(evento);
    }
    BPM = value;
    adjustRangeToBPM(CICLOS_EN_GRAFICA);

    float value_ti = SettingIERatio::getTiWithData(static_cast<double>(Relacion_IE), static_cast<double>(BPM));
    setTi(static_cast<double>(value_ti));

    saveLastConfiguration();
}

void MainWindow::on_l_modo_clicked()
{
    ui->l_background_blur->show();
    ui->l_background_blur->raise();
    if(parameters_modes!=nullptr){
        delete parameters_modes;
    }
    parameters_modes = new SettingModes(this);
    parameters_modes->setTitle("Modo");
    parameters_modes->setShadow(QColor(153, 222, 98));
    parameters_modes->setConfig(ui->l_modo->getText());
    parameters_modes->move(12, 120);
    parameters_modes->show();
    connect(parameters_modes, SIGNAL(setted(int)), this, SLOT(setMode(int)));
    ui->l_modo->highlight();
}
void MainWindow::setMode(int value){
    disconnect(parameters_modes, SIGNAL(setted(int)), this, SLOT(setMode(int)));
    QString previous_state = ui->l_modo->getText();
    ui->l_background_blur->hide();
    if(value == 1){
        ui->l_modo->setTextString("VCV");
    }else if(value== 2){
        ui->l_modo->setTextString("VAC");
    }
    QString evento = "Cambio Modo de Ventilación " + previous_state + " -> " + ui->l_modo->getText();
    if(static_cast<int>(ModoVentilacion) != value){
        write_LOG(evento);
    }
    ModoVentilacion = value;

    saveLastConfiguration();
}

void MainWindow::on_l_volumen_clicked()
{
    ui->l_background_blur->show();
    ui->l_background_blur->raise();
    if(parameters_center!=nullptr){
        delete parameters_center;
    }
    parameters_center = new SettingCenterParameters(this);
    parameters_center->setTitle("Volumen");
    parameters_center->setTextColor(QColor(255, 134, 134));
    parameters_center->setShadow(QColor(255, 134, 134));
    parameters_center->setConfigs(ui->l_volumen->getDefaultText().toInt(), 50, static_cast<int>(MAX_VOLUMEN), MIN_VOLUMEN_TIDAL);
    parameters_center->move(ui->l_volumen->pos().x() + ui->l_volumen->width()/2
                            - parameters_center->width()/2, 100);
    parameters_center->show();
    connect(parameters_center, SIGNAL(setted(int)), this, SLOT(setVolumen_Tidal(int)));
    ui->l_volumen->highlight();
}
void MainWindow::setVolumen_Tidal(int value){
    disconnect(parameters_center, SIGNAL(setted(int)), this, SLOT(setVolumen_Tidal(int)));
    QString evento = "Cambios de Parámetros (Vt) " + QString::number(static_cast<int>(VolumenTidal)) + " -> " + QString::number(value);
    ui->l_background_blur->hide();
    ui->l_volumen->setTextString(QString::number(value));
    ui->l_volumen->setDefautTextString(QString::number(value));
    if(static_cast<int>(VolumenTidal) != value){
        write_LOG(evento);
    }
    VolumenTidal = value;

    saveLastConfiguration();
}
//---------------------------------------------------------------------------------------------------------------------------


// Funciones de ajuste de barras---------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------
void MainWindow::adjustBarLevels(int level_p_max, int level_pinst, int level_peep)
{
    if(level_peep >= 0){
        adjust_peep(level_peep);
        adjust_pinst(-1);
    }
    if(level_pinst >= 0){
        adjust_pinst(level_pinst);
    }
    if(level_p_max >= 0){
        adjust_p_max(level_p_max);
    }
}
void MainWindow::adjust_peep(int level_peep)
{
    Q_UNUSED(level_peep);
    //    int pixel_range = MIN_Y_LEVEL_BAR - MAX_Y_LEVEL_BAR;
    //    float ratio = ((float)level_peep/MAX_P_MAX_LEVEL_BAR) * pixel_range;
    //    int pos_y_Pmax = MIN_Y_LEVEL_BAR - static_cast<int>(ratio);
    //     ui->l_nivel_PEEP->move(ui->l_nivel_PEEP->pos().x(), pos_y_Pmax);
    //       ui->l_marca_PEEP->move(ui->l_marca_PEEP->pos().x(), pos_y_Pmax);
    //    int height = MIN_Y_LEVEL_BAR_POS - ui->l_nivel_PEEP->pos().y();
    //     ui->l_nivel_PEEP->setFixedSize(ui->l_nivel_PEEP->size().width(), height);
}
void MainWindow::adjust_pinst(int level_pinst)
{
    Q_UNUSED(level_pinst);
    if(level_pinst >= 0){
        //        int pixel_range = MIN_Y_LEVEL_BAR - MAX_Y_LEVEL_BAR;
        //        float ratio = ((float)level_pinst/MAX_P_MAX_LEVEL_BAR) * pixel_range;
        //        int pos_y_Pmax = MIN_Y_LEVEL_BAR - static_cast<int>(ratio);
        //         ui->l_nivel_PINST->move(ui->l_nivel_PINST->pos().x(), pos_y_Pmax);
        //     ui->l_marca_PINST->move(ui->l_marca_PINST->pos().x(), pos_y_Pmax);
        //     ui->l_marca_PINST_value->move(ui->l_marca_PINST_value->pos().x(), pos_y_Pmax);
    }
    //    int height = ui->l_nivel_PEEP->pos().y() - ui->l_nivel_PINST->pos().y();
    //         ui->l_nivel_PINST->setFixedSize(ui->l_nivel_PINST->size().width(), height);
    //         ui->l_nivel_PINST->raise();
}
void MainWindow::adjust_p_max(int level_p_max)
{
    Q_UNUSED(level_p_max);
    //    int pixel_range = MIN_Y_LEVEL_BAR - MAX_Y_LEVEL_BAR;
    //    float ratio = ((float)level_p_max/MAX_P_MAX_LEVEL_BAR) * pixel_range;
    //    int pos_y_Pmax = MIN_Y_LEVEL_BAR - static_cast<int>(ratio);
    //       ui->l_nivel_Pmax->move(ui->l_nivel_Pmax->pos().x(), pos_y_Pmax);
    //    ui->l_marca_Pmax->move(ui->l_marca_Pmax->pos().x(), pos_y_Pmax);
}
//----------------------------------------------------------------------------------------------------------------------------


// Funcion de configuracion de grafico de funcion-----------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------
void MainWindow::setupGraph(){

    customPlot = static_cast<Plot *>(ui->widget_graph);

    customPlot->set_Range_x_axis_initial(0, MUESTRAS_EN_GRAFICA);

    rescaleYAxis(MAX_P_MAX_LEVEL_BAR, false);

    customPlot->setup_Graph();

    //    customPlot->addGraph();
    //    QPen pen = QPen(QColor(0, 204, 255).lighter(130));
    //    pen.setWidth(0);
    //    pen.setColor(QColor(255, 255, 255).lighter(130));
    //    customPlot->graph(2)->setPen(pen);
}
void MainWindow::rescaleYAxis(int p_max, bool replot){
    p_max+=5;
    customPlot->set_Range_y_axis_initial(0, p_max);
    customPlot->set_Range_y_axis(0, p_max);

    QVector<double> TickValues;
    QVector<QString> TickLabels;
    // you can safely change the values according to the output
    if(p_max < 20){
        for (double i=2.5; i < p_max; i+=2.5) {
            TickValues << i;
            if(i < 10){
                TickLabels << QString::number(i, 'f', 1);
            }else{
                TickLabels << QString::number(i, 'f', 0);
            }
        }
    }else{
        for (int i=5; i < p_max; i+=5) {
            TickValues << i;
            TickLabels << QString::number(i);
        }
    }
    // disable default ticks and their labels
    customPlot->yAxis->setAutoTicks(false);
    customPlot->yAxis->setAutoTickLabels(false);
    // add your custom values and labels
    customPlot->yAxis->setTickVector(TickValues);
    customPlot->yAxis->setTickVectorLabels(TickLabels);

    if(started_ventilation){
        customPlot->setHorizontalLimitLine(static_cast<int>(Pmax));
    }
    if(replot){
        customPlot->updateGraph();
    }
}
//----------------------------------------------------------------------------------------------------------------------------


// Funcion de ajuste de grafico en funcion de BPM-----------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------
void MainWindow::adjustRangeToBPM(float ciclos_en_grafica){ //Recibe la cantidad de ciclos de respiracion en el rango de la grafica
    float factor = BPM / ciclos_en_grafica;
    float secons_to_show = 60/ factor;
    int x_range = static_cast<int>(secons_to_show * UART_READ_DATA_FUNCTION_SIZE*2/*UART_READ_DATA_FUNCTION_SIZE*2 - cant de muestras en un segundo*/);
    if(x >= x_range){
        x=0;
    }
    customPlot->set_Range_x_axis_initial(0, x_range);
    customPlot->set_Range_x_axis(0, x_range);

    if(started_ventilation){
        customPlot->setHorizontalLimitLine(static_cast<int>(Pmax));
    }
    customPlot->updateGraph();
}
//----------------------------------------------------------------------------------------------------------------------------

// Funcion de slot que lee temperatura registrada----------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------
void MainWindow::readTempSensor(double temp_received){//(la clase ReadTempDS18B20 se encarga de todo
    Q_UNUSED(temp_received);
    //ui->l_temp_value->setText(sensor->temp(""));
}
//----------------------------------------------------------------------------------------------------------------------------

// Funcion de slot que apaga raspberry pi---------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------
void MainWindow::questionTurnOff(){//(la clase ReadTempDS18B20 se encarga de todo
    disconnect(serialPort, &SerialPort::turn_off_program, this, &MainWindow::questionTurnOff);
    Dialog_Question *question = new Dialog_Question(this, "Apagando", "¿Desea apagar, se detendrá la ventilación?");
    question->show();
    question->raise();
    connect(question, &Dialog_Question::accepted, this, &MainWindow::turnOffRaspi);
    qDebug()<<"Shuting down**********************";
}
void MainWindow::turnOffRaspi(int ok){//(la clase ReadTempDS18B20 se encarga de todo

    if(ok == 1){
        saveLastConfiguration();
        currentState = SerialPort::APAGADO;
        //        sendData(SerialPort::APAGADO);
        Screen_Apagado_Sistema *screen_apagado =  new Screen_Apagado_Sistema(this);
        screen_apagado->show();
    }else{
        connect(serialPort, &SerialPort::turn_off_program, this, &MainWindow::questionTurnOff);
    }
}
void MainWindow::closeApplication(){
    QApplication::closeAllWindows();
}
//----------------------------------------------------------------------------------------------------------------------------


// Funcion de slot que resetea GPIO---------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------
void MainWindow::resetGPIO(){//(la clase ReadTempDS18B20 se encarga de todo

    ProcessesClass::executeProcess(this, "sudo python /home/pi/Ventilador/Ventilador/scripts/reset_gpio.py", ProcessesClass::LINUX, 100);
}
//----------------------------------------------------------------------------------------------------------------------------

// Funcion de slot que apaga motor---------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------
void MainWindow::turnOffMotor(){//(la clase ReadTempDS18B20 se encarga de todo  
    motor_deactivate = false;
    ProcessesClass::executeProcess(this, "sudo python /home/pi/Ventilador/Ventilador/scripts/power_off_motor.py", ProcessesClass::LINUX, 100);
}
//----------------------------------------------------------------------------------------------------------------------------


// Funcion de slot que habilita motor---------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------
void MainWindow::enableMotor(){//(la clase ReadTempDS18B20 se encarga de todo  
    if(!motor_deactivate){
        motor_deactivate = true;
        ProcessesClass::executeProcess(this, "sudo python /home/pi/Ventilador/Ventilador/scripts/power_on_motor.py", ProcessesClass::LINUX, 100);
    }
}
//----------------------------------------------------------------------------------------------------------------------------

// Funcion de slot que apaga bocina---------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------
void MainWindow::turnOffBuzzer(){//(la clase ReadTempDS18B20 se encarga de todo
    buzzer_active = false;
    ProcessesClass::executeProcess(this, "sudo python /home/pi/Ventilador/Ventilador/scripts/sound_buzzer_off.py", ProcessesClass::LINUX, 100);
}
//----------------------------------------------------------------------------------------------------------------------------


// Funcion de slot que suena bocina---------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------
void MainWindow::soundBuzzer(){//(la clase ReadTempDS18B20 se encarga de todo

    if(!buzzer_active){
        buzzer_active = true;
        ProcessesClass::executeProcess(this, "sudo python /home/pi/Ventilador/Ventilador/scripts/sound_buzzer.py", ProcessesClass::LINUX, 100);
    }
}
//----------------------------------------------------------------------------------------------------------------------------
