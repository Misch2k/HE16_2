#ifndef POINT_H
#define POINT_H

#include <QWidget>

class QSlider;

class Point : public QWidget
{
    Q_OBJECT
public:
    explicit Point(QWidget *parent = nullptr);
private:
    void paintEvent(QPaintEvent *event);
    void calcPoints(QPainter *p);
    void mousePressEvent(QMouseEvent *event);
    std::vector<QPoint> points;
    int count;
signals:

public slots:
};

#endif // POINT_H
