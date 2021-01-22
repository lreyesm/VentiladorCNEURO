#include "messagedialog.h"
#include "ui_messagedialog.h"

MessageDialog::MessageDialog(QWidget *parent, QString title,  QString text) :
    QWidget(parent),
    ui(new Ui::MessageDialog)
{
    ui->setupUi(this);
    setWindowFlags(Qt::CustomizeWindowHint);

    ui->l_alarma->setText(title);
    ui->l_descripcion->setText(text);
    alarma = title;
    descripcion = text;
}

MessageDialog::~MessageDialog()
{
    delete ui;
}

void MessageDialog::showCenter(){

    this->move(0, 0);
    int h = this->parentWidget()->height() ;
    int w = this->parentWidget()->width() ;
    if(h > 480){ h=480;}
    if(w > 800){ w=800;}
    int xpos = static_cast<int>(static_cast<float>(w - ui->widget->width())/2);
    int ypos = static_cast<int>(static_cast<float>(h - ui->widget->height())/2);
    ui->widget->move(xpos, ypos-20);
    this->show();
}

bool MessageDialog::decodeAlarm(float alarma_l){
    uint32_t alarma = static_cast<uint32_t>(alarma_l);
    bool return_value = false;
    if((alarma & 0x01) == 0x01){
        if(!checkedAlarmActiva(LEAK_PRESION)){
            return_value = true;
            addAlarm(LEAK_PRESION);
            this->setAlarmAndDescription("Desconexión", "Puede que haya fuga de presión");
            this->showCenter();
        }
    }
    else{
        clearAlarm(LEAK_PRESION);
    }
    if((alarma & 0x02) == 0x02){
        if(!checkedAlarmActiva(OVER_PRESION)){
            return_value = true;
            addAlarm(OVER_PRESION);
            this->setAlarmAndDescription("Sobre presión", "Se ha superado presíon máxima");
            this->showCenter();
        }
    }
    else{
        clearAlarm(OVER_PRESION);
    }
    if((alarma & 0x04) == 0x04){
        if(!checkedAlarmActiva(LOW_PRESION)){
            return_value = true;
            addAlarm(LOW_PRESION);
            this->setAlarmAndDescription("PEEP", "Presión fuera de rango PEEP");
            this->showCenter();
         }
    }else{
        clearAlarm(LOW_PRESION);
    }
    return return_value;
}

void MessageDialog::setAlarma(QString alarm)
{
    alarma = alarm;
    ui->l_alarma->setText(alarm);
}

void MessageDialog::setDescripcion(QString des)
{
    descripcion = des;
    ui->l_descripcion->setText(des);
}

void MessageDialog::setAlarmAndDescription(QString alarm, QString des){
    setAlarma(alarm);
    setDescripcion(des);
}

bool MessageDialog::addAlarm(uint32_t alarma_l){//returna true si añadio la alarma
    if(!checkedAlarmActiva(alarma_l)){
        alarmas_activas.append(alarma_l);
        return true;
    }
    return false;
}
bool MessageDialog::checkedAlarmActiva(uint32_t alarma_l){//true si esta activa
    if(alarmas_activas.contains(alarma_l)){
        return true;
    }
    else {
        return false;
    }
}

bool MessageDialog::clearAlarm(uint32_t alarma_l){
    if(checkedAlarmActiva(alarma_l)){
        alarmas_activas.removeOne(alarma_l);
        return true;
    }
    return false;
}

void MessageDialog::clearAlarms(){
    alarmas_activas.clear();
}

void MessageDialog::on_pb_ok_clicked()
{
    this->close();
    emit aceptado();
    emit checkedAlarm(false);//false para no poner en silencio la alarma
}

