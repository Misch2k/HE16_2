#include <QGridLayout>
#include <QWidget>

#include "test.h"
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    QGridLayout *grid = new QGridLayout();
    grid->setContentsMargins(0,0,0,0);
    QWidget *window = new QWidget();
    window->setStyleSheet("border: 1px solid black;");
    test *ex1 = new test(this);
    grid->addWidget(ex1,0 ,0);
    window->setLayout(grid);
    this->setCentralWidget(window);
}

MainWindow::~MainWindow()
{

}
