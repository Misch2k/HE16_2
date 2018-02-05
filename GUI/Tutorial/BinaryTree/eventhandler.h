#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <QObject>
#include "model.h"
#include "centerwidget.h"

class EventHandler : public QObject
{
    Q_OBJECT
public:
    EventHandler(CenterWidget *parent = nullptr);
private:
    CenterWidget *parent;
signals:
    void updateTree();
public slots:
    void addItem();
    void deleteItem();
    void deleteAll();
};

#endif // EVENTHANDLER_H
