#include "thread.h"
#include <QDebug>
#include <stdlib.h>
#include <QMutexLocker>

int Thread::counter = 0;
bool Thread::read = false;

Thread::Thread(bool isRead) : isRead(isRead)
{
    mutex = new QMutex();
}

void Thread::run()
{
    for(int i = 0; i < 10; i++){
        if(isRead){
            {
                QMutexLocker locker(mutex);
                if(read){
                    qDebug() << "Get counter = " << counter << " - " << currentThreadId();
                    read = false;
                }
            }
            msleep(1000);
        }else{
            {
                QMutexLocker locker(mutex);
                if(!read){
                    int temp = rand();
                    counter = temp;
                    qDebug() << "Set counter = " << temp << " - " << currentThreadId();
                    read = true;
                }
            }
            msleep(1000);
        }
    }
}
