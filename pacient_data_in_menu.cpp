#include "pacient_data_in_menu.h"
#include "ui_pacient_data_in_menu.h"
#include <QDebug>
#include "download_data.h"
#include "messagedialog.h"
Pacient_Data_in_Menu::Pacient_Data_in_Menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Pacient_Data_in_Menu)
{
    ui->setupUi(this);

    QObject::connect(ui->le_nombre, &MyLineEdit::pressedLineEdit, this, &Pacient_Data_in_Menu::showKeyBoard);
    QObject::connect(ui->le_CI_HC, &MyLineEdit::pressedLineEdit, this, &Pacient_Data_in_Menu::showKeyBoard);
    QObject::connect(ui->le_sexo, &MyLineEdit::pressedLineEdit, this, &Pacient_Data_in_Menu::showKeyBoard);
    QObject::connect(ui->le_edad, &MyLineEdit::pressedLineEdit, this, &Pacient_Data_in_Menu::showKeyBoard);
    QObject::connect(ui->le_height, &MyLineEdit::pressedLineEdit, this, &Pacient_Data_in_Menu::showKeyBoard);
    QObject::connect(ui->le_weight, &MyLineEdit::pressedLineEdit, this, &Pacient_Data_in_Menu::showKeyBoard);

    QObject::connect(ui->pt_comentarios, &MyPlainTextEdit::pressedPlainTextEdit, this, &Pacient_Data_in_Menu::showKeyBoardonPlainTextEdit);

}

Pacient_Data_in_Menu::~Pacient_Data_in_Menu()
{
    delete ui;
}

void Pacient_Data_in_Menu::setPacientData(const PacientClass &pacient){
    if(pacient.has_name){
        ui->le_nombre->setText(pacient.name_pacient);
    }
    ui->le_edad->setText(pacient.age_pacient);
    ui->le_CI_HC->setText(pacient.ID);
    ui->le_weight->setText(pacient.weight);
    ui->le_height->setText(pacient.height);
    ui->le_sexo->setText(pacient.sexo_paciente);
    ui->pt_comentarios->setPlainText(pacient.comentarios);

    bool has_name = pacient.has_name;
    this->pacient.operator_equal(pacient);
    this->pacient.has_name = has_name;
}

void Pacient_Data_in_Menu::showKeyBoardonPlainTextEdit(QPlainTextEdit *widget)
{
    bool shown = false;
    if(teclado != nullptr){
        if(!teclado->isHidden()){
            shown = true;
        }
        delete teclado;
    }
    teclado = new KeyBoard(this, widget, false, 580, 200, 0, 155);
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
    }
    QObject::connect(teclado, &KeyBoard::closeKeyboard, this, &Pacient_Data_in_Menu::moveDownPlaintextEdit);

}

void Pacient_Data_in_Menu::moveDownPlaintextEdit(){
    pt_on_upPosition = false;
    QObject::disconnect(teclado, &KeyBoard::closeKeyboard, this, &Pacient_Data_in_Menu::moveDownPlaintextEdit);
    animateWidgetUpToDown(ui->pt_comentarios);
}

void Pacient_Data_in_Menu::animateWidgetDownToUp(QWidget *widget, int anim_time){ //mueve el widget de donde esta hacia arriba
    QRect startValue = widget->geometry();
    QRect endValue = QRect(startValue.x(),startValue.y() - startValue.height()
                           ,startValue.width(), startValue.height());


    QPropertyAnimation *animation = new QPropertyAnimation(widget, "geometry");
    animation->setDuration(anim_time);
    animation->setStartValue(startValue);
    animation->setEndValue(endValue);
    animation->start();
}
void Pacient_Data_in_Menu::animateWidgetUpToDown(QWidget *widget, int anim_time){

    QRect startValue = widget->geometry();
    QRect endValue = QRect(startValue.x(),startValue.y() + startValue.height()
                           ,startValue.width(), startValue.height());

    QPropertyAnimation *animation = new QPropertyAnimation(widget, "geometry");
    animation->setDuration(anim_time);
    animation->setStartValue(startValue);
    animation->setEndValue(endValue);
    animation->start();
}

void Pacient_Data_in_Menu::showKeyBoard(QLineEdit *widget)
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
    teclado = new KeyBoard(this, widget, numeric, 580, 200, 0, 155);
    teclado->setWidget(widget);
    qDebug()<<widget->objectName();
    if(shown){
        teclado->show();
    }else{
        teclado->showKeyBoard();
    }
}

void Pacient_Data_in_Menu::on_pb_aceptar_clicked()
{
    bool save_old_data = false;
    QString old_dir, old_name;
    QString name = ui->le_nombre->text().trimmed();
    QString edad = ui->le_edad->text();
    if(!name.isEmpty()){
        if(!pacient.has_name){
            //Copy all previous content to new folder with correct name
            save_old_data = true;
            old_dir = pacient.getMainDir();
            old_name = pacient.name_pacient;
        }

        if(name != pacient.name_pacient){
            pacient.operator_equal(PacientClass(name, edad));
            if(save_old_data){
                Download_Data::copyRecursively(old_dir, pacient.getMainDir());
                QDir dir(old_dir);
                dir.removeRecursively();
                dir.setPath(pacient.getMainDir());
                if (dir.exists()) {  ///cambiando el nombre de los archivos sin nombre por el nuevo
                    Q_FOREACH(QFileInfo info, dir.entryInfoList(QDir::Files)) {
                        QString filename = info.absoluteFilePath();
                        QString newName = filename, new_name_old = filename;

                        new_name_old = newName.replace(old_name, name + "_previousFile");
                        newName = newName.replace(old_name, name);

                        if(QFile::exists(newName)){
                            QFile::rename(newName, new_name_old);
                        }
                        QFile::rename(filename, newName);
                    }

                }
            }
        }
        pacient.comentarios = ui->pt_comentarios->toPlainText();
        pacient.ID = ui->le_CI_HC->text().trimmed();
        pacient.weight = ui->le_weight->text();
        pacient.sexo_paciente = ui->le_sexo->text();
        pacient.height= ui->le_height->text();
        emit sendPacient(pacient);
    }
    emit aceptedChanges();
}

void Pacient_Data_in_Menu::on_le_height_editingFinished()
{
    bool ok;
    QString height_string = ui->le_height->text();
    int height = height_string.toInt(&ok);
    if(ok){
        if(height > 300 || height < 100){
            MessageDialog *mess = new MessageDialog(this, "Fuera de Rango", "La estatura debe estar entre 300cm y 100cm");
            mess->showCenter();
            ui->le_height->clear();
        }
    }
}

void Pacient_Data_in_Menu::on_le_edad_editingFinished()
{
    bool ok;
    QString age_string = ui->le_edad->text();
    int age = age_string.toInt(&ok);
    if(ok){
        if(age > 120 || age < 0){
            MessageDialog *mess = new MessageDialog(this, "Fuera de Rango", "La edad debe estar entre 0 y 120 años");
            mess->showCenter();
            ui->le_edad->clear();
        }
    }
}

void Pacient_Data_in_Menu::on_le_weight_editingFinished()
{
    bool ok;
    QString weight_string = ui->le_weight->text();
    int weight = weight_string.toInt(&ok);
    if(ok){
        if(weight > 200 || weight < 5){
            MessageDialog *mess = new MessageDialog(this, "Fuera de Rango", "El peso debe estar entre 5kg y 200kg");
            mess->showCenter();
            ui->le_weight->clear();
        }
    }
}
