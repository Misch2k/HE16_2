#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPaintEvent>

class QPaintEvent;

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
signals:

public slots:
};

#endif // WIDGET_H
