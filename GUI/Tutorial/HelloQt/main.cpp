#include "mainwindow.h"
#include <QApplication>
#include <QDial>
#include <QLCDNumber>
#include <QSlider>
#include <QPushButton>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Create MainWindow as Parent of All Widgets
    MainWindow *window = new MainWindow();
    window->setMinimumSize(320, 200);

    // Create a Dial
    QDial *dial = new QDial(window);
    // Set MinimumSize
    dial->setMinimumSize(100,100);
    // Move it (x,y)
    dial->move(0,50);
    dial->setStyleSheet("background-color: red");
    dial->setToolTip("PLEASE DO NOT TOUCH THIS BUTTON");
    dial->setEnabled(false);

    QLCDNumber *lcd = new QLCDNumber(window);
    lcd->setMaximumWidth(100);
    lcd->move(0,0);

    QSlider *slider = new QSlider(Qt::Horizontal, window);
    slider->setMinimumSize(200,5);
    slider->move(110, 0);


    // Debug Messages
    qInfo() << "\nPress F1 to see the documentation of this Class direct in QT :thumb_up:";
    qDebug() << "Hello Debugger :D";
    //QApplication::beep();
    //qFatal("Uhhh... FATAL ERROR!! ..Bzzzzz..");

    window->show();

    return app.exec();
}
