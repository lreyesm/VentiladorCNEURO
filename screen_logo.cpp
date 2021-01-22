#include "screen_logo.h"
#include "ui_screen_logo.h"
#include <QDebug>

Screen_Logo::Screen_Logo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Screen_Logo)
{
    ui->setupUi(this);    
    ui->l_version->setText(version_software);
    QTimer::singleShot(3000, this, SLOT(close_screen_logo()));
    qDebug()<<"cambio**************11111111**********";
}

Screen_Logo::~Screen_Logo()
{
    delete ui;
}

void Screen_Logo::close_screen_logo(){
    emit closed_screen_logo();
    close();
}

void Screen_Logo::startLogoAnimation(){
    ui->l_logo->startAnimation(false, 40, 1000);
//    QTimer::singleShot(3000, this, SLOT(close_screen_logo()));
}



void Screen_Logo::on_l_logo_clicked()
{
//    close_screen_logo();
}

