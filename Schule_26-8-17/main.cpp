#include <iostream>

using namespace std;

template <class T>

T getSmallest(T *array, int SIZE){
    T check = array[0];

    for (int i = 0; i < SIZE; ++i) {
        if(array[i] < check){
            check = array[i];
        }
        return check;
    }
}

int main() {
    int testArray1[5]{5,4,3,2,1};
    float testArray2[5]{4.3,5.4,3.2,1.3,0.7};
    cout << getSmallest(testArray1, 5) << endl;
    return 0;
}