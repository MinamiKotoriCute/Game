#include "gamehallinterface.h"
#include "gamehall.h"

extern "C"
GameHallInterface *CreateGameHall()
{
    return new GameHall();
}
