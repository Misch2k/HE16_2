#include "centerwidget.h"
#include "eventhandler.h"
#include "binarysearchtree.h"

#include "model.h"
#include <map>
#include <cmath>
#include <QDebug>

CenterWidget::CenterWidget(QWidget *parent) : QWidget(parent)
{
    init();
    initLayout();
    initConnections();
}

int CenterWidget::getNumberInput()
{
    return this->numberInput->text().toInt();
}

void CenterWidget::init()
{
    // Header
    this->headerTitle = new QLabel("BinaryTree", this);
    this->selectType = new QComboBox(this);
    this->selectType->addItem("Binary Search Tree");

    // Menu
    this->numberInput = new QLineEdit(this);
    //numberInput->setInputMask("999");
    this->addItem = new QPushButton("ADD", this);
    this->deleteItem = new QPushButton("Delete", this);
    this->deleteAllItems = new QPushButton("Delete all", this);

    // Layout
    bodyLayout = new QGridLayout();
    tree = new BinarySearchTree(bodyLayout);
}

void CenterWidget::initLayout()
{
    // Layouts
    mainLayout = new QVBoxLayout();
    QGridLayout *headerLayout = new QGridLayout();
    QGridLayout *menueLayout = new QGridLayout();


    // Local Widgets
    QLabel *menueTitle = new QLabel("Add", this);

    // Header
    headerLayout->addWidget(headerTitle, 0, 0);
    headerLayout->addWidget(selectType, 0, 1);
    headerLayout->minimumSize();

    // Menue
    menueLayout->addWidget(menueTitle, 0, 0);
    menueLayout->addWidget(numberInput, 0, 1);
    menueLayout->addWidget(addItem, 0, 2);
    menueLayout->addWidget(deleteItem, 0, 3);
    menueLayout->addWidget(deleteAllItems, 0, 5);
    menueLayout->minimumSize();


    // Complete Layout
    mainLayout->addLayout(headerLayout);
    mainLayout->addLayout(menueLayout);
    mainLayout->addLayout(bodyLayout);
    this->setLayout(mainLayout);
}

void CenterWidget::initConnections()
{
    EventHandler *events = new EventHandler(this);
    connect(this->addItem, SIGNAL(clicked(bool)), this, SLOT(insertItem()));
    connect(this->deleteAllItems, SIGNAL(clicked(bool)), this, SLOT(deleteAllItem()));
    connect(this->deleteItem, SIGNAL(clicked(bool)), this, SLOT(deleteItem1()));
}

void CenterWidget::updateTree()
{

    //std::map<int,int> tmp = Model::get().tree->getTree();
   // int size = Model::get().tree->getSize();
   // for( auto v : Model::get().labels){
   //     bodyLayout->addWidget(v.second);
   // }
   // mainLayout->addLayout(bodyLayout);
    //qDebug() << Model::get().tree->getHeight();

    //int t_width = pow(2, Model::get().tree->getHeight() - 1);
    //int t_height = Model::get().tree->getHeight();

}

void CenterWidget::insertItem()
{
    this->tree->insertItem(this->getNumberInput());
}

void CenterWidget::deleteItem1()
{
    this->tree->deleteItem(this->getNumberInput());
}

void CenterWidget::deleteAllItem()
{
    this->tree->deleteAllItems();
}
