#include "Thread2.h"
#include "Widget2.h"

Thread2::Thread2(Widget2 *parent) : parent(parent)
{
    mute = new QMutex;
    wait = false;
}

void Thread2::run()
{
    while(true){
        parent->move();
        QMutexLocker lock(mute);
        msleep(30);

        if(wait){
            query.wait(mute);
        }
    }
}

void Thread2::waitWithRender(bool val)
{
    wait = val;
    if(!val){
        query.wakeAll();
    }
}
