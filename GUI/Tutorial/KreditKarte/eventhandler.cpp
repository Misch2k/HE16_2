#include "eventhandler.h"
#include "creditcardcheck.h"
#include "cccmodel.h"
#include "ctime"
#include "algorithm"

void EventHandler::checkCompany(QString cardNumber)
{
    qDebug() << "Card Number: " << cardNumber;

    switch (cardNumber.toInt()) {
    case 4 :
        // Visa
        CCCModel::getInstance().setCompanyImage(QPixmap(":/images/Images/visa.gif"));
        break;
    case 5 :
        //Master
        CCCModel::getInstance().setCompanyImage(QPixmap(":/images/Images/master.gif"));
        break;
    case 6:
        CCCModel::getInstance().setCompanyImage(QPixmap(":/images/Images/amex.gif"));
        break;
    default :
        CCCModel::getInstance().setCompanyImage(QPixmap(":/images/Images/false.png"));
    }
    emit companyChanged();
    qDebug() << "checkCompany()";
}

bool EventHandler::checkDate(int month, int year)
{
    time_t t = time(0);
    // get time now
    struct tm * now = localtime( & t );
    qDebug() << "Card\n" << "  Month: " << month << "\n  Year: " << year << endl;
    qDebug() << "Time\n" << "  Month: " << now->tm_mon+1 << "\n  Year " << now->tm_year+1900 << endl;
    if(year < now->tm_year+1900){
        return false;
    }else if(year == now->tm_year+1900 && month < now->tm_mon+1){
        return false;
    }
    return true;
}

EventHandler::EventHandler(CreditCardCheck *parent) : parent(parent)
{
}

bool EventHandler::lunAlgo(QString Number)
{
    Number.replace(" ", "");
    qDebug() << "Number after Replace: " << Number << endl;
    if (Number.length() != 16) {
        return false;
    }
    int tmp = 0;
    reverse(Number.rbegin(), Number.rend());
    std::string nr = Number.toStdString();
    for(unsigned int i = 0; i < nr.length(); i+=2){
        tmp += nr.at(i) - '0';
    }
    for(unsigned int i = 1; i < nr.length(); i+=2){
        int temp = (nr.at(i) - '0') * 2;
        if (temp > 10) temp -= 9;
        tmp += temp;
    }
    qDebug() << tmp;
    return tmp % 10 == 0;
}

void EventHandler::validateCard()
{
    bool result;
    checkCompany(CCCModel::getInstance().getCardNumber().left(1));
    result = lunAlgo(CCCModel::getInstance().getCardNumber());
    result = result && checkDate(CCCModel::getInstance().getMonth(), CCCModel::getInstance().getYear());
    emit  setValidation(result);
}
