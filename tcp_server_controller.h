#ifndef TCP_SERVER_CONTROLLER_H
#define TCP_SERVER_CONTROLLER_H


#include <QTcpSocket>
#include <QTcpServer>

class TCP_Server_Controller: public QObject
{
    Q_OBJECT
public:
    explicit TCP_Server_Controller(QObject *parent = nullptr);

    bool is_Connected(){return conectado;}

signals:
    void connected(QString);
    void dataAvailableTCP(QByteArray);

public slots:
    void on_newConnection();
    void on_ready();

    void write_data(QByteArray bytes);
private slots:
    void on_Disconnected();
private:
    QTcpServer server;
    QList<QTcpSocket *> listSocket;
    bool conectado = false; //true si tiene al menos un socket conectado
};

#endif // TCP_SERVER_CONTROLLER_H
