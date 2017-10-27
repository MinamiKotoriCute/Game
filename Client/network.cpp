#include "network.h"
#include "../Common/globaldefine.h"

#include <QTcpSocket>
#include <QThread>


Network::Network(QObject *parent) : QObject(parent), socket(new QTcpSocket)
{
    QThread *thread = new QThread(this);
    socket->moveToThread(thread);
    connect(thread, &QThread::destroyed, socket, &QTcpSocket::deleteLater);
    connect(this, &Network::sendToServer, socket, [this](QByteArray b){socket->write(b);});
    connect(socket, &QTcpSocket::readyRead, this, &Network::_reciveFromServer);
    connect(this, &Network::connectToHost, socket, [this](QHostAddress address, quint16 port){socket->connectToHost(address, port);});
    thread->start();

    connect(socket, &QTcpSocket::connected, [=]{
        qDebug() << "connected";
    });
}

bool Network::isConnect() const
{
    return socket->isOpen();
}

void Network::_reciveFromServer()
{
    QByteArray rawData = socket->readAll();
#ifndef QT_NO_INFO_OUTPUT
    qInfo() << "recive from server: " << rawData.mid(0, INFO_NETWORK_RECIVE_SHOW_BYTES) << rawData.mid(0, INFO_NETWORK_RECIVE_SHOW_BYTES).toHex();
#else
#ifndef QT_NO_DEBUG_OUTPUT
    qDebug() << QString("recive from server, %d bytes.").arg(rawData.size());
#endif  //QT_NO_DEBUG_OUTPUT
#endif  //QT_NO_INFO_OUTPUT

    emit reciveFromServer(rawData);
}
