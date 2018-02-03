#ifndef CCCWINDOW_H
#define CCCWINDOW_H

#include "QMainWindow"
#include "creditcardcheck.h"

class CCCWindow : public QMainWindow
{
public:
    CCCWindow();
private:
    CreditCardCheck *widget;
};

#endif // CCCWINDOW_H
