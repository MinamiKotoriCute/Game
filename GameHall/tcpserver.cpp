#include "tcpserver.h"

#include <QThread>
#include <QDebug>

#include <QCoreApplication>

TcpServer::TcpServer(QObject *parent) : QTcpServer(parent)
{
    qDebug() << "TcpServer" << QThread::currentThreadId();
}

TcpServer::~TcpServer()
{
    qDebug() << "~TcpServer" << QThread::currentThreadId();
}

void TcpServer::start()
{
    deleteLater();
}

void TcpServer::incomingConnection(qintptr socketDescriptor)
{

}
