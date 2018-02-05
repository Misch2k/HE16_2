#include "creditcardcheck.h"
#include "creditcardcheck.h"
#include "eventhandler.h"
#include "cccmodel.h"

CreditCardCheck::CreditCardCheck()
{
    // Class Attribute initialization
    init();
    // Combobox initialization
    initCombobox();
    // Layout initialization
    initGridLayout();
    // Events
    EventHandler *eventHandler = new EventHandler(this);
    connect(validButton, SIGNAL(clicked(bool)), this, SLOT(updateDataModel()));
    connect(cardNumber,SIGNAL(editingFinished()), this, SLOT(updateDataModel()));
    connect(cardMonth, SIGNAL(activated(int)), this, SLOT(updateDataModel()));
    connect(cardYear, SIGNAL(activated(int)), this, SLOT(updateDataModel()));
    connect(cardMonth, SIGNAL(activated(int)), eventHandler, SLOT(validateCard()));
    connect(cardYear, SIGNAL(activated(int)), eventHandler, SLOT(validateCard()));
    connect(cardNumber, SIGNAL(editingFinished()), eventHandler, SLOT(validateCard()));
    connect(this, SIGNAL(runValidation()), eventHandler, SLOT(validateCard()));
    connect(eventHandler, SIGNAL(companyChanged()), this, SLOT(updateCompany()));
    connect(eventHandler, SIGNAL(setValidation(bool)), this, SLOT(setValidation(bool)));
    qDebug() << "Initialisatzion of CreditCardCheck";
}

void CreditCardCheck::init(){
    // INIT ALL OBJECTS
    this->cardNumber = new QLineEdit(this);
    QRegExp rx("^([0-9]{4}[ -]){3}[0-9]{4}$");
    cardNumber->setInputMask("9999 9999 9999 9999;_");
    this->cardMonth = new QComboBox(this);
    this->cardYear = new QComboBox(this);
    this->messageBox = new QLabel("NOT VALID", this);
    this->validButton = new QPushButton("VALIDATE", this);
    this->companyImage = new QLabel(this);
}

void CreditCardCheck::initCombobox()
{
    // TITLE
    this->cardMonth->addItem("Month");
    this->cardYear->addItem("Year");
    // MONTES and YEAR as NUMBERS
    for(int i = 1; i <= 12; ++i){
        this->cardMonth->addItem(QString::fromStdString(std::to_string(i)));
    }
    for(int i = 2015; i < 2030; ++i){
        this->cardYear->addItem(QString::fromStdString(std::to_string(i)));
    }

    // FIX FOR: First Element = Title element -> not selectable
    QStandardItemModel *model = qobject_cast<QStandardItemModel*>(cardMonth->model());
    QModelIndex firstIndex = model->index(0, cardMonth->modelColumn(),cardMonth->rootModelIndex());
    QStandardItem* firstItem = model->itemFromIndex(firstIndex);
    firstItem->setSelectable(false);

    QStandardItemModel *model1 = qobject_cast<QStandardItemModel*>(cardYear->model());
    QModelIndex firstIndex1 = model1->index(0, cardYear->modelColumn(),cardYear->rootModelIndex());
    QStandardItem* firstItem1 = model1->itemFromIndex(firstIndex1);
    firstItem1->setSelectable(false);


}

void CreditCardCheck::initGridLayout()
{
    // Only Local elements
    QLabel *title = new QLabel("<h1>Check Credit Card</h1>");
    QLabel *titleNr = new QLabel("Nr.");
    QLabel *titleDate = new QLabel("Date");
    QLabel *limiter = new QLabel("/");
    titleDate->setMaximumWidth(30);
    limiter->setMaximumWidth(10);
    companyImage->setPixmap(QPixmap(":/images/Images/false.png"));
    QGridLayout *grid = new QGridLayout();
    grid->addWidget(title, 0, 0, 1, 4);
    grid->addWidget(titleNr, 1, 0);
    grid->addWidget(cardNumber, 1, 1, 1, 3);
    grid->addWidget(titleDate, 2, 0);
    grid->addWidget(cardMonth, 2 , 1);
    grid->addWidget(limiter, 2, 2);
    grid->addWidget(cardYear, 2, 3);
    grid->addWidget(validButton, 4, 0, 1, 4);
    grid->addWidget(messageBox, 5, 0, 1, 4);
    grid->addWidget(companyImage, 0, 5);
    this->setLayout(grid);

}

void CreditCardCheck::updateDataModel()
{
    CCCModel::getInstance().setCardNumber(this->cardNumber->text());
    CCCModel::getInstance().setMonth(this->cardMonth->currentText().toInt());
    CCCModel::getInstance().setYear(this->cardYear->currentText().toInt());
    emit runValidation();
}

void CreditCardCheck::setValidation(bool valid){
    if(valid){
        messageBox->setText("VALID");
        messageBox->setStyleSheet(
                    "background-color: green; "
                    "color: yellow"
                    );
    }else{
        messageBox->setText("NOT VALID");
        messageBox->setStyleSheet(
                    "background-color: red; "
                    "color: white"
                    );

    }
}

void CreditCardCheck::updateCompany()
{
    qDebug() << "updateCompany()";
    this->companyImage->setPixmap(CCCModel::getInstance().getCompanyImage());
}

