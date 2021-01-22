#ifndef READTEMPDS18B20CLASS_H
#define READTEMPDS18B20CLASS_H

#include <QObject>
#include <QtCore>
#include "processesclass.h"

class ReadTempDS18B20Class : public QThread
{
    Q_OBJECT

public:
    explicit ReadTempDS18B20Class(QObject *parent = nullptr, int period = 0);
    QString temp(QString n);
    double temp();

    void run() override {
        readTemp();        
    }
signals:
    void tempReady(double);

public slots:

private slots:
    void runReadThread();
    double readTemp();

private:
    QString sensorName = "";
    QString readTempString();
    double currentTemp;
    double convertTempToDouble(QString tempString);
    QTimer timer;
    QFile *file;
};

#endif // READTEMPDS18B20CLASS_H
