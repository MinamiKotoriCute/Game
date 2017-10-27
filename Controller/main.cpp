#include "mainwindow.h"
#include <QApplication>

#include <QHostAddress>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //register metatype, use to communication on different thread
    qRegisterMetaType<QHostAddress>("QHostAddress");
    //qRegisterMetaType<QHostAddress>("qintptr");

    MainWindow w;
    w.show();

    return a.exec();
}
