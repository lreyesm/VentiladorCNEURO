#include "readtempds18b20class.h"

ReadTempDS18B20Class::ReadTempDS18B20Class(QObject *parent, int period) : QThread(parent)
{
    QString response = "";

    //Creando carpeta de lectura del protocolo 1wire-----------------------------------------------------------------------
    response = ProcessesClass::executeProcess(parent, "sudo /sbin/modprobe w1-gpio", ProcessesClass::LINUX, 500);
    response = ProcessesClass::executeProcess(parent, "sudo /sbin/modprobe w1-therm", ProcessesClass::LINUX, 500);
    //---------------------------------------------------------------------------------------------------------------------

    //listando los dispositivos conectados---------------------------------------------------------------------------------
    response = ProcessesClass::executeProcess(parent, "ls /sys/bus/w1/devices/", ProcessesClass::LINUX, 500);
    QStringList devices = response.split("\n");
    //---------------------------------------------------------------------------------------------------------------------

    //Buscando el dispositivo DS18B20 conectado----------------------------------------------------------------------------
    QString device;
    foreach(device, devices){
        if(device.contains("28-")){
            sensorName = device;
        }
    }
    //---------------------------------------------------------------------------------------------------------------------

//    runReadThread();

    if(period > 0){
        timer.setInterval(period);
        QObject::connect(&timer, &QTimer::timeout, this, &ReadTempDS18B20Class::runReadThread);
        timer.start();
    }
}


//Lee la temperatura del sensor y devuelve un QString con su valor (si aproximar)------------------------------------------
QString ReadTempDS18B20Class::readTempString(){
    QFile tempFile("/sys/bus/w1/devices/"+sensorName+"/w1_slave");
    QString value ="";
    if(tempFile.exists()){
        qDebug()<<"Existe";
        if(tempFile.open(QIODevice::ReadOnly)){
            QString text = QString::fromLatin1(tempFile.readAll());
            QStringList data = text.split("t=");
            if(data.size()>1){
                value = data.at(1).trimmed();
                qDebug()<<value;
            }
            tempFile.close();
        }
        else{
            qDebug()<<"No se pudo abrir archivo " + tempFile.fileName();
        }
    }else{
        qDebug()<<"No existe archivo " + tempFile.fileName();
    }
    return value;
}

double ReadTempDS18B20Class::convertTempToDouble(QString tempString){
    bool ok;
    int temp = tempString.toInt(&ok);
    if(ok){
        return (static_cast<double>(temp))/1000;
    }else{
        return -255;
    }
}

double ReadTempDS18B20Class::readTemp()
{
    currentTemp = convertTempToDouble(readTempString());
    emit tempReady(currentTemp);
    return currentTemp;
}

double ReadTempDS18B20Class::temp(){
    return currentTemp;
}

void ReadTempDS18B20Class::runReadThread()
{
    run();
}

QString ReadTempDS18B20Class::temp(QString n){
    n = QString::number(currentTemp , 'f', 3);
    return n;
}
