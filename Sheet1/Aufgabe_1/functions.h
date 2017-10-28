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
void fillThisArray(int *array, int SIZE_OF_ARRAY, int max = 20000, int min = 1) {
    //Fill Array with Numbers
    for (int i = 0; i < SIZE_OF_ARRAY; ++i) {
        array[i] = rand() % (max-min) + min;
    }
}

#endif //AUFGABE_1_FUNCTIONS_H

