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
    bool lunAlgo(QString Number);
    bool checkDate(int month, int year);
public:
    EventHandler(CreditCardCheck *parent);
public slots:
    void validateCard();
signals:
    void companyChanged();
    bool setValidation(bool);
};

#endif // EVENTHANDLER_H
