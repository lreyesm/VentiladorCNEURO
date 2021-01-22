#ifndef SETTINGCENTERPARAMETERS_H
#define SETTINGCENTERPARAMETERS_H

#include <QWidget>

namespace Ui {
class SettingCenterParameters;
}

class SettingCenterParameters : public QWidget
{
    Q_OBJECT

public:
    explicit SettingCenterParameters(QWidget *parent = nullptr);
    ~SettingCenterParameters();
    void setConfigs(int value =0, int step=5, int max=100, int min=0);

    void setTitle(QString title);
    void setTextColor(QColor color);
    void setShadow(QColor color = QColor(63, 63, 63, 180));
signals:
    void setted(int);

private slots:
    void on_l_up_clicked();
    void on_l_down_clicked();
    void on_l_ok_clicked();

private:
    Ui::SettingCenterParameters *ui;
    int m_max_value = 100;
    int m_min_value =0;
    int m_step = 5;
    QString title = "";
};

#endif // SETTINGCENTERPARAMETERS_H
