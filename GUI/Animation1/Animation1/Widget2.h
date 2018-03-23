#ifndef Widget2_H
#define Widget2_H
#include <QObject>
#include <QWidget>
#include "Thread2.h"


class Widget2 : public QWidget
{
    Q_OBJECT
public:
    explicit Widget2(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    int x;
    int y;
    int vx;
    int vy;
    int speed;
    Thread2 *t1;
    void move();
signals:
    void stopRender(bool);
public slots:
    void setSpeed(int);
};

#endif // Widget2_H
