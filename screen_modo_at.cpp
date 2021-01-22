#include "screen_modo_at.h"
#include "ui_screen_modo_at.h"
#include "processesclass.h"
#include "mainwindow.h"
#include "dialog_question.h"
#include "loadinganimation.h"
#include "passwordrequest.h"
#include <QTimer>
#include "globals_settings.h"
#include "screen_apagado_sistema.h"

Screen_Modo_AT::Screen_Modo_AT(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Screen_Modo_AT)
{
    ui->setupUi(this);    
    ui->l_version->setText(version_software);
    if(QApplication::desktop()->width() < 1366){
        setWindowFlags(Qt::CustomizeWindowHint);
        this->setCursor(Qt::BlankCursor);
    }
    this->move(0, 0);

    ui->cb_capnography_state->setChecked(MainWindow::capnography_active);
    ui->pb_fluke_controller->hide();

    PasswordRequest *passRequest = new PasswordRequest(this);
    passRequest->showCenter();

    QTimer::singleShot(500, this, SLOT(chequearConfiguracion()));
    QTimer::singleShot(800, this, SLOT(chequearConfiguracionMaxVolumen()));
}

Screen_Modo_AT::~Screen_Modo_AT()
{
    delete ui;
}
QStringList Screen_Modo_AT::searchIntoDrives(QStringList list_Drives, QDir &dir){ //Retorna lista de carpetas

    QStringList list_folders;
    list_Drives = dir.entryList(QDir::AllDirs | QDir::NoDotAndDotDot);
    list_Drives.removeAll("");

    QDir dirDrive(dir);

    if(!list_Drives.isEmpty()){
        QString drive;
        qDebug()<<"Drives:";

        foreach (drive, list_Drives) {
            dirDrive.setPath(dir.path());
            qDebug()<<drive;
            if(!drive.isEmpty()){
                dirDrive.setPath(dirDrive.path() + "/" + drive);

                list_folders = dirDrive.entryList(QDir::AllDirs | QDir::NoDotAndDotDot);
                if(list_folders.isEmpty()){
                    if(QFile::exists(dirDrive.path())){
                        QFile::remove(dirDrive.path());
                        qDebug()<<"Dir to delete: " << "sudo rmdir " + dirDrive.path();
                        ProcessesClass::executeProcess(this, "sudo rmdir "+ dirDrive.path(),
                                                           ProcessesClass::LINUX, 500, true);
                        continue;
                    }
                }
                QString folder;
                foreach (folder, list_folders) {
                    qDebug()<<folder;
                    if(!folder.isEmpty() && folder.contains("Neuronic", Qt::CaseInsensitive)
                            && (folder.contains("Update", Qt::CaseInsensitive) || folder.contains("Actualiza", Qt::CaseInsensitive))){
                        qDebug()<<"Drives Selected: "<<drive;
                        dir.setPath(dirDrive.path());
                        return list_folders;

                    }
                }
            }
        }
    }
    else{
        qDebug()<<"No hay dispositivo conectado";
    }
    return QStringList();
}

QStringList Screen_Modo_AT::searchIntoFolders(QStringList list_folders, QDir &dir)
{
    QStringList list_files;

    QString folder;
    qDebug()<<"Folders:";
    foreach (folder, list_folders) {
        qDebug()<<folder;
        if(!folder.isEmpty() && folder.contains("Neuronic", Qt::CaseInsensitive)
                && (folder.contains("Update", Qt::CaseInsensitive) || folder.contains("Actualiza", Qt::CaseInsensitive))){
            dir.setPath(dir.path() + "/" + folder);
            list_files = dir.entryList(QDir::Files);
            return list_files;

        }
    }
    return QStringList();
}

