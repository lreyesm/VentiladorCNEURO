#include "download_data.h"
#include "ui_download_data.h"
#include <QDebug>
#include "messagedialog.h"
#include <QScrollerProperties>
#include <QScroller>
#include "processesclass.h"
#include <QScrollBar>
#include "optionsselector.h"
#include "loadinganimation.h"
#include "mainwindow.h"

Download_Data::Download_Data(QWidget *parent, QString pacient_name) :
    QWidget(parent),
    ui(new Ui::Download_Data)
{
    ui->setupUi(this);
    ui->l_descargar_paciente->setThirdState(false);

    QString name_files =  pacient_name.replace(":", "_").replace("-", "_");

    QDir dir = QDir::current();
    dir.cdUp();
    dir_pacientes = dir.path() + "/" + "Pacientes/";

    dir.setPath(dir.path() + "/" + "Pacientes/" + name_files);
    dir_paciente = dir.path();

    if(!dir.exists()){
        dir.mkpath(dir.path());
    }

    lista_pacientes = searchPacientsData(dir_pacientes);

    ui->listWidget->addItems(lista_pacientes);

    ui->l_page->setText(getCurrentPageString(current_page));

    ui->listWidget->verticalScrollBar()->setStyleSheet("QScrollBar:vertical { width: 25px;}");

    QString res = removeUSBMocks();

    connect(ui->listWidget->verticalScrollBar(), &QScrollBar::valueChanged, this, &Download_Data::onScrollerChanged);
}

void Download_Data::onScrollerChanged(int value){
    QAbstractItemModel* model = ui->listWidget->model();
    int num_rows = model->rowCount();
    double den = LOGS_IN_SCREEN;
    int currentPage;
    double div = ceil(num_rows/den);
    if(value >= num_rows - LOGS_IN_SCREEN){
        currentPage = static_cast<int>(div) - 1;
    }else{
        currentPage = static_cast<int>(value / den);
    }

    if(div < 1){
        div = 1;
    }
    QString view = QString::number(currentPage+1)+"/"+
            QString::number(static_cast<int>(div));
    ui->l_page->setText(view);

    current_page = currentPage;
}

Download_Data::~Download_Data()
{
    delete ui;
}

bool Download_Data::copyRecursively(const QString &srcFilePath, const QString &tgtFilePath)
{
    QFileInfo srcFileInfo(srcFilePath);
    if (srcFileInfo.isDir()) {
        QDir targetDir(tgtFilePath);
        targetDir.cdUp();
        if(QFile::exists(QFileInfo(tgtFilePath).fileName())){
            QFile::remove(QFileInfo(tgtFilePath).fileName());
        }
        if (!targetDir.mkpath(QFileInfo(tgtFilePath).fileName()))
            return false;
        QDir sourceDir(srcFilePath);
        QStringList fileNames = sourceDir.entryList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot | QDir::Hidden | QDir::System);
        foreach (const QString &fileName, fileNames) {
            const QString newSrcFilePath
                    = srcFilePath + QLatin1Char('/') + fileName;
            const QString newTgtFilePath
                    = tgtFilePath + QLatin1Char('/') + fileName;
            if (!copyRecursively(newSrcFilePath, newTgtFilePath)){
                return false;
            }
        }
    } else {
        if(QFile::exists(tgtFilePath)){
            QFile::remove(tgtFilePath);
        }
        if (!QFile::copy(srcFilePath, tgtFilePath))
            return false;
    }
    return true;
}

QStringList Download_Data::searchPacientsData(QString dir_source){

    QDir dir = QDir::current();
    dir.setPath(dir_source); ///...Pacientes/

    QStringList list_Pacient_folders = dir.entryList(QDir::AllDirs | QDir::NoDotAndDotDot);
    //    for(int i=0; i < list_Pacient_folders.size(); i++){
    //        list_Pacient_folders[i].replace("_", " ");
    //    }
    return list_Pacient_folders;
}

void Download_Data::searchData(QString dir_destiny){

    QDir dir = QDir::current();
    dir.setPath(dir_destiny); ///media/pi/ADATA UFD

    QStringList list_files, list_folders;

    folder_to_copy = searchDrivesAndCreateDir(dir);
}
bool Download_Data::checkIfUSBConnected(){ //devuelve true si hay USB conectada
    QDir dir("/media/pi/");
    QStringList list_Drives = dir.entryList(QDir::AllDirs | QDir::NoDotAndDotDot);
    list_Drives.removeAll("");

    if(list_Drives.isEmpty()){
        qDebug()<<"No hay dispositivo conectado";
        return false;
    }
    return true;
}
void Download_Data::selectedDrive(QString drive){
    selected_drive = drive;
}

