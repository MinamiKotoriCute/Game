#include "tcpsocket.h"

#include <QTcpSocket>
#include <QThread>
#include <QTimer>

TcpSocket::TcpSocket(QThread *r_thread, QObject *parent) :
        QObject(parent), m_thread(r_thread)
{
    if(m_thread == nullptr){
        m_thread = new QThread(this);
    }
    m_socket = new QTcpSocket;
    m_socket->moveToThread(m_thread);
    connect(m_thread, &QThread::destroyed, m_socket, &QTcpSocket::deleteLater);
    m_thread->start();

    connect(this, &TcpSocket::setSocketDescriptor, m_socket,
            [this](int r_socketDescriptor){qDebug() << r_socketDescriptor;m_socket->setSocketDescriptor(r_socketDescriptor);});
    connect(this, &TcpSocket::connectToHost, m_socket,
            [this](const QHostAddress &address, quint16 port){m_socket->connectToHost(address, port);});
    connect(m_socket, &QTcpSocket::readyRead, this, [this]{emit reciveMessage(m_socket->readAll());});
}
