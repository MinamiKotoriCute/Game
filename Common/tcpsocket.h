#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include <QObject>
#include <QHostAddress>

class QTcpSocket;
class Thread;

class TcpSocket : public QObject
{
    Q_OBJECT
public:
    explicit TcpSocket(QThread *r_thread = nullptr, QObject *parent = nullptr);
    ~TcpSocket();

signals:
    void setSocketDescriptor(int socketDescriptor);
    void connectToHost(const QHostAddress &address, quint16 port);
    void reciveMessage(QByteArray message);
    void sendMessage(QByteArray message);
    void disconnected();
    void connected();

public slots:

private:
    QTcpSocket *m_socket;
    QThread *m_thread;
};

Q_DECLARE_METATYPE(QHostAddress)
//Q_DECLARE_METATYPE(qintptr)

#endif // TCPSOCKET_H
