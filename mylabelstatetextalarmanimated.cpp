#include "mylabelstatetextalarmanimated.h"

#include <QTimer>
#include "globals_settings.h"
#include <QDebug>

MyLabelStateTextAlarmAnimated::MyLabelStateTextAlarmAnimated(QWidget *parent)
    :QLabel(parent)
{
    this->setMouseTracking(true);
    textAnimated = new MyTextAnimated(parent);
    //    textAnimated->setPixmap(QPixmap(":/icons/selection_point.png"));

    connect(this, SIGNAL(objectNameChanged(const QString&)), this, SLOT(setFotoInit(const QString&)));
    connect(textAnimated, SIGNAL(mouseLeftClicked()), this, SLOT(startAnimationFromChild()));
}

MyLabelStateTextAlarmAnimated::~MyLabelStateTextAlarmAnimated()
{
    //    delete animation;
}


void MyLabelStateTextAlarmAnimated::startAlarm(int interval){

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

void MyLabelStateTextAlarmAnimated::stopAlarm(){
    emit stopedAlarm();
    alarm_activated = false;
    disconnect(&timer_alarm, SIGNAL(timeout()), this, SLOT(changeColor()));
    timer_alarm.stop();
    currentState =  UNACTIVE_STATE;
    setTextString(defaultText);
    setTextColor(text_unactiveColor);
    if(QFile::exists(":/icons/" + info + "_on.png")){
        this->setPixmap(QPixmap(":/icons/" + info + "_off.png"));
    }
}

void MyLabelStateTextAlarmAnimated::changeColor(){
    if(currentState == ACTIVE_STATE){
        currentState =  UNACTIVE_STATE;
        setTextString(defaultText);
        setTextColor(text_unactiveColor);
        if(QFile::exists(":/icons/" + info + "_on.png")){
            this->setPixmap(QPixmap(":/icons/" + info + "_off.png"));
        }
    }else{
        currentState =  ACTIVE_STATE;
        setTextColor(text_activeColor);
        setTextString(activeText);
        if(QFile::exists(":/icons/" + info + "_on.png")){
            this->setPixmap(QPixmap(":/icons/" + info + "_on.png"));
        }
    }
}

void MyLabelStateTextAlarmAnimated::setBackgroundImage(const QString image_filename)
{
    if(QFile::exists(":/icons/" + image_filename + ".png")){
        this->setStyleSheet("border-image: url(:/icons/"+ image_filename +".png);");
    }
    else{
        qDebug()<<"No se ha creado icono de este label (image_filename.png)";
    }
}

void MyLabelStateTextAlarmAnimated::setActiveTextColor(QColor text_active_color, QColor text_unactive_color){
    if(text_active_color.isValid()){
        text_activeColor = text_active_color;
    }
    if(text_unactive_color.isValid()){
        text_unactiveColor = text_unactive_color;
    }
}
QColor MyLabelStateTextAlarmAnimated::getTextDefaultCurrent(){
    return text_unactiveColor;
}
QColor MyLabelStateTextAlarmAnimated::getTextActiveColor(){
    return text_activeColor;
}
void MyLabelStateTextAlarmAnimated::setTextColor(const QColor color){
    textAnimated->setTextColor(color);
}
QColor MyLabelStateTextAlarmAnimated::getTextColorCurrent(){
    return textAnimated->getTextColor();
}

QString MyLabelStateTextAlarmAnimated::getStringBackgroundColor(QColor color)
{
    QString c = QString::number(color.red()) + ","
            + QString::number(color.green()) + ","
            + QString::number(color.blue());

    return c;
}

void MyLabelStateTextAlarmAnimated::highlight()
{
    this->raise();
    textAnimated->raise();
}


void MyLabelStateTextAlarmAnimated::setActiveTextString(QString text)
{
//    textAnimated->setText(text);
    activeText = text;
}

void MyLabelStateTextAlarmAnimated::setDefautTextString(QString text)
{
//    textAnimated->setText(text);
    defaultText = text;
}

void MyLabelStateTextAlarmAnimated::setTextString(QString text)
{
    textAnimated->setText(text);
}

QString MyLabelStateTextAlarmAnimated::getActiveText(){
    return activeText;
}
QString MyLabelStateTextAlarmAnimated::getDefaultText(){
    return defaultText;
}
QString MyLabelStateTextAlarmAnimated::getText(){
    return textAnimated->text();
}

void MyLabelStateTextAlarmAnimated::setFotoInit(const QString& n)
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
    QTimer::singleShot(100, this, SLOT(setRadioButtonPos()));
}
void MyLabelStateTextAlarmAnimated::setAnimationInit()
{

    startValue = this->geometry();
    endValue = QRect(startValue.x()+anim_scale,startValue.y() +anim_scale
                     ,startValue.width() - anim_scale*2,startValue.height() - anim_scale*2);
    maxSize= this->maximumSize();
    if(((maxSize.width() +  anim_scale*2) < 10000) && ((maxSize.height() +anim_scale*2) < 10000)){
        this->setMaximumSize(maxSize.width() +  anim_scale*2, maxSize.height() + anim_scale*2);
    }
    animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(anim_time);
    animation->setStartValue(startValue);
    animation->setEndValue(endValue);
}
void MyLabelStateTextAlarmAnimated::setAnimationEnd()
{
    //    disconnect(animation, &QPropertyAnimation::finished, this, &MyLabelStateTextAlarmAnimated::setAnimationEnd);
    //    disconnect(animation, SIGNAL(finished()), this, SLOT(setAnimationEnd()));
    delete animation;
    animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(anim_time);
    animation->setStartValue(endValue);
    animation->setEndValue(startValue);
    connect(animation, SIGNAL(finished()), this, SLOT(finalizadaAnimacion()));
    animation->start();
}
void MyLabelStateTextAlarmAnimated::finalizadaAnimacion()
{
    disconnect(animation, SIGNAL(finished()), this, SLOT(finalizadaAnimacion()));
    this->setMaximumSize(maxSize);
    delete animation;
    animationOnGoing = false;
    QTimer::singleShot(50, this, SLOT(emitirClicked()));

    startValue = this->geometry();
}

