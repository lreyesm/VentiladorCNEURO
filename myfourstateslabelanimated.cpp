#include "myfourstateslabelanimated.h"

#include <QTimer>


MyFourStatesLabelAnimated::MyFourStatesLabelAnimated(QWidget *parent)
    :QLabel(parent)
{
    this->setMouseTracking(true);
    connect(this, SIGNAL(objectNameChanged(const QString&)), this, SLOT(setFotoInit(const QString&)));
}

MyFourStatesLabelAnimated::~MyFourStatesLabelAnimated()
{
    //    delete animation;
}


bool MyFourStatesLabelAnimated::isFourthState(){
    if(current_state == FOURTH_STATE){
        return true;
    }
    else{
        return false;
    }
}

void MyFourStatesLabelAnimated::setFotoInit(const QString& n)
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
void MyFourStatesLabelAnimated::setAnimationInit()
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
void MyFourStatesLabelAnimated::setAnimationEnd()
{
    //    disconnect(animation, &QPropertyAnimation::finished, this, &MyFourStatesLabelAnimated::setAnimationEnd);
    //    disconnect(animation, SIGNAL(finished()), this, SLOT(setAnimationEnd()));
    delete animation;
    animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(anim_time);
    animation->setStartValue(endValue);
    animation->setEndValue(startValue);
    connect(animation, SIGNAL(finished()), this, SLOT(finalizadaAnimacion()));
    animation->start();
}
void MyFourStatesLabelAnimated::finalizadaAnimacion()
{
    disconnect(animation, SIGNAL(finished()), this, SLOT(finalizadaAnimacion()));
    this->setMinimumSize(minSize);
    delete animation;

    QTimer::singleShot(50, this, SLOT(emitirClicked()));

    startValue = this->geometry();
}

void MyFourStatesLabelAnimated::startAnimationFromChild()
{
    if(!animationOnGoing){
        if(!isChecked()){
            setChecked(true);
        }
        startAnimation(true);
    }
}

void MyFourStatesLabelAnimated::emitirClicked()
{
    animationOnGoing = false;
    if(emit_enabled){
        emit clicked();
        emit send_text(this->text());
    }
}

void MyFourStatesLabelAnimated::startAnimation(bool emit_clicked, int scale, int anim_tim)
{
    //hacer un single shot con delay
    animationOnGoing = true;
    emit_enabled = emit_clicked;
    anim_time = anim_tim;
    anim_scale = scale;
    setAnimationInit();
    connect(animation, SIGNAL(finished()), this, SLOT(setAnimationEnd()));
    animation->start();
    //    connect(animation, &QPropertyAnimation::finished, this, &MyFourStatesLabelAnimated::setAnimationEnd);

}

void MyFourStatesLabelAnimated::mousePressEvent(QMouseEvent *ev)
{
    Q_UNUSED(ev);
    label_size = this->size();
    if(!this->is_Enabled()){
        return;
    }
    if(!startValue.isEmpty()){
        if(startValue.size() != this->geometry().size()){
            this->setGeometry(startValue);
        }
    }
    startValue = this->geometry();
    if(!animationOnGoing){
        if(currentState() != FOURTH_STATE){
            if(!isChecked()){ //del cuarto estado paso a OFF_STATE
                setChecked(true);
            }else {
                setChecked(false);
            }
        }

        if(myanimationEnabled){
            startAnimation(true);
        }else{
            emitirClicked();
        }
    }
}

void MyFourStatesLabelAnimated::moveEvent(QMoveEvent *event)
{
    QWidget::moveEvent(event);
}

void MyFourStatesLabelAnimated::setChecked(bool checked){
    set_Enabled(true);
    if(checked){
        setCurrentState(ON_STATE);
        if(QFile::exists(":/icons/" + info + "_on.png")){
            this->setPixmap(QPixmap(":/icons/" + info + "_on.png"));
        }
    }else{
        setCurrentState(OFF_STATE);
        if(QFile::exists(":/icons/" + info + "_off.png")){
            this->setPixmap(QPixmap(":/icons/" + info + "_off.png"));
        }
    }
}

void MyFourStatesLabelAnimated::setThirdState(bool enable){
    setCurrentState(THIRTH_STATE);
    set_Enabled(enable);
    if(QFile::exists(":/icons/" + info + ".png")){
        this->setPixmap(QPixmap(":/icons/" + info + ".png"));

    }
}

void MyFourStatesLabelAnimated::setFourthState(bool enable){
    setCurrentState(FOURTH_STATE);
    set_Enabled(enable);
    if(QFile::exists(":/icons/" + info + "_4th_state.png")){
        this->setPixmap(QPixmap(":/icons/" + info + "_4th_state.png"));
    }
}

bool MyFourStatesLabelAnimated::isChecked(){
    if(currentState() ==  ON_STATE){
        return true;
    }else{
        return false;
    }
}
