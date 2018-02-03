#include "cccwindow.h"


CCCWindow::CCCWindow()
{
    this->widget = new CreditCardCheck;
    this->setCentralWidget(widget);
}
