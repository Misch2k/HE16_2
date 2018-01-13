#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

template <class T>

T getSmallest(T *array, int SIZE){
    T check = array[0];

    for (int i = 0; i < SIZE; ++i) {
        if(array[i] < check){
            check = array[i];
        }
    }
    return check;

}


class MyClass {
private:
int x;
public:
    int const getX();
    void setX(int x);
    bool operator<(const MyClass &);
};

int const MyClass::getX() {
    return this->x;
}

void MyClass::setX(int x) {
    this->x = x;
}

bool MyClass::operator<(const MyClass &obj){
    return x < obj.x;
}

int main() {
    int testArray1[5] = {5,4,3,2,1};
    float testArray2[5] = {4.3,5.4,3.2,1.3,0.7};
    char testArray3[5] = {'a','b','c','d','e'};
    string testArray4[5] = {"asdf","asdf","fdas","adfa","asdfas"};
    //cout << getSmallest<int>(testArray1, 5) << endl;
    //cout << getSmallest<float>(testArray2, 5) << endl;
    //cout << getSmallest<char>(testArray3, 5) << endl;
    //cout << getSmallest<string>(testArray4, 5) << endl;

    MyClass classArray[5];
    for (int i = 0; i < 5; ++i) {
        classArray[i].setX(rand()%1000);
    }

    MyClass result = getSmallest<MyClass>(classArray, 5);



    return 0;
}