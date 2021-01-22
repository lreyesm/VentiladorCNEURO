#include "mylabelalarmphotoanimated.h"

#include <QTimer>
#include <QDebug>


MyLabelAlarmPhotoAnimated::MyLabelAlarmPhotoAnimated(QWidget *parent)
    :QLabel(parent)
{
    //    this->setMouseTracking(true);
    connect(this, SIGNAL(objectNameChanged(const QString&)), this, SLOT(setFotoInit(const QString&)));
}
MyLabelAlarmPhotoAnimated::~MyLabelAlarmPhotoAnimated()
{
    //    delete animation;
}
void MyLabelAlarmPhotoAnimated::setFotoInit(const QString& n)
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

void MyLabelAlarmPhotoAnimated::mousePressEvent(QMouseEvent *event){
    //    qDebug()<<"MyLabelAlarmPhotoAnimated mousePressEvent ->    x: " + QString::number(event->x()) + "   y: "+QString::number(event->y());
    QWidget::mousePressEvent(event);
}
void MyLabelAlarmPhotoAnimated::mouseMoveEvent(QMouseEvent *event){
    //    qDebug()<<"MyLabelAlarmPhotoAnimated mouseMoveEvent ->    x: " + QString::number(event->x()) + "   y: "+QString::number(event->y());
    QWidget::mouseMoveEvent(event);
}
void MyLabelAlarmPhotoAnimated::mouseReleaseEvent(QMouseEvent *event){
    qDebug()<<"MyLabelAlarmPhotoAnimated mouseReleaseEvent ->    x: " + QString::number(event->x()) + "   y: "+QString::number(event->y());
    QWidget::mouseReleaseEvent(event);
}

void MyLabelAlarmPhotoAnimated::startAlarm(int interval){

    if(alarm_activated){
        return;
    }
    emit startedAlarm(interval);
    alarm_activated = true;
    isConfigure = true;
    disconnect(&timer_alarm, SIGNAL(timeout()), this, SLOT(changeColor()));
    connect(&timer_alarm, SIGNAL(timeout()), this, SLOT(changeColor()));
    timer_alarm.stop();
    timer_alarm.setInterval(interval);
    timer_alarm.start();
}

void MyLabelAlarmPhotoAnimated::stopAlarm(){
    emit stopedAlarm();
    alarm_activated = false;
    isConfigure = false;
    disconnect(&timer_alarm, SIGNAL(timeout()), this, SLOT(changeColor()));
    timer_alarm.stop();
    currentState = UNACTIVE_STATE;
    if(QFile::exists(":/icons/" + info + "_off.png")){
        this->setPixmap(QPixmap(":/icons/" + info + "_off.png"));
    }
}

void MyLabelAlarmPhotoAnimated::setBackgroundColor(QColor color){
    if(isConfigure){
        if(color == QColor(Qt::transparent)){
            currentState = ACTIVE_STATE;
            changeColor();
        }
        else{
            currentState = UNACTIVE_STATE;
            changeColor();
        }
    }
}
void MyLabelAlarmPhotoAnimated::setConfigure(){
    isConfigure = true;
}
void MyLabelAlarmPhotoAnimated::changeColor(){
    if(currentState == ACTIVE_STATE){
        currentState = UNACTIVE_STATE;
        if(QFile::exists(":/icons/" + info + "_off.png")){
            this->setPixmap(QPixmap(":/icons/" + info + "_off.png"));
        }
    }else{
        currentState = ACTIVE_STATE;
        if(QFile::exists(":/icons/" + info + "_on.png")){
            this->setPixmap(QPixmap(":/icons/" + info + "_on.png"));
        }
    }
}

void MyLabelAlarmPhotoAnimated::setBackgroundImage(const QString image_filename)
{
    if(QFile::exists(":/icons/" + image_filename + ".png")){
        this->setStyleSheet("border-image: url(:/icons/"+ image_filename +".png);");
    }
    else{
        qDebug()<<"No se ha creado icono de este label (image_filename.png)";
    }
}

QString MyLabelAlarmPhotoAnimated::getStringBackgroundColor(QColor color)
{
    QString c = QString::number(color.red()) + ","
            + QString::number(color.green()) + ","
            + QString::number(color.blue());

    return c;
}

void MyLabelAlarmPhotoAnimated::hideChilds(){
    //    menu_expanded->hide();
}

void MyLabelAlarmPhotoAnimated::setAnimationInit()
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
void MyLabelAlarmPhotoAnimated::setAnimationEnd()
{
    //    disconnect(animation, &QPropertyAnimation::finished, this, &MyLabelAlarmPhotoAnimated::setAnimationEnd);
    //    disconnect(animation, SIGNAL(finished()), this, SLOT(setAnimationEnd()));
    delete animation;
    animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(anim_time);
    animation->setStartValue(endValue);
    animation->setEndValue(startValue);
    connect(animation, SIGNAL(finished()), this, SLOT(finalizadaAnimacion()));
    animation->start();
}
void MyLabelAlarmPhotoAnimated::finalizadaAnimacion()
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
void MyLabelAlarmPhotoAnimated::emitirClicked()
{
    emit clicked();
    emit mouseLeftClicked(this->objectName());
}

void MyLabelAlarmPhotoAnimated::startAnimation(int delay, int scale, int anim_tim)
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
    //    connect(animation, &QPropertyAnimation::finished, this, &MyLabelAlarmPhotoAnimated::setAnimationEnd);

}

void MyLabelAlarmPhotoAnimated::setChecked(bool checked){
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
bool MyLabelAlarmPhotoAnimated::isChecked(){
    return activated_state;
}
