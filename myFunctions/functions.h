/*
 * MK - 25.08.2017
 *
 * My own Functions
 */

#include <iostream>
#include <cstdlib>
#include <chrono>

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


class myTime{
public:
    static chrono::time_point<std::chrono::_V2::system_clock>  start();
    static void stop(chrono::time_point<std::chrono::_V2::system_clock> start_time, int time ,chrono::time_point<chrono::system_clock> end);
};

chrono::time_point<std::chrono::_V2::system_clock> myTime::start()
{
    return chrono::high_resolution_clock::now();
}

void myTime::stop(chrono::time_point<chrono::system_clock> start_time, int time = 0, chrono::time_point<chrono::system_clock> end=chrono::high_resolution_clock::now())
{
    switch(time){
        case 1 :
            cout << endl << "Zeit: " << std::chrono::duration_cast<chrono::nanoseconds>(end-start_time).count() << " Nanoseconds"<<endl;
            break;
        case 2 :
            cout << "Zeit: " << std::chrono::duration_cast<chrono::microseconds>(end-start_time).count() << " Microseconds"<<endl;
            break;
        case 3 :
            cout << "Zeit: " << std::chrono::duration_cast<chrono::milliseconds>(end-start_time).count() << " Milliseconds"<<endl;
            break;
        case 4 :
            cout << "Zeit: " << std::chrono::duration_cast<chrono::seconds>(end-start_time).count() << " Seconds"<<endl;
            break;
        default :
            cout << endl << "Zeit: " << std::chrono::duration_cast<chrono::nanoseconds>(end-start_time).count() << " Nanoseconds"<<endl;
            cout << "Zeit: " << std::chrono::duration_cast<chrono::microseconds>(end-start_time).count() << " Microseconds"<<endl;
            cout << "Zeit: " << std::chrono::duration_cast<chrono::milliseconds>(end-start_time).count() << " Milliseconds"<<endl;
            cout << "Zeit: " << std::chrono::duration_cast<chrono::seconds>(end-start_time).count() << " Seconds"<<endl;
            break;
    }
    return;
}

#endif //AUFGABE_1_FUNCTIONS_H


