#include "tcpserver.h"

#include <QThread>
#include <QDebug>
#include <QTcpSocket>

#include <QCoreApplication>

TcpServer::TcpServer(QObject *parent) : QTcpServer(parent)
{
    qDebug() << "TcpServer main thread" << QThread::currentThread() << " id " << QThread::currentThreadId();
}

TcpServer::~TcpServer()
{
    qDebug() << "~TcpServer" << QThread::currentThreadId();
}

void TcpServer::start()
{

}

void TcpServer::incomingConnection(qintptr socketDescriptor)
{
    QTcpSocket *socket = new QTcpSocket;

    //initialize fail
    if(socket->setSocketDescriptor(socketDescriptor) == false){
        qDebug() << "socket initialize fail. " << __FUNCTION__ << __LINE__;
        return;
    }

    emit newConnection(socket);
}
