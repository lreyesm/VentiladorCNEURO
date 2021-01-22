#include "screen_calibration.h"
#include "ui_screen_calibration.h"
#include "screen_modo_at.h"
#include "globals_settings.h"

Screen_Calibration::Screen_Calibration(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Screen_Calibration)
{
    ui->setupUi(this);
    ui->l_version->setText(version_software);

    timer.setInterval(500);
    connect(&timer, &QTimer::timeout, this, &Screen_Calibration::updateProgresBarCalibrationMotor);
    timer.start();
}

Screen_Calibration::~Screen_Calibration()
{
    delete ui;
}

void Screen_Calibration::setCalibationErrorText(QString text){
    if(!text.isEmpty()){
        ui->l_calibration_text_label->setText(text);
    }

    ui->progressBar_calibracion->setStyleSheet(QStringLiteral(
                                                   "QProgressBar::chunk {"
                                                   "border-radius: 4px;"
                                                   "background-color: #FF0000;}"
                                                   "QProgressBar {"
                                                   "border-radius: 4px;"
                                                   "background-color: #E3E3E3;}"));
}
void Screen_Calibration::updateProgresBarCalibrationMotor()
{
    int value = ui->progressBar_calibracion->value();
    value += 10;
    incrementProgressBar(value);
//    if(value >= 50) {  //Comentar este if si no esta conectado al arduino***********************************************************************
//        disconnect(&timer, &QTimer::timeout, this, &Screen_Calibration::updateProgresBarCalibrationMotor);
//        timer.stop();
//    }
}

void Screen_Calibration::initPresureCalibration(){
    connect(&timer, &QTimer::timeout, this, &Screen_Calibration::updateProgresBarCalibrationPresion);
    timer.start();
}

void Screen_Calibration::updateProgresBarCalibrationPresion()
{
    int value = ui->progressBar_calibracion->value();
    value += 10;
    incrementProgressBar(value);

    if(value >= 90) {
        disconnect(&timer, &QTimer::timeout, this, &Screen_Calibration::updateProgresBarCalibrationPresion);
        timer.stop();
    }
}

void Screen_Calibration::incrementProgressBar(int value){
    if(value != -1){
        ui->progressBar_calibracion->setValue(value);
    }
}

void Screen_Calibration::on_progressBar_calibracion_valueChanged(int value)
{
    if(value >= 99){
        disconnect(&timer, &QTimer::timeout, this, &Screen_Calibration::updateProgresBarCalibrationMotor);
        QTimer::singleShot(2000, this , SLOT(on_pb_continue_clicked()));
    }
}

void Screen_Calibration::close_Screen_Calibration(){
    if(!modo_AT_active){
        timer.stop();
        emit closed_screen_calibration();
        close();
    }
}

void Screen_Calibration::on_pb_continue_clicked()
{
    close_Screen_Calibration();
}

void Screen_Calibration::on_pb_modo_at_clicked()
{
    modo_AT_active = true;
    Screen_Modo_AT *modo_at = new Screen_Modo_AT(this);
    modo_at->show();
}
