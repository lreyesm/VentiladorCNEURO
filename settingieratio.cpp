#include "settingieratio.h"
#include "ui_settingieratio.h"
#include <QGraphicsDropShadowEffect>


SettingIERatio::SettingIERatio(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingIERatio)
{
    ui->setupUi(this);
    setWindowFlags(Qt::CustomizeWindowHint);
}

SettingIERatio::~SettingIERatio()
{
    delete ui;
}
void SettingIERatio::setShadow(QColor color){
    QGraphicsDropShadowEffect *eff = new QGraphicsDropShadowEffect(this);
    eff->setBlurRadius(20);
    eff->setOffset(1);
    eff->setColor(color);
    ui->label->setGraphicsEffect(eff);
}
void SettingIERatio::setTitle(QString title)
{
    ui->l_title->setText(title);
    this->title = title;
}

void SettingIERatio::setConfigs(float IE, double Ti, double BPM)
{
    m_Ti = Ti;
    m_BPM =  BPM;
    ui->l_value_ti->setText(QString::number(Ti, 'f', 1));

    if(static_cast<double>(IE) < 0.25){
        IE = 0.25;
    }
    if(static_cast<double>(IE) > 1){
        IE = 1;
    }
    m_ie = static_cast<double>(IE);


    ui->l_value->setText(convertFloatToStringRatio(IE));

}

void SettingIERatio::on_l_up_ti_clicked()
{
    m_Ti += Ti_step;
    float rel = getIEWithData(m_Ti, m_BPM);
    if(static_cast<double>(rel) < 0.25 || static_cast<double>(rel) > 1){
        m_Ti -= Ti_step;
    }
    setTi_value(m_Ti);
    m_ie = static_cast<double>(getIEWithData(m_Ti, m_BPM));
    QString relIE  = convertFloatToStringRatio(static_cast<float>(m_ie));
    ui->l_value->setText(relIE);
}
void SettingIERatio::on_l_down_ti_clicked()
{
    m_Ti -= Ti_step;
    float rel = getIEWithData(m_Ti, m_BPM);
    if(static_cast<double>(rel) < 0.25 || static_cast<double>(rel) > 1){
        m_Ti += Ti_step;
    }
    setTi_value(m_Ti);
    m_ie = static_cast<double>(getIEWithData(m_Ti, m_BPM));
    QString relIE  = convertFloatToStringRatio(static_cast<float>(m_ie));
    ui->l_value->setText(relIE);
}

float SettingIERatio::getIEWithData(double Ti, double BPM){
    double te, t_time = 60/ BPM;
    te = t_time - Ti;

    double relation = Ti / te;
    return static_cast<float>(relation);
}

float SettingIERatio::getTiWithData(double IE, double BPM){
    double ti, t_time = 60/ BPM;
    ti = t_time/(1 + 1/IE);

    return static_cast<float>(ti);
}

void SettingIERatio::setTi_value(double ti){
    m_Ti = ti;
    if(m_Ti > m_max_Ti_value){
        m_Ti = m_max_Ti_value;
    }
    if(m_Ti < m_min_Ti_value){
        m_Ti = m_min_Ti_value;
    }
    ui->l_value_ti->setText(QString::number(m_Ti, 'f', 1));
}


void SettingIERatio::on_l_down_clicked()
{
    QString ie_string = ui->l_value->text();
    double ie_part2 = ie_string.split(":").at(1).toDouble();
    ie_part2 -= ie_step;
    if(ie_part2 < 1){
        ie_part2 += ie_step;
    }
    m_ie = 1 / ie_part2;
    m_Ti = static_cast<double>(getTiWithData(m_ie, m_BPM));
    ui->l_value_ti->setText(QString::number(m_Ti, 'f', 1));
    ui->l_value->setText(convertFloatToStringRatio(static_cast<float>(m_ie)));
}

void SettingIERatio::on_l_up_clicked()
{
    QString ie_string = ui->l_value->text();
    double ie_part2 = ie_string.split(":").at(1).toDouble();
    ie_part2 += ie_step;
    if(ie_part2 > 4){
        ie_part2 -= ie_step;
    }
    m_ie = 1 / ie_part2;
    m_Ti = static_cast<double>(getTiWithData(m_ie, m_BPM));
    ui->l_value_ti->setText(QString::number(m_Ti, 'f', 1));
    ui->l_value->setText(convertFloatToStringRatio(static_cast<float>(m_ie)));
}

void SettingIERatio::on_l_ok_clicked()
{
    emit setted(static_cast<float>(m_ie));
    emit setted_Ti(m_Ti);
    this->close();
}

QString SettingIERatio::convertFloatToStringRatio(float f)
{
    double te = 1 / static_cast<double>(f);

    QString ratio = "1:"+ QString::number(te, 'f', 1);

    return ratio;
}

float SettingIERatio::convertStringRatioToFloat(QString ratio)
{
    bool ok;
    double num1, num2=1;
    float f = 1;
    QStringList split = ratio.split(":");
    if(split.size() > 1){
        QString n = split.at(0);
        num1 = n.toDouble(&ok);
        if(ok){
            n = split.at(1);
            num2 = n.toDouble(&ok);
            if(ok){
                f = static_cast<float>(num1/num2);
            }
        }

    }
    return f;
}
