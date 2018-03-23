#include "mainwindow.h"
#include <QApplication>
#include "thread.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Thread t1;
    Thread t2;

    Thread r1(true);
    Thread r2(true);

    t1.start();
    t2.start();
    r1.start();
    r2.start();

    return a.exec();
}
