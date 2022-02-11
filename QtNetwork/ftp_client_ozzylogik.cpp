#include "ftp_client_ozzylogik.h"
#include <QThread>
#include <QDataStream>
#include <QMetaEnum>
#include <QFile>
#include <QDir>

void FTPClientOzzylogik::saveFile(const QByteArray &data)
{
    QFile file(QDir::currentPath() + "/savedfiles/" + filename);
    if(file.open(QIODevice::Text | QIODevice::WriteOnly))
    {
        QTextStream stream(&file);
        stream << data;
        qDebug() << "File is saved.";
    }
}

FTPClientOzzylogik::FTPClientOzzylogik(QString ip_server, quint16 port, QObject *parent)
    : TCPClient{parent}
{
    this->ip_server=ip_server;
    this->port=port;
}

void FTPClientOzzylogik::getFile(const QString &filename)
{
    this->filename = filename;
    lastCommand = FTP_COMMANDS::GET;
    getSocket()->send(QVariant::fromValue(FTP_COMMANDS::GET).toString() + "/" + filename);
}

void FTPClientOzzylogik::alreadyReadSlot(const QByteArray &data)
{
    switch (lastCommand)
        {
        case GET:
            saveFile(data);
            break;
        default:
            lastCommand = ERR;
            break;
        }  
}

