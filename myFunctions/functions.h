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

void addLetterToString(string * s, int SIZE){
    for (int i = 0; i < SIZE; ++i) {
        *s += (char)(rand()%26 + 'a');
    }
}

template <class T>
void print_r(const T *ray, int SIZE, int step = 1){
        cout << "Array : " << endl;
    for (int i = 0; i < SIZE; i += step) {
        cout << i << " => "<< ray[i] << endl;
    }
}

void print_runtime(const clock_t start, const clock_t stop = clock(), int SIZE = 0){
    if(SIZE != 0){
        cout << "Array SIZE = " << SIZE << endl;
    }
    cout << "Runtime = " << (double)(stop-start)/CLOCKS_PER_SEC;
}
#endif //AUFGABE_1_FUNCTIONS_H


