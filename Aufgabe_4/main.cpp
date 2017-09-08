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

// My functions (to fill arrays with numbers, array print function and print_runtime function
#include "../myFunctions/functions.h"

// Class Trader.h
#include "Trader.h"


using namespace std;



int main() {

    // 1730 - 900 = Minutes per day
    const int SIZE = 1730-900;
    int stockValues[SIZE];
    int testStockFall[10]{20,18,16,14,12,10,8,6,4,2};
    int testStockRise[10]{2,4,6,8,10,12,14,16,18,20};

    // Fill the Array with random numbers between 1000-500
    fillThisArray(stockValues, SIZE, 190, 150);

    // Test the method
    //cout << "TestArray (only fall) = " << Trader::calculateMaxProfit(testStockFall, 10) << endl;
    //cout << "TestArray (only rise) = " << Trader::calculateMaxProfit(testStockRise, 10) << endl;


    clock_t start;
    start = clock();

    cout << Trader::calculateMaxProfit(stockValues, SIZE) << endl;


    // Print the runtime. Needs only Start Value (Function has a second parameter with clock() as default value
    print_runtime(start);

    return 0;
}