#include "validmessage.h"
#include <QDebug>


void validMessage::setValidate(const QString &text){
    qDebug() << "Text changed handler";
    bool valid = text.length() == 16;

}
