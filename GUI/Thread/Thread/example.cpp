#include "example.h"
#include <QPainter>
#include <QPen>
#include <QDebug>
#include <QStyleOption>
#include <QTime>

Example::Example(QWidget *parent) : QWidget(parent)
{
    // Generate different background color for each widget
    //this->setStyleSheet(QString("background: rgb(%1,%2,%3);").arg(qrand() % 256).arg(qrand() % 256).arg(qrand() % 256));

}

void Example::paintEvent(QPaintEvent *event)
{
    QPainter paint(this);
    // Draw StyleSheet of this Widget - begin()
    QStyleOption opt;
     opt.init(this);
     style()->drawPrimitive(QStyle::PE_Widget, &opt, &paint, this);
    QWidget::paintEvent(event);
    // Draw StyleSheet of this Widget - end()

    // Draw events

}
