//
// Created by Michel on 25.11.2017.
//

#include "PriorityQueue.h"

PriorityQueue::PriorityQueue() {
    this->size = 0;
}

void PriorityQueue::insert(int value) {
    this->values[size] = value;
    int index = size;
    ++size;
    int newIndex;
    int rightPosition = false;
    while (!rightPosition) {
        if (index == 0) {
            break;
        }
        newIndex = (index - 1) / 2;
        if (this->values[index] < this->values[newIndex]) {
            // Swap
            int temp = this->values[index];
            this->values[index] = this->values[newIndex];
            this->values[newIndex] = temp;
            index = newIndex;
        } else {
            rightPosition = true;
        }
    }
}

int PriorityQueue::extractMin() {
    if (this->size == 0) return -1;
    if (this->size == 1) {
        --size;
        return values[0];
    }

    int result = this->values[0];
    this->values[0] = this->values[size - 1];
    --size;
    int index = 0;
    int newIndex;
    int rightPosition = false;
    while (!rightPosition) {

        if (values[index * 2 + 1] <= values[index * 2 + 2] || index * 2 + 2 > size - 1) {
            // Left element is smaller
            if (index * 2 + 1 > size - 1) {
                rightPosition = true;
                break;
            } else {
                newIndex = index * 2 + 1;
            }
        } else {
            // Right element is smaller
            newIndex = index * 2 + 2;
        }
        if (this->values[index] > this->values[newIndex]) {
            // Swap
            int temp = this->values[index];
            this->values[index] = this->values[newIndex];
            this->values[newIndex] = temp;
            index = newIndex;
        } else {
            rightPosition = true;
        }
    }
    return result;
}

int PriorityQueue::getSize() const {
    return size;
}

