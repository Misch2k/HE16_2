//
// Created by M. Kugler on 02.09.2017.
//

#ifndef AUFGABE4_TRADER_H
#define AUFGABE4_TRADER_H

class Trader {
public:
    static int calculateMaxProfit(const int *values, const int ARRAY_SIZE);
};


int Trader::calculateMaxProfit(const int *values, const int ARRAY_SIZE) {
    int *stock = new int [ARRAY_SIZE];

    for (int i = ARRAY_SIZE-1; i >= 0; --i) {
        stock[i] = 1;
    }

    int maxWin(values[1]-values[0]);

    for (int i = 0; i < ARRAY_SIZE-1; ++i) {
        for (int j = i+1; j < ARRAY_SIZE; ++j) {
            if(values[j]-values[i] > maxWin){
                maxWin = values[j]-values[i];
            }
        }
    }

    delete [] stock;
    return maxWin;
};

#endif //AUFGABE4_TRADER_H
