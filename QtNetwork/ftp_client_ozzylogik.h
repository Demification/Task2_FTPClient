#ifndef FTP_CLIENT_OZZYLOGIK_H
#define FTP_CLIENT_OZZYLOGIK_H

#include <QObject>
#include <QStringList>

#include "tcp_client.h"

class FTPClientOzzylogik : public TCPClient
{
public:
    enum FTP_COMMANDS { GET , ERR};
    Q_ENUM(FTP_COMMANDS);

private:
    Q_OBJECT

    FTP_COMMANDS lastCommand;
    QString filename;
    void saveFile(const QByteArray& data);

public:
    explicit FTPClientOzzylogik(QString ip_server, quint16 port, QObject *parent = nullptr);
       void getFile(const QString &filename);

public slots:
    void alreadyReadSlot(const QByteArray& data);
};

#endif // FTP_CLIENT_OZZYLOGIK_H
