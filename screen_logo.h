#ifndef SCREEN_LOGO_H
#define SCREEN_LOGO_H

#include <QWidget>
#include "serialport.h"
#include <QDateTime>

namespace Ui {
class Screen_Logo;
}

class Screen_Logo : public QWidget
{
    Q_OBJECT

public:
    explicit Screen_Logo(QWidget *parent = nullptr);
    ~Screen_Logo();

signals:
    void closed_screen_logo();
    void setFechaHoraReceived(QDateTime);

public slots:
    void startLogoAnimation();
    void close_screen_logo();

private slots:

    void on_l_logo_clicked();

private:
    Ui::Screen_Logo *ui;
};

#endif // SCREEN_LOGO_H
