#ifndef SETTINGIERATIO_H
#define SETTINGIERATIO_H

#include <QWidget>
#include <QStringList>
#include <QString>

namespace Ui {
class SettingIERatio;
}

class SettingIERatio : public QWidget
{
    Q_OBJECT


public:
    explicit SettingIERatio(QWidget *parent = nullptr);
    ~SettingIERatio();
    void setConfigs(float IE = 1, double Ti = 0.3, double BPM = 20);

    void setTitle(QString title);
    static float convertStringRatioToFloat(QString ratio);
    static QString convertFloatToStringRatio(float f);

    static float getIEWithData(double Ti, double BPM);

    static float getTiWithData(double IE, double BPM);
    void setShadow(QColor color = QColor(63,63,63,180));
signals:
    void setted(float);
    void setted_Ti(double);

private slots:
    void on_l_up_clicked();
    void on_l_down_clicked();
    void on_l_ok_clicked();

    void on_l_up_ti_clicked();
    void on_l_down_ti_clicked();
private:
    Ui::SettingIERatio *ui;
    double m_Ti, m_BPM, m_ie;
    double Ti_step = 0.1, ie_step = 0.1, m_max_Ti_value = 3.7, m_min_Ti_value = 0.3;
    QString title = "";
    void setTi_value(double ti);
};

#endif // SETTINGIERATIO_H
