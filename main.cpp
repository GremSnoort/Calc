#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setMaximumHeight(630);
    w.setMaximumWidth(500);
    w.setMinimumHeight(630);
    w.setMinimumWidth(500);

    w.show();

    return a.exec();
}
