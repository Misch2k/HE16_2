#include <iostream>
#include <map>
#include <chrono>

using namespace std;
using ns = chrono::nanoseconds;
using get_time = chrono::steady_clock;

/* AUFGABE 1, Fakultaet
Welches ist die groesste Zahl, fuer welche die Fakultaet mit C++
berechnet werden kann (falls der Datentyp long long verwendet wird.)?
*/

/* AUFGABE 2, Fibonacci Rekursiv (inkl Performance Messung!)
*/
int fibRe(int n) {
    if (n == 1 || n == 2) return 1;
    else return fibRe(n - 1) + fibRe(n - 2);
}


/* AUFGABE 3, Fibonacci Iterativ (inkl Performance Messung!)
*/
int fibIt(int n) {
    int first, second, temp;
    first = 0;
    second = 1;
    for (int i = 0; i < n; ++i) {
        temp = first + second;
        second = first;
        first = temp;
    }
    return first;
}

/* AUFGABE 4, Fibonacci Rekursiv mit Verbesserung
*/
int fibReImp(int n) {
    map<int, int> solvedFib;
    if (n == 1 || n == 2) return 1;
    else {
        solvedFib.insert(pair<int, int>(n, (solvedFib.find(n - 1) != solvedFib.end() ? solvedFib.at(n - 1) : fibReImp(
                n - 1)) + (solvedFib.find(n - 2) != solvedFib.end() ? solvedFib.at(n - 2) : fibReImp(n - 2))));
        return solvedFib.at(n);
    }
};

/* AUFGABE 5, Exponentiation Rekursiv
*/
double power(double x, int n) {
    // your code
    if (n == 0) return 1;
    if (n == 1) return x;
    if (n % 2 == 1) {
        double result = power(x, (n-1)/2);
        return result * result * x;
    } else {
        double result = power(x, n/2);
        return result * result;
    }
}

int main(int argc, char **argv) {
    auto start = get_time::now();
    auto end = get_time::now();
    auto diff = start - end;

    // Test Aufgabe 2
    cout << "Aufgabe 2" << endl;
    cout << "=============" << endl;
    start = get_time::now();
    if (fibRe(1) == 1 && fibRe(3) == 2 && fibRe(8) == 21) {
        cout << "Aufgabe 2 ist richtig" << endl;
    } else {
        cout << "Aufgabe 2 ist falsch" << endl;
    }
    end = get_time::now();
    diff = end - start;
    cout << "Elapsed time is :  " << chrono::duration_cast<ns>(diff).count() << " ns " << endl;
    cout << endl << endl;


    // Test Aufgabe 3
    cout << "Aufgabe 3" << endl;
    cout << "=============" << endl;
    start = get_time::now();
    if (fibIt(1) == 1 && fibIt(3) == 2 && fibIt(8) == 21) {
        cout << "Aufgabe 3 ist richtig" << endl;
    } else {
        cout << "Aufgabe 3 ist falsch" << endl;
    }

    end = get_time::now();
    diff = end - start;
    cout << "Elapsed time is :  " << chrono::duration_cast<ns>(diff).count() << " ns " << endl;
    cout << endl << endl;


    // Test Aufgabe 4
    cout << "Aufgabe 4" << endl;
    cout << "=============" << endl;
    start = get_time::now();
    if (fibReImp(1) == 1 && fibReImp(3) == 2 && fibReImp(8) == 21) {
        cout << "Aufgabe 4 ist richtig" << endl;
    } else {
        cout << "Aufgabe 4 ist falsch" << endl;
    }
    end = get_time::now();
    diff = end - start;
    cout << "Elapsed time is :  " << chrono::duration_cast<ns>(diff).count() << " ns " << endl;
    cout << endl << endl;

    // Test Aufgabe 5
    cout << "Aufgabe 5" << endl;
    cout << "=============" << endl;
    start = get_time::now();
    if (power(2, 2) == 4 && power(2, 0) == 1 && power(3, 3) == 27) {
        cout << "Aufgabe 5 ist richtig" << endl;
    } else {
        cout << "Aufgabe 5 ist falsch" << endl;
    }
    end = get_time::now();
    diff = end - start;
    cout << "Elapsed time is :  " << chrono::duration_cast<ns>(diff).count() << " ns " << endl;
    cout << endl << endl;


    cout << power(2, 4);
    return 0;
}
