#include "mainwindow.h"
#include "QGridLayout"
#include "point.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    QGridLayout *grid = new QGridLayout;
    Point *point;
    point = new Point(this);
    grid->addWidget(point, 0, 0);
    this->setCentralWidget(point);
}

MainWindow::~MainWindow()
{

}
