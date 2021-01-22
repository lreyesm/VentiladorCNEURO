#include "myradiobuttonanimated.h"
#include <QTimer>
#include "globals_settings.h"

MyRadioButtonAnimated::MyRadioButtonAnimated(QWidget *parent)
    :QLabel(parent)
{
    this->setMouseTracking(true);
    radioPicture = new MyPointAnimated(parent);
    radioPicture->setPixmap(QPixmap(":/icons/radio_button_off.png"));
    radioPicture->setScaledContents(true);
    radioPicture->setFixedSize(90,90);

    connect(this, SIGNAL(objectNameChanged(const QString&)), this, SLOT(setFotoInit(const QString&)));
    connect(radioPicture, SIGNAL(mouseLeftClicked()), this, SLOT(startAnimationFromChild()));
}

MyRadioButtonAnimated::~MyRadioButtonAnimated()
{
    //    delete animation;
}

void MyRadioButtonAnimated::setFotoInit(const QString& n)
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
void MyRadioButtonAnimated::setAnimationInit()
{

    startValue = this->geometry();
    endValue = QRect(startValue.x()/*-anim_scale*/,startValue.y() -anim_scale
                     ,startValue.width()/* +anim_scale*2*/,startValue.height() /*+anim_scale*2*/);
    maxSize= this->maximumSize();
    this->setMaximumSize(maxSize.width() +  anim_scale*2, maxSize.height() +anim_scale*2);
    animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(anim_time);
    animation->setStartValue(startValue);
    animation->setEndValue(endValue);
}
void MyRadioButtonAnimated::setAnimationEnd()
{
    //    disconnect(animation, &QPropertyAnimation::finished, this, &MyRadioButtonAnimated::setAnimationEnd);
    //    disconnect(animation, SIGNAL(finished()), this, SLOT(setAnimationEnd()));
    animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(anim_time);
    animation->setStartValue(endValue);
    animation->setEndValue(startValue);
    connect(animation, SIGNAL(finished()), this, SLOT(finalizadaAnimacion()));
    animation->start();
}
void MyRadioButtonAnimated::finalizadaAnimacion()
{
    disconnect(animation, SIGNAL(finished()), this, SLOT(finalizadaAnimacion()));
    this->setMaximumSize(maxSize);
    delete animation;
    animationOnGoing = false;
    QTimer::singleShot(50, this, SLOT(emitirClicked()));
    //    emit clicked();
    //    emit mouseLeftClicked();
    startValue = this->geometry();
}

void MyRadioButtonAnimated::startAnimationFromChild()
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
            //        radioPicture->startAnimation(); //Comentado porque fue el emisor de animacion
        }else{
            emit clicked();
        }
    }
}

void MyRadioButtonAnimated::emitirClicked()
{
    emit clicked();
}

void MyRadioButtonAnimated::startAnimation(int delay, int scale, int anim_tim)
{
    Q_UNUSED(delay);
    //hacer un single shot con delay
    anim_time = anim_tim;
    anim_scale = scale;
    setAnimationInit();
    animationOnGoing = true;
    connect(animation, SIGNAL(finished()), this, SLOT(setAnimationEnd()));
    animation->start();
    //    connect(animation, &QPropertyAnimation::finished, this, &MyRadioButtonAnimated::setAnimationEnd);

}

void MyRadioButtonAnimated::mousePressEvent(QMouseEvent *ev)
{
    Q_UNUSED(ev);
    if(!animationOnGoing){
        if(!isChecked()){
            setChecked(true);
        }
        if(myanimationEnabled){
            startAnimation(0);
            radioPicture->startAnimation(0, 8);
        }else{
            emit clicked();
        }
    }

}

void MyRadioButtonAnimated::setRadioButtonPos(){
    int pos_x = this->pos().x(), pos_y = this->pos().y(),
            w_radioPicture = static_cast<int>(static_cast<float>(radioPicture->size().width() / 2)),
            h_radioPicture = static_cast<int>(static_cast<float>(radioPicture->size().height() / 2)),
            width_m = static_cast<int>((static_cast<float>(this->size().width() / 2))),
            height_m = static_cast<int>((static_cast<float>(this->size().height())));

    radioPicture->move(pos_x + width_m - w_radioPicture, pos_y + height_m - h_radioPicture/2);
    radioPicture->show();
    radioPicture->raise();
}

void MyRadioButtonAnimated::setChecked(bool checked){
    if(checked){
        activated_state = true;
        setRadioButtonPos();
        radioPicture->setPixmap(QPixmap(":/icons/radio_button_on.png"));
        if(QFile::exists(":/icons/" + info + "_on.png")){
            this->setPixmap(QPixmap(":/icons/" + info + "_on.png"));
        }
        if(myanimationEnabled){
            if(!radioPicture->isOngoingAnimation())
                radioPicture->startAnimation(0, 8);
        }
    }else{
        activated_state = false;
        radioPicture->setPixmap(QPixmap(":/icons/radio_button_off.png"));
        if(QFile::exists(":/icons/" + info + "_off.png")){
            this->setPixmap(QPixmap(":/icons/" + info + "_off.png"));
        }
    }
}
bool MyRadioButtonAnimated::isChecked(){
    return activated_state;
}