QString Download_Data::searchDrivesAndCreateDir(QDir &dir){ //Retorna lista de carpetas
    QStringList list_Drives = dir.entryList(QDir::AllDirs | QDir::NoDotAndDotDot, QDir::Time);
    list_Drives.removeAll("");

    if(!list_Drives.isEmpty()){
        QString drive;
        qDebug()<<"Drives:";

        OptionsSelector *optionsSelector = new OptionsSelector(this, list_Drives);
        QEventLoop loop;
        connect(optionsSelector, &OptionsSelector::selected_option, this, &Download_Data::selectedDrive);
        connect(optionsSelector, &OptionsSelector::selected, &loop, &QEventLoop::quit);
        optionsSelector->moveCenter();
        optionsSelector->show();
        optionsSelector->raise();
        loop.exec();
        if(!selected_drive.isEmpty()) {
            drive = selected_drive;
            qDebug()<<drive;
            //                if(list_Drives.contains(drive +"1"))
            //                    drive += "1";
            dir.setPath(dir.path() + "/" + drive);

            drivePath = dir.path();

            dir.setPath(dir.path() + "/Neuronic " + nombre_equipo);

            if(!dir.exists()){
                dir.mkpath(dir.path());
            }

            return dir.path();
        }
    }
    else{
        qDebug()<<"No hay dispositivo conectado";
    }
    return "";
}

void Download_Data::on_listWidget_pressed(const QModelIndex &index)
{
    paciente_seleccionado = lista_pacientes.at(index.row()).trimmed();

    QDir dir = QDir::current();
    dir.cdUp();

    dir.setPath(dir.path() + "/" + "Pacientes/" + paciente_seleccionado);
    dir_paciente = dir.path();

    ui->l_descargar_paciente->setChecked(false);
}

void Download_Data::on_l_descargar_todos_clicked()
{
    setCopyingState(1);

    searchData(rootFolder);

    ui->l_descargar_todos->setChecked(false);

    LoadingAnimation *animation = new LoadingAnimation(this, "Copiando Archivos...");
    animation->centerWidget();
    animation->showLoadingAnimation(false);
    animation->showAnimation();
    connect(this, &Download_Data::stopAnimation,
            animation, &LoadingAnimation::stopAnimation);
    QTimer::singleShot(300, this, &Download_Data::initCopyAll);
}

void Download_Data::on_l_descargar_paciente_clicked()
{
    setCopyingState(1);

    searchData(rootFolder);

    ui->l_descargar_paciente->setChecked(false);

    LoadingAnimation *animation = new LoadingAnimation(this, "Copiando Archivos...");
    animation->centerWidget();
    animation->showLoadingAnimation(false);
    animation->showAnimation();
    connect(this, &Download_Data::stopAnimation,
            animation, &LoadingAnimation::stopAnimation);
    QTimer::singleShot(300, this, &Download_Data::initCopyPacient);
}
void Download_Data::initCopyPacient(){
    if(!QFile::exists(dir_paciente)){
        MessageDialog *message = new MessageDialog(this, "Error", "No se encontró datos para copiar");
        message->showCenter();
    }
    else if(!folder_to_copy.isEmpty()){
        if(copyRecursively(dir_paciente, folder_to_copy + "/Pacientes/" + paciente_seleccionado)){
            //            animation->stopAnimation();
            MessageDialog *message = new MessageDialog(this, "Éxito", "Datos descargados correctamente");
            message->showCenter();
        }else{
            MessageDialog *message = new MessageDialog(this, "Error", "No hay dispositivo conectado");
            message->showCenter();
        }
    }else{
        //        animation->stopAnimation();
        MessageDialog *message = new MessageDialog(this, "Error", "No hay dispositivo conectado");
        message->showCenter();
    }
    emit stopAnimation();
    setCopyingState(0);
}
void Download_Data::initCopyAll(){
    if(!QFile::exists(dir_pacientes)){
        MessageDialog *message = new MessageDialog(this, "Error", "No se encontró datos para copiar");
        message->showCenter();
    }
    else if(!folder_to_copy.isEmpty()){
        if(copyRecursively(dir_pacientes, folder_to_copy + "/Pacientes")){
            //            animation->stopAnimation();
            MessageDialog *message = new MessageDialog(this, "Éxito", "Todos descargados correctamente");
            message->showCenter();
        }else{
            MessageDialog *message = new MessageDialog(this, "Error", "No hay dispositivo conectado");
            message->showCenter();
        }
    }else{
        //        animation->stopAnimation();
        MessageDialog *message = new MessageDialog(this, "Error", "No hay dispositivo conectado");
        message->showCenter();
    }
    emit stopAnimation();
    setCopyingState(0);
}

