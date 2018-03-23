#ifndef THREAD_H
#define THREAD_H
#include <QMutex>
#include <QThread>

class Thread : public QThread
{
public:
    Thread(bool isRead = false);
    static int counter;
    static bool read;
private:
    void run();
    bool isRead;
    QMutex *mutex;
};

#endif // THREAD_H
