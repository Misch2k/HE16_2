#include "eventhandler.h"
#include "QDebug"

EventHandler::EventHandler(CenterWidget *parent) : parent(parent)
{
    Model::get();
}

void EventHandler::addItem()
{
    //Model::get().tree->insertItem(parent->getNumberInput());
    emit updateTree();
}

void EventHandler::deleteItem()
{
    //Model::get().tree->deleteItem(parent->getNumberInput());
    emit updateTree();
}

void EventHandler::deleteAll()
{
   // Model::get().tree->deleteAllItems();
    emit updateTree();
}
