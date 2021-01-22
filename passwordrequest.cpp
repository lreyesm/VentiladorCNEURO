#include "passwordrequest.h"
#include "ui_passwordrequest.h"
#include "messagedialog.h"
#include <QDebug>
PasswordRequest::PasswordRequest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PasswordRequest)
{
    ui->setupUi(this);

    QObject::connect(ui->le_clave, &MyLineEdit::pressedLineEdit, this, &PasswordRequest::showKeyBoard);
    QObject::connect(ui->le_nombre_usuario, &MyLineEdit::pressedLineEdit, this, &PasswordRequest::showKeyBoard);
}

PasswordRequest::~PasswordRequest()
{
    delete ui;
}
void PasswordRequest::animateWidgetDownToUp(QWidget *widget, int anim_time){ //mueve el widget de donde esta hacia arriba
    QRect startValue = widget->geometry();
    QRect endValue = QRect(startValue.x(),startValue.y() - startValue.height()
                           ,startValue.width(), startValue.height());
    QPropertyAnimation *animation = new QPropertyAnimation(widget, "geometry");
    animation->setDuration(anim_time);
    animation->setStartValue(startValue);
    animation->setEndValue(endValue);
    animation->start();
}
void PasswordRequest::animateWidgetUpToDown(QWidget *widget, int anim_time){

    QRect startValue = widget->geometry();
    QRect endValue = QRect(startValue.x(),startValue.y() + startValue.height()
                           ,startValue.width(), startValue.height());
    QPropertyAnimation *animation = new QPropertyAnimation(widget, "geometry");
    animation->setDuration(anim_time);
    animation->setStartValue(startValue);
    animation->setEndValue(endValue);
    animation->start();
}
void PasswordRequest::showKeyBoard(QLineEdit *widget)
{
    bool shown = false;
    if(teclado != nullptr){
        if(!teclado->isHidden()){
            shown = true;
        }
        delete teclado;
    }
    bool numeric = false;
    if(widget->objectName().contains("edad")
            ||widget->objectName().contains("height")
            ||widget->objectName().contains("weight")){
        numeric = true;
    }
    teclado = new KeyBoard(this, widget, numeric, 800, 220, 0, 260);
    teclado->setWidget(widget);
    qDebug()<<widget->objectName();
    if(shown){
        teclado->show();
    }else{
        teclado->showKeyBoard();
    }
}

void PasswordRequest::showCenter(){

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

void PasswordRequest::on_pb_ok_clicked()
{
    if(ui->le_nombre_usuario->text().trimmed().contains("NEURONIC", Qt::CaseInsensitive)){
        if(ui->le_clave->text().trimmed() == "Neuro2020"){
            emit loginCorrect();
            this->close();
            return;
        }
    }
    emit loginFailed();
    MessageDialog *msg = new MessageDialog(this, "Error", "Nombre de usuario o contraseña incorrecta");
    msg->showCenter();
}


void PasswordRequest::on_pb_show_hide_password_clicked()
{
    showPassword = !showPassword;
    if(showPassword){
        QPixmap pix(":icons/hide.png");
        ui->pb_show_hide_password->setPixmap(pix);
        ui->le_clave->setEchoMode(QLineEdit::Normal);
    }else{
        QPixmap pix(":icons/show.png");
        ui->pb_show_hide_password->setPixmap(pix);
        ui->le_clave->setEchoMode(QLineEdit::Password);
    }
}

