#include "socket_shell.h"

SocketShell::SocketShell(QObject *parent)
    : QTcpSocket{parent}
{
    static int i = 0;
    myName = "Socket-" + QString::number(i);
}

QString SocketShell::getMyName()
{
    return myName;
}

void SocketShell::readyReadSlot()
{
    QDataStream in(this);
    in.setVersion(QDataStream::Qt_4_8);

    if(in.status() == QDataStream::Ok)
    {
        readData.clear();
        readData = readAll();
        emit alreadyRead(readData);
    }
    else
        qWarning() << myName << " can`t read data !";
}
