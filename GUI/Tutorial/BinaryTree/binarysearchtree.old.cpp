#include "binarysearchtree.old.h"
#include "model.h"

BinarySearchTreeOld::BinarySearchTreeOld()
{
    this->tree = new std::map<int,int>;
    this->size = 0;
}

BinarySearchTreeOld::~BinarySearchTreeOld()
{
    delete this->tree;
}

void BinarySearchTreeOld::insertItem(int v, int index)
{
    if(tree->find(index) == tree->end()){
        tree->insert(std::pair<int,int>(index, v));
        //Model::get().labels.insert(std::pair<int, QLabel*>(index, new QLabel(QString::number(v))));
        size++;
        //qDebug() << "Insert " << v << " at Position " << index;
    }else{
        if(tree->at(index) >= v){
            insertItem(v, getLeft(index));
        }else{
            insertItem(v, getRight(index));
        }
    }
}

void BinarySearchTreeOld::deleteItem(int v)
{
    if(v < 0){
        //qDebug() << "Value < 0";
        return;
    }
    int pos = findItem(v);
    if(pos == -1){
        //qDebug() << "Value not found";
    }else{
        deleteItemRec(pos);
    }
}

void BinarySearchTreeOld::deleteItemRec(int index)
{
    int pos = getRightMember(index);
    if(pos != -1)
    {
        //qDebug() << "Delete item pos " << index << " and ersetzte it with pos " << pos;
        tree->at(index) = tree->at(pos);
        //Model::get().labels.erase(index);
        //Model::get().labels.at(index) = Model::get().labels.at(pos);
        deleteItemRec(pos);
    }else{
        //qDebug() << "Delete item pos " << index;
        tree->erase(index);
        //Model::get().labels.erase(index);
        size--;
    }
}

int BinarySearchTreeOld::getRightMember(int index, bool left, bool first){
    //qDebug() << "Search " << (left ? "left" : "right") << " member: " << index;
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

void BinarySearchTreeOld::deleteAllItems()
{
    tree->clear();
    size = 0;
}

int BinarySearchTreeOld::getHeight()
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

int BinarySearchTreeOld::getSize()
{
    return size;
}

std::map<int, int> BinarySearchTreeOld::getTree()
{
    return *this->tree;
}

void BinarySearchTreeOld::Print()
{
    std::map<int,int>::iterator it;
    for(it = tree->begin(); it != tree->end(); it++){
        //qDebug() << it->second;
    }
}

int BinarySearchTreeOld::getRight(int v)
{
    return v*2+2;
}

int BinarySearchTreeOld::getLeft(int v)
{
    return v*2+1;
}

int BinarySearchTreeOld::getParent(int v)
{
    return (v-1)/2;
}

int BinarySearchTreeOld::findItem(int v, int index)
{
    if(tree->find(index) == tree->end()){
        //qDebug() << "Item not found";
        return -1;
    }else if(tree->at(index) == v){
        //qDebug() << v << " : " << tree->at(index);
        return index;
    }else{
        //qDebug() << v << " : " << tree->at(index);
        if(tree->at(index) > v){
            return findItem(v, getLeft(index));
        }else{
            return findItem(v, getRight(index));
        }
    }
}
