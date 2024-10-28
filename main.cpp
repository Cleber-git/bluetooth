#include "mainwindow.h"

#include <QApplication>
#include "screenofconnect.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    screenOfConnect w;
    w.show();
    return a.exec();
}
