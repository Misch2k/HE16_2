#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <vector>

using namespace std;

template <class T>
class Result{
public:
    T nPositive;
    T nZero;
    T nNegative;
    Result();
    friend std::ostream & operator<<(std::ostream & stream, const Result<T> & obj){

        stream << "Groesster: " << obj.nPositive << endl;
        stream << "Gleich 0 : " << obj.nZero << endl;
        stream << "Kleinste : " << obj.nNegative << endl;

        return stream;
    }
};
//Defaultkonstruktor erstellung eines Objekts Result mit den drei Werten auf 0
template <class T>
Result<T>::Result(): nNegative(0), nPositive(0) , nZero(0){
}

template <class T>
class ArrayUtil{
private:
    //Result<T> *nPositive;
    //Result<T> *nZero;
    //Result<T> *nNegative;
public:
    ArrayUtil<T> operator= (const ArrayUtil<T> & obj);
    static Result<T> analyseArray(vector<T> input);
};


template <class T>
//static Result<T> analyseArray(vector<T> input){
Result<T> ArrayUtil<T>::analyseArray(vector<T> input) {
    Result<T> *ausgabe = new Result<T>();

    for (unsigned int i = 0 ; i < input.size() ; i++){
        if (input[i] >= 1){
            //cout << input[i] << " ist groesser als 0" << endl;
            ausgabe->nPositive+=1;
        }else if (input[i] == 0){
            //cout << input[i] << " ist gleich 0" << endl;
            ausgabe->nZero+=1;
        }else if (input[i] < 0){
            //cout << input[i] << " ist kleier als 0" << endl;
            ausgabe->nNegative+=1;
        }
    }
/*
    cout << endl <<"Stand Anzahl: " << endl;
    cout << "Groesser: " << ausgabe->nPositive << endl;
    cout << "gleich 0: " << ausgabe->nZero << endl;
    cout << "kleiner : " << ausgabe->nNegative << endl;
*/
    ausgabe->nPositive*=10;
    ausgabe->nZero*=10;
    ausgabe->nNegative*=10;

    //cout << "Rechnung: " << ausgabe->nPositive << " * (100/ " << input.size() << ")";
    ausgabe->nPositive = (ausgabe->nPositive*(float(100)/input.size()));
    ausgabe->nZero = (ausgabe->nZero*(float(100)/input.size()));
    ausgabe->nNegative = (ausgabe->nNegative*(float(100)/input.size()));

    return *ausgabe;
}

template <class T>
ArrayUtil<T> ArrayUtil<T>::operator= (const ArrayUtil<T> & obj) {
    return *this;
}

int main()
{
    ArrayUtil<int> obj;
    float nPositiv(0.0),nZero(0.0),nNegative(0.0);
    vector<int> zahlen;
    zahlen.push_back(1);
    zahlen.push_back(10);
    zahlen.push_back(0);
    zahlen.push_back(-6);
    zahlen.push_back(-9);
    zahlen.push_back(2);
    zahlen.push_back(5);


    cout << "Input: 1, 10, 0, -6, -9, 2, 5" << endl;

    Result<int> bla = obj.analyseArray(zahlen);
    cout << bla << endl;
    //nPositiv =


    //cout << " Leosung: [nPositive: " <<  57.1%; nZero: 14.3%; nNegative: 28.6%]" << endl;

    return 0;
}
