#include "mylabelalarmanimated.h"
#include <QTimer>
#include <QDebug>


MyLabelAlarmAnimated::MyLabelAlarmAnimated(QWidget *parent)
    :QLabel(parent)
{
    //    this->setMouseTracking(true);
    //    connect(this, SIGNAL(objectNameChanged(const QString&)), this, SLOT(setFotoInit(const QString&)));
}
MyLabelAlarmAnimated::~MyLabelAlarmAnimated()
{
    //    delete animation;
}

void MyLabelAlarmAnimated::mousePressEvent(QMouseEvent *event){
//    qDebug()<<"MyLabelAlarmAnimated mousePressEvent ->    x: " + QString::number(event->x()) + "   y: "+QString::number(event->y());
    QWidget::mousePressEvent(event);
}
void MyLabelAlarmAnimated::mouseMoveEvent(QMouseEvent *event){
//    qDebug()<<"MyLabelAlarmAnimated mouseMoveEvent ->    x: " + QString::number(event->x()) + "   y: "+QString::number(event->y());
     QWidget::mouseMoveEvent(event);
}
void MyLabelAlarmAnimated::mouseReleaseEvent(QMouseEvent *event){
     qDebug()<<"MyLabelAlarmAnimated mouseReleaseEvent ->    x: " + QString::number(event->x()) + "   y: "+QString::number(event->y());
     QWidget::mouseReleaseEvent(event);
}

void MyLabelAlarmAnimated::startAlarm(int interval){

    if(alarm_activated){
        return;
    }
    emit startedAlarm(interval);
    isConfigured = true;
    alarm_activated = true;
    disconnect(&timer_alarm, SIGNAL(timeout()), this, SLOT(changeColor()));
    connect(&timer_alarm, SIGNAL(timeout()), this, SLOT(changeColor()));
    currentColor =  QColor(Qt::transparent);
    this->setStyleSheet(this->styleSheet().remove("background-color: rgb("
                                                  + getStringBackgroundColor(activeColor)  +
                                                 "); color: rgb(" + getStringBackgroundColor(text_activeColor) + ");"));
    timer_alarm.stop();
    timer_alarm.setInterval(interval);
    timer_alarm.start();
}

void MyLabelAlarmAnimated::stopAlarm(){
    emit stopedAlarm();
    isConfigured = false;
    alarm_activated = false;
    disconnect(&timer_alarm, SIGNAL(timeout()), this, SLOT(changeColor()));
    timer_alarm.stop();
    this->setStyleSheet("");
}

void MyLabelAlarmAnimated::setBackgroundColor(QColor color){
    if(isConfigured){
    if(color == QColor(Qt::transparent)){
        currentColor = activeColor;
        changeColor();
    }
    else{
        currentColor = QColor(Qt::transparent);
        changeColor();
    }
    }
}

void MyLabelAlarmAnimated::changeColor(){
    if(currentColor == activeColor){
        currentColor =  QColor(Qt::transparent);
        this->setStyleSheet(this->styleSheet().remove("background-color: rgb("
                                                      + getStringBackgroundColor(activeColor)  +
                                                     "); color: rgb(" + getStringBackgroundColor(text_activeColor) + ");"));
    }else{
        currentColor =  activeColor;
        this->setStyleSheet(this->styleSheet() + "background-color: rgb("
                             + getStringBackgroundColor(activeColor)   +
                            "); color: rgb(" + getStringBackgroundColor(text_activeColor) + ");");
    }
}

void MyLabelAlarmAnimated::setBackgroundImage(const QString image_filename)
{
    if(QFile::exists(":/icons/" + image_filename + ".png")){
        this->setStyleSheet("border-image: url(:/icons/"+ image_filename +".png);");
    }
    else{
        qDebug()<<"No se ha creado icono de este label (image_filename.png)";
    }
}

void MyLabelAlarmAnimated::setConfigure(){
    isConfigured = true;
}

void MyLabelAlarmAnimated::setActiveColor(QColor color, QColor text_color){
    isConfigured = true;
    if(color.isValid()){
        activeColor = color;
    }
    if(text_color.isValid()){
        text_activeColor = text_color;
    }
}

QString MyLabelAlarmAnimated::getStringBackgroundColor(QColor color)
{
    QString c = QString::number(color.red()) + ","
            + QString::number(color.green()) + ","
            + QString::number(color.blue());

    return c;
}

void MyLabelAlarmAnimated::hideChilds(){
    //    menu_expanded->hide();
}
void MyLabelAlarmAnimated::setFotoInit(const QString& n)
{
    disconnect(this, SIGNAL(objectNameChanged(const QString&)), this, SLOT(setFotoInit(const QString&)));
    info = n;
    if(!info.isEmpty()){
        if(info.contains("_")){
            QStringList name = info.split("_");
            if(name.size() >= 2){
                name.removeAt(0);
                info = name.join("_").trimmed();
            }
        }
        if(QFile::exists(":/icons/" + info + "_off.png")){
            this->setPixmap(QPixmap(":/icons/" + info + "_off.png"));
        }
    }
}
void MyLabelAlarmAnimated::setAnimationInit()
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
void MyLabelAlarmAnimated::setAnimationEnd()
{
    //    disconnect(animation, &QPropertyAnimation::finished, this, &MyLabelAlarmAnimated::setAnimationEnd);
    //    disconnect(animation, SIGNAL(finished()), this, SLOT(setAnimationEnd()));
    delete animation;
    animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(anim_time);
    animation->setStartValue(endValue);
    animation->setEndValue(startValue);
    connect(animation, SIGNAL(finished()), this, SLOT(finalizadaAnimacion()));
    animation->start();
}
void MyLabelAlarmAnimated::finalizadaAnimacion()
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
void MyLabelAlarmAnimated::emitirClicked()
{
    emit clicked();
    emit mouseLeftClicked(this->objectName());
}

void MyLabelAlarmAnimated::startAnimation(int delay, int scale, int anim_tim)
{
    Q_UNUSED(delay);
    //hacer un single shot con delay
    //    setScaledContents(true);
    anim_time = anim_tim;
    anim_scale = scale;
    setAnimationInit();
    animationOnGoing = true;
    connect(animation, SIGNAL(finished()), this, SLOT(setAnimationEnd()));
    animation->start();
    //    connect(animation, &QPropertyAnimation::finished, this, &MyLabelAlarmAnimated::setAnimationEnd);

}

void MyLabelAlarmAnimated::setChecked(bool checked){
    if(checked){
        activated_state = true;
        if(QFile::exists(":/icons/" + info + "_on.png")){
            this->setPixmap(QPixmap(":/icons/" + info + "_on.png"));
        }
    }else{
        activated_state = false;
        if(QFile::exists(":/icons/" + info + "_off.png")){
            this->setPixmap(QPixmap(":/icons/" + info + "_off.png"));
        }
    }
}
bool MyLabelAlarmAnimated::isChecked(){
    return activated_state;
}
