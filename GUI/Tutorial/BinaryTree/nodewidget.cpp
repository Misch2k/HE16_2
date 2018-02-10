#include "nodewidget.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QString>
#include "binarysearchtree.h"

NodeWidget::NodeWidget(BinarySearchTree *par, int index, int value, QWidget *parent) : QWidget(parent), index(index), value(value)
{
    this->par = par;
    init(value);
    widgetLayout();
    initStyleSheet();
}

int NodeWidget::getIndex() const
{
    return this->index;
}

int NodeWidget::getValue() const
{
    return this->value;
}

void NodeWidget::setValue(int value)
{
    this->value = value;
    this->label->setText(QString::number(value));
}

QPoint NodeWidget::getPosition() const
{
    return QPoint(this->pos().x() + this->label->pos().x(), this->pos().y() + this->label->pos().y());
}

QPoint NodeWidget::posLeftMiddle() const
{
    return getPosition() + QPoint(0, label->height()/2);
}
QPoint NodeWidget::posRightMiddle() const
{
    return getPosition() + QPoint(label->width(), label->height()/2);
}
QPoint NodeWidget::posTopCenter() const
{
    return getPosition() + QPoint(label->width()/2,0);
}


void NodeWidget::init(int value)
{
    deleteButton = new QPushButton("Delete", this);
    deleteButton->setProperty("class", "option");
    deleteButton->hide();
    closeButton = new QPushButton("Close", this);
    closeButton->setProperty("class", "option");
    closeButton->hide();
    label = new QPushButton(QString::number(value), this);
    label->setProperty("class", "root");

}

void NodeWidget::widgetLayout()
{
    layout = new QGridLayout(this);
    layout->addWidget(label, 0, 0, 1, 2, Qt::AlignCenter);
    layout->addWidget(deleteButton, 1, 0);
    layout->addWidget(closeButton, 1, 1);
    this->setLayout(layout);


    connect(this->label, SIGNAL(clicked(bool)), this, SLOT(showButtons()));
    connect(this->closeButton, SIGNAL(clicked(bool)), this, SLOT(hideButtons()));
    connect(this->deleteButton, SIGNAL(clicked(bool)), this, SLOT(deleteItemByIndex()));
    connect(this, SIGNAL(deleteThisItem(int)), this->par, SLOT(deleteThisItem(int)));
    connect(this, SIGNAL(updateNodeOut()), this->par, SLOT(updateIN()));
}

void NodeWidget::initStyleSheet()
{

    QFile f(":/qss/style.css");
    if (f.open(QFile::ReadOnly | QFile::Text)){
        QTextStream in(&f);
        QString style(in.readAll());
        this->setStyleSheet(style);
    }
}

void NodeWidget::showButtons()
{
    this->deleteButton->show();
    this->closeButton->show();
    emit updateNodeOut();

}

void NodeWidget::hideButtons()
{
    this->deleteButton->hide();
    this->closeButton->hide();
    emit updateNodeOut();
}

void NodeWidget::deleteItemByIndex()
{
    emit deleteThisItem(this->index);
    emit updateNodeOut();
}
