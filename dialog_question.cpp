#include "dialog_question.h"
#include "ui_dialog_question.h"

Dialog_Question::Dialog_Question(QWidget *parent, QString title, QString question) :
    QWidget(parent),
    ui(new Ui::Dialog_Question)
{
    ui->setupUi(this);
    ui->l_situacion->setText(title);
    ui->l_pregunta->setText(question);
}

Dialog_Question::~Dialog_Question()
{
    delete ui;
}

void Dialog_Question::showCenter(){

    this->move(0, 0);
    int h = this->parentWidget()->height();
    int w = this->parentWidget()->width();
    if(h > 480){ h=480;}
    if(w > 800){ w=800;}
    int xpos = static_cast<int>(static_cast<float>(w - ui->widget->width())/2);
    int ypos = static_cast<int>(static_cast<float>(h - ui->widget->height())/2);
    ui->widget->move(xpos, ypos-20);
    this->show();
}

void Dialog_Question::resizeWidgetQuestion(int w, int h){
    ui->widget->setFixedSize(w, h);
    ui->label->setFixedSize(w, h);
    ui->l_situacion->setFixedSize(static_cast<int>(0.96*w), 31);
    ui->l_situacion->move(static_cast<int>(0.02*w), static_cast<int>(0.1*h));
    ui->l_pregunta->setFixedSize(static_cast<int>(0.96*w), static_cast<int>(0.5*h));
    ui->l_pregunta->move(static_cast<int>(0.02*w), static_cast<int>(0.2*h));
    ui->pb_ok->move(20, h-50);
    ui->pb_cancel->move(w-150, h-50);

    showCenter();
}
void Dialog_Question::on_pb_cancel_clicked()
{
    emit cancelado();
    emit accepted(0);
    emit rejected(1);
    this->close();
}


void Dialog_Question::on_pb_ok_clicked()
{
    emit aceptado();
    emit accepted(1);
    this->close();
}
