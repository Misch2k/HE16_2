//
// Created by Michel on 25.11.2017.
//

#ifndef PRIORITYQUEUE_PRIORITYQUEUE_H
#define PRIORITYQUEUE_PRIORITYQUEUE_H
#include <array>
#include <ostream>
#include <iostream>

using namespace std;

class PriorityQueue {
private:
    array<int, 1000> values;
    int size;
public:
    PriorityQueue();
    void insert(int value);
    int extractMin();
    int getSize() const;

    friend ostream &operator<<(ostream &stream, PriorityQueue &obj){
        for(int i = 0; i < obj.getSize(); i++){
            stream << i << ": " << obj.values[i] << endl;
        }
        return stream;
    }
};


#endif //PRIORITYQUEUE_PRIORITYQUEUE_H
