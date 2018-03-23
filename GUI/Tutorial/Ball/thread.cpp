#include "thread.h"

Thread::Thread()
{

}

void Thread::run()
{
    while (true) {
        emit doSomeThing();
        msleep(20);
    }

}
