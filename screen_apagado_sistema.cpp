#include "screen_apagado_sistema.h"
#include "ui_screen_apagado_sistema.h"
#include "processesclass.h"

Screen_Apagado_Sistema::Screen_Apagado_Sistema(QWidget *parent, bool shutdown) :
    QWidget(parent),
    ui(new Ui::Screen_Apagado_Sistema)
{
    ui->setupUi(this);
    if(shutdown){
        turnOffRaspi();
    }else{
        ui->l_calibration_text_label->setText("Reiniciando Sistema");
        rebootRaspi();
    }
}

Screen_Apagado_Sistema::~Screen_Apagado_Sistema()
{
    delete ui;
}
void Screen_Apagado_Sistema::rebootRaspi(){//(la clase ReadTempDS18B20 se encarga de todo
    ProcessesClass::executeProcess(this, "sudo python /home/pi/Ventilador/Ventilador/scripts/reboot.py", ProcessesClass::LINUX, 100);
    QTimer::singleShot(1000, this, &Screen_Apagado_Sistema::closeApplication);
}
void Screen_Apagado_Sistema::turnOffRaspi(){//(la clase ReadTempDS18B20 se encarga de todo
    ProcessesClass::executeProcess(this, "sudo python /home/pi/Ventilador/Ventilador/scripts/shutdown.py", ProcessesClass::LINUX, 100);
    QTimer::singleShot(2000, this, &Screen_Apagado_Sistema::closeApplication);
}
void Screen_Apagado_Sistema::closeApplication(){
    QApplication::closeAllWindows();
}
