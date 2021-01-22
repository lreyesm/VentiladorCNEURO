#include "screen_calibration_error.h"
#include "ui_screen_calibration_error.h"

Screen_Calibration_Error::Screen_Calibration_Error(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Screen_Calibration_Error)
{
    ui->setupUi(this);
}

Screen_Calibration_Error::~Screen_Calibration_Error()
{
    delete ui;
}

void Screen_Calibration_Error::on_pb_modoAT_clicked()
{

}

void Screen_Calibration_Error::on_pb_apagar_clicked()
{

}