bool Screen_Modo_AT::searchFilesAndLoadUpdateQt(QStringList list_files, QDir &dir, QString dir_destiny)
{
    bool res = false;
    qDebug()<<"Files:";
    QString file;
    foreach (file, list_files) {
        qDebug()<<file;
        if(file.contains("Updater", Qt::CaseInsensitive)){

            QDir dir_act = QDir::current();
            dir_act.setPath(dir_destiny + "Update/");
            if(!dir_act.exists()){
                dir_act.mkpath(dir_act.path());
            }

            QFile file_source(dir.path() + "/" +file);
            QFile file_destiny(dir_act.path() + "/" +file);
            if(file_source.exists()){
                qDebug()<<"file_source exist";
            }else{
                qDebug()<<"file_source does not exist";
            }
            if(file_destiny.exists()){
                qDebug()<<"file_destiny exist";
                if(file_destiny.rename(file_destiny.fileName(), file_destiny.fileName()+ "_"
                                       + QDateTime::currentDateTime().toString("yyyyMMddHHmmss"))){
                    qDebug()<<"backup success";
                }else{
                    qDebug()<<"backup not success";
                }

            }else{
                qDebug()<<"file_destiny does not exist";
            }

            qDebug()<<file_source.fileName();
            qDebug()<<file_destiny.fileName();

            if(QFile::copy(dir.path() + "/" +file,
                           dir_act.path() + "/" +file)){
                qDebug()<<"copy success";
                return true;

            }else{
                qDebug()<<"copy not success";
            }
        }
        if(file.contains(".py", Qt::CaseInsensitive)){

            QDir dir_act = QDir::current();
            dir_act.setPath(dir_destiny + "Ventilador/Ventilador/scripts/");
            if(!dir_act.exists()){
                dir_act.mkpath(dir_act.path());
            }

            QFile file_source(dir.path() + "/" +file);
            QFile file_destiny(dir_act.path() + "/" +file);
            if(file_source.exists()){
                qDebug()<<"file_source exist";
            }else{
                qDebug()<<"file_source does not exist";
            }
            if(file_destiny.exists()){
                qDebug()<<"file_destiny exist";
                if(file_destiny.rename(file_destiny.fileName(), file_destiny.fileName()+ "_"
                                       + QDateTime::currentDateTime().toString("yyyyMMddHHmmss"))){
                    qDebug()<<"backup success";
                }else{
                    qDebug()<<"backup not success";
                }

            }else{
                qDebug()<<"file_destiny does not exist";
            }

            qDebug()<<file_source.fileName();
            qDebug()<<file_destiny.fileName();

            if(QFile::copy(dir.path() + "/" +file,
                           dir_act.path() + "/" +file)){
                qDebug()<<"copy success";
                res = true;
            }else{
                qDebug()<<"copy not success";
                res = false;
            }
        }
        if(file.contains("neuronic.png", Qt::CaseInsensitive)){

            QDir dir_act = QDir::current();
            dir_act.setPath("/usr/share/rpd-wallpaper/");
            if(!dir_act.exists()){
                dir_act.mkpath(dir_act.path());
            }

            QFile file_source(dir.path() + "/" +file);
            QFile file_destiny(dir_act.path() + "/" +file);
            if(file_source.exists()){
                qDebug()<<"file_source exist";
            }else{
                qDebug()<<"file_source does not exist";
            }
            if(file_destiny.exists()){
                qDebug()<<"file_destiny exist";
                if(file_destiny.rename(file_destiny.fileName(), file_destiny.fileName()+ "_"
                                       + QDateTime::currentDateTime().toString("yyyyMMddHHmmss"))){
                    qDebug()<<"backup success";
                }else{
                    qDebug()<<"backup not success";
                }

            }else{
                qDebug()<<"file_destiny does not exist";
            }

            qDebug()<<file_source.fileName();
            qDebug()<<file_destiny.fileName();

            if(QFile::copy(dir.path() + "/" +file,
                           dir_act.path() + "/" +file)){
                qDebug()<<"copy success";
                res = true;
            }else{
                qDebug()<<"copy not success";
                res = false;
            }
        }
    }
    return res;
}

void Screen_Modo_AT::updateVentilatorQt(QString dir_source, QString dir_destiny){
    QDir dir = QDir::current();
    dir.setPath(dir_source); ///media/pi/ADATA UFD

    QStringList list_files, list_folders, list_Drives;

    list_folders = searchIntoDrives(list_Drives, dir);
    if(list_folders.isEmpty()){
        return;
    }
    list_files = searchIntoFolders(list_folders, dir);
    if(list_files.isEmpty()){
        return;
    }
    searchFilesAndLoadUpdateQt(list_files, dir, dir_destiny);
}

void Screen_Modo_AT::on_pb_update_clicked()
{
    Dialog_Question *question = new Dialog_Question(this, "Confirmación", "Se actualizarán scripts de Python3 y fotos automáticamente"
                                                                          "\nal abrir pantalla de actualización. ¿Desea continuar?");
    question->resizeWidgetQuestion(600, 200);
    question->raise();
    connect(question, &Dialog_Question::aceptado, this, &Screen_Modo_AT::openUpdateApp);

}
void Screen_Modo_AT::openUpdateApp(){
    updateVentilatorQt("/media/pi/", "/home/pi/");

    SerialPort *serialPort = getSerialPortInstance();
    if(serialPort){
        if(serialPort->isOpen()){
            serialPort->close();
        }
    }
    QString pid;
    if(!checkIfClosed(pid)){
        closeTCP_IP_ClientAplication(pid);
    }
    qDebug()<<"Destroying";
    QTimer::singleShot(500, this, &Screen_Modo_AT::closeApplication);
    ProcessesClass::executeProcess(this, "sudo /opt/update_script.sh", ProcessesClass::LINUX, 1000, true);

    //    Updater* updater = new Updater(this);
    //    updater->show();
}

bool Screen_Modo_AT::closeTCP_IP_ClientAplication(QString pid){
    QString ans = ProcessesClass::executeProcess(this, "sudo kill "+pid, ProcessesClass::LINUX, 500, true);
    if(ans.trimmed().isEmpty()){
        return true;
    }
    return false;
}
bool Screen_Modo_AT::checkIfClosed(QString &pid){ //returna true si esta cerrada

    QString ps = ProcessesClass::executeProcess(this, "ps -eo pid,ppid,ni,comm", ProcessesClass::LINUX, 500, true);
    pid = ProcessesClass::executeProcess(this, "pidof TCP_IP_Client", ProcessesClass::LINUX, 500, true);
    if(ps.contains("Ventilador", Qt::CaseInsensitive)){
        return false; //Si tiene "Ventilador" la app esta abierta retorna false
    }else{
        if(pid.trimmed().isEmpty()){//Si no tiene "Ventilador" compruebo nuevamente con pidof
            return true;//Si el pidof esta vacio esta cerrada app retorno true
        }
    }
    return false;
}
void Screen_Modo_AT::on_pb_calibrate_pressure_s1_clicked()
{
    requestPressureS1Calibration();
}

void Screen_Modo_AT::on_pb_calibrate_pressure_s2_clicked()
{
    requestPressureS2Calibration();
}

void Screen_Modo_AT::on_pb_calibrate_volumen_clicked()
{
    requestVolumenCalibration();
}

void Screen_Modo_AT::closeApplication()
{
    QApplication::closeAllWindows();
}
void Screen_Modo_AT::on_pb_cerrar_clicked()
{
    Screen_Apagado_Sistema *screen_apagado =  new Screen_Apagado_Sistema(this, false); //false reboot
    screen_apagado->show();
    this->close();
}

