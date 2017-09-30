//
// Created by M. Kugler on 17.09.2017.
//

#ifndef AUFGABE_7_COINCOMBINATION_H
#define AUFGABE_7_COINCOMBINATION_H

#include <iostream>
#include <math.h>
#include <map>
#include <set>

using namespace std;

class CoinCombination {
public:
    static void printCoinCombination(
            double value,
            const double *coins,
            const int ARRAY_SIZE
    );
};

void CoinCombination::printCoinCombination(double value, const double *coins, const int ARRAY_SIZE) {

    set<int> SumOfCoins;
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        SumOfCoins.insert(static_cast<int>(coins[i] * 100));
    }

    value *= 100;

    for (set<int>::reverse_iterator rit = SumOfCoins.rbegin(); rit != SumOfCoins.rend(); ++rit) {
        int temp = static_cast<int>(value / *rit);

        if(temp != 0){
            value -= *rit * temp;
            cout << *rit << endl;
            cout << (double)*rit/100 << " => " << temp << endl;
        }
    }

}

#endif //AUFGABE_7_COINCOMBINATION_H
