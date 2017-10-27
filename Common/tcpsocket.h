#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include <QObject>
#include <QHostAddress>

class QTcpSocket;

class TcpSocket : public QObject
{
    Q_OBJECT
public:
    explicit TcpSocket(QThread *r_thread = nullptr, QObject *parent = nullptr);

signals:
    void setSocketDescriptor(int socketDescriptor);
    void connectToHost(const QHostAddress &address, quint16 port);
    void reciveMessage(QByteArray message);

public slots:

private:
    QTcpSocket *m_socket;
    QThread *m_thread;
};

Q_DECLARE_METATYPE(QHostAddress)
//Q_DECLARE_METATYPE(qintptr)

#endif // TCPSOCKET_H
