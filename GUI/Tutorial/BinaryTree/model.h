#ifndef MODEL_H
#define MODEL_H

#include <QLabel>
#include <QString>

class Model
{
public:
    static Model& get();
    ~Model();
private:
    Model();

};

#endif // MODEL_H
