#include "mywidgetalarmanimated.h"
#include <QTimer>
#include <QDebug>
#include "qlabel_button.h"
#include <QPushButton>
#include <QLayout>

MyWidgetAlarmAnimated::MyWidgetAlarmAnimated(QWidget *parent)
    :QWidget(parent)
{
    widget_notifications = new MyWidgetAnimated(parent);
    QVBoxLayout *layout = new QVBoxLayout;
    widget_notifications->setLayout(layout);
    QString style = "background-color: rgb(35, 33, 30);"
                    "color: #E3E3E3;"
                    "border-radius: 5px;";
    widget_notifications->setStyleSheet(style);
    widget_notifications->hide();
    posibles_actives_colors << QColor(Qt::black) << color_alarm_notifications << color_high_priority << color_medium_priority << color_low_priority;

    fillMapAlarms();

    connect(widget_notifications, &MyWidgetAnimated::mouseLeftClicked, this,
            &MyWidgetAlarmAnimated::hideMenuAlarms);
}

MyWidgetAlarmAnimated::~MyWidgetAlarmAnimated()
{
}

bool MyWidgetAlarmAnimated::isActiveAlarm(QString alarm){
    if(listaAlarmas.contains(alarm)){
        return true;
    }else {
        return false;
    }
}

void MyWidgetAlarmAnimated::fillMapAlarms(){

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

int MyWidgetAlarmAnimated::getAlarmCode(QString alarm){
    if(mapaAlarmas.values().contains(alarm)){
        return mapaAlarmas.key(alarm);
    }
    return 0;
}

QString MyWidgetAlarmAnimated::getAlarmString(int code_alarm){
    if(mapaAlarmas.keys().contains(code_alarm)){
        return mapaAlarmas.value(code_alarm);
    }
    return "";
}

int MyWidgetAlarmAnimated::getPriorityOfAlarm(int alarm_code){
    if(alarm_code <= low_battery){
        return high_priority;
    }else if (alarm_code <= low_co2_level) {
        return medium_priority;
    }else{
        return low_priority;
    }
}

void MyWidgetAlarmAnimated::startAlarm(int interval){

    if(alarm_activated){
        return;
    }
    emit startedAlarm(interval);
    alarm_activated = true;
    connect(&timer_alarm, SIGNAL(timeout()), this, SLOT(changeColor()));
    timer_alarm.stop();
    timer_alarm.setInterval(interval);
    timer_alarm.start();
}

void MyWidgetAlarmAnimated::stopAlarm(){
    emit stopedAlarm();
    alarm_activated = false;
    disconnect(&timer_alarm, SIGNAL(timeout()), this, SLOT(changeColor()));
    timer_alarm.stop();
    setOffState();
}

void MyWidgetAlarmAnimated::setOffState(){
    currentColor =  QColor(Qt::transparent);
    QString style = this->styleSheet();
    QColor color;
    foreach(color, posibles_actives_colors){
        QString color_active_str = "background-color: rgb("
                + getStringBackgroundColor(color)  + ");";
        style.remove(color_active_str);
        style.remove("color: rgb(" + getStringBackgroundColor(color) + ");");
    }
    style += "color: rgb(" + getStringBackgroundColor(text_unactiveColor) + ");";
    this->setStyleSheet(style);
}

bool MyWidgetAlarmAnimated::hasHighPriorityAlarms(){
    if(listaAlarmas_AltaPrioridad.isEmpty()){
        return false;
    }
    return true;
}
QString MyWidgetAlarmAnimated::getLastAlarm(){
    if(listaAlarmas_AltaPrioridad.isEmpty()){
        return "";
    }else{
        setActiveAlarm(listaAlarmas_AltaPrioridad.last());
        return listaAlarmas_AltaPrioridad.last();
    }
}

void MyWidgetAlarmAnimated::setBlankState(){
    currentColor = color_alarm_notifications;
    QString style = this->styleSheet();
    QColor color;
    foreach(color, posibles_actives_colors){
        QString color_active_str = "background-color: rgb("
                + getStringBackgroundColor(color)  + ");";
        style.remove(color_active_str);
    }
    style.remove("color: rgb(" + getStringBackgroundColor(text_activeColor) + ");");
    style += "color: rgb(" + getStringBackgroundColor(QColor(Qt::black)) + ");";
    style += "background-color: rgb("
            + getStringBackgroundColor(QColor(Qt::white)) + ");";
    this->setStyleSheet(style);
    qDebug()<<style;
    emit changedColor(currentColor);
}
void MyWidgetAlarmAnimated::changeColor(){
    if(currentColor == activeColor){
        setOffState();
    }else{
        currentColor =  activeColor;
        QString style = this->styleSheet() + "background-color: rgb("
                + getStringBackgroundColor(activeColor) + ");";
        style.remove("background-color: rgb(" + getStringBackgroundColor(color_alarm_notifications) + ");");
        style.remove("color: rgb(" + getStringBackgroundColor(text_unactiveColor) + ");");
        style += "color: rgb(" + getStringBackgroundColor(text_activeColor) + ");";
        this->setStyleSheet(style);
    }
    emit changedColor(currentColor);
}
bool MyWidgetAlarmAnimated::isActiveState(){
    if(currentColor == activeColor){
        return true;
    }else{
        return false;
    }
}

void MyWidgetAlarmAnimated::setActiveColor(QColor color, QColor text_color){
    if(color.isValid()){
        activeColor = color;
    }
    if(text_color.isValid()){
        text_activeColor = text_color;
    }
}

QString MyWidgetAlarmAnimated::getStringBackgroundColor(QColor color)
{
    QString c = QString::number(color.red()) + ","
            + QString::number(color.green()) + ","
            + QString::number(color.blue());

    return c;
}

void MyWidgetAlarmAnimated::setBackgroundImage(const QString image_filename)
{
    if(QFile::exists(":/icons/" + image_filename + ".png")){
        this->setStyleSheet("border-image: url(:/icons/"+ image_filename +".png);");
    }
    else{
        qDebug()<<"No se ha creado icono de este label (image_filename.png)";
    }
}

void MyWidgetAlarmAnimated::removeAlarmDeLista(QString text){
    if(text.isEmpty()){
        return;
    }
    if(listaAlarmas.contains(text)){
        listaAlarmas.removeOne(text);
        emit removidaAlarma("Desactivada -> "+text);
    }
    int count_alarms = countTotalAlarmas();
    if(count_alarms > 1){
        emit alarm_count(QString::number(count_alarms));
    }else{
        emit alarm_count("");
    }
}
void MyWidgetAlarmAnimated::removeAlarmDeListaAltaPrioridad(QString text){
    if(text.isEmpty()){
        return;
    }
    if(listaAlarmas_AltaPrioridad.contains(text)){
        listaAlarmas_AltaPrioridad.removeOne(text);
        emit removidaAlarma("Limpiada Alarma -> "+text);
    }
    int count_alarms = countTotalAlarmas();
    if(count_alarms > 1){
        emit alarm_count(QString::number(count_alarms));
    }else{
        emit alarm_count("");
    }
    if(count_alarms == 0){
        hideMenuAlarms();
        emit hidingWidgetAlarms();
    }
}

void MyWidgetAlarmAnimated::removeAlarmAltaPriority(QString text){
    if(text.isEmpty()){
        return;
    }
    if(listaAlarmas_AltaPrioridad.contains(text)){
        deleteOneAlarm(text);
        removeAlarmDeListaAltaPrioridad(text);
    }
    if(listaAlarmas.isEmpty() && listaAlarmas_AltaPrioridad.isEmpty()){
        hideMenuAlarms();
    }
}

bool MyWidgetAlarmAnimated::isHighPriorityAlarm(QString text){
    int code = getAlarmCode(text);
    if(getPriorityOfAlarm(code) == high_priority){
        return true;
    }
    return false;
}

void MyWidgetAlarmAnimated::removeAlarm(QString text){
    if(text.isEmpty()){
        return;
    }
    if(listaAlarmas.contains(text)){
        removeAlarmDeLista(text);
        if(isHighPriorityAlarm(text)){
            transformOneToUnActive(text);
        }else{
            deleteOneAlarm(text);
        }
    }
    if(listaAlarmas.isEmpty() && listaAlarmas_AltaPrioridad.isEmpty()){
        hideMenuAlarms();
    }
}
void MyWidgetAlarmAnimated::loadEraseHighPriority(){
    if(!alarmSaved.isEmpty()){
        if(!listaAlarmas_AltaPrioridad.contains(alarmSaved)){
            listaAlarmas_AltaPrioridad.append(alarmSaved);
            alarmSaved = "";
        }
    }
}
void MyWidgetAlarmAnimated::setActiveAlarm(QString text){
    activeAlarm = text;
}
QString MyWidgetAlarmAnimated::getActiveAlarm(){
    if(listaAlarmas.contains(activeAlarm)){
        return activeAlarm;
    }
    else {
        return getLastAlarm();
    }
}
void MyWidgetAlarmAnimated::setText(QString text){
    if(text.isEmpty()){
        return;
    }
    if(isHighPriorityAlarm(text)){
        if(!listaAlarmas_AltaPrioridad.contains(text)){
            listaAlarmas_AltaPrioridad.append(text);
        }
    }
    if(!listaAlarmas.contains(text)){
        listaAlarmas.append(text);
        emit nuevaAlarma("Alarma -> "+text);
    }

    int count_alarms = countTotalAlarmas();
    if(count_alarms > 1){
        emit alarm_count(QString::number(count_alarms));
    }else{
        emit alarm_count("");
    }
    widget_notifications->setGeometry(this->pos().x(), this->pos().y() + this->height(),
                                      this->width(), 0);


    addHighPriorityAlarmsToWidget();
    addAllAlarmsToWidget();

}
int MyWidgetAlarmAnimated::countTotalAlarmas(){
    QStringList list = listaAlarmas;
    QString alarma;
    foreach(alarma, listaAlarmas_AltaPrioridad){
        if(!list.contains(alarma)){
            list.append(alarma);
        }
    }
    int count_alarms = list.size();
    return count_alarms;
}
QStringList MyWidgetAlarmAnimated::getText(){
    return listaAlarmas;
}
void MyWidgetAlarmAnimated::hideChilds(){
    //    menu_expanded->hide();
}

void MyWidgetAlarmAnimated::setAnimationInit()
{

    startValue = this->geometry();
    endValue = QRect(startValue.x()-anim_scale,startValue.y() -anim_scale
                     ,startValue.width() +anim_scale*2,startValue.height() +anim_scale*2);
    maxSize= this->maximumSize();
    if(((maxSize.width() +  anim_scale*2) < 10000) && ((maxSize.height() +anim_scale*2) < 10000)){
        this->setMaximumSize(maxSize.width() +  anim_scale*2, maxSize.height() +anim_scale*2);
    }
    animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(anim_time);
    animation->setStartValue(startValue);
    animation->setEndValue(endValue);
}
void MyWidgetAlarmAnimated::setAnimationEnd()
{
    delete animation;
    animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(anim_time);
    animation->setStartValue(endValue);
    animation->setEndValue(startValue);
    connect(animation, SIGNAL(finished()), this, SLOT(finalizadaAnimacion()));
    animation->start();
}
void MyWidgetAlarmAnimated::finalizadaAnimacion()
{
    disconnect(animation, SIGNAL(finished()), this, SLOT(finalizadaAnimacion()));
    animationOnGoing = false;
    if(maxSize.width() < 10000 && maxSize.height() < 10000){
        this->setMaximumSize(maxSize);
    }
    delete animation;
    QTimer::singleShot(50, this, SLOT(emitirClicked()));
    //    emit mouseLeftClicked();
}
void MyWidgetAlarmAnimated::emitirClicked()
{
    emit clicked();
    emit mouseLeftClicked(this->objectName());
}

void MyWidgetAlarmAnimated::startAnimation(int delay, int scale, int anim_tim)
{
    Q_UNUSED(delay);
    //hacer un single shot con delay
    anim_time = anim_tim;
    anim_scale = scale;
    setAnimationInit();
    animationOnGoing = true;
    connect(animation, SIGNAL(finished()), this, SLOT(setAnimationEnd()));
    animation->start();
}

void MyWidgetAlarmAnimated::mousePressEvent(QMouseEvent *ev)
{
    emit pressEvent(ev);
    emit pressed();
    if(!isChecked()){
        if((listaAlarmas.size() > 0 && alarm_activated)
                || (listaAlarmas_AltaPrioridad.size() >= 1 && !alarm_activated)){
            setChecked(true);
            showWidgetNotifications();
            animateWidgetUpToDown(widget_notifications);
        }
    }else {
        hideMenuAlarms();
    }
    emit clicked();
}
void MyWidgetAlarmAnimated::showWidgetNotifications(){
    emit showing_menu_alarms(true);
    widget_notifications->setGeometry(this->pos().x(), this->pos().y() + this->height(),
                                      this->width(), 0);


    addHighPriorityAlarmsToWidget();
    addAllAlarmsToWidget();

    widget_notifications->show();
    widget_notifications->raise(); ///importante, si no no se ve el widget
}

void MyWidgetAlarmAnimated::addAllAlarmsToWidget(){
    QString alarma;
    QFont font = this->font();
    font.setPointSize(14);
    foreach(alarma, listaAlarmas){
        //        if(activeAlarm == alarma){
        //            continue;
        //        }
        QString objName = alarma;
        objName = "w_"+objName.replace(" ", "").trimmed();

        QColor background_color, text_color = QColor(Qt::black);
        bool isHighPriority = false;
        int code = getAlarmCode(alarma);
        if(getPriorityOfAlarm(code) == high_priority){
            isHighPriority = true;
            background_color = color_high_priority;
            text_color = QColor(Qt::white);
        }
        else if(getPriorityOfAlarm(code) == medium_priority){
            background_color = color_medium_priority;
        }
        else if(getPriorityOfAlarm(code) == low_priority){
            background_color = color_low_priority;
        }


        widget_notifications->setGeometry(widget_notifications->pos().x(),widget_notifications->pos().y(),
                                          widget_notifications->size().width(), widget_notifications->height() + 50);
        QWidget *widget = new QWidget(nullptr);
        widget->setStyleSheet("background-color: rgb("
                              + getStringBackgroundColor(background_color)+ ");"
                              +"color: rgb("
                              + getStringBackgroundColor(text_color)+ ");");
        QHBoxLayout *layout = new QHBoxLayout;
        layout->setContentsMargins(50,0,0,0);
        widget->setLayout(layout);
        widget->setObjectName(objName);
        widget->setFixedSize(this->width() - 20, 39);
        //            widget->layout()->setAlignment(Qt::AlignTop);

        QLabel *label = new QLabel(widget);
        label->setText(alarma);
        label->setObjectName(alarma.replace(" ", "").trimmed());
        label->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
        label->setFont(font);

        widget->layout()->addWidget(label);

        //Este label es para rellenar espacio y que se vea bien al desplegar, no tiene ninguna funcion
        QLabel *label2 = new QLabel(widget);
        label2->setFixedSize(80,30);
        label2->setObjectName("l_blank_space_"+objName);
        widget->layout()->addWidget(label2);

        if(!hasChild(objName)){
            widget_notifications->layout()->addWidget(widget);
        }
    }

}
void MyWidgetAlarmAnimated::addHighPriorityAlarmsToWidget(){
    QString alarma;
    QFont font = this->font();
    font.setPointSize(14);
    foreach(alarma, listaAlarmas_AltaPrioridad){
        //        if(alarma == activeAlarm){
        //            continue;
        //        }
        if(listaAlarmas.contains(alarma)){
            transformOneToActive(alarma);
            continue;
        }
        QString objName = alarma;
        objName = "w_"+objName.replace(" ", "").trimmed();

        widget_notifications->setGeometry(widget_notifications->pos().x(),widget_notifications->pos().y(),
                                          widget_notifications->size().width(), widget_notifications->height() + 50);
        QWidget *widget = new QWidget(nullptr);
        widget->setStyleSheet("background-color: rgb("
                              + getStringBackgroundColor(QColor(Qt::white))+ ");"
                              +"color: rgb("
                              + getStringBackgroundColor(QColor(Qt::black))+ ");");
        QHBoxLayout *layout = new QHBoxLayout;
        layout->setContentsMargins(50,0,0,0);
        widget->setLayout(layout);

        widget->setObjectName(objName);
        widget->setFixedSize(this->width()-20, 39);
        widget->layout()->setAlignment(Qt::AlignVCenter);

        QLabel *label = new QLabel(widget);
        label->setText(alarma);
        label->setObjectName(alarma.replace(" ", "").trimmed());
        label->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
        label->setFont(font);

        widget->layout()->addWidget(label);

        QPushButton *button = new QPushButton(widget);
        QIcon icon(":/icons/clean.png");
        button->setObjectName("pb_cleaner_" + objName);
        button->setIcon(icon);
        button->setIconSize(QSize(40,30));
        button->setFixedSize(80,30);
        connect(button, &QPushButton::clicked, widget,
                &QWidget::deleteLater);
        connect(button, &QPushButton::clicked, this,
                &MyWidgetAlarmAnimated::resizeWidgetNotifications);

        widget->layout()->addWidget(button);

        connect(widget, &QWidget::destroyed, this,
                &MyWidgetAlarmAnimated::alarmaLimpiada);

        if(!hasChild(objName)){
            widget_notifications->layout()->addWidget(widget);
        }
    }

}
void MyWidgetAlarmAnimated::cleanHighPriorityAlarms(){
    QString alarma;
    foreach (alarma, listaAlarmas_AltaPrioridad) {
        removeAlarmAltaPriority(alarma);
    }
}

void MyWidgetAlarmAnimated::alarmaLimpiada(QObject *widget){
    QString name = widget->objectName();
    QString alarma;
    QString alarm_string;
    foreach (alarma, listaAlarmas_AltaPrioridad) {
        alarm_string = alarma;
        if(!listaAlarmas.contains(alarm_string)){
            alarma =  "w_"+alarma.replace(" ", "").trimmed();
            if(name == alarma){
                removeAlarmDeListaAltaPrioridad(alarm_string);
            }
        }
    }
}

void MyWidgetAlarmAnimated::resizeWidgetNotifications(){
    widget_notifications->setGeometry(widget_notifications->pos().x(), widget_notifications->pos().y(),
                                      widget_notifications->width(), widget_notifications->height() - 50);
    if(widget_notifications->geometry().height() <= 0){
        hideMenuAlarms();
    }
}


void MyWidgetAlarmAnimated::hideWidgetNotifications(){
    widget_notifications->hide();
}

void MyWidgetAlarmAnimated::hideMenuAlarms(){
    if(widget_notifications->height() > 0){
        animateWidgetDownToUp(widget_notifications);
    }else {
        widget_notifications->hide();
    }
    setChecked(false);
    emit showing_menu_alarms(false);
}

void MyWidgetAlarmAnimated::animateWidgetUpToDown(QWidget *widget, int anim_time){
    QRect endValue = widget->geometry();
    QRect startValue = QRect(endValue.x(), endValue.y()
                             ,endValue.width(), 80);

    QPropertyAnimation *animation = new QPropertyAnimation(widget, "geometry");
    animation->setDuration(anim_time);
    animation->setStartValue(startValue);
    animation->setEndValue(endValue);
    animation->start();
}
void MyWidgetAlarmAnimated::animateWidgetDownToUp(QWidget *widget, int anim_time){
    QRect startValue = widget->geometry();
    QRect endValue = QRect(startValue.x(), startValue.y()
                           ,startValue.width(), 0);

    QPropertyAnimation *animation = new QPropertyAnimation(widget, "geometry");
    animation->setDuration(anim_time);
    animation->setStartValue(startValue);
    animation->setEndValue(endValue);
    connect(animation, SIGNAL(finished()), widget, SLOT(hide()));
    animation->start();
}

void MyWidgetAlarmAnimated::setChecked(bool checked){
    if(checked){
        activated_state = true;

    }else{
        activated_state = false;
    }
}


void MyWidgetAlarmAnimated::deleteOneAlarm(QString alarm){
    alarm =  "w_"+alarm.replace(" ", "").trimmed();
    int c= widget_notifications->children().size();
    for (int i=0; i < c; i++) {
        QObject *obj = static_cast<QObject*>((widget_notifications->
                                              children().at(i)));
        if(obj->isWidgetType()){
            QWidget *widget = static_cast<QWidget*>(obj);
            if(widget){
                if(widget->objectName() == alarm){
                    widget->deleteLater();
                    resizeWidgetNotifications();
                }
            }
        }
    }
}
void MyWidgetAlarmAnimated::transformOneToUnActive(QString alarm){
    alarm =  "w_"+alarm.replace(" ", "").trimmed();
    int c= widget_notifications->children().size();
    for (int i=0; i < c; i++) {
        QObject *obj = static_cast<QObject*>((widget_notifications->
                                              children().at(i)));
        if(obj->isWidgetType()){
            QWidget *widget = static_cast<QWidget*>(obj);
            if(widget){
                if(widget->objectName() == alarm){
                    QString style= widget->styleSheet();
                    style.remove("background-color: rgb("
                                 + getStringBackgroundColor(color_high_priority)+ ");");
                    style.remove("color: rgb("
                                 + getStringBackgroundColor(QColor(Qt::white))+ ");");
                    style += "background-color: rgb("
                            + getStringBackgroundColor(QColor(Qt::white))+ ");";
                    style += "color: rgb("
                            + getStringBackgroundColor(QColor(Qt::black))+ ");";
                    widget->setStyleSheet(style);

                    QPushButton *button = new QPushButton(widget);
                    QIcon icon(":/icons/clean.png");
                    button->setObjectName("pb_cleaner_" + alarm);
                    button->setIcon(icon);
                    button->setIconSize(QSize(40,30));
                    button->setFixedSize(80,30);
                    connect(button, &QPushButton::clicked, widget,
                            &QWidget::deleteLater);
                    connect(button, &QPushButton::clicked, this,
                            &MyWidgetAlarmAnimated::resizeWidgetNotifications);

                    widget->layout()->addWidget(button);

                    connect(widget, &QWidget::destroyed, this,
                            &MyWidgetAlarmAnimated::alarmaLimpiada);

                    for (int i=0; i < widget->children().size(); i++) {
                        QObject *obj_2 = static_cast<QObject*>((widget->
                                                                children().at(i)));
                        if(obj_2->isWidgetType()){
                            QWidget *widget_2 = static_cast<QWidget*>(obj_2);
                            if(widget_2){
                                if(widget_2->objectName().contains("l_blank_space")){
                                    widget_2->deleteLater();
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
void MyWidgetAlarmAnimated::transformOneToActive(QString alarm){
    alarm =  "w_"+alarm.replace(" ", "").trimmed();
    int c= widget_notifications->children().size();
    for (int i=0; i < c; i++) {
        QObject *obj = static_cast<QObject*>((widget_notifications->
                                              children().at(i)));
        if(obj->isWidgetType()){
            QWidget *widget = static_cast<QWidget*>(obj);
            if(widget){
                if(widget->objectName() == alarm){
                    QString style= widget->styleSheet();
                    style.remove("background-color: rgb("
                                 + getStringBackgroundColor(QColor(Qt::white))+ ");");
                    style.remove("color: rgb("
                                 + getStringBackgroundColor(QColor(Qt::black))+ ");");
                    style += "background-color: rgb("
                            + getStringBackgroundColor(color_high_priority)+ ");";
                    style += "color: rgb("
                            + getStringBackgroundColor(QColor(Qt::white))+ ");";
                    widget->setStyleSheet(style);

                    disconnect(widget, &QWidget::destroyed, this,
                               &MyWidgetAlarmAnimated::alarmaLimpiada);

                    for (int i=0; i < widget->children().size(); i++) {
                        QObject *obj_2 = static_cast<QObject*>((widget->
                                                                children().at(i)));
                        if(obj_2->isWidgetType()){
                            QWidget *widget_2 = static_cast<QWidget*>(obj_2);
                            if(widget_2){
                                if(widget_2->objectName().contains("pb_cleaner")){
                                    widget_2->deleteLater();
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
bool MyWidgetAlarmAnimated::hasChild(QString n){
    int c= widget_notifications->children().size();
    for (int i=0; i < c; i++) {
        QObject *obj = static_cast<QObject*>((widget_notifications->
                                              children().at(i)));
        if(obj->isWidgetType()){
            QWidget *widget = static_cast<QWidget*>(obj);
            if(widget){
                if(widget->objectName() == n){
                    return true;
                }
            }
        }
    }
    return false;
}
void MyWidgetAlarmAnimated::deleteAllChilds(){
    QString alarma;
    salvaLista.clear();
    foreach(alarma, listaAlarmas)
    {
        salvaLista.append(alarma);
    }
    int c= widget_notifications->children().size();
    for (int i=0; i < c; i++) {
        QObject *obj = static_cast<QObject*>((widget_notifications->
                                              children().at(i)));
        if(obj->isWidgetType()){
            QWidget *widget = static_cast<QWidget*>(obj);
            if(widget){
                if(widget->objectName() != "l_alarm_text"
                        ){
                    widget->deleteLater();
                }else{
                    widget->setFixedSize(widget_notifications->size().width(), 0);
                }
            }
        }
    }
}


bool MyWidgetAlarmAnimated::isChecked(){
    return activated_state;
}
void MyWidgetAlarmAnimated::mouseMoveEvent(QMouseEvent *ev)
{
    emit mouseEntered(ev->pos());
}
