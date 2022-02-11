#ifndef GUI_CLIENT_H
#define GUI_CLIENT_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class ClientWnd; }
QT_END_NAMESPACE

class ClientWnd : public QMainWindow
{
    Q_OBJECT

public:
    ClientWnd(QWidget *parent = nullptr);
    ~ClientWnd();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ClientWnd *ui;
};
#endif // GUI_CLIENT_H
