#include "screen_pacient_data.h"
#include "ui_screen_pacient_data.h"
#include "screen_datetime.h"
#include <QFileDialog>
#include "messagedialog.h"

Screen_Pacient_Data::Screen_Pacient_Data(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Screen_Pacient_Data)
{
    ui->setupUi(this);    
    ui->l_version->setText(version_software);
    QObject::connect(ui->le_nombre, &MyLineEdit::pressedLineEdit, this, &Screen_Pacient_Data::showKeyBoard);
    QObject::connect(ui->le_CI_HC, &MyLineEdit::pressedLineEdit, this, &Screen_Pacient_Data::showKeyBoard);
    QObject::connect(ui->le_sexo, &MyLineEdit::pressedLineEdit, this, &Screen_Pacient_Data::showKeyBoard);
    QObject::connect(ui->le_edad, &MyLineEdit::pressedLineEdit, this, &Screen_Pacient_Data::showKeyBoard);
    QObject::connect(ui->le_height, &MyLineEdit::pressedLineEdit, this, &Screen_Pacient_Data::showKeyBoard);
    QObject::connect(ui->le_weight, &MyLineEdit::pressedLineEdit, this, &Screen_Pacient_Data::showKeyBoard);

    QObject::connect(ui->pt_comentarios, &MyPlainTextEdit::pressedPlainTextEdit, this, &Screen_Pacient_Data::showKeyBoardonPlainTextEdit);

    //    QTimer::singleShot(1500, this, SLOT(showKeyBoard()));
}

Screen_Pacient_Data::~Screen_Pacient_Data()
{
    delete ui;
}
int Screen_Pacient_Data::estimateVolumen(int volumen){
    float division = volumen / 50;
    int estimate =  qRound(division);
    return estimate*50;
}
int Screen_Pacient_Data::fitHeightFemaleWithData(int height){
    if(height <= 153){
        return 320;
    }
    if(154 <= height && height < 157){
        return 330;
    }
    if(157 <= height && height < 160){
        return 350;
    }
    if(160 <= height && height < 162){
        return 370;
    }
    if(162 <= height && height < 165){
        return 380;
    }
    if(165 <= height && height < 167){
        return 400;
    }
    if(167 <= height && height < 170){
        return 410;
    }
    if(170 <= height && height < 172){
        return 430;
    }
    if(172 <= height && height < 175){
        return 450;
    }
    if(175 <= height && height < 177){
        return 460;
    }
    if(177 <= height && height < 180){
        return 480;
    }
    if(180 <= height && height < 182){
        return 500;
    }
    if(182 <= height && height < 185){
        return 510;
    }
    if(185 <= height && height < 187){
        return 530;
    }
    if(187 <= height && height < 190){
        return 540;
    }
    if(190 <= height && height < 193){
        return 560;
    }
    if(193 <= height && height < 195){
        return 580;
    }
    if(195 <= height && height < 198){
        return 590;
    }
    if(198 <= height && height < 200){
        return 610;
    }
    if(200 <= height && height < 203){
        return 620;
    }
    if(203 <= height && height < 205){
        return 640;
    }
    if(205 <= height && height < 208){
        return 660;
    }
    if(208 <= height && height < 210){
        return 670;
    }
    if(210 <= height && height < 213){
        return 690;
    }
    if(213 <= height){
        return 710;
    }
    return 150;
}
int Screen_Pacient_Data::fitHeightMaleWithData(int height){
    if(height <= 153){
        return 350;
    }
    if(154 <= height && height < 157){
        return 370;
    }
    if(157 <= height && height < 160){
        return 380;
    }
    if(160 <= height && height < 162){
        return 400;
    }
    if(162 <= height && height < 165){
        return 410;
    }
    if(165 <= height && height < 167){
        return 430;
    }
    if(167 <= height && height < 170){
        return 450;
    }
    if(170 <= height && height < 172){
        return 460;
    }
    if(172 <= height && height < 175){
        return 480;
    }
    if(175 <= height && height < 177){
        return 500;
    }
    if(177 <= height && height < 180){
        return 510;
    }
    if(180 <= height && height < 182){
        return 530;
    }
    if(182 <= height && height < 185){
        return 540;
    }
    if(185 <= height && height < 187){
        return 560;
    }
    if(187 <= height && height < 190){
        return 570;
    }
    if(190 <= height && height < 193){
        return 590;
    }
    if(193 <= height && height < 195){
        return 610;
    }
    if(195 <= height && height < 198){
        return 620;
    }
    if(198 <= height && height < 200){
        return 640;
    }
    if(200 <= height && height < 203){
        return 660;
    }
    if(203 <= height && height < 205){
        return 670;
    }
    if(205 <= height && height < 208){
        return 690;
    }
    if(208 <= height && height < 210){
        return 700;
    }
    if(210 <= height && height < 213){
        return 720;
    }
    if(213 <= height){
        return 740;
    }
    return 150;
}
void Screen_Pacient_Data::showKeyBoardonPlainTextEdit(QPlainTextEdit *widget)
{
    bool shown = false;
    if(teclado != nullptr){
        if(!teclado->isHidden()){
            shown = true;
        }
        delete teclado;
    }
    teclado = new KeyBoard(this, widget, false, 800, 228, 0, 252);
    teclado->setWidget(widget);
    qDebug()<<widget->objectName();
    if(shown){
        teclado->show();
    }else{
        teclado->showKeyBoard();
    }
    if(!pt_on_upPosition){
        pt_on_upPosition = true;
        animateWidgetDownToUp(ui->pt_comentarios);
        animateWidgetDownToUp(ui->l_icon_comentarios);
    }
    QObject::connect(teclado, &KeyBoard::closeKeyboard, this, &Screen_Pacient_Data::moveDownPlaintextEdit);
}

