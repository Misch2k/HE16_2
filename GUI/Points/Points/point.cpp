#include "point.h"
#include "QPainter"
#include "QDebug"
#include "QPoint"
#include "vector"
#include "QMouseEvent"

Point::Point(QWidget *parent) : QWidget(parent)
{
    points.emplace_back(QPoint(width()*0.5, height()*0.05));
    points.emplace_back(QPoint(width()*0.5, height()*0.95));
    points.emplace_back(QPoint(width()*0.95, height()*0.5));
    count = 0;
}

void Point::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 2));
    calcPoints(&painter);
    //painter.drawLine(0,0,width(), height());
}

void Point::calcPoints(QPainter *paint)
{

    for_each(points.begin(), points.end(), [paint](QPoint &p){paint->drawPoint(p);});

    QPoint now;
    now = points[rand()%3];
    for(int i = 0; i < 100000; i++){
        int r = rand()%3;
        switch (r){
        case 0:
            paint->setPen(QPen(Qt::red, 2));
            break;
        case 1:
            paint->setPen(QPen(Qt::green, 2));
            break;
        case 2:
            paint->setPen(QPen(Qt::blue, 2));
            break;
        }
        QPoint m(now.x() + (points[r].x() - now.x())/2, now.y() + (points[r].y() - now.y())/2);
        paint->drawPoint(m);
        now = m;
    }
}

void Point::mousePressEvent(QMouseEvent *event)
{

    points[count] = event->pos();
    count++;
    if(count == 3){
        count = 0;
        repaint();
    }
}