void Download_Data::on_l_eject_memory_clicked()
{
    if(checkIfUSBConnected()){
        ProcessesClass::executeProcess(this, "sudo umount /dev/sda");
        ProcessesClass::executeProcess(this, "sudo udisksctl power-off -b /dev/sda");

        ProcessesClass::executeProcess(this, "sudo umount /dev/sda1");
        ProcessesClass::executeProcess(this, "sudo udisksctl power-off -b /dev/sda1");

        QString res = removeUSBMocks();

        MessageDialog *message = new MessageDialog(this, "Ejectada", "Memoria removida correctamente");
        message->showCenter();
    }
    else{
        MessageDialog *message = new MessageDialog(this, "No ejectada", "No hay dispositivo conectado");
        message->showCenter();
    }
}
QString Download_Data::removeUSBMocks(){
    QString response = "";
    QDir dir(rootFolder);
    QStringList list_Drives = dir.entryList(QDir::AllDirs | QDir::NoDotAndDotDot);
    list_Drives.removeAll("");

    QString penDrives = ProcessesClass::executeProcess(this, "lsusb");

    if(penDrives.contains("Device 001")){
        penDrives.remove("Device 001");
        penDrives.remove("Device 002");
        qDebug()<<"****************** penDrives *******************";
        qDebug()<<penDrives;
        qDebug()<<"****************** end penDrives *******************";
        if(!penDrives.contains("Device ")){
            if(!list_Drives.isEmpty()){
                QString drive;
                qDebug()<<"Drives to delete: ";
                QString command = "";
                foreach (drive, list_Drives) {
                    qDebug()<<drive;
                    if(!drive.isEmpty()){
                        dir.setPath(dir.path() + "/" + drive);
                        //                    QStringList subfolders = dir.entryList(QDir::Files | QDir::AllDirs | QDir::NoDotAndDotDot );
                        QString removeCommand = "sudo rm -rf \"" + dir.path() + "\"";
                        qDebug()<<"Dir to delete: " << removeCommand;
                        command += removeCommand + " && ";
                    }
                }
                command = command.trimmed().remove(command.length() - 3, 2);
                response = ProcessesClass::executeProcess(this, command,
                                                          ProcessesClass::LINUX, 800, true);
                qDebug()<<"command to delete: " << command;
                qDebug()<<"response to delete: " << response;

            }
        }
    }
    return response;
}
QString Download_Data::getCurrentPageString(int currentPage){
    QAbstractItemModel* model = ui->listWidget->model();
    int num_rows = model->rowCount();
    double den = LOGS_IN_SCREEN;
    double div = ceil(num_rows/den);
    if(div < 1){
        div = 1;
    }
    QString view = QString::number(currentPage+1)+"/"+
            QString::number(static_cast<int>(div));
    return view;
}
void Download_Data::on_l_down_trigger_clicked()
{
    QAbstractItemModel* model = ui->listWidget->model();
    int num_rows = model->rowCount();
    if(current_page > 0){
        current_page--;
    }
    if(num_rows > current_page*LOGS_IN_SCREEN){
        ui->listWidget->scrollToItem(ui->listWidget->item(current_page*LOGS_IN_SCREEN),
                                     QAbstractItemView::PositionAtTop);
    }
    //    ui->l_page->setText(getCurrentPageString(current_page));
}

void Download_Data::on_l_up_trigger_clicked()
{
    QAbstractItemModel* model = ui->listWidget->model();
    int num_rows = model->rowCount();
    if(num_rows > (current_page + 1)*LOGS_IN_SCREEN){
        current_page++;
    }
    if(num_rows > current_page*LOGS_IN_SCREEN){
        ui->listWidget->scrollToItem(ui->listWidget->item(current_page*LOGS_IN_SCREEN),
                                     QAbstractItemView::PositionAtTop);
    }
    //    ui->l_page->setText(getCurrentPageString(current_page));
}

MainWindow* Download_Data::getMainWindowInstance(){
    MainWindow *mainWindow = qobject_cast<MainWindow*>(this->parent()->parent());
    if(mainWindow){
        qDebug()<<"Casteo OK";
        return mainWindow;
    }else{
        qDebug()<<"Casteo ERROR";
        return nullptr;
    }
}

void Download_Data::setCopyingState(float state){
    MainWindow *w = getMainWindowInstance();
    if( w ){
        //setear estado de calibracion de presion s1
        w->setCopyingState(state);
    }
}
