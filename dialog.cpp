#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent, QString title, QString question) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->l_situacion->setText(title);
    ui->l_pregunta->setText(question);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::showCenter(){

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


void Dialog::on_pb_cancel_clicked()
{
    emit rejected();
    this->close();
}


void Dialog::on_pb_ok_clicked()
{
    emit accepted();
    this->close();
}


