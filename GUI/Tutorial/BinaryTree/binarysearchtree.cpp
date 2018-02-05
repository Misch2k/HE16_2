#include "binarysearchtree.h"
#include "model.h"
#include <QDebug>


BinarySearchTree::BinarySearchTree(QGridLayout *parentLayout, QWidget *parent) : QWidget(parent)
{
    this->parentLayout = parentLayout;
    tree = new std::map<int, QLabel*>;
    size = 0;
}

BinarySearchTree::~BinarySearchTree()
{
    delete tree;
}

void BinarySearchTree::insertItem(int v, int index)
{
    if(!tree->count(index)){
        tree->insert(std::pair<int, QLabel*>(index, new QLabel(QString::number(v))));
        parentLayout->addWidget(tree->at(index));
        //print();
        size++;
        updateTree();
        //qDebug() << "Insert " << v << " at Position " << index;
    }else{
        if(tree->at(index)->text().toInt() >= v){
            insertItem(v, getLeft(index));
        }else{
            insertItem(v, getRight(index));
        }
    }
}

void BinarySearchTree::deleteAllItems()
{
    std::map<int, QLabel*>::iterator it;

    for(it = tree->begin(); it != tree->end(); it++){
        parentLayout->removeWidget(it->second);
        delete it->second;
    }
    tree->clear();
    size = 0;
    updateTree();

}


int BinarySearchTree::getRight(int v)
{
    return v*2+2;
}

int BinarySearchTree::getLeft(int v)
{
    return v*2+1;
}

int BinarySearchTree::getParent(int v)
{
    return (v-1)/2;
}

void BinarySearchTree::deleteItem(int v)
{
    if(v < 0){
        return;
    }
    int pos = findItem(v);
    if(pos == -1){
    }else{
        deleteItemRec(pos);
    }
    //print();
    updateTree();
}

void BinarySearchTree::deleteItemRec(int index)
{
    int pos = getRightMember(index);
    if(pos != -1)
    {
        tree->at(index)->setText(tree->at(pos)->text());
        deleteItemRec(pos);
    }else{
        delete tree->at(index);
        tree->erase(index);
        size--;
        updateTree();
    }
}

int BinarySearchTree::getRightMember(int index, bool left, bool first){
    if(first){
        if(tree->count(getLeft(index))){
            return getRightMember(getLeft(index), true, false);
        }else if(tree->count(getRight(index))){
            return getRightMember(getRight(index), false, false);
        }else{
            return -1;
        }
    }else{
        if(left){
            if(!tree->count(getRight(index))) return index;
            return getRightMember(getRight(index), true, false);
        }else{
            if(!tree->count(getLeft(index))) return index;
            return getRightMember(getLeft(index), false, false);
        }
    }
}

int BinarySearchTree::findItem(int v, int index)
{
    if(!tree->count(index)){
        return -1;
    }else if(tree->at(index)->text().toInt() == v){
        return index;
    }else{
        if(tree->at(index)->text().toInt() > v){
            return findItem(v, getLeft(index));
        }else{
            return findItem(v, getRight(index));
        }
    }
}

void BinarySearchTree::print(){
    std::map<int, QLabel*>::iterator it;
    for(it = tree->begin(); it != tree->end(); it++){
        //qDebug() << it->second->text();
    }
    //qDebug() << "";

}



int BinarySearchTree::getSize()
{
    return size;
}

void BinarySearchTree::updateTree()
{
    int t_width = pow(2, getHeight()-1);
    int t_height = getHeight();
    //qDebug() << t_width * 2 << " : " << t_height;
    if(t_height > 0){
        std::map<int, QLabel*>::iterator it;
        for(it = tree->begin(); it != tree->end(); it++){
            parentLayout->removeWidget(it->second);
        }
        generateTree(0, 0, Cord(0, t_width*2));
    }
}

void BinarySearchTree::generateTree(int index, int height, Cord cord)
{

    //qDebug() << "Item: " << tree->at(index)->text() << "\n  Height: " << height << "\n  Width: " << cord.pos() << "\n  Index:" << index;
    //print();
    parentLayout->addWidget(tree->at(index), height, cord.pos());
    if(tree->count(getLeft(index))){
        //qDebug() << "Left way";
        generateTree(getLeft(index), height+1, Cord(cord.left, cord.pos()));
    }
    if(tree->count(getRight(index))){
        //qDebug() << "Right way";
        generateTree(getRight(index), height+1, Cord(cord.pos(), cord.right));
    }
}


int BinarySearchTree::getHeight()
{
    if(tree->rbegin() == tree->rend()) return 0;
    int lastIndex = tree->rbegin()->first;
    int count = 1;
    while(lastIndex != 0){
        lastIndex = getParent(lastIndex);
        count++;
    };
    return count;
}
