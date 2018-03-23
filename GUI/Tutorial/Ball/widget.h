#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class QPaintEvent;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

    void paintEvent(QPaintEvent *event);
private:
    int x, y, xSpeed, ySpeed;
public slots:
    void move();
};

#endif // WIDGET_H
