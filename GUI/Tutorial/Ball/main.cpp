#include "widget.h"
#include <QApplication>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QIntValidator>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget *mainWidget = new QWidget();

    Widget w;

    QPushButton *b1 = new QPushButton("Set");
    QLineEdit *li = new QLineEdit();

    li->setValidator(new QIntValidator(0,100));

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(b1, 0,0);
    layout

    return a.exec();
}
