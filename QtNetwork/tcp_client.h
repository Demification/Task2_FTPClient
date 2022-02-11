#ifndef TCP_CLIENT_H
#define TCP_CLIENT_H

#include <QObject>
#include <QThread>
#include <QTcpSocket>

#include "socket_shell.h"

class TCPClient : public QThread
{
    Q_OBJECT
    SocketShell* socket = nullptr;
    QString getMyName();

protected:
    QString ip_server;
    quint16 port;

public:
    explicit TCPClient(QObject *parent = nullptr);

    SocketShell* getSocket();

    void run() override;

public slots:
    void disconnectedSlot();

};

#endif // TCP_CLIENT_H
