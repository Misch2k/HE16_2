/*
 * AUFGABE 7 - Münzkombination
 * by Michel Kugler - 17.09.2017
 *
 * In dieer Aufgabe soll ein Algorithmus implementiert werden,
 * welcher fr eien bestimmten Geldbetrag die minimale anzahl Münzen berechnet.
 *
 * Der Algorithmus erhält als Input den Betrag sowie ein Array mit den verfügbaren Münzen.
 *
 *
 *
 * class CoinCombination {
 * public:
 *     static void printCoinCombination(
 *             double value,
 *             const double *coins,
 *             const int ARRAY_SIZE
 *     );
 * };
 *
 *
 *
 */

#include <iostream>
#include <ctime>
#include "CoinCombination.h"
#include "../../myFunctions/functions.h"


using namespace std;


int main() {
    double coins[]{5, 2, 1, 0.5, 0.25, 0.2, 0.1, 0.05};
    int numberOfCoins = 8;
    double sumOfMoney = 0;

    time_t start;

    cout << "Type in a amount: " << endl;
    cin >> sumOfMoney;

    start = clock();
    CoinCombination::printCoinCombination(sumOfMoney, coins, numberOfCoins);
    print_runtime(start);
    return 0;
}