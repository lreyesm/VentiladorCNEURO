#include "loadinganimation.h"
#include "ui_loadinganimation.h"
#include <QTransform>
#include "math.h"
#include <QFrame>
#include <QSlider>
#include <QVBoxLayout>
#include "QProgressIndicator.h"
#include "globals_settings.h"

LoadingAnimation::LoadingAnimation(QWidget *parent, QString text) :
    QWidget(parent),
    ui(new Ui::LoadingAnimation)
{
    ui->setupUi(this);
//    if(ui->l_loading->pixmap()){
//        pix = *ui->l_loading->pixmap();
//    }
    if(!text.isEmpty()){
        ui->l_loading_text->setText(text);
    }
}

LoadingAnimation::~LoadingAnimation()
{
    delete ui;
}
void LoadingAnimation::setLoadingText(QString text)
{
    if(!text.isEmpty()){
        ui->l_loading_text->setText(text);
    }
}
QString LoadingAnimation::getLoadingText()
{
    return  ui->l_loading_text->text();
}

void LoadingAnimation::showAnimation(){
    this->show();
    this->raise();
    this->startAnimation();
}
void LoadingAnimation::startAnimation()
{
    QProgressIndicator* pi = new QProgressIndicator();
    QObject::connect(this, SIGNAL(stoppedAnimation()), pi, SLOT(stopAnimation()));

    QHBoxLayout* hbl = new QHBoxLayout(ui->widget_loading);
    hbl->addWidget(pi);

    pi->setColor(color_green_oxigen);
    pi->setFixedSize(90, 90);
    pi->setAnimationDelay(50);
    pi->startAnimation();
}

void LoadingAnimation::stopAnimation()
{
    emit stoppedAnimation();
    this->close();
    this->deleteLater();
}

void LoadingAnimation::rotate_right()
{
//    double dimension = pix.size().width();
//    dimension = dimension / sqrt(2);

//    QTransform transform;
//    transform = transform.rotate(45);

//    //    pix = pix.scaled(static_cast<int>(dimension), static_cast<int>(dimension));
//    pix = pix.transformed(transform, Qt::SmoothTransformation);

//    ui->l_loading->setPixmap(pix);


    //    QSize size = pix.size();
    //    QImage srcImg(pix.toImage());
    //    QPoint center = srcImg.rect().center();
    //    QMatrix matrix;
    //    matrix.translate(center.x(), center.y());
    //    matrix.rotate(30);
    //    QImage dstImg = srcImg.transformed(matrix);
    //    QPixmap dstPix = QPixmap::fromImage(dstImg);
    //    pix = dstPix/*.scaled(size.width(), size.height())*/;
    //    size = pix.size();
    //    ui->l_loading->setPixmap(pix);

}

