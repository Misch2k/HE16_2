#include "model.h"


Model::Model()
{
}

Model& Model::get(){
    static Model instance;
    return instance;
}

Model::~Model()
{

}

