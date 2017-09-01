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
// ctime => time counter
#include <ctime>
// functions.h => irrelevant functions for this project
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

        // temp has the multiplication of all values before (couted up).
        // Save it in the position of the array
        long temp = 1;
        for (int i = 0; i < ARRAY_SIZE; ++i) {
            product[i] = temp;
            temp *= values[i];
        }

        // temp has the factor of all values before (counted down)
        // Multiply it with the value in the product[i] position and product has the multiplication of all values excluded itself.
        temp = 1;
        for (int i = ARRAY_SIZE - 1; i >= 0; --i) {
            product[i] *= temp;
            temp *= values[i];
        }

        // Return the address of product array
        return product;
    };

};

int main() {

    //Initialize the testArray and fill with Numbers
    long SIZE = 30;
    long testArray[SIZE];
    fillThisArray<long>(testArray, SIZE , 10);

    cout << "Testarray before" << endl;
    for (int i = 0; i < SIZE; ++i) {
        cout << "Array [" << i << "] = " << testArray[i] << endl;
    }

    //Pointer where the Array is saved in
    long *output;


    //Time Capture
    time_t start, stop;

    start = clock();
    output = ArrayUtil::multiplyArrayValues(testArray, SIZE);
    stop = clock();

    cout << "Testarray after" << endl;
    for (int i = 0; i < SIZE; ++i) {
        cout << "Array [" << i << "] = " << output[i] << endl;
    }

    cout << "Runtime ArrayUtil = " << (double) (stop - start) / CLOCKS_PER_SEC;

    delete[]output;


    return 0;
}