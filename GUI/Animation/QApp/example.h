#ifndef EXAMPLE_H
#define EXAMPLE_H
#include <QObject>
#include <QWidget>


class Example : public QWidget
{
    Q_OBJECT
public:
    explicit Example(QWidget *parent = nullptr);
private:
    void paintEvent(QPaintEvent *event);
signals:

public slots:
};

#endif // EXAMPLE_H
