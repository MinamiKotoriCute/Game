#include "gamehall.h"

#include <QDebug>
#include <QTimer>
#include <QThread>

#include "tcpserver.h"

GameHall::GameHall()
{
    qDebug() << "GameHall";
    server = nullptr;

    startServer();
}

GameHall::~GameHall()
{
    qDebug() << "~GameHall";
}

void GameHall::startServer()
{
    if(server)
        delete server;

    QThread *thread = new QThread;
    server = new TcpServer;
    server->moveToThread(thread);
    connect(thread, &QThread::started, server, &TcpServer::start);
    connect(server, &TcpServer::destroyed, thread, &QThread::quit);
    connect(thread, &QThread::finished, thread, &QThread::deleteLater);
    connect(thread, &QThread::destroyed, [](){qDebug() << "QThread::destroyed";});
    thread->start();
}

void GameHall::print()
{
    qDebug() << "GameHall::print";

    QTimer::singleShot(1000, [=](){
        qDebug() << "QTimer";
        if(add){
            qDebug() << add;
            add(1,2);
        }
    });
}
