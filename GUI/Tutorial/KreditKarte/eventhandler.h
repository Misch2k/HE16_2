#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <QObject>
#include <QDebug>

class CreditCardCheck;

class EventHandler : public QObject
{
    Q_OBJECT
private:
    CreditCardCheck *parent;
    void checkCompany(QString cardNumber);
public:
    EventHandler(CreditCardCheck *parent);
public slots:
    void onCheckButtonClicked();
};

#endif // EVENTHANDLER_H
