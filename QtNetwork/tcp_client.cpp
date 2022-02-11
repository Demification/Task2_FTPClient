#include "tcp_client.h"
#include <QDataStream>
#include <QHostAddress>
#include <QThread>

#include "ftp_client_ozzylogik.h"

TCPClient::TCPClient(QObject *parent)
    : QThread{parent}
{

}

QString TCPClient::getMyName()
{
    return "TCPClient";
}

SocketShell *TCPClient::getSocket()
{
    return socket;
}

void TCPClient::run()
{
    socket = new SocketShell();

    socket->connectToHost(ip_server, port);

    int msec = 10000;
    socket->waitForConnected(msec);

    if(socket->state() == QAbstractSocket::SocketState::ConnectedState)
    {
        connect(socket, &QTcpSocket::readyRead, socket, &SocketShell::readyReadSlot, Qt::ConnectionType::DirectConnection);
        connect(socket,  &QTcpSocket::disconnected, this, &TCPClient::disconnectedSlot);

        FTPClientOzzylogik* lo = dynamic_cast<FTPClientOzzylogik*>(this);
        if (lo)
        {
            connect(socket, &SocketShell::alreadyRead, lo, &FTPClientOzzylogik::alreadyReadSlot, Qt::DirectConnection);
            lo->getFile("example");
        }

        qDebug() << getMyName() << " start.";
        exec();
    }
    else
        qDebug() << getMyName() << " oops... what wrong?";
}

void TCPClient::disconnectedSlot()
{
    qInfo() << getMyName() << " is disconnected.";
    socket->deleteLater();
    exit(0);
}


