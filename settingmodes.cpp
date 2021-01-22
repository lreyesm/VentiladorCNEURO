#include "settingmodes.h"
#include "ui_settingmodes.h"
#include <QGraphicsDropShadowEffect>

SettingModes::SettingModes(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingModes)
{
    ui->setupUi(this);
     setWindowFlags(Qt::CustomizeWindowHint);
}

SettingModes::~SettingModes()
{
    delete ui;
}
void SettingModes::setShadow(QColor color){
    QGraphicsDropShadowEffect *eff = new QGraphicsDropShadowEffect(this);
    eff->setBlurRadius(20);
    eff->setOffset(1);
    eff->setColor(color);
    ui->label->setGraphicsEffect(eff);
}
void SettingModes::setConfig(QString current)
{
    if(current == "VCV")
    {
        ui->l_pcv->setChecked(true);
    }
    else if(current == "VAC")
    {
        ui->l_acv->setChecked(true);
    }
}

void SettingModes::setTitle(QString title)
{
    ui->l_title->setText(title);
    this->title = title;
    ui->l_acv->setRadioButtonPos();
    ui->l_pcv->setRadioButtonPos();
}


void SettingModes::on_l_ok_clicked()
{
    emit setted(value);
    this->close();
}

void SettingModes::on_l_pcv_clicked()
{
    value = 1;
    ui->l_acv->setChecked(false);
}

void SettingModes::on_l_acv_clicked()
{
    value = 2;
    ui->l_pcv->setChecked(false);
}
