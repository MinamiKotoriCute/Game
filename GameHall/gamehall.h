#ifndef GAMEHALL_H
#define GAMEHALL_H

#include "gamehallinterface.h"

#include <QObject>

class TcpServer;

class GameHall : public GameHallInterface
{
    Q_OBJECT
public:
    GameHall();
    ~GameHall();

    void startServer();

    void print();

private:
    TcpServer *server;
};

#endif // GAMEHALL_H
