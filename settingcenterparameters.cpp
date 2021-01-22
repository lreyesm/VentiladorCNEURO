#include "settingcenterparameters.h"
#include "ui_settingcenterparameters.h"
#include <QGraphicsDropShadowEffect>

SettingCenterParameters::SettingCenterParameters(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingCenterParameters)
{
    ui->setupUi(this);
    setWindowFlags(Qt::CustomizeWindowHint);
}

SettingCenterParameters::~SettingCenterParameters()
{
    delete ui;
}

void SettingCenterParameters::setShadow(QColor color){
    QGraphicsDropShadowEffect *eff = new QGraphicsDropShadowEffect(this);
    eff->setBlurRadius(20);
    eff->setOffset(1);
    eff->setColor(color);
    ui->label->setGraphicsEffect(eff);
}
void SettingCenterParameters::setTextColor(QColor color)
{
    QString red = QString::number(color.red());
    QString green = QString::number(color.green());
    QString blue = QString::number(color.blue());
    QString color_string = "color: rgb("+red+","+green+","+blue+");";
    QString style_sheet = this->styleSheet().split("color").at(0);
    ui->l_value->setStyleSheet(style_sheet + color_string);
}

void SettingCenterParameters::setTitle(QString title)
{
    ui->l_title->setText(title);
    this->title = title;
}

void SettingCenterParameters::setConfigs(int value, int step, int max, int min)
{
    ui->l_value->setText(QString::number(value));
    m_step = step;
    m_max_value = max;
    m_min_value = min;
}

void SettingCenterParameters::on_l_up_clicked()
{
    bool ok;
    int value = ui->l_value->text().toInt(&ok);
    if(ok){
        value += m_step;
        if(value > m_max_value){
            value = m_max_value;
        }
        ui->l_value->setText(QString::number(value));
    }
}

void SettingCenterParameters::on_l_down_clicked()
{
    bool ok;
    int value = ui->l_value->text().toInt(&ok);
    if(ok){
        value -= m_step;
        if(value < m_min_value){
            value = m_min_value;
        }
        ui->l_value->setText(QString::number(value));
    }
}

void SettingCenterParameters::on_l_ok_clicked()
{
    bool ok;
    int value = ui->l_value->text().toInt(&ok);
    emit setted(value);
    this->close();
}

