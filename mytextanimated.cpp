#include "mytextanimated.h"
#include <QTimer>
#include "globals_settings.h"

MyTextAnimated::MyTextAnimated(QWidget *parent)
    :QLabel(parent)
{
//    this->setMouseTracking(true);
//    connect(this, SIGNAL(objectNameChanged(const QString&)), this, SLOT(setFotoInit(const QString&)));
    this->setStyleSheet(QStringLiteral("font: 22pt \"DIN Pro\"; border-image: url(:/icons/menu_o.png);"));
    this->setScaledContents(true);
    this->setText("VCV");
    this->setFixedSize(80,40);
    this->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
}
MyTextAnimated::~MyTextAnimated()
{
    //    delete animation;
}
void MyTextAnimated::setTextColor(const QColor color)
{
    textColorCurrent = color;
    //color: rgb(227,134,134);
    QString red = QString::number(color.red());
    QString green = QString::number(color.green());
    QString blue = QString::number(color.blue());
    QString color_string = "color: rgb("+red+","+green+","+blue+");";
    QString style_sheet = this->styleSheet().split("color").at(0);
    this->setStyleSheet(style_sheet + color_string);
}

QColor MyTextAnimated::getTextColor()
{
    return textColorCurrent;
}

void MyTextAnimated::setFotoInit(const QString& n)
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
void MyTextAnimated::setAnimationInit()
{

    startValue = this->geometry();
    endValue = QRect(startValue.x()-anim_scale,startValue.y() -anim_scale
                     ,startValue.width() +anim_scale*2,startValue.height() +anim_scale*2);
    maxSize= this->maximumSize();
    this->setMaximumSize(maxSize.width() +  anim_scale*2, maxSize.height() +anim_scale*2);
    animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(anim_time);
    animation->setStartValue(startValue);
    animation->setEndValue(endValue);
}
void MyTextAnimated::setAnimationEnd()
{
    //    disconnect(animation, &QPropertyAnimation::finished, this, &MyTextAnimated::setAnimationEnd);
    //    disconnect(animation, SIGNAL(finished()), this, SLOT(setAnimationEnd()));
    delete animation;
    animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(anim_time);
    animation->setStartValue(endValue);
    animation->setEndValue(startValue);
    connect(animation, SIGNAL(finished()), this, SLOT(finalizadaAnimacion()));
    animation->start();
}
void MyTextAnimated::finalizadaAnimacion()
{
    disconnect(animation, SIGNAL(finished()), this, SLOT(finalizadaAnimacion()));
    animationOnGoing = false;
    this->setMaximumSize(maxSize);
    delete animation;
    QTimer::singleShot(50, this, SLOT(emitirClicked()));
    //    emit mouseLeftClicked();
}
void MyTextAnimated::emitirClicked()
{
    emit clicked();
}

void MyTextAnimated::startAnimation(int delay, int scale, int anim_tim)
{
    //hacer un single shot con delay
    anim_time = anim_tim;
    anim_scale = scale;
    setAnimationInit();
    animationOnGoing = true;
    connect(animation, SIGNAL(finished()), this, SLOT(setAnimationEnd()));
    animation->start();
    //    connect(animation, &QPropertyAnimation::finished, this, &MyTextAnimated::setAnimationEnd);

}
bool MyTextAnimated::isOngoingAnimation(){
    return animationOnGoing;
}
void MyTextAnimated::mousePressEvent(QMouseEvent *ev)
{
    //    if(QApplication::mouseButtons()==Qt::RightButton){
    //        emit mouseRightClicked();
    //    }
    //    if(QApplication::mouseButtons()==Qt::LeftButton){
    emit mouseLeftClicked();

    if(!animationOnGoing){
//        if(!isChecked()){
//            setChecked(true);
//        }
        if(myanimationEnabled){
            startAnimation(0);
        }else{
            emit clicked();
        }
    }

    //    }
}
void MyTextAnimated::setChecked(bool checked){
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
bool MyTextAnimated::isChecked(){
    return activated_state;
}

