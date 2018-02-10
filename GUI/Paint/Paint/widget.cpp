#include "widget.h"
#include <QPainter>


Widget::Widget(QWidget *parent) : QWidget(parent)
{

}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    for(int i = 1; i<= 20; i++){
        painter.drawLine(0,0,width()/20*i,height());
    }
    for(int i = 1; i<= 20; i++){
        painter.drawLine(0,0,width(),height()/20*i);
    }
    for(int i = 1; i<= 20; i++){
        painter.drawLine(width(),height(), width()/20*i, 0 );
    }
    for(int i = 1; i<= 20; i++){
        painter.drawLine(width(),height(), 0, height()/20*i);
    }
}
