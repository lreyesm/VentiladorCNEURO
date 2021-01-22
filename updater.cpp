#include "updater.h"
#include "ui_updater.h"
#include <QFileDialog>
#include <QDebug>
#include <QDateTime>
#include "processesclass.h"

Updater::Updater(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Updater)
{
    ui->setupUi(this);

//    ProcessesClass::executeProcess(this, "sudo /home/pi/Ventilador/Ventilador/scripts/Update", ProcessesClass::LINUX, 100);
}

Updater::~Updater()
{
    delete ui;
}

void Updater::on_pb_update_arduino_clicked()
{
    updateVentilatorArduino("/media/pi/");
}

void Updater::on_pb_update_raspberry_pi_qt_clicked()
{
    updateVentilatorQt("/media/pi/", "/home/pi/Ventilador/Ventilador/");
}

void Updater::on_pb_close_clicked()
{
    this->close();
}


QStringList Updater::searchIntoDrives(QStringList &list_Drives, QDir &dir){ //Retorna lista de carpetas

    QStringList list_folders;
    list_Drives = dir.entryList(QDir::AllDirs | QDir::NoDotAndDotDot);
    list_Drives.removeAll("");
    list_Drives.removeAll("BOOT");
    list_Drives.removeAll("BOOT1");

    if(!list_Drives.isEmpty()){
        QString drive;
        qDebug()<<"Drives:";

        ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText() + "\n\n" +"Drives:");
        foreach (drive, list_Drives) {
            qDebug()<<drive;
            ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText() + "\n" +drive);
            if(!drive.isEmpty()){
                dir.setPath(dir.path() + "/" + drive);

                list_folders = dir.entryList(QDir::AllDirs | QDir::NoDotAndDotDot);

                return list_folders;
            }
        }
    }
    else{
        qDebug()<<"No hay dispositivo conectado";
        ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText() + "\n" +"No hay dispositivo conectado");
    }
    return QStringList();
}

QStringList Updater::searchIntoFolders(QStringList list_folders, QDir &dir)
{
    QStringList list_files;

    QString folder;
    qDebug()<<"Folders:";
    ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText() + "\n\n" +"Folders:");
    foreach (folder, list_folders) {
        qDebug()<<folder;
        ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText() + "\n" +folder);
        if(!folder.isEmpty() && folder.contains("Neuronic", Qt::CaseInsensitive)
                && (folder.contains("Update", Qt::CaseInsensitive) || folder.contains("Actualiza", Qt::CaseInsensitive))){
            dir.setPath(dir.path() + "/" + folder);
            list_files = dir.entryList(QDir::Files);

            return list_files;

        }
    }
    return QStringList();
}

QStringList Updater::searchFilesAndLoadUpdateQt(QStringList list_files, QDir &dir, QString dir_destiny)
{
    qDebug()<<"Files:";
    ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText() + "\n" +"\nFiles:");
    QString file;
    foreach (file, list_files) {
        qDebug()<<file;
        ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText() + "\n" +file);
        if(file.contains("Ventilador", Qt::CaseInsensitive)){

            QDir dir_act = QDir::current();
            dir_act.setPath(dir_destiny);
            if(!dir_act.exists()){
                dir_act.mkpath(dir_act.path());
            }

            QFile file_source(dir.path() + "/" +file);
            QFile file_destiny(dir_act.path() + "/" +file);
            if(file_source.exists()){
                qDebug()<<"file_source exist";
                ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText() + "\n" +"file_source exist");
            }else{
                qDebug()<<"file_source does not exist";
                ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText() + "\n" +"file_source does not exist");
            }
            if(file_destiny.exists()){
                qDebug()<<"file_destiny exist";
                ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText() + "\n" +"file_destiny exist");
                //                QFile::copy(file_destiny.fileName(),
                //                                               file_destiny.fileName()+ "_" + QDateTime::currentDateTime().toString("yyyyMMddHHmmss"))
                if(file_destiny.rename(file_destiny.fileName(), file_destiny.fileName()+ "_"
                                       + QDateTime::currentDateTime().toString("yyyyMMddHHmmss"))){
                    qDebug()<<"backup success";
                    ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText() + "\n" +"backup success");
                }else{
                    qDebug()<<"backup not success";
                    ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText() + "\n" +"backup not success");
                }

            }else{
                qDebug()<<"file_destiny does not exist";
                ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText() + "\n" +"file_destiny does not exist");
            }

            qDebug()<<file_source.fileName();
            ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText() + "\n" +file_source.fileName());
            qDebug()<<file_destiny.fileName();
            ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText() + "\n" +file_destiny.fileName());

            if(QFile::copy(dir.path() + "/" +file,
                           dir_act.path() + "/" +file)){
                qDebug()<<"copy success";
                ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText() + "\n" +"copy success");
            }else{
                qDebug()<<"copy not success";
                ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText() + "\n" +"copy not success");
            }
        }
    }
}

bool Updater::searchFilesAndLoadUpdateArduino(QStringList list_files, QDir &dir)
{
    qDebug()<<"Files:";
    ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText() + "\n\n" +"Files:");
    QString file;
    foreach (file, list_files) {
        qDebug()<<file;
        ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText() + "\n" +file);
        if(file.contains(".hex", Qt::CaseInsensitive)){

            QFile file_source(dir.path() + "/" +file);

            if(file_source.exists()){
                qDebug()<<"file_source exist";
                ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText() + "\n" +"file_source exist");
                qDebug()<<file_source.fileName();
                ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText() + "\n" +file_source.fileName());
//                SerialPort *serialPort = new SerialPort(this);
//                serialPort->openPort();
                QString cmdline = "/usr/share/arduino/hardware/tools/avrdude -C/usr/share/arduino/hardware/tools/avrdude.conf "
                                  "-v -v -v -v -patmega2560 -cwiring -P/dev/ttyACM0 -b115200 -D -Uflash:w:" ////ttyACM0 - serial0 (con este es necesario abrir el puerto)
                        +file_source.fileName() + ":i";
                qDebug()<<"Burning code: "+file+" ...";
                ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText() + "\n\n" + "Burning code: "+file+" ...");
                QString result = ProcessesClass::executeProcess(this, cmdline, ProcessesClass::LINUX, 1000);
                ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText() + "\n" +result);
                return true;
            }else{
                qDebug()<<"file_source does not exist";
                ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText() + "\n" +"file_source does not exist");
            }

        }
    }
    return false;
}

void Updater::updateVentilatorQt(QString dir_source, QString dir_destiny){
    ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText() +"Updating ventilator Qt app...\n");
    QDir dir = QDir::current();
    dir.setPath(dir_source); ///media/pi/ADATA UFD

    QStringList list_files, list_folders, list_Drives;

    list_folders = searchIntoDrives(list_Drives, dir);
    list_files = searchIntoFolders(list_folders, dir);
    searchFilesAndLoadUpdateQt(list_files, dir, dir_destiny);
}

void Updater::updateVentilatorArduino(QString dir_source){
    ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText() +"Updating Arduino .hex...\n");
    QDir dir = QDir::current();
    dir.setPath(dir_source); ///media/pi/ADATA UFD

    QStringList list_files, list_folders, list_Drives;

    list_folders = searchIntoDrives(list_Drives, dir);
    list_files = searchIntoFolders(list_folders, dir);

    searchFilesAndLoadUpdateArduino(list_files, dir);
}
