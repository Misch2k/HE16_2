#include "Widget2.h"
#include <QPainter>
#include <QStyleOption>
#include <Thread2.h>

Widget2::Widget2(QWidget *parent) : QWidget(parent)
{
    x = 0;
    y = 0;
    vx = 2;
    vy = 2;
    speed = 2;
    t1 = new Thread2(this);
    t1->start();

    connect(this, SIGNAL(stopRender(bool)), t1, SLOT(waitWithRender(bool)));
}

void Widget2::paintEvent(QPaintEvent *event)
{
    QPainter paint(this);
    paint.setRenderHint(QPainter::HighQualityAntialiasing);
    // Draw StyleSheet of this Widget - begin()
    QStyleOption opt;
    opt.init(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &paint, this);
    QWidget::paintEvent(event);
    // Draw StyleSheet of this Widget - end()

    // Draw events
    paint.drawArc(x,y, 50, 50, 0, 5760);
}

void Widget2::move()
{
    if(x >= width()-52){
        vx = 0 - speed;
    }else if(x <= 2){
        vx = speed;
    }
    if(y >= height()-52){
        vy = 0 - speed;
    }else if(y < 2){
        vy = speed;
    }
    x += vx;
    y += vy;
    update();
}

void Widget2::setSpeed(int speed)
{
    if(speed != 0){
        this->speed = speed;
        if(vx >= 0){
            vx = speed;
        }else{
            vx = 0 - speed;
        }
        if(vy >= 0){
            vy = speed;
        }else{
            vy = 0 - speed;
        }
        emit stopRender(false);
    }else{
        emit stopRender(true);
    }
}
