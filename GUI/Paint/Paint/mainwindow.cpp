#include "mainwindow.h"
#include <QPainter>
#include <widget.h>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    Widget *mainWidget = new Widget();
    this->setCentralWidget(mainWidget);
}

MainWindow::~MainWindow()
{

}
