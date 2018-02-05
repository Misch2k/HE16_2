#include "cccmodel.h"

CCCModel::CCCModel()
{

}

CCCModel& CCCModel::getInstance()
{
    static CCCModel instance;
    return instance;
}

QString CCCModel::getCardNumber() const
{
    return this->cardNumber;
}

void CCCModel::setCardNumber(QString cardNumber)
{
    this->cardNumber = cardNumber;
}

int CCCModel::getMonth() const
{
    return this->month;
}

void CCCModel::setMonth(int month)
{
    this->month = month;
}

int CCCModel::getYear() const
{
    return this->year;
}

void CCCModel::setYear(int year)
{
    this->year = year;
}

QString CCCModel::getCompany() const
{
    return this->company;
}

void CCCModel::setCompany(QString company)
{
    this->company = company;
}

QPixmap CCCModel::getCompanyImage() const
{
    return this->companyImage;
}

void CCCModel::setCompanyImage(QPixmap companyImage)
{
    this->companyImage = companyImage;
}
