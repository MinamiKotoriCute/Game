#include "tcpsocket.h"

#include <QTcpSocket>
#include <QThread>
#include <QTimer>

TcpSocket::TcpSocket(QThread *r_thread, QObject *parent) :
        QObject(parent), m_thread(r_thread)
{
    if(m_thread == nullptr){
        m_thread = new QThread;
        connect(this, &TcpSocket::destroyed, m_thread, &QThread::quit);
        connect(m_thread, &QThread::finished, m_thread, &QThread::deleteLater);
        //connect(m_thread, &QThread::destroyed, []{qDebug() << "m_thread ~";});
    }

    m_socket = new QTcpSocket;
    m_socket->moveToThread(m_thread);
    //connect(m_socket, &QTcpSocket::destroyed, []{qDebug() << "m_socket ~";});
    connect(m_socket, &QTcpSocket::disconnected, this, &TcpSocket::deleteLater);
    m_thread->start();

    connect(this, &TcpSocket::setSocketDescriptor, m_socket,
            [this](int r_socketDescriptor){m_socket->setSocketDescriptor(r_socketDescriptor);});
    connect(this, &TcpSocket::connectToHost, m_socket,
            [this](const QHostAddress &address, quint16 port){m_socket->connectToHost(address, port);});
    connect(m_socket, &QTcpSocket::readyRead, this, [this]{emit reciveMessage(m_socket->readAll());});
    connect(this, &TcpSocket::sendMessage, m_socket, [this](QByteArray message){m_socket->write(message);});
    connect(m_socket, &QTcpSocket::disconnected, this, &TcpSocket::disconnected);
    connect(m_socket, &QTcpSocket::connected, this, &TcpSocket::connected);
}

TcpSocket::~TcpSocket()
{
    if(m_socket)
        delete m_socket;
    //qDebug() << "[TcpSocket] ~TcpSocket";
}
