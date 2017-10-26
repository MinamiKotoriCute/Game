#ifndef GAMEHALLINTERFACE_H
#define GAMEHALLINTERFACE_H

#include <QObject>

#include "gamehall_global.h"

class GAMEHALLSHARED_EXPORT GameHallInterface : public QObject
{
    Q_OBJECT
public:
    virtual ~GameHallInterface(){}
    virtual void print(){}

    void (*add)(int a, int b);
};

typedef GameHallInterface* (*createGameHallFunction)();

extern "C" GAMEHALLSHARED_EXPORT GameHallInterface* CreateGameHall();

#endif // GAMEHALLINTERFACE_H