void Screen_Modo_AT::on_cb_capnography_state_toggled(bool checked)
{    
    salvarConfiguraciondeCapnografia(checked);
    MainWindow *w = getMainWindowInstance();
    if( w ){
        //setear estado de calibracion de presion s1
        w->setCapnographyActive(checked);
        QString action = (checked)?"Activada":"Desactivada";
        ui->cb_capnography_state->setText("Capnografía "+action);
    }else{
        QString action = (checked)?"activada":"desactivada";
        MessageDialog *mess = new MessageDialog(this, "Error", "La capnografía no pudo ser "+action+", por favor reinicie, y reintente");
        mess->showCenter();
    }
}
void Screen_Modo_AT::chequearConfiguracion(){
    if(ui->cb_capnography_state->text() == "Capnografía"){
        bool checked = checkifCapnographyActive();
        ui->cb_capnography_state->setChecked(checked);
        on_cb_capnography_state_toggled(checked);
    }
}

bool Screen_Modo_AT::checkifCapnographyActive(){
    QFile file("capnographyConfig.dat");
    if(file.exists()){
        return true;
    }
    return false;
}
void Screen_Modo_AT::salvarConfiguraciondeCapnografia(bool activa){
    if(activa){
        QFile file("capnographyConfig.dat");
        if(file.open(QIODevice::WriteOnly))
        {

        }
    }else{
        QFile file("capnographyConfig.dat");
        if(file.exists()){
            file.remove();
        }
    }
}

MainWindow* Screen_Modo_AT::getMainWindowInstance(){
    MainWindow *mainWindow = qobject_cast<MainWindow*>(this->parent()->parent());
    if(mainWindow){
        qDebug()<<"Casteo OK";
        return mainWindow;
    }else{
        qDebug()<<"Casteo ERROR";
        return nullptr;
    }
}
SerialPort* Screen_Modo_AT::getSerialPortInstance(){
    MainWindow *mainWindow = getMainWindowInstance();
    if(mainWindow){
        SerialPort* sp = mainWindow->getSerialPortInstance();
        if(sp){
            return sp;
        }
    }
    return nullptr;
}
void Screen_Modo_AT::setDelay(QWidget *parent, int delayMs, QString text){
    QEventLoop *loop = new QEventLoop(this);
    QTimer::singleShot(delayMs, loop, &QEventLoop::quit);
    LoadingAnimation *animation = new LoadingAnimation(parent, text);
    animation->showAnimation();
    if(!loop->exec())
    {
        animation->stopAnimation();
    }
}
void Screen_Modo_AT::getPressure(){
    if(fluke_controller){
        if(fluke_controller->isOpenFlukeCommunication()){
            timer.stop();
            QList<QByteArray> respuesta = fluke_controller->getPressure();
            if(respuesta.size()>0){
                QByteArray ba = respuesta.first();
                QString str = QString::fromLatin1(ba);
                str.remove("\r");
                bool ok;
                float pressure = str.trimmed().toFloat(&ok);
                if(ok){
                    MainWindow *w = getMainWindowInstance();
                    if( w ){
                        //setear estado de calibracion de presion s1
                        w->setPressureFromFluke(pressure);
                    }
                }
            }
            timer.start();
            return;
        }
    }
}
void Screen_Modo_AT::getVolumen(){
    if(fluke_controller){
        if(fluke_controller->isOpenFlukeCommunication()){
            timer.stop();
            QList<QByteArray> respuesta = fluke_controller->getVolume();
            if(respuesta.size()>1){
                QByteArray ba = respuesta.at(1);
                QString str = QString::fromLatin1(ba);
                QStringList split =  str.split(",");
                QString floatVti_str="";
                if(split.size() > 2){
                    floatVti_str = split.at(2).trimmed();
                }
                if(!floatVti_str.isEmpty()){
                    bool ok;
                    float volumen = floatVti_str.trimmed().toFloat(&ok);
                    if(ok){
                        MainWindow *w = getMainWindowInstance();
                        if( w ){
                            //setear estado de calibracion de presion s1
                            w->setVolumenFromFluke(volumen);
                        }
                    }
                }
            }
            timer.start();
            return;
        }
    }
}


