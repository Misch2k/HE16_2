/*
 * Sheet 4 - Aufgabe 2
 *
 * Implementieren Sie eine Methode analyseArray welche als Parameter einen Vector mit
 * Integer Werten bekommt. Diese Werte sind entweder Positiv, Negativ resp. Null sind.
 * Diese Drei Werte werden als Objekt der Klasse Result zurückgegeben.
 *
 *
 * class Result {
 * public:
 *     int nPositive;
 *     int nZero;
 *     int nNegative;
 * };
 *
 * class ArrayUtil {
 * public:
 *     static Result analyseArray(vector<int> input);
 * };
 *
 */


#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

class Result {
public:
    int nPositive;
    int nZero;
    int nNegative;

    friend ostream& operator<<(ostream &stream, Result &obj){
        int temp = obj.nPositive + obj.nZero + obj.nNegative;
        stream << "Positive: " << (100 / (double)temp) * obj.nPositive << "%" << endl;
        stream << "Negative: " << (100 / (double)temp) * obj.nNegative << "%" << endl;
        stream << "Zeros:    " << (100 / (double)temp) * obj.nZero << "%" << endl;

        return stream;
    }
};


class ArrayUtil {
public:
    static Result analyseArray(vector<int> input);
};

Result ArrayUtil::analyseArray(vector<int> input) {
    Result value;

    value.nPositive = 0;
    value.nZero = 0;
    value.nNegative = 0;

    for(int number : input){
        if(number < 0){
            value.nNegative++;
        }else if( number > 0){
            value.nPositive++;
        }else{
            value.nZero++;
        }
    }

    return value;
};

int main() {

    vector<int> numbers;
    for (int i = 0; i < 1562; ++i) {
        numbers.push_back(rand()%100 - 50);
    }


    Result obj = ArrayUtil::analyseArray(numbers);

    cout << obj << endl;

    return 0;
}