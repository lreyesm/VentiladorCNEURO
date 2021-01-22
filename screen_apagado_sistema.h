#ifndef SCREEN_APAGADO_SISTEMA_H
#define SCREEN_APAGADO_SISTEMA_H

#include <QWidget>

namespace Ui {
class Screen_Apagado_Sistema;
}

class Screen_Apagado_Sistema : public QWidget
{
    Q_OBJECT

public:
    explicit Screen_Apagado_Sistema(QWidget *parent = nullptr, bool shutdown = true);
    ~Screen_Apagado_Sistema();   

private slots:
    void closeApplication();
    void turnOffRaspi();
    void rebootRaspi();
private:
    Ui::Screen_Apagado_Sistema *ui;
};

#endif // SCREEN_APAGADO_SISTEMA_H
