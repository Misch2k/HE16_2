#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <QDebug>
#include <map>


class BinarySearchTreeOld
{
public:
    BinarySearchTreeOld();
    ~BinarySearchTreeOld();
    void insertItem(int v, int index = 0);
    void deleteItem(int v);
    void deleteItemRec(int index);
    void deleteAllItems();
    int getHeight();
    int getSize();
    std::map<int, int> getTree();
    void Print();
    std::map<int, int> *tree;
private:
    int size;
    int getRight(int v);
    int getLeft(int v);
    void getHeight(int index, int &count);
    int getParent(int v);
    int findItem(int v, int index = 0);
    int getRightMember(int index, bool left = true, bool first = true);
};

#endif // BINARYSEARCHTREE_H
