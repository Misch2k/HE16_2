#ifndef CENTERWIDGET_H
#define CENTERWIDGET_H

#include "binarysearchtree.h"
#include <QObject>
#include <QWidget>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>
#include <map>

class BinarySearchTree;

class CenterWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CenterWidget(QWidget *parent = nullptr);
    int getNumberInput();
private:
    void init();
    void initLayout();
    void initConnections();
    QVBoxLayout *mainLayout;
    // Header Elements
    QLabel *headerTitle;
    QComboBox *selectType;

    // Menu Elements
    QLineEdit *numberInput;
    QPushButton *addItem;
    QPushButton *deleteItem;
    QPushButton *deleteAllItems;

    // Body Elements
    QGridLayout *bodyLayout;
    BinarySearchTree *tree;


signals:

public slots:
    void updateTree();
    void insertItem();
    void deleteItem1();
    void deleteAllItem();
};

#endif // CENTERWIDGET_H
