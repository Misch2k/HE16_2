#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "nodewidget.h"
#include <QObject>
#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QString>
#include <QPainter>

struct Cord {
    Cord(int l, int r) : left(l), right(r)
    {

    }
    int pos()
    {
        return (left+right)/2;
    }
    int left;
    int right;
};

class BinarySearchTree : public QWidget
{
    Q_OBJECT
public:
    BinarySearchTree(QGridLayout *parentLayout = nullptr, QWidget *parent = nullptr);
    ~BinarySearchTree();
    void insertItem(int v, int index = 0);
    void deleteAllItems();
    void deleteItem(int v);
    int getHeight();
    int getSize();
    std::map<int, NodeWidget*> *tree;
private:
    void updateTree();
    void generateTree(int index, int height, Cord cord);
    int size;
    QGridLayout *parentLayout;
    int getRight(int v);
    int getLeft(int v);
    int getParent(int v);
    void getHeight(int index, int &count);
    void deleteItemRec(int index);
    int findItem(int v, int index = 0);
    int getRightMember(int index, bool left = true, bool first = true);
    void print();
signals:
    void updateOut();
public slots:
    void deleteThisItem(int index);
    void updateIN();

};

#endif // BINARYSEARCHTREE_H
