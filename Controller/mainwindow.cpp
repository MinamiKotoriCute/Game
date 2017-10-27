#include "mainwindow.h"

#include <QLibrary>
#include <QDebug>

#include "../GameHall/gamehallinterface.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QLibrary lib("GameHall.dll");
    createGameHallFunction f = (createGameHallFunction)lib.resolve("CreateGameHall");
    if(f){
        GameHallInterface *it = f();
        it->listen(QHostAddress::AnyIPv4, 9487);
    }
}

MainWindow::~MainWindow()
{

}