/////////////////////////Calibrasion de presion en sensor 1///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Screen_Modo_AT::requestPressureS1Calibration(){
    MainWindow *w = getMainWindowInstance();
    if( w ){
        //setear estado de calibracion de presion s1
        previousPmax = w->getPressureBeforeFluke();
    }
    Dialog_Question *question = new Dialog_Question(this, "Calibración de Presión Sensor 1", "Siga las instrucciones para la calibración"
                                                                                             "\nde presion del Sensor 1."
                                                                                             ""
                                                                                             "\n- Presione \"Aceptar\" para continuar.");
    question->resizeWidgetQuestion(600, 250);
    question->raise();
    connect(question, &Dialog_Question::accepted, this, &Screen_Modo_AT::requestPressureS1Point1Calibration);
}
void Screen_Modo_AT::requestPressureS1Point1Calibration(int ok){
    if(ok == 1){ //Aceptado
        fluke_controller = new ScreenFlukeController(this);

        if(fluke_controller){
            if(fluke_controller->isOpenFlukeCommunication()){
                fluke_controller->closeFlukeCommunication();
                setDelay(this, 3000, "Reiniciando conexión con Fluke...");
            }
            if(fluke_controller->openFlukeCommunication()){
                setDelay(this, 3000, "Estableciendo conexión con Fluke...");


                if(!fluke_controller->setMeasurementLowPressureUnit()){
                    errorPressureCalibration();
                    return;
                }
                setDelay(this, 1000, "Estableciendo unidad de Medición...");


                if(!fluke_controller->setMeasurementModeLowPressure()){
                    errorPressureCalibration();
                    return;
                }
                setDelay(this, 1000, "Estableciendo Medición de baja presión...");


                Dialog_Question *question = new Dialog_Question(this, "Calibración de presión punto 1",
                                                                "1 - Conecte uno de los extremos del circuito de caliración de"
                                                                "\n presión a la toma de presión positiva del analizador de flujo."
                                                                "\n\n2 - Conecte el segundo extremo del circuito de caliración de presión"
                                                                "\n a la toma de presión ubicada en la tapa lateral izquierda del PCUVENTE."
                                                                "\n\n3 - Conecte el extremo restante a la toma de presión de referencia."
                                                                "\n\n4 - Ajuste la presión al valor de referencia 1."
                                                                "\n\n- Presione \"Aceptar\" para iniciar la "
                                                                "\ncalibración y espere por el fin de calibración");
                question->resizeWidgetQuestion(700, 470);
                question->raise();
                connect(question, &Dialog_Question::accepted, this, &Screen_Modo_AT::startPressureS1Point1Calibration);
                timer.setInterval(1500);
                connect(&timer, &QTimer::timeout, this, &Screen_Modo_AT::getPressure);
                timer.start();
            }else{
                MessageDialog *mess = new MessageDialog(this, "Fluke no conectado", "Conecte el Fluke e intente nuevamente");
                connect(mess, &MessageDialog::aceptado, this, &Screen_Modo_AT::requestPressureS1Calibration);
                mess->showCenter();
            }
        }
    }
    else if(ok == 0){//Cancelado
        Dialog_Question *question = new Dialog_Question(this, "Saliendo de Calibración", "¿Desea cancelar calibración de Presión?");
        question->resizeWidgetQuestion(600, 200);
        question->raise();
        connect(question, &Dialog_Question::cancelado, this, &Screen_Modo_AT::requestPressureS1Calibration);
        connect(question, &Dialog_Question::aceptado, this, &Screen_Modo_AT::closeFlukeConnection);
    }
}
void Screen_Modo_AT::startPressureS1Point1Calibration(int ok){
    if(ok == 1){ //Aceptado
        calibration_pressure_active = true;
        MainWindow *w = getMainWindowInstance();
        if( w ){
            //setear estado de calibracion de presion s1
            w->setSerialPortState(SerialPort::CALIBRACION_PRESION_S1_T0);
        }
        SerialPort *serialPort = getSerialPortInstance();
        if( serialPort ){
            //setear estado de calibracion de presion s1
            connect(serialPort, &SerialPort::calibracion_exitosa_presion_modo_at, this, &Screen_Modo_AT::requestPressureS1Point2Calibration);
            connect(serialPort, &SerialPort::calibracion_fallida_presion_modo_at, this, &Screen_Modo_AT::errorPressureCalibration);

            LoadingAnimation *animation = new LoadingAnimation(this, "Calibrando Presión en Sensor 1 Punto 1...");
            animation->showAnimation();
            connect(serialPort, &SerialPort::calibracion_exitosa_presion_modo_at, animation, &LoadingAnimation::stopAnimation);
            connect(serialPort, &SerialPort::calibracion_fallida_presion_modo_at, animation, &LoadingAnimation::stopAnimation);
        }
    }
    else if(ok == 0){//Cancelado
        Dialog_Question *question = new Dialog_Question(this, "Saliendo de Calibración", "¿Desea cancelar calibración de Presión?");
        question->resizeWidgetQuestion(600, 200);
        question->raise();
        connect(question, &Dialog_Question::rejected, this, &Screen_Modo_AT::requestPressureS1Point1Calibration);
        connect(question, &Dialog_Question::aceptado, this, &Screen_Modo_AT::closeFlukeConnection);
    }
}
void Screen_Modo_AT::requestPressureS1Point2Calibration(){
    SerialPort *serialPort = getSerialPortInstance();
    if( serialPort ){
        disconnect(serialPort, &SerialPort::calibracion_exitosa_presion_modo_at, this, &Screen_Modo_AT::requestPressureS1Point2Calibration);
    }
    calibration_pressure_active = false;
    MainWindow *w = getMainWindowInstance();
    if( w ){
        //setear estado de calibracion de presion s1
        w->setSerialPortState(SerialPort::STANDBY);
    }
    Dialog_Question *question = new Dialog_Question(this, "Calibración de presión en punto 2",
                                                    "\n1 - Ajustar la presión al valor de referencia 2"
                                                    "\n\n- Presione \"Aceptar\" para iniciar la "
                                                    "\ncalibración y espere por el fin de calibración");
    question->resizeWidgetQuestion(600, 300);
    question->raise();
    connect(question, &Dialog_Question::accepted, this, &Screen_Modo_AT::startPressureS1Point2Calibration);
}
void Screen_Modo_AT::startPressureS1Point2Calibration(int ok){
    if(ok == 1){ //Aceptado
        calibration_pressure_active = true;
        MainWindow *w = getMainWindowInstance();
        if( w ){
            //setear estado de calibracion de presion s1
            w->setSerialPortState(SerialPort::CALIBRACION_PRESION_S1_T1);
        }
        SerialPort *serialPort = getSerialPortInstance();
        if( serialPort ){
            //        QTimer::singleShot(3000, this, &MainWindow::successOxygenCalibration);
            connect(serialPort, &SerialPort::calibracion_exitosa_presion_modo_at, this, &Screen_Modo_AT::successPressureCalibration);
            connect(serialPort, &SerialPort::calibracion_fallida_presion_modo_at, this, &Screen_Modo_AT::errorPressureCalibration);

            LoadingAnimation *animation = new LoadingAnimation(this, "Calibrando Presión en Sensor 1 Punto 2...");
            animation->showAnimation();
            connect(serialPort, &SerialPort::calibracion_exitosa_presion_modo_at, animation, &LoadingAnimation::stopAnimation);
            connect(serialPort, &SerialPort::calibracion_fallida_presion_modo_at, animation, &LoadingAnimation::stopAnimation);
        }
    }
    else if(ok == 0){//Canceladotine
        Dialog_Question *question = new Dialog_Question(this, "Saliendo de Calibración", "¿Desea cancelar calibración de Presión?");
        question->resizeWidgetQuestion(600, 200);
        question->raise();
        connect(question, &Dialog_Question::cancelado, this, &Screen_Modo_AT::requestPressureS1Point2Calibration);
        connect(question, &Dialog_Question::aceptado, this, &Screen_Modo_AT::closeFlukeConnection);
    }
}
/////////////////////////Calibrasion de presion en sensor 1///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////Calibrasion de presion en sensor 2///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Screen_Modo_AT::requestPressureS2Calibration(){
    MainWindow *w = getMainWindowInstance();
    if( w ){
        //setear estado de calibracion de presion s2
        previousPmax = w->getPressureBeforeFluke();
    }
    Dialog_Question *question = new Dialog_Question(this, "Calibración de Presión S2", "Siga las instrucciones para la calibración"
                                                                                       "\nde presion del Sensor 2."
                                                                                       ""
                                                                                       "\n- Presione \"Aceptar\" para continuar.");
    question->resizeWidgetQuestion(600, 250);
    question->raise();
    connect(question, &Dialog_Question::accepted, this, &Screen_Modo_AT::requestPressureS2Point1Calibration);
}
void Screen_Modo_AT::requestPressureS2Point1Calibration(int ok){
    if(ok == 1){ //Aceptado

        fluke_controller = new ScreenFlukeController(this);

        if(fluke_controller){
            if(fluke_controller->isOpenFlukeCommunication()){
                fluke_controller->closeFlukeCommunication();
                setDelay(this, 3000, "Reiniciando conexión con Fluke...");
            }
            if(fluke_controller->openFlukeCommunication()){
                setDelay(this, 3000, "Estableciendo conexión con Fluke...");


                if(!fluke_controller->setMeasurementLowPressureUnit()){
                    errorPressureCalibration();
                    return;
                }
                setDelay(this, 1000, "Estableciendo unidad de Medición...");


                if(!fluke_controller->setMeasurementModeLowPressure()){
                    errorPressureCalibration();
                    return;
                }
                setDelay(this, 1000, "Estableciendo Medición de baja presión...");


                Dialog_Question *question = new Dialog_Question(this, "Calibración de presión punto 1",
                                                                "1 - Conecte uno de los extremos del circuito de caliración de"
                                                                "\n presión a la toma de presión positiva del analizador de flujo."
                                                                "\n\n2 - Conecte el segundo extremo del circuito de caliración de"
                                                                "\n presión a la toma de presión ubicada en la tapa frontal del PCUVENTE."
                                                                "\n\n3 - Conecte el extremo restante a la toma de presión de referencia."
                                                                "\n\n4 - Ajuste la presión al valor de referencia 1."
                                                                "\n\n- Presione \"Aceptar\" para iniciar la "
                                                                "\ncalibración y espere por el fin de calibración");
                question->resizeWidgetQuestion(700, 470);
                question->raise();
                connect(question, &Dialog_Question::accepted, this, &Screen_Modo_AT::startPressureS2Point1Calibration);
                timer.setInterval(1500);
                connect(&timer, &QTimer::timeout, this, &Screen_Modo_AT::getPressure);
                timer.start();
            }else{
                MessageDialog *mess = new MessageDialog(this, "Fluke no conectado", "Conecte el Fluke e intente nuevamente");
                connect(mess, &MessageDialog::aceptado, this, &Screen_Modo_AT::requestPressureS2Calibration);
                mess->showCenter();
            }
        }
    }
    else if(ok == 0){//Cancelado
        Dialog_Question *question = new Dialog_Question(this, "Saliendo de Calibración", "¿Desea cancelar calibración de Presión?");
        question->resizeWidgetQuestion(600, 200);
        question->raise();
        connect(question, &Dialog_Question::cancelado, this, &Screen_Modo_AT::requestPressureS2Calibration);
        connect(question, &Dialog_Question::aceptado, this, &Screen_Modo_AT::closeFlukeConnection);
    }
}
void Screen_Modo_AT::startPressureS2Point1Calibration(int ok){
    if(ok == 1){ //Aceptado
        calibration_pressure_active = true;
        MainWindow *w = getMainWindowInstance();
        if( w ){
            //setear estado de calibracion de presion s2
            w->setSerialPortState(SerialPort::CALIBRACION_PRESION_S2_T0);
        }
        SerialPort *serialPort = getSerialPortInstance();
        if( serialPort ){
            //setear estado de calibracion de presion s2
            connect(serialPort, &SerialPort::calibracion_exitosa_presion_modo_at, this, &Screen_Modo_AT::requestPressureS2Point2Calibration);
            connect(serialPort, &SerialPort::calibracion_fallida_presion_modo_at, this, &Screen_Modo_AT::errorPressureCalibration);

            LoadingAnimation *animation = new LoadingAnimation(this, "Calibrando Presión en Sensor 2 Punto 1...");
            animation->showAnimation();
            connect(serialPort, &SerialPort::calibracion_exitosa_presion_modo_at, animation, &LoadingAnimation::stopAnimation);
            connect(serialPort, &SerialPort::calibracion_fallida_presion_modo_at, animation, &LoadingAnimation::stopAnimation);
        }
    }
    else if(ok == 0){//Cancelado
        Dialog_Question *question = new Dialog_Question(this, "Saliendo de Calibración", "¿Desea cancelar calibración de Presión?");
        question->resizeWidgetQuestion(600, 200);
        question->raise();
        connect(question, &Dialog_Question::rejected, this, &Screen_Modo_AT::requestPressureS2Point1Calibration);
        connect(question, &Dialog_Question::aceptado, this, &Screen_Modo_AT::closeFlukeConnection);
    }
}
void Screen_Modo_AT::requestPressureS2Point2Calibration(){
    SerialPort *serialPort = getSerialPortInstance();
    if( serialPort ){
        disconnect(serialPort, &SerialPort::calibracion_exitosa_presion_modo_at, this, &Screen_Modo_AT::requestPressureS2Point2Calibration);
    }
    calibration_pressure_active = false;
    MainWindow *w = getMainWindowInstance();
    if( w ){
        //setear estado de calibracion de presion s2
        w->setSerialPortState(SerialPort::STANDBY);
    }
    Dialog_Question *question = new Dialog_Question(this, "Calibración de presión en punto 2",
                                                    "\n1 - Ajustar la presión al valor de referencia 2"
                                                    "\n\n- Presione \"Aceptar\" para iniciar la "
                                                    "\ncalibración y espere por el fin de calibración");
    question->resizeWidgetQuestion(600, 300);
    question->raise();
    connect(question, &Dialog_Question::accepted, this, &Screen_Modo_AT::startPressureS2Point2Calibration);
}
void Screen_Modo_AT::startPressureS2Point2Calibration(int ok){
    if(ok == 1){ //Aceptado
        calibration_pressure_active = true;
        MainWindow *w = getMainWindowInstance();
        if( w ){
            //setear estado de calibracion de presion s2
            w->setSerialPortState(SerialPort::CALIBRACION_PRESION_S2_T1);
        }
        SerialPort *serialPort = getSerialPortInstance();
        if( serialPort ){
            //        QTimer::singleShot(3000, this, &MainWindow::successOxygenCalibration);
            connect(serialPort, &SerialPort::calibracion_exitosa_presion_modo_at, this, &Screen_Modo_AT::successPressureCalibration);
            connect(serialPort, &SerialPort::calibracion_fallida_presion_modo_at, this, &Screen_Modo_AT::errorPressureCalibration);

            LoadingAnimation *animation = new LoadingAnimation(this, "Calibrando Presión en Sensor 2 Punto 2...");
            animation->showAnimation();
            connect(serialPort, &SerialPort::calibracion_exitosa_presion_modo_at, animation, &LoadingAnimation::stopAnimation);
            connect(serialPort, &SerialPort::calibracion_fallida_presion_modo_at, animation, &LoadingAnimation::stopAnimation);
        }
    }
    else if(ok == 0){//Cancelado
        Dialog_Question *question = new Dialog_Question(this, "Saliendo de Calibración", "¿Desea cancelar calibración de Presión?");
        question->resizeWidgetQuestion(600, 200);
        question->raise();
        connect(question, &Dialog_Question::cancelado, this, &Screen_Modo_AT::requestPressureS2Point2Calibration);
        connect(question, &Dialog_Question::aceptado, this, &Screen_Modo_AT::closeFlukeConnection);
    }
}
/////////////////////////Calibrasion de presion en sensor 2///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////Calibrasion de volumen///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Screen_Modo_AT::requestVolumenCalibration(){
    MainWindow *w = getMainWindowInstance();
    if( w ){
        //setear estado de calibracion de presion s2
        previousVolumen = w->getVolumenBeforeFluke();
    }
    Dialog_Question *question = new Dialog_Question(this, "Calibración de Volumen", "Siga las instrucciones para la calibración"
                                                                                    "\nde Volumen."
                                                                                    ""
                                                                                    "\n- Presione \"Aceptar\" para continuar.");
    question->resizeWidgetQuestion(600, 250);
    question->raise();
    connect(question, &Dialog_Question::accepted, this, &Screen_Modo_AT::requestStartVolumenCalibration);
}
void Screen_Modo_AT::requestStartVolumenCalibration(int ok){
    if(ok == 1){ //Aceptado
        fluke_controller = new ScreenFlukeController(this);

        if(fluke_controller){
            if(fluke_controller->isOpenFlukeCommunication()){
                fluke_controller->closeFlukeCommunication();
                setDelay(this, 3000, "Reiniciando conexión con Fluke...");
            }
            if(fluke_controller->openFlukeCommunication()){
                setDelay(this, 3000, "Estableciendo conexión con Fluke...");


                if(!fluke_controller->setMeasurementVolumenMilimeterUnit()){
                    errorVolumenCalibration();
                    return;
                }
                setDelay(this, 2000, "Estableciendo unidad de Medición...");


                if(!fluke_controller->setMeasurementModeVolumen()){
                    errorVolumenCalibration();
                    return;
                }
                setDelay(this, 2000, "Estableciendo Medición de Volumen...");


                Dialog_Question *question = new Dialog_Question(this, "Instrucciones para Calibración de Volumen",
                                                                "1 - Conectar el circuito paciente a la entrada del analizador de flujo."
                                                                "\n\n2 - Conectar pulmón de prueba a la salida del analizador de flujo."
                                                                "\n\n3 - Configurar pulmón de prueba con 20mL/cmH2O"
                                                                "\n de compianza y 5cmH2O/L/s de resistencia"
                                                                "\n\n4 - Retirar válvula PEEP del circuito paciente."
                                                                "\n\n- Presione \"Aceptar\" para iniciar la "
                                                                "\ncalibración y espere por el fin de calibración");
                question->resizeWidgetQuestion(700, 470);
                question->raise();
                connect(question, &Dialog_Question::accepted, this, &Screen_Modo_AT::startVolumenCalibration);
                timer.setInterval(1500);
                connect(&timer, &QTimer::timeout, this, &Screen_Modo_AT::getVolumen);
                timer.start();
            }else{
                MessageDialog *mess = new MessageDialog(this, "Fluke no conectado", "Conecte el Fluke e intente nuevamente");
                connect(mess, &MessageDialog::aceptado, this, &Screen_Modo_AT::requestVolumenCalibration);
                mess->showCenter();
            }
        }
    }
    else if(ok == 0){//Cancelado
        Dialog_Question *question = new Dialog_Question(this, "Saliendo de Calibración", "¿Desea cancelar calibración de Volumen?");
        question->resizeWidgetQuestion(600, 200);
        question->raise();
        connect(question, &Dialog_Question::cancelado, this, &Screen_Modo_AT::requestVolumenCalibration);
        connect(question, &Dialog_Question::aceptado, this, &Screen_Modo_AT::closeFlukeConnection);
    }
}
void Screen_Modo_AT::startVolumenCalibration(int ok){
    if(ok == 1){ //Aceptado
        calibration_volumen_active = true;
        MainWindow *w = getMainWindowInstance();
        if( w ){
            //setear estado de calibracion de presion s2
            w->setSerialPortState(SerialPort::CALIBRACION_VOLUMEN);
        }
        SerialPort *serialPort = getSerialPortInstance();
        if( serialPort ){
            //        QTimer::singleShot(3000, this, &MainWindow::successOxygenCalibration);
            connect(serialPort, &SerialPort::calibracion_exitosa_volumen, this, &Screen_Modo_AT::successVolumenCalibration);
            connect(serialPort, &SerialPort::calibracion_fallida_volumen, this, &Screen_Modo_AT::errorVolumenCalibration);

            LoadingAnimation *animation = new LoadingAnimation(this, "Calibrando Volumen...");
            animation->showAnimation();
            connect(serialPort, &SerialPort::calibracion_exitosa_volumen, animation, &LoadingAnimation::stopAnimation);
            connect(serialPort, &SerialPort::calibracion_fallida_volumen, animation, &LoadingAnimation::stopAnimation);
        }
    }
    else if(ok == 0){//Cancelado
        Dialog_Question *question = new Dialog_Question(this, "Saliendo de Calibración", "¿Desea cancelar calibración de Volumen?");
        question->resizeWidgetQuestion(600, 200);
        question->raise();
        connect(question, &Dialog_Question::cancelado, this, &Screen_Modo_AT::requestVolumenCalibration);
        connect(question, &Dialog_Question::aceptado, this, &Screen_Modo_AT::closeFlukeConnection);
    }
}
/////////////////////////Calibrasion de volumen///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void Screen_Modo_AT::errorVolumenCalibration(){
    closeFlukeConnection();
    calibration_volumen_active = false;
    MainWindow *w = getMainWindowInstance();
    if( w ){
        //setear estado de calibracion de presion s1
        w->setSerialPortState(SerialPort::STANDBY);
        w->setVolumenFromFluke(previousVolumen);
    }
    SerialPort *serialPort = getSerialPortInstance();
    if( serialPort ){
        disconnect(serialPort, &SerialPort::calibracion_exitosa_volumen, this, &Screen_Modo_AT::successVolumenCalibration);
        disconnect(serialPort, &SerialPort::calibracion_exitosa_volumen, this, &Screen_Modo_AT::requestVolumenCalibration);;
        disconnect(serialPort, &SerialPort::calibracion_fallida_volumen, this, &Screen_Modo_AT::errorVolumenCalibration);
    }
    MessageDialog *mess = new MessageDialog(this, "Error", "Calibración de Volumen fallida");
    mess->showCenter();
}
void Screen_Modo_AT::successVolumenCalibration(){
    closeFlukeConnection();
    calibration_volumen_active = false;
    MainWindow *w = getMainWindowInstance();
    if( w ){
        //setear estado de calibracion de presion s1
        w->setSerialPortState(SerialPort::STANDBY);
        w->setVolumenFromFluke(previousVolumen);
    }
    SerialPort *serialPort = getSerialPortInstance();
    if( serialPort ){
        disconnect(serialPort, &SerialPort::calibracion_exitosa_volumen, this, &Screen_Modo_AT::successVolumenCalibration);
        disconnect(serialPort, &SerialPort::calibracion_exitosa_volumen, this, &Screen_Modo_AT::requestVolumenCalibration);;
        disconnect(serialPort, &SerialPort::calibracion_fallida_volumen, this, &Screen_Modo_AT::errorVolumenCalibration);
    }
    MessageDialog *mess = new MessageDialog(this, "Éxito", "Calibración de Volumen finalizada");
    mess->showCenter();
}

