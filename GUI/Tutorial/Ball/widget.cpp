#include "widget.h"

#include <QPaintEvent>
#include <QPainter>

#include "thread.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent), x(100), y(100), xSpeed(6), ySpeed(6)
{
    Thread *t = new Thread();
    t->start();

    QObject::connect(t, SIGNAL(doSomeThing()), this, SLOT(move()));
    QObject::connect(t, SIGNAL(doSomeThing()), this, SLOT(update()));
}

Widget::~Widget()
{

}

void Widget::move()
{
    int RADIUS = 40;
    x = x+xSpeed;
    y = y+ySpeed;

    if (x + RADIUS > width() || x < 0) {
        xSpeed *= -1;
    }
    if (y + RADIUS > height() || y < 0) {
        ySpeed *= -1;
    }

}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawArc(x, y, 40, 40, 0, 5760);
}
