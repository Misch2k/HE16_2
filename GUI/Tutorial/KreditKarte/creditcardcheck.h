#ifndef CREDITCARDCHECK_H
#define CREDITCARDCHECK_H


#include <QPushButton>
#include <QGridLayout>
#include <QLineEdit>
#include <QComboBox>
#include <QLabel>
#include <QString>
#include <QStandardItemModel>
#include <QDebug>
#include "eventhandler.h"
#include "validmessage.h"
#include "QPaintEvent"
#include "Qt"
#include "QMainWindow"

class CreditCardCheck : public QWidget
{
    Q_OBJECT
private:
    QLineEdit *cardNumber;
    QComboBox *cardMonth;
    QComboBox *cardYear;
    QLabel *messageBox;
    QPushButton *validButton;
    QLabel *companyImage;
    void init();
    void initCombobox();
    void initGridLayout();
public:
    CreditCardCheck();
public slots:
    void updateCompany();
    void setValidation(bool);
private slots:
    void updateDataModel();
signals:
    void runValidation();
};

#endif // CREDITCARDCHECK_H