void Screen_Modo_AT::deleteFlukeController(QObject *obj){
    obj = nullptr;
}

void Screen_Modo_AT::errorPressureCalibration(){
    closeFlukeConnection();
    calibration_pressure_active = false;
    MainWindow *w = getMainWindowInstance();
    if( w ){
        //setear estado de calibracion de presion s1
        w->setSerialPortState(SerialPort::STANDBY);
        w->setPressureFromFluke(previousPmax);
    }
    SerialPort *serialPort = getSerialPortInstance();
    if( serialPort ){
        disconnect(serialPort, &SerialPort::calibracion_exitosa_presion_modo_at, this, &Screen_Modo_AT::successPressureCalibration);
        disconnect(serialPort, &SerialPort::calibracion_exitosa_presion_modo_at, this, &Screen_Modo_AT::requestPressureS1Point2Calibration);
        disconnect(serialPort, &SerialPort::calibracion_exitosa_presion_modo_at, this, &Screen_Modo_AT::requestPressureS2Point2Calibration);
        disconnect(serialPort, &SerialPort::calibracion_fallida_presion_modo_at, this, &Screen_Modo_AT::errorPressureCalibration);
    }
    MessageDialog *mess = new MessageDialog(this, "Error", "Calibración de Presión fallida");
    mess->showCenter();
}
void Screen_Modo_AT::successPressureCalibration(){
    closeFlukeConnection();
    calibration_pressure_active = false;
    MainWindow *w = getMainWindowInstance();
    if( w ){
        //setear estado de calibracion de presion s1
        w->setSerialPortState(SerialPort::STANDBY);
        w->setPressureFromFluke(previousPmax);
    }
    SerialPort *serialPort = getSerialPortInstance();
    if( serialPort ){
        disconnect(serialPort, &SerialPort::calibracion_exitosa_presion_modo_at, this, &Screen_Modo_AT::successPressureCalibration);
        disconnect(serialPort, &SerialPort::calibracion_exitosa_presion_modo_at, this, &Screen_Modo_AT::requestPressureS1Point2Calibration);
        disconnect(serialPort, &SerialPort::calibracion_exitosa_presion_modo_at, this, &Screen_Modo_AT::requestPressureS2Point2Calibration);
        disconnect(serialPort, &SerialPort::calibracion_fallida_presion_modo_at, this, &Screen_Modo_AT::errorPressureCalibration);
    }
    MessageDialog *mess = new MessageDialog(this, "Éxito", "Calibración de Presión finalizada");
    mess->showCenter();
}
void Screen_Modo_AT::closeFlukeConnection(){
    if(fluke_controller){
        if(fluke_controller->isOpenFlukeCommunication()){
            fluke_controller->closeFlukeCommunication();
        }
    }
    disconnect(&timer, &QTimer::timeout, this, &Screen_Modo_AT::getVolumen);
    disconnect(&timer, &QTimer::timeout, this, &Screen_Modo_AT::getPressure);
    timer.stop();
    fluke_controller->deleteLater();
}

