/*
 * MK - 25.08.2017
 *
 * Aufgabe 1
 * Analyse the Runtime from the Function foo
 *
 * Result = O(n) => Linear
 * 
 * It's just one Loop.
 */


#include <iostream>
//ctime => time count
#include <ctime>
//cstdlib => random number
#include "functions.h"

using namespace std;

/**
 * Return the sum and Product from all element of an array
 * @param array
 * @param size
 */
void foo(int *array, int size) {

    int sum = 0;
    int product = 1;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    for (int i = 0; i < size; i++) {
        product *= array[i];
    };
    cout << sum << "," << product << endl;
}


int main() {

    //Initialize an array to test
    int SIZE = 100000;
    int testArray[SIZE];

    //Fill testArray with random Numbers
    fillThisArray(testArray, SIZE);

    //Execute the function 5 times and show time for each round
    for (int i = 0; i < 5; ++i) {
        //Start time
        time_t start, stop;
        start = clock();

        //Run foo()
        foo(testArray, SIZE);

        //Stop time
        stop = clock();
        cout << "Round " << i << " = " << (double) (stop - start) / CLOCKS_PER_SEC << endl;
    }
    return 0;
}
