//
// Created by M. Kugler on 08.09.2017.
//

#ifndef AUFGABE_5_ARRAYUTIL2_H
#define AUFGABE_5_ARRAYUTIL2_H

#include <climits>

class ArrayUtil2 {
public:
    static int highestProduct(int *values, const int ARRAY_SIZE);
};


int ArrayUtil2::highestProduct(int *values, const int ARRAY_SIZE) {
    if (ARRAY_SIZE < 3) return false;

    int highest1(INT_MIN), highest2(INT_MIN), highest3(INT_MIN), lowest1(INT_MAX), lowest2(INT_MAX);
    int hasZero = 1;

    int result;

    for (int i = 0; i < ARRAY_SIZE; ++i) {
        if (values[i] != 0) {
            if (values[i] >= highest1) {
                highest3 = highest2;
                highest2 = highest1;
                highest1 = values[i];
            } else if (values[i] >= highest2) {
                highest3 = highest2;
                highest2 = values[i];
            } else if (values[i] >= highest3) {
                highest3 = values[i];
            }

            if (values[i] <= lowest1) {
                lowest2 = lowest1;
                lowest1 = values[i];
            } else if (values[i] <= lowest2) {
                lowest2 = values[i];
            }
        } else {
            hasZero = 0;
        }

    }

/*
    cout << "Highest 1 : " << highest1 << endl;
    cout << "Highest 2 : " << highest2 << endl;
    cout << "Highest 3 : " << highest3 << endl;
    cout << "Lowest  1 : " << lowest1 << endl;
    cout << "Lowest  2 : " << lowest2 << endl;
    cout << "hasZero   : " << (hasZero == 0 ? "true" : "false") << endl;
    cout << "======================" << endl;
*/

    if (lowest2 * lowest1 > highest2 * highest3) {
        result = lowest1 * lowest2 * highest1;
    } else {
        result = highest1 * highest2 * highest3;
    }

    if(result < 0){
        return result *= hasZero;
    }else
        return result;
}


#endif //AUFGABE_5_ARRAYUTIL2_H
