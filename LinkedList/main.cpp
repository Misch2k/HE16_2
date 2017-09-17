#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {
    LinkedList<int> obj;

    for (int i = 0; i < 10; ++i) {
        obj.add(5);
    }


    return 0;
}