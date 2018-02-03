#include <QApplication>
#include <QHBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget *window = new QWidget;

    QHBoxLayout *hLayout = new QHBoxLayout;
    QVBoxLayout *vLayout = new QVBoxLayout;



    hLayout->addWidget(dial);


    window->setLayout(layout);

    // Debug Messages
    qInfo() << "\nPress F1 to see the documentation of this Class direct in QT :thumb_up:";
    qDebug() << "Hello Debugger :D";
    //QApplication::beep();
    //qFatal("Uhhh... FATAL ERROR!! ..Bzzzzz..");

    window->show();

    return app.exec();
}
