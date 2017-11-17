#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setMaximumHeight(500);
    w.setMaximumWidth(400);
    w.setMinimumHeight(500);
    w.setMinimumWidth(400);

    w.show();

    return a.exec();
}
