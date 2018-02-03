#include <QApplication>
#include <cccwindow.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    CCCWindow *window = new CCCWindow();
    window->show();

    return app.exec();
}
