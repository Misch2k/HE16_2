#include "cccwindow.h"
#include "QStatusBar"
CCCWindow::CCCWindow()
{
    this->widget = new CreditCardCheck;
    this->setCentralWidget(widget);
}
