#include "mainwindow.h"
#include "centerwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setCentralWidget(new CenterWidget(this));
}

MainWindow::~MainWindow()
{

}
