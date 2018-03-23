#include "mainwindow.h"
#include <QGridLayout>
#include <QHBoxLayout>
#include <QWidget>
#include "Widget2.h"
#include <QSlider>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{


    QGridLayout *grid = new QGridLayout();
    grid->setContentsMargins(0,0,0,0);
    QWidget *window = new QWidget();
    window->setStyleSheet("border: 1px solid black;");
    Widget2 *ex1 = new Widget2(this);
    QSlider *slide = new QSlider(this);
    slide->setOrientation(Qt::Horizontal);
    slide->setMinimum(0);
    slide->setMaximum(10);
    grid->addWidget(ex1,0 ,0);
    this->setMenuWidget(slide);
    window->setLayout(grid);
    this->setCentralWidget(window);

    connect(slide, SIGNAL(valueChanged(int)), ex1, SLOT(setSpeed(int)));
}

MainWindow::~MainWindow()
{

}
