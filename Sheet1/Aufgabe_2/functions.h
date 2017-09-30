/*
 * MK - 25.08.2017
 *
 * My own Functions
 */

#include <cstdlib>

#ifndef AUFGABE_1_FUNCTIONS_H
#define AUFGABE_1_FUNCTIONS_H

/**
 * Fill an Array with random INT Numbers between min and max
 * @param array
 * @param SIZE_OF_ARRAY
 * @param max
 * @param min
**/

template <class T, class I = T>

void fillThisArray(T *array, int SIZE_OF_ARRAY, I max = 20000, I min = 1) {
    //Fill Array with Numbers
    for (int i = 0; i < SIZE_OF_ARRAY; ++i) {
        array[i] = ((T)(rand() % (int)(max+1-min)) + min);
    }
}

#endif //AUFGABE_1_FUNCTIONS_H


