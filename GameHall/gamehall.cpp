#include "gamehall.h"

#include <functional>

#include <QDebug>
#include <QTimer>
#include <QThread>
#include <QTcpSocket>

#include "tcpserver.h"

GameHall::GameHall() : server(new TcpServer)
{
    connect(server, &TcpServer::newConnection, this, &GameHall::newConnection);
    connect(this, &GameHall::listen, server, [this](const QHostAddress &address, quint16 port){server->listen(address, port);});

    startServerThread();
}

GameHall::~GameHall()
{
    qDebug() << "~GameHall";
}

void GameHall::startServerThread()
{
    QThread *thread = new QThread;
    server->moveToThread(thread);
    connect(thread, &QThread::started, server, &TcpServer::start);
    connect(server, &TcpServer::destroyed, thread, &QThread::quit);
    connect(thread, &QThread::finished, thread, &QThread::deleteLater);
    connect(thread, &QThread::destroyed, [](){qDebug() << "QThread::destroyed";});
    thread->start();
}

void GameHall::newConnection(QTcpSocket *newConnectSocket)
{
    qDebug() << "server\t" << "new connect";
    connect(newConnectSocket, &QTcpSocket::readyRead, this, [this, newConnectSocket](){
        this->getMessageFromClient(newConnectSocket);
    });
}

void GameHall::getMessageFromClient(QTcpSocket *socket)
{
    qDebug() << "server\t" << "GameHall::getMessageFromClient" << socket->readAll();
}
