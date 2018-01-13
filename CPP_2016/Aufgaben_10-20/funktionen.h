#include <iostream>
#include <cmath>
using namespace std;

/* void uberladen1(int a, int b){
    cout << "Es wurde 2x ein INT Wert eingegeben" << endl;
}

void uberladen1(char a, char b){
    cout << "Es wurde 2x ein CHAR Wert eingegeben" << endl;
}

void uberladen1(int a, char b){
    cout << "Der erste Wert war INT, der zweite war ein CHAR" << endl;
}

void uberladen1(char a, int b){
    cout << "Der erste Wert war ein CHAR, der zweite war ein INT"<<endl;
}
*/
//Aufgabe 10.2
//Eine Funktion welche den Wert zurück giebt, wie viel mal sie aufgerufen wurde

void counter(int a){
    static int counter1 = 0;
    for(int i=0;i<a;i++){
        counter1++;
    }

    cout << "Diese Funktion wurde bereits " << counter1 << " mal ausgeführt." << endl;
}

//Aufgabe 15.1
//Eine SWAP Funktion die mit Pointern arbeitet.

void func_swap(double *a,double *b){
    double *temp;

    cout << "Der erste Wert vor dem Funktionsaufruf: " << *a << endl;
    cout << "Der zweite Wert vor dem Funktionsaufruf: " << *b << endl << endl;

    temp = a;
    a=b;
    b=temp;

    cout << "Der erste Wert nach dem Funktionsaufruf: " << *a << endl;
    cout << "Der zweite Wert nach dem Funktionsaufruf: " << *b << endl;

}

//Aufgabe 15.3
//Kleines EinMalEins in einer Funktion. Array übergeben.


//Aufgabe 19.2
//PI berechnen.

int laenge(double zahl) {
  double count;
  count = 0;
  while ((zahl/pow(10,count)) > 10)
    count++;
  return static_cast<int>(count);
}
