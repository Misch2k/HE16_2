#include <iostream>
#include "PriorityQueue.h"

int main() {
    PriorityQueue kontainer;

    for(int i = 0; i < 20; i++){
        kontainer.insert(rand()%50);
    }
    cout << kontainer << endl;

    while(kontainer.getSize() != 0){
        cout << kontainer.extractMin() << endl;
    }

    cin.get();
    return 0;
}