#include "gui_client.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ClientWnd w;
    w.show();
    return a.exec();
}
