#ifndef VALIDMESSAGE_H
#define VALIDMESSAGE_H

#include <QObject>
#include <QLabel>
#include <QString>

class validMessage : public QLabel {
    Q_OBJECT
public:
    validMessage(const QString &text, QWidget *parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags()) :
     QLabel(text, parent, f){}
public slots:
    void setValidate(const QString &);
};


#endif // VALIDMESSAGE_H