void Screen_Modo_AT::on_pb_fluke_controller_clicked()
{
    ScreenFlukeController *fluke = new ScreenFlukeController(nullptr);
    fluke->show();
}

/////////////////////////Configuracion de AMBU///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Screen_Modo_AT::on_rb_mark_4_toggled(bool checked)
{
    if(checked){
        salvarConfiguraciondeCapnografia(MARK_4);
        MainWindow *w = getMainWindowInstance();
        if( w ){
            w->setMaxVolumen(MARK_4);
            if(w->getVolumenBeforeFluke() > MARK_4){
                w->setVolumenFromFluke(MARK_4);
            }
        }
        QFont f = ui->rb_mark_4->font();
        f.setBold(true);
        ui->rb_mark_4->setFont(f);
    }else{
        QFont f = ui->rb_mark_4->font();
        f.setBold(false);
        ui->rb_mark_4->setFont(f);
    }
}

void Screen_Modo_AT::on_rb_ambu_silicona_toggled(bool checked)
{
    if(checked){
        salvarConfiguraciondeCapnografia(AMBU_SILICONA);
        MainWindow *w = getMainWindowInstance();
        if( w ){
            w->setMaxVolumen(AMBU_SILICONA);
        }
        QFont f = ui->rb_ambu_silicona->font();
        f.setBold(true);
        ui->rb_ambu_silicona->setFont(f);

    }else{
        QFont f = ui->rb_ambu_silicona->font();
        f.setBold(false);
        ui->rb_ambu_silicona->setFont(f);
    }
}
void Screen_Modo_AT::chequearConfiguracionMaxVolumen(){
    int max_vol = checkifMaxVolumenActive();
    if(max_vol == MARK_4){
        ui->rb_mark_4->setChecked(true);
        on_rb_mark_4_toggled(true);

        ui->rb_ambu_silicona->setChecked(false);
        on_rb_ambu_silicona_toggled(false);
    }else if(max_vol == AMBU_SILICONA){
        ui->rb_ambu_silicona->setChecked(true);
        on_rb_ambu_silicona_toggled(true);

        ui->rb_mark_4->setChecked(false);
        on_rb_mark_4_toggled(false);
    }
}

int Screen_Modo_AT::checkifMaxVolumenActive(){
    QFile file("maxVolumen.dat");
    if(file.exists()){
        if(file.open(QIODevice::ReadOnly))
        {
            QDataStream in(&file);
            int max_vol;
            in >> max_vol;

            file.close();
            return max_vol;
        }
    }
    return MARK_4;
}
void Screen_Modo_AT::salvarConfiguraciondeCapnografia(int max_vol){

    QFile file("maxVolumen.dat");
    if(file.open(QIODevice::WriteOnly))
    {
        QDataStream out(&file);
        out << max_vol;
        file.close();
    }
}
/////////////////////////Configuracion de AMBU///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////










