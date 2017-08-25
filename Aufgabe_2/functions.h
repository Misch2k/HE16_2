/*
 * MK - 25.08.2017
 *
 * My own Functions
 */

#include <iostream>
#include <cstdlib>

using namespace std;

#ifndef AUFGABE_1_FUNCTIONS_H
#define AUFGABE_1_FUNCTIONS_H

/**
 * Fill an Array with random INT Numbers between min and max
 * @param array
 * @param SIZE_OF_ARRAY
 * @param max
 * @param min
**/
void fillThisArray(int *array, int SIZE_OF_ARRAY, int max = 20000, int min = 1) {
    //Fill Array with Numbers
    for (int i = 0; i < SIZE_OF_ARRAY; ++i) {
        array[i] = rand() % (max+1-min) + min;
    }
}

//Overload for dataType long
void fillThisArray(long *array, long SIZE_OF_ARRAY, long max = 20000, long min = 1) {
    //Fill Array with Numbers
    long counter = 1;
    for (long i = 0; i < SIZE_OF_ARRAY; i++) {
        array[i] = (long)(rand() % (max-min) + min);
        counter *= array[i];
    }
}

#endif //AUFGABE_1_FUNCTIONS_H