void Screen_Pacient_Data::moveDownPlaintextEdit(){
    pt_on_upPosition = false;
    QObject::disconnect(teclado, &KeyBoard::closeKeyboard, this, &Screen_Pacient_Data::moveDownPlaintextEdit);
    animateWidgetUpToDown(ui->pt_comentarios);
    animateWidgetUpToDown(ui->l_icon_comentarios);
}

void Screen_Pacient_Data::animateWidgetDownToUp(QWidget *widget, int anim_time){ //mueve el widget de donde esta hacia arriba
    QRect startValue = widget->geometry();
    QRect endValue = QRect(startValue.x(),startValue.y() - startValue.height()
                           ,startValue.width(), startValue.height());
    QPropertyAnimation *animation = new QPropertyAnimation(widget, "geometry");
    animation->setDuration(anim_time);
    animation->setStartValue(startValue);
    animation->setEndValue(endValue);
    animation->start();
}
void Screen_Pacient_Data::animateWidgetUpToDown(QWidget *widget, int anim_time){

    QRect startValue = widget->geometry();
    QRect endValue = QRect(startValue.x(),startValue.y() + startValue.height()
                           ,startValue.width(), startValue.height());
    QPropertyAnimation *animation = new QPropertyAnimation(widget, "geometry");
    animation->setDuration(anim_time);
    animation->setStartValue(startValue);
    animation->setEndValue(endValue);
    animation->start();
}

void Screen_Pacient_Data::showKeyBoard(QLineEdit *widget)
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
    teclado = new KeyBoard(this, widget, numeric, 800, 228, 0, 252);
    teclado->setWidget(widget);
    qDebug()<<widget->objectName();
    if(shown){
        teclado->show();
    }else{
        teclado->showKeyBoard();
    }
}

void Screen_Pacient_Data::close_Screen_Pacient_Data(){

    PacientClass pacient(ui->le_nombre->text().trimmed(), ui->le_edad->text());
    pacient.ID = ui->le_CI_HC->text();
    pacient.sexo_paciente = ui->le_sexo->text();
    pacient.age_pacient = ui->le_edad->text();
    pacient.height = ui->le_height->text();
    pacient.weight = ui->le_weight->text();
    pacient.comentarios = ui->pt_comentarios->toPlainText();

    emit closed_Screen_Pacient_Data(pacient);
    close();
}


void Screen_Pacient_Data::on_pb_aceptar_clicked()
{
    close_Screen_Pacient_Data();
}

void Screen_Pacient_Data::setFechaHora(QDateTime datetime)
{
    emit settedFechaHora(datetime);
}


void Screen_Pacient_Data::on_pb_ajustar_fecha_hora_clicked()
{ 
    Screen_DateTime *dt = new Screen_DateTime(this);
    QObject::connect(dt, &Screen_DateTime::fechaHora, this, &Screen_Pacient_Data::setFechaHora);
    dt->showCenter();
    ui->pb_ajustar_fecha_hora->setChecked(false);
}

void Screen_Pacient_Data::on_le_height_editingFinished()
{
    bool ok;
    QString height_string = ui->le_height->text();
    int height = height_string.toInt(&ok);
    if(ok){
        if(height > 300 || height < 100){
            MessageDialog *mess = new MessageDialog(this, "Fuera de Rango", "La estatura debe estar entre 300cm y 100cm");
            mess->show();
            ui->le_height->clear();
        }
    }
}

void Screen_Pacient_Data::on_le_edad_editingFinished()
{
    bool ok;
    QString age_string = ui->le_edad->text();
    int age = age_string.toInt(&ok);
    if(ok){
        if(age > 120 || age < 0){
            MessageDialog *mess = new MessageDialog(this, "Fuera de Rango", "La edad debe estar entre 0 y 120 años");
            mess->show();
            ui->le_edad->clear();
        }
    }
}

void Screen_Pacient_Data::on_le_weight_editingFinished()
{
    bool ok;
    QString weight_string = ui->le_weight->text();
    int weight = weight_string.toInt(&ok);
    if(ok){
        if(weight > 200 || weight < 5){
            MessageDialog *mess = new MessageDialog(this, "Fuera de Rango", "El peso debe estar entre 5kg y 200kg");
            mess->show();
            ui->le_weight->clear();
        }
    }
}
