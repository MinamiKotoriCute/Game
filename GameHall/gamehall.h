#ifndef GAMEHALL_H
#define GAMEHALL_H

#include "gamehallinterface.h"

#include <QObject>

#include "tcpserver.h"

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
    void newConnection(QTcpSocket *newConnectSocket);
    void getMessageFromClient(QTcpSocket *socket);

private:
    TcpServer *server;
};

Q_DECLARE_METATYPE(QHostAddress)

#endif // GAMEHALL_H