void MyLabelStateTextAlarmAnimated::startAnimationFromChild()
{
    if(!animationOnGoing){
        if(!isChecked()){
            setChecked(true);
        }
        if(!startValue.isEmpty()){
            if(startValue.size() != this->geometry().size()){
                this->setGeometry(startValue);
            }
        }
        startValue = this->geometry();
        if(myanimationEnabled){
            startAnimation(0);
        }else{
            emit clicked();
        }
        //        textAnimated->startAnimation(); //Comentado porque fue el emisor de animacion
    }
}

void MyLabelStateTextAlarmAnimated::emitirClicked()
{
    emit clicked();
}

void MyLabelStateTextAlarmAnimated::startAnimation(int delay, int scale, int anim_tim)
{
    Q_UNUSED(delay);
    //hacer un single shot con delay
    anim_time = anim_tim;
    anim_scale = scale;
    setAnimationInit();
    animationOnGoing = true;
    connect(animation, SIGNAL(finished()), this, SLOT(setAnimationEnd()));
    animation->start();
    //    connect(animation, &QPropertyAnimation::finished, this, &MyLabelStateTextAlarmAnimated::setAnimationEnd);

}

void MyLabelStateTextAlarmAnimated::mousePressEvent(QMouseEvent *ev)
{
    emit pressEvent(ev);
    if(!animationOnGoing){
        if(!isChecked()){
            setChecked(true);
        }
        if(myanimationEnabled){
            startAnimation(0);
            textAnimated->startAnimation(0, 8);
        }else{
            emit clicked();
        }
    }
}

void MyLabelStateTextAlarmAnimated::setRadioButtonPos(){
    int pos_x = this->pos().x(), pos_y = this->pos().y(),
            w_textAnimated = static_cast<int>(static_cast<float>(textAnimated->size().width()) / 2),
            width_m = static_cast<int>(static_cast<float>(this->size().width()) / 2),
            height_m = static_cast<int>(static_cast<float>(this->size().height()) / 2);

    textAnimated->move(pos_x + width_m - w_textAnimated, pos_y + height_m -3);
    textAnimated->show();
    textAnimated->raise();
}

void MyLabelStateTextAlarmAnimated::setChecked(bool checked){
    if(checked){
        activated_state = true;
        setRadioButtonPos();
//        if(QFile::exists(":/icons/" + info + "_on.png")){  ///cambiar de foto al chequear (on)
//            this->setPixmap(QPixmap(":/icons/" + info + "_on.png"));
//        }
        if(myanimationEnabled){
            if(!textAnimated->isOngoingAnimation())
                textAnimated->startAnimation(0, 8);
        }
    }else{
        activated_state = false;
//        if(QFile::exists(":/icons/" + info + "_off.png")){  ///cambiar de foto al chequear (off)
//            this->setPixmap(QPixmap(":/icons/" + info + "_off.png"));
//        }
    }
}
bool MyLabelStateTextAlarmAnimated::isChecked(){
    return activated_state;
}


