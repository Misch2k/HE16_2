#ifndef test_H
#define test_H
#include <QObject>
#include <QWidget>


class test : public QWidget
{
    Q_OBJECT
public:
    explicit test(QWidget *parent = nullptr);
private:
    void paintEvent(QPaintEvent *event);
signals:

public slots:
};

#endif // test_H
