#include "tcpserver.h"

#include <QThread>
#include <QDebug>
#include <QTcpSocket>

#include <QCoreApplication>

#include "tcpsocket.h"

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
    qDebug() << socketDescriptor << sizeof(qintptr);
    //TcpSocket *socket = new TcpSocket(QThread::currentThread());
    TcpSocket *socket = new TcpSocket();
    socket->setSocketDescriptor(socketDescriptor);

    qDebug() << "server\t" << "new connect" << QThread::currentThread();
    emit newConnection(socket);
}
