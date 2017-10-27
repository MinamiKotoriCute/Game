#include "mainwindow.h"
#include <QApplication>

#include <QHostAddress>
#include <QTimer>
#include <QTcpSocket>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //register metatype, use to communication on different thread
    qRegisterMetaType<QHostAddress>("QHostAddress");

    MainWindow w;
    w.show();

    /*QTimer::singleShot(1000, []{
        qDebug() << "client\t" << "connect to host";
        QTcpSocket *socket = new QTcpSocket;
        socket->connectToHost(QHostAddress::LocalHost, 9487);

        qDebug() << "client\t" << "write";
        socket->write("hello");
    });*/

    return a.exec();
}
