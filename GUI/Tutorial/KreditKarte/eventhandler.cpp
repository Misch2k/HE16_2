#include "eventhandler.h"
#include "creditcardcheck.h"

void EventHandler::checkCompany(QString cardNumber)
{
    qDebug() << "Card Number: " << cardNumber;

    switch (cardNumber.toInt()) {
    case 4 :
        // Visa
        parent->setImage(QPixmap(":/images/Images/visa.gif"));
        break;
    case 5 :
        //Master
        parent->setImage(QPixmap(":/images/Images/master.gif"));
        break;
    case 6:
        parent->setImage(QPixmap(":/images/Images/amex.gif"));
        break;
    default :
        parent->setImage(QPixmap(":/images/Images/false.png"));
    }

    qDebug() << "Image save";
}

EventHandler::EventHandler(CreditCardCheck *parent) : parent(parent)
{
}

void EventHandler::onCheckButtonClicked(){
    qDebug() << parent->getNumberText();
    checkCompany(parent->getNumberText().left(1));
    parent->setValidation(parent->getNumberText() == "1");
}
