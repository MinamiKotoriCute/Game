#ifndef GAMEHALL_H
#define GAMEHALL_H

#include "gamehallinterface.h"

#include <QObject>

#include "tcpserver.h"

class TcpSocket;

class GameHall : public GameHallInterface
{
    Q_OBJECT
public:
    GameHall();
    ~GameHall() override;

    void startServerThread();

signals:
    bool listen(const QHostAddress &address = QHostAddress::Any, quint16 port = 0) override;

protected slots:
    void newConnection(TcpSocket *newConnectSocket);
    void getMessageFromClient(TcpSocket *socket, QByteArray r_message);

private:
    TcpServer *server;
};


#endif // GAMEHALL_H
