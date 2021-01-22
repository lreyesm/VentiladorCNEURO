#include "mylabellongpressanimated.h"
#include <QDebug>


MyLabelLongPressAnimated::MyLabelLongPressAnimated(QWidget *parent)
    :QLabel(parent)
{
    //    this->setMouseTracking(true);
    //    connect(this, SIGNAL(objectNameChanged(const QString&)), this, SLOT(setFotoInit(const QString&)));
}

MyLabelLongPressAnimated::~MyLabelLongPressAnimated()
{
    //    delete animation;
}

void MyLabelLongPressAnimated::setBackgroundImage(const QString image_filename)
{
    if(QFile::exists(":/icons/" + image_filename + ".png")){
        this->setStyleSheet("border-image: url(:/icons/"+ image_filename +".png);");
    }
    else{
        qDebug()<<"No se ha creado icono de este label (image_filename.png)";
    }
}

void MyLabelLongPressAnimated::hideChilds(){
    //    menu_expanded->hide();
}
void MyLabelLongPressAnimated::setFotoInit(const QString& n)
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
void MyLabelLongPressAnimated::setAnimationInit()
{

    int anim_scale_width = static_cast<int>(this->width() * static_cast<float>(anim_scale)/100);
    int anim_scale_height = static_cast<int>(this->height() * static_cast<float>(anim_scale)/100);

    startValue = this->geometry();
    endValue = QRect(startValue.x()+anim_scale_width,startValue.y() +anim_scale_height
                     ,startValue.width() - anim_scale_width*2,startValue.height() - anim_scale_height*2);
    minSize= this->minimumSize();
    if(((minSize.width() -  anim_scale_width*2) > 0) && ((minSize.height() - anim_scale_height*2) > 0)){
        this->setMinimumSize(minSize.width() -  anim_scale_width*2, minSize.height() - anim_scale_height*2);
    }
    animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(anim_time);
    animation->setStartValue(startValue);
    animation->setEndValue(endValue);
}
void MyLabelLongPressAnimated::setAnimationEnd()
{
    //    disconnect(animation, &QPropertyAnimation::finished, this, &MyLabelLongPressAnimated::setAnimationEnd);
    //    disconnect(animation, SIGNAL(finished()), this, SLOT(setAnimationEnd()));
    animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(anim_time);
    animation->setStartValue(endValue);
    animation->setEndValue(startValue);
    connect(animation, SIGNAL(finished()), this, SLOT(finalizadaAnimacion()));
    animation->start();
}
void MyLabelLongPressAnimated::finalizadaAnimacion()
{
    timer.stop();
    disconnect(animation, SIGNAL(finished()), this, SLOT(finalizadaAnimacion()));

    this->setMinimumSize(minSize);
    animation->deleteLater();

    emit clicked();
    emit send_text(this->text());
    emit mouseLeftClicked(this->objectName());
    //    qDebug()<<"emitirClicked: ----------------------------------";
    animationOnGoing = false;

    startValue = this->geometry();
}
void MyLabelLongPressAnimated::emitirClicked()
{
    if(state_pressed){
        timer.setInterval(PRESS_HOLD_ACTIVATIONS);
        emit clicked();
        //        qDebug()<<"emitirClicked: ----------------------------------";
    }
}

void MyLabelLongPressAnimated::startAnimation(int delay, int scale, int anim_tim)
{
    Q_UNUSED(delay);
    animationOnGoing = true;
    anim_time = anim_tim;
    anim_scale = scale;
    setAnimationInit();

    animation->start();

}

void MyLabelLongPressAnimated::mousePressEvent(QMouseEvent *ev)
{
    Q_UNUSED(ev);
    state_pressed = true;
    //    qDebug()<<"pressed: ----------------------------------";

    if(myanimationEnabled){
        if(!animationOnGoing){
            disconnect(&timer, &QTimer::timeout, this, &MyLabelLongPressAnimated::emitirClicked);
            timer.stop();
            timer.setInterval(DELAY_PRESS_HOLD);
            connect(&timer, &QTimer::timeout, this, &MyLabelLongPressAnimated::emitirClicked);
            timer.start();
            if(!startValue.isEmpty()){
                if(startValue.size() != this->geometry().size()){
                    this->setGeometry(startValue);
                }
            }
            startValue = this->geometry();
            startAnimation(0);
        }
    }
    else{

    }
}

void MyLabelLongPressAnimated::mouseReleaseEvent(QMouseEvent *ev)
{
    Q_UNUSED(ev);
    emit release();
    state_pressed = false;
    disconnect(&timer, &QTimer::timeout, this, &MyLabelLongPressAnimated::emitirClicked);
    timer.stop();
    //    qDebug()<<"released: ----------------------------------";
    if(myanimationEnabled){
        setAnimationEnd();
    }
    else{
        emit clicked();
    }
}

void MyLabelLongPressAnimated::setChecked(bool checked){
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
bool MyLabelLongPressAnimated::isChecked(){
    return activated_state;
}
void MyLabelLongPressAnimated::mouseMoveEvent(QMouseEvent *ev)
{
    emit mouseEntered(ev->pos());
}
