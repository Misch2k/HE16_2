#include "mainwindow.h"
#include <QGridLayout>
#include <QHBoxLayout>
#include <QWidget>
#include "example.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    QGridLayout *grid = new QGridLayout();
    grid->setContentsMargins(0,0,0,0);
    QWidget *window = new QWidget();
    window->setStyleSheet("border: 1px solid black;");
    Example *ex1 = new Example(this);
    Example *ex2 = new Example(this);
    Example *ex3 = new Example(this);
    grid->addWidget(ex1,0 ,0);
    grid->addWidget(ex2,0 ,1);
    grid->addWidget(ex3,1 ,0, 1, 2);
    window->setLayout(grid);
    this->setCentralWidget(window);
}

MainWindow::~MainWindow()
{

}
