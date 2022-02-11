#include "gui_client.h"
#include "ui_gui_client.h"

#include <QHostAddress>
#include <QThreadPool>
#include <QRandomGenerator>

#include "QtNetwork/ftp_client_ozzylogik.h"

ClientWnd::ClientWnd(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ClientWnd)
{
    ui->setupUi(this);
}

ClientWnd::~ClientWnd()
{
    delete ui;
}

void ClientWnd::on_pushButton_clicked()
{
    for(int i = 0; i < ui->spinBox->value(); i++)
    {
        FTPClientOzzylogik* ftpc = new FTPClientOzzylogik(ui->lineEdit->text(), ui->lineEdit_2->text().toUShort());
        ftpc->start();
    }
}

