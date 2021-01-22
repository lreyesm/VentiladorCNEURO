#include "tcp_server_controller.h"

TCP_Server_Controller::TCP_Server_Controller(QObject *parent) : QObject(parent)
{
    connect(&server,&QTcpServer::newConnection,this,&TCP_Server_Controller::on_newConnection);
    server.listen(QHostAddress::Any,10101);
}


void TCP_Server_Controller::on_newConnection(){
    QTcpSocket* socket=server.nextPendingConnection();
    QObject::connect(socket,&QTcpSocket::readyRead, this, &TCP_Server_Controller::on_ready);
    QObject::connect(socket,&QTcpSocket::disconnected, this,&TCP_Server_Controller::on_Disconnected);
    conectado = true;
    emit connected("");
    listSocket.append(socket);
}

void TCP_Server_Controller::on_Disconnected(){
    for (int i = 0; i < listSocket.size(); i++) {
        if(listSocket[i]->state() == QAbstractSocket::UnconnectedState){
            listSocket[i]->deleteLater();
            listSocket.removeAt(i);
            i--;
        }
    }
    if(listSocket.isEmpty()){
        conectado = false;
    }
}

void TCP_Server_Controller::on_ready(){
    QString n;
    QTcpSocket *socket=(QTcpSocket*)sender();
    QByteArray bytes=socket->read(socket->bytesAvailable());
    n = QString::fromLatin1(bytes);

    emit dataAvailableTCP(bytes);

}

void TCP_Server_Controller::write_data(QByteArray bytes){
    if(is_Connected()){
        for (int i = 0; i < listSocket.size(); i++) {
            listSocket[i]->write(bytes);
        }
    }
}
