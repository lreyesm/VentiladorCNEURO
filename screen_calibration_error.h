#ifndef SCREEN_CALIBRATION_ERROR_H
#define SCREEN_CALIBRATION_ERROR_H

#include <QWidget>

namespace Ui {
class Screen_Calibration_Error;
}

class Screen_Calibration_Error : public QWidget
{
    Q_OBJECT

public:
    explicit Screen_Calibration_Error(QWidget *parent = nullptr);
    ~Screen_Calibration_Error();

private slots:
    void on_pb_modoAT_clicked();

    void on_pb_apagar_clicked();

private:
    Ui::Screen_Calibration_Error *ui;
};

#endif // SCREEN_CALIBRATION_ERROR_H
