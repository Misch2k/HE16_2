/*
 * Aufgabe 3 - Aktienkurse
 * Michel Kugler
 *
 * In dieser Aufgabe soll eie Methode implementiert werden, welche als parameter einen Array enthält.
 * Dieser Array beinhaltet die Aktienpreise eines bestimmten Unternehmen für einen Tag.
 * Der Arrayindex ist dabei die Minute seit Start.
 * Börse öffnet um 09:00 und schliesst um 17.30)
 *
 * Beispiel:
 * stockprice[0] = 100 // Wert der Aktie um 09:00
 * stockprice[10] = 95 // Wert der Aktie um 09:10
 * stockprice[440] = 110 // Wert der Aktie um 16:20
 *
 *
 * Finde Sie den maximalen Gewinn der an diesem Tag erzielt werden konnte.
 * Achtung: "shorting" (Verkauf vor Kauf) ist nicht erlaubt.
 * Ebenso ist es nicht erlaub die Aktie zum gleichen Zeitpunkt zu kaufen und zu verkaufen.
 * Es kann durchaus möglich sein, dass der Gewinn negativ ist.
 *
 *  class Trader {
 *  public:
 *      static int calculateMaxProfit(const int *values, const int ARRAY_SIZE);
 *  };
 *
 *  Resultat:
 *  O(n^2/2)
 */


#include <iostream>
#include <ctime>
#include "../myFunctions/functions.h"

// Class Trader.h
#include "Trader.h"


using namespace std;



int main() {

    // 1730 - 900 = Minutes per day
    const int SIZE = 1730-900;
    int stockValues[SIZE];

    // Fill the Array with random numbers between 1000-500
    fillThisArray(stockValues, SIZE, 1000, 500);

    // To print the Array
    print_r<int>(stockValues, SIZE, 30);

    clock_t start;
    start = clock();

    cout << Trader::calculateMaxProfit(stockValues, SIZE) << endl;


    // Print the runtime. Needs only Start Value (stock value has Default clock() as value
    print_runtime(start);

    return 0;
}