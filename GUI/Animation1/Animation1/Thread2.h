#ifndef Thread2_H
#define Thread2_H

#include <QThread>
#include <QObject>
#include <QMutex>
#include <QMutexLocker>
#include <QWaitCondition>

class Widget2;

class Thread2 : public QThread
{
    Q_OBJECT
public:
    Thread2(Widget2 *parent);
private:
    void run();
    Widget2 *parent;
    QMutex *mute;
    bool wait;
    QWaitCondition query;
public slots:
    void waitWithRender(bool);
};

#endif // Thread2_H
