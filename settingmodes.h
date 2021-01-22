#ifndef SETTINGMODES_H
#define SETTINGMODES_H

#include <QWidget>

namespace Ui {
class SettingModes;
}


class SettingModes : public QWidget
{
    Q_OBJECT

public:
    explicit SettingModes(QWidget *parent = nullptr);
    ~SettingModes();
    void setTitle(QString title);

    void setConfig(QString current);
    void setShadow(QColor color);
signals:
    void setted(int);

private slots:
    void on_l_ok_clicked();

    void on_l_pcv_clicked();

    void on_l_acv_clicked();

private:
    Ui::SettingModes *ui;
    int value = 0;
    QString title = "";
};

#endif // SETTINGMODES_H
