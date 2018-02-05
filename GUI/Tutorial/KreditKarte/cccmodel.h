#ifndef CCCMODEL_H
#define CCCMODEL_H
#include "QString"
#include "QPixmap"

class CCCModel
{
public:
    static CCCModel &getInstance();
    QString getCardNumber() const;
    void setCardNumber(QString cardNumber);
    int getMonth() const;
    void setMonth(int month);
    int getYear() const;
    void setYear(int year);
    QString getCompany() const;
    void setCompany(QString company);
    QPixmap getCompanyImage() const;
    void setCompanyImage(QPixmap companyImage);

    // Do not allow copy constructors
    CCCModel(CCCModel const&) = delete;
    CCCModel operator=(CCCModel const&) = delete;
private:
    QString cardNumber;
    int month;
    int year;
    QString company;
    CCCModel();
    QPixmap companyImage;
};

#endif // CCCMODEL_H
