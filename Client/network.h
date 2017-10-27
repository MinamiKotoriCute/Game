#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>

class Network : public QObject
{
    Q_OBJECT
public:
    explicit Network(QObject *parent = nullptr);
    bool isConnect() const;

signals:
    void reciveFromServer(QByteArray b);
    void sendToServer(QByteArray b);
    void connectToHost(QHostAddress address, quint16 port);

public slots:

private slots:
    void _reciveFromServer();

private:
    QTcpSocket *socket;
};

Q_DECLARE_METATYPE(QHostAddress)

#endif // NETWORK_H
