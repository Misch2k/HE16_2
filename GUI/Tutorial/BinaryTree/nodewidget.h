#ifndef NODEWIDGET_H
#define NODEWIDGET_H

#include <QObject>
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>

class BinarySearchTree;

class NodeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit NodeWidget(BinarySearchTree *par ,int index, int value, QWidget *parent = nullptr);
    int getIndex() const;
    int getValue() const;
    void setValue(int value);
    QPoint getPosition() const;
    QPoint posLeftMiddle() const;
    QPoint posRightMiddle() const;
    QPoint posTopCenter() const;
    BinarySearchTree *par;
private:
    int index;
    int value;
    QGridLayout *layout;
    QPushButton *deleteButton;
    QPushButton *closeButton;
    QPushButton *label;
    void init(int value);
    void widgetLayout();
    void initStyleSheet();
signals:
    void updateNodeOut();
    int deleteThisItem(int index);
public slots:
    void showButtons();
    void hideButtons();
    void deleteItemByIndex();
};

#endif // NODEWIDGET_H
