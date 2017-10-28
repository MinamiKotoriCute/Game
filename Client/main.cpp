#include "mainwindow.h"
#include <QApplication>
#include <QHostAddress>

#include <QTimer>

#include "tcpsocket.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qRegisterMetaType<QHostAddress>("QHostAddress");

    MainWindow w;
    w.show();

    QTimer::singleShot(1000, []{
        TcpSocket *socket = new TcpSocket;
        socket->connectToHost(QHostAddress("127.0.0.1"), 9487);

        QTimer::singleShot(1000, [=]{
            socket->sendMessage("Hello, form client");
        });
    });

    return a.exec();
}
