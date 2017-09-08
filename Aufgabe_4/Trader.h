//
// Created by M. Kugler on 02.09.2017.
//

#ifndef AUFGABE4_TRADER_H
#define AUFGABE4_TRADER_H

struct StockValue {
    int value;
    int position;
};


class Trader {
public:
    static int calculateMaxProfit(const int *values, const int ARRAY_SIZE);
};

/**
 * Calculate the max difference between two values. Count only forward.
 * @param values
 * @param ARRAY_SIZE
 * @return
 */
int Trader::calculateMaxProfit(const int *values, const int ARRAY_SIZE) {

    // Initialize both temp variable with a default value from array
    int minValue = values[0];
    int maxDiff = values[1] - values[0];

    // First if: Check the diff between the minvalue and actual value. When higher save it
    // Second if: Check if the actual value is smaller then one before.
    for (int i = 1; i < ARRAY_SIZE; ++i) {
        if ((values[i] - minValue) > maxDiff) {
            maxDiff = (values[i] - minValue);
        };
        if (values[i] < minValue) {
            minValue = values[i];
        }
    }

    return maxDiff;

};


#endif //AUFGABE4_TRADER_H
