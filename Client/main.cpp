#include "mainwindow.h"
#include <QApplication>
#include <QHostAddress>

#include <QTimer>

#include "network.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qRegisterMetaType<QHostAddress>("QHostAddress");

    MainWindow w;
    w.show();

    QTimer::singleShot(1000, []{
        Network *network = new Network;
        network->connectToHost(QHostAddress("127.0.0.1"), 9487);

        QTimer::singleShot(1000, [=]{
            network->sendToServer("Hello, form client");
        });
    });

    return a.exec();
}
