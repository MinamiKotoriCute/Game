#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpServer>

class TcpServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit TcpServer(QObject *parent = nullptr);
    ~TcpServer();


signals:
    void finished();

public slots:
    void start();

protected:
    void incomingConnection(qintptr socketDescriptor);
};

#endif // TCPSERVER_H
