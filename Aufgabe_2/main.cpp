/*
 * MK - 25.08.2017
 *
 * Aufgabe_2
 *
 * Complete the method to return an Array full of products from each position.
 * Except the initial position.
 *
 * Method:
 * static long* multiplyArrayValues(const long *values, const int ARRAY_SIZE)
 */

#include <iostream>
//ctime => time counter
#include <ctime>
//functions.h => irrelevant functions for this project
#include "functions.h"


using namespace std;


class ArrayUtil {
public:
    /**
     * This Method multiplies all positions exclude the initial position and return it in an array
     * @param values
     * @param ARRAY_SIZE
     * @return
     */
    static long *multiplyArrayValues(const long *values, const int ARRAY_SIZE) {
        static long *product = new long[ARRAY_SIZE];
        static long *product2 = new long[ARRAY_SIZE];

        //Aufwärts Multiplizieren
        long temp = 1;
        for (int i = 0; i < ARRAY_SIZE; ++i) {
            product[i] = temp;
            temp *= values[i];
        }

        //Abwärts Multiplizieren
        temp = 1;
        for (int i = ARRAY_SIZE - 1; i >= 0; --i) {
            product2[i] = temp;
            temp *= values[i];
        }

        //Beide Arrays Miteinander Multiplizieren
        for (int i = 0; i < ARRAY_SIZE; ++i) {
            product[i] = product[i] * product2[i];
        }
        delete[] product2;
        return product;
    };

};

int main() {

    //Initialize the testArray and fill with Numbers
    // SIZE can't be bigger then 30 with numbers from 1 - 10 (It will return 0)
    long SIZE = 40;
    long testArray[SIZE];
    fillThisArray(testArray, SIZE, 10);

    //checkSum to Check that no number in the Array was 0
    long checkSum = 1;

    //Pointer where the Array is saved in
    long *output;


    //Time Capture
    time_t start, stop;

    start = clock();
    output = ArrayUtil::multiplyArrayValues(testArray, SIZE);
    stop = clock();

    for (long i = 0; i < SIZE; ++i) {
        checkSum += output[i];
    }

    cout << "Runtime = " << (double) (stop - start) / CLOCKS_PER_SEC;
    cout << "Checksum = " << checkSum << endl;

    delete[]output;


    return 0;
}