//
// Created by M. Kugler on 08.09.2017.
//

#ifndef AUFGABE_5_ARRAYUTIL_H
#define AUFGABE_5_ARRAYUTIL_H


class ArrayUtil {
public:
    static int highestProduct(int *values, const int ARRAY_SIZE);
};

int ArrayUtil::highestProduct(int *values, const int ARRAY_SIZE) {
    // Size of the Array when it has to be dynamic
    const int toMultiplyHighest = 3;
    // result :D
    int result = 1;
    // Flag, if an index has come once before
    bool doIt = true;

    // For the 3 Highest Numbers & index Array if index come once to prevent do count this twice
    int *highest = new int[toMultiplyHighest];
    int *doNot = new int[toMultiplyHighest];

    // Fill arrays
    for (int i = 0; i < toMultiplyHighest; ++i) {
        highest[i] = values[0];
        doNot[i] = -1;
    }

    /**
     * First  : Loop all highest
     * Second : Loop to loop the input array
     * Third  : Loop the doNot ray filled with indexes
     */
    for (int j = 0; j < toMultiplyHighest; ++j) {
        for (int i = 0; i < ARRAY_SIZE; ++i) {
            for (int k = 0; k < toMultiplyHighest; ++k) {
                doIt = i == doNot[k];
            }
            if ((values[i] > highest[j]) && !doIt) {
                highest[j] = values[i];
                doNot[j] = i;
            }
        }
    }

    //print_r(highest, toMultiplyHighest);

    for (int i = 0; i < toMultiplyHighest; ++i) {
        result *= highest[i];
    }

    delete[] highest;
    delete[] doNot;
    return result;
};



#endif //AUFGABE_5_ARRAYUTIL_H
