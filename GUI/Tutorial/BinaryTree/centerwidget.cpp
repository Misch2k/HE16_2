#include "centerwidget.h"
#include "eventhandler.h"
#include "binarysearchtree.h"
#include "nodewidget.h"
#include <map>

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

CenterWidget::~CenterWidget()
{
    delete tree;
}

int CenterWidget::getNumberInput()
{
    return this->numberInput->text().toInt();
}

void CenterWidget::paintEvent(QPaintEvent *)
{

    // QPainter
    QPainter paint(this);
    paint.setPen(QPen(Qt::black, 2, Qt::SolidLine ,Qt::RoundCap));
    std::map<int, NodeWidget*>::iterator it;
    for(it = tree->tree->begin(); it != tree->tree->end(); it++){
        NodeWidget *pNode = it->second;
        if(tree->tree->count(pNode->getIndex()*2+1)){
            NodeWidget *cNode = tree->tree->at(pNode->getIndex()*2+1);
            paint.drawLine(pNode->posLeftMiddle(), cNode->posTopCenter());
        }
        if(tree->tree->count(pNode->getIndex()*2+2)){
            NodeWidget *cNode = tree->tree->at(pNode->getIndex()*2+2);
            paint.drawLine(pNode->posRightMiddle(), cNode->posTopCenter());
        }
    }
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

    // Layout
    bodyLayout = new QGridLayout();
    tree = new BinarySearchTree(bodyLayout);

    // Complete Layout
    mainLayout->addLayout(headerLayout);
    mainLayout->addLayout(menueLayout);
    mainLayout->addLayout(bodyLayout);
    this->setLayout(mainLayout);

}

void CenterWidget::initConnections()
{
    connect(this->addItem, SIGNAL(clicked(bool)), this, SLOT(insertItem()));
    connect(this->numberInput, SIGNAL(returnPressed()), this, SLOT(insertItem()));
    connect(this->deleteAllItems, SIGNAL(clicked(bool)), this, SLOT(deleteAllItem()));
    connect(this->deleteItem, SIGNAL(clicked(bool)), this, SLOT(deleteItem1()));
    connect(this->tree, SIGNAL(updateOut()), this, SLOT(updatePaint()));
}

void CenterWidget::updateTree()
{
    this->update();
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

void CenterWidget::updatePaint()
{
    qDebug() << "Update";
    this->update();
}
