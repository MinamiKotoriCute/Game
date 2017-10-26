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
        it->add = [](int a, int b){
            qDebug() << "a=" << a << " b=" << b;
        };
        qDebug() << it->add;
        it->print();
        //delete it;
        //it->deleteLater();
    }
}

MainWindow::~MainWindow()
{

}
