#include "mylabelalarmphototextanimated.h"

#include <QTimer>
#include <QDebug>

MyLabelAlarmPhotoTextAnimated::MyLabelAlarmPhotoTextAnimated(QWidget *parent)
    :QLabel(parent)
{
    //    this->setMouseTracking(true);
        connect(this, SIGNAL(objectNameChanged(const QString&)), this, SLOT(setFotoInit(const QString&)));
}
MyLabelAlarmPhotoTextAnimated::~MyLabelAlarmPhotoTextAnimated()
{
    //    delete animation;
}
void MyLabelAlarmPhotoTextAnimated::setFotoInit(const QString& n)
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
            this->setStyleSheet(QString("border-image: url(:/icons/" + info + "_off.png"));
        }
    }
}

void MyLabelAlarmPhotoTextAnimated::mousePressEvent(QMouseEvent *event){
//    qDebug()<<"MyLabelAlarmPhotoTextAnimated mousePressEvent ->    x: " + QString::number(event->x()) + "   y: "+QString::number(event->y());
    QWidget::mousePressEvent(event);
}
void MyLabelAlarmPhotoTextAnimated::mouseMoveEvent(QMouseEvent *event){
//    qDebug()<<"MyLabelAlarmPhotoTextAnimated mouseMoveEvent ->    x: " + QString::number(event->x()) + "   y: "+QString::number(event->y());
     QWidget::mouseMoveEvent(event);
}
void MyLabelAlarmPhotoTextAnimated::mouseReleaseEvent(QMouseEvent *event){
     qDebug()<<"MyLabelAlarmPhotoTextAnimated mouseReleaseEvent ->    x: " + QString::number(event->x()) + "   y: "+QString::number(event->y());
     QWidget::mouseReleaseEvent(event);
}

void MyLabelAlarmPhotoTextAnimated::startAlarm(int interval){

    if(alarm_activated){
        return;
    }
    emit startedAlarm(interval);
    alarm_activated = true;
    disconnect(&timer_alarm, SIGNAL(timeout()), this, SLOT(changeColor()));
    connect(&timer_alarm, SIGNAL(timeout()), this, SLOT(changeColor()));
    timer_alarm.stop();
    timer_alarm.setInterval(interval);
    timer_alarm.start();
}

void MyLabelAlarmPhotoTextAnimated::stopAlarm(){
    emit stopedAlarm();
    alarm_activated = false;
    disconnect(&timer_alarm, SIGNAL(timeout()), this, SLOT(changeColor()));
    timer_alarm.stop();
    currentState = UNACTIVE_STATE;
    if(QFile::exists(":/icons/" + info + "_off.png")){
        this->setStyleSheet(QString("border-image: url(:/icons/" + info +"_off.png);"
                                    "color: rgb(" + getStringBackgroundColor(text_unactiveColor) + ");"));

    }
}

bool MyLabelAlarmPhotoTextAnimated::isActiveState(){
    if(currentState == ACTIVE_STATE){
        return true;
    }else{
        return false;
    }
}

void MyLabelAlarmPhotoTextAnimated::setPhotoColor(QColor color){
    if(color == color_medium_priority || color == color_low_priority
            || color == color_alarm_notifications){
        currentState = UNACTIVE_STATE;
        changeColor();
    }
    else{
        currentState = ACTIVE_STATE;
        changeColor();
    }
}
void MyLabelAlarmPhotoTextAnimated::changeColor(){
    if(currentState == ACTIVE_STATE){
        currentState = UNACTIVE_STATE;
        if(QFile::exists(":/icons/" + info + "_off.png")){//icono blanco
            this->setStyleSheet(QString("border-image: url(:/icons/" + info +"_off.png);"
                                        "color: rgb(" + getStringBackgroundColor(text_unactiveColor) + ");"));
        }
    }else{
        currentState = ACTIVE_STATE;
        if(QFile::exists(":/icons/" + info + "_on.png")){ //icono negro
            this->setStyleSheet(QString("border-image: url(:/icons/" + info +"_on.png);"
                                        "color: rgb(" + getStringBackgroundColor(text_activeColor) + ");"));

        }
    }
}

void MyLabelAlarmPhotoTextAnimated::setBackgroundImage(const QString image_filename)
{
    if(QFile::exists(":/icons/" + image_filename + ".png")){
        this->setStyleSheet("border-image: url(:/icons/"+ image_filename +".png);");
    }
    else{
        qDebug()<<"No se ha creado icono de este label (image_filename.png)";
    }
}

QString MyLabelAlarmPhotoTextAnimated::getStringBackgroundColor(QColor color)
{
    QString c = QString::number(color.red()) + ","
            + QString::number(color.green()) + ","
            + QString::number(color.blue());

    return c;
}

void MyLabelAlarmPhotoTextAnimated::hideChilds(){
    //    menu_expanded->hide();
}

void MyLabelAlarmPhotoTextAnimated::setAnimationInit()
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
void MyLabelAlarmPhotoTextAnimated::setAnimationEnd()
{
    //    disconnect(animation, &QPropertyAnimation::finished, this, &MyLabelAlarmPhotoTextAnimated::setAnimationEnd);
    //    disconnect(animation, SIGNAL(finished()), this, SLOT(setAnimationEnd()));
    delete animation;
    animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(anim_time);
    animation->setStartValue(endValue);
    animation->setEndValue(startValue);
    connect(animation, SIGNAL(finished()), this, SLOT(finalizadaAnimacion()));
    animation->start();
}
void MyLabelAlarmPhotoTextAnimated::finalizadaAnimacion()
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
void MyLabelAlarmPhotoTextAnimated::emitirClicked()
{
    emit clicked();
    emit mouseLeftClicked(this->objectName());
}

void MyLabelAlarmPhotoTextAnimated::startAnimation(int delay, int scale, int anim_tim)
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
    //    connect(animation, &QPropertyAnimation::finished, this, &MyLabelAlarmPhotoTextAnimated::setAnimationEnd);

}

void MyLabelAlarmPhotoTextAnimated::setChecked(bool checked){
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
bool MyLabelAlarmPhotoTextAnimated::isChecked(){
    return activated_state;
}
