#include "mylabelstatetextanimated.h"
#include <QTimer>
#include "globals_settings.h"

MyLabelStateTextAnimated::MyLabelStateTextAnimated(QWidget *parent)
    :QLabel(parent)
{
    this->setMouseTracking(true);
    textAnimated = new MyTextAnimated(parent);
    //    textAnimated->setPixmap(QPixmap(":/icons/selection_point.png"));

    connect(this, SIGNAL(objectNameChanged(const QString&)), this, SLOT(setFotoInit(const QString&)));
    connect(textAnimated, SIGNAL(mouseLeftClicked()), this, SLOT(startAnimationFromChild()));
}

MyLabelStateTextAnimated::~MyLabelStateTextAnimated()
{
    //    delete animation;
}

void MyLabelStateTextAnimated::highlight()
{
    this->raise();
    textAnimated->raise();
}


void MyLabelStateTextAnimated::setTextString(QString text)
{
    textAnimated->setText(text);
}


QString MyLabelStateTextAnimated::getText(){
    return textAnimated->text();
}

void MyLabelStateTextAnimated::setFotoInit(const QString& n)
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
void MyLabelStateTextAnimated::setAnimationInit()
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
void MyLabelStateTextAnimated::setAnimationEnd()
{
    //    disconnect(animation, &QPropertyAnimation::finished, this, &MyLabelStateTextAnimated::setAnimationEnd);
    //    disconnect(animation, SIGNAL(finished()), this, SLOT(setAnimationEnd()));
    delete animation;
    animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(anim_time);
    animation->setStartValue(endValue);
    animation->setEndValue(startValue);
    connect(animation, SIGNAL(finished()), this, SLOT(finalizadaAnimacion()));
    animation->start();
}
void MyLabelStateTextAnimated::finalizadaAnimacion()
{
    disconnect(animation, SIGNAL(finished()), this, SLOT(finalizadaAnimacion()));
    this->setMaximumSize(maxSize);
    delete animation;
    animationOnGoing = false;
    QTimer::singleShot(50, this, SLOT(emitirClicked()));

    startValue = this->geometry();
}

void MyLabelStateTextAnimated::startAnimationFromChild()
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

void MyLabelStateTextAnimated::emitirClicked()
{
    emit clicked();
}

void MyLabelStateTextAnimated::startAnimation(int delay, int scale, int anim_tim)
{
    Q_UNUSED(delay);
    //hacer un single shot con delay
    anim_time = anim_tim;
    anim_scale = scale;
    setAnimationInit();
    animationOnGoing = true;
    connect(animation, SIGNAL(finished()), this, SLOT(setAnimationEnd()));
    animation->start();
    //    connect(animation, &QPropertyAnimation::finished, this, &MyLabelStateTextAnimated::setAnimationEnd);

}

void MyLabelStateTextAnimated::mousePressEvent(QMouseEvent *ev)
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


void MyLabelStateTextAnimated::setTextColor(const QColor color){
    textAnimated->setTextColor(color);
}
void MyLabelStateTextAnimated::setRadioButtonPos(){
    int pos_x = this->pos().x(), pos_y = this->pos().y(),
            w_textAnimated = static_cast<int>(static_cast<float>(textAnimated->size().width()) / 2),
            width_m = static_cast<int>(static_cast<float>(this->size().width()) / 2),
            height_m = static_cast<int>(static_cast<float>(this->size().height()) / 2);

    textAnimated->move(pos_x + width_m - w_textAnimated, pos_y + height_m -3);
    textAnimated->show();
    textAnimated->raise();
}

void MyLabelStateTextAnimated::setChecked(bool checked){
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
bool MyLabelStateTextAnimated::isChecked(){
    return activated_state;
}


