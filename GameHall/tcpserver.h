#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpServer>

class TcpSocket;

class TcpServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit TcpServer(QObject *parent = nullptr);
    ~TcpServer();

signals:
    void finished();
    void newConnection(TcpSocket *newConnectSocket);

public slots:
    void start();   //thread start call this

protected:
    void incomingConnection(qintptr socketDescriptor);
};

#endif // TCPSERVER_H
