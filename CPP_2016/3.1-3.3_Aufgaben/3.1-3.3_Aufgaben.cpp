#include <iostream>

using namespace std;

int main()
{

    //Aufgabe: Addition von Variable "a" auf 3 Verschiedene Arten.

    int a(0);
    cout << "Initialisiert a = " << a << endl;

    a = a+1;
    cout << "a + 1 = " << a << endl;

    a++;
    cout << "a++ = " << a << endl;

    ++a;
    cout << "++a = " << a << endl;

    cout << "\n\n\n" << endl;


    //Aufgabe: Inkremiteirung
    cout << "Welchen Wert giebt folgendes Programm aus?\na=12;\na+=++a+a++;\na=a+a;" << endl;
    a=12;
    a+=++a+a++;
    a=a+a;
    cout <<"a hat jetzt den Wert: " << a << endl;
    cout << "\n\n\n" << endl;



    /*Aufgabe: Schreiben Sie ein Programm, welches das Speichervolumen folgender Datentypen
    in Byte ausgibt:
    • int
    • long int
    • float
    • double
    • long double
    • char*/

    cout << "Sizeof folgender Variablen:" << endl;

    cout << "sizeof(int) = "<< sizeof(int) << endl;
    cout << "sizeof(long int) = "<< sizeof(long int) << endl;
    cout << "sizeof(float) = "<< sizeof(float) << endl;
    cout << "sizeof(double) = "<< sizeof(double) << endl;
    cout << "sizeof(long double) = "<< sizeof(long double) << endl;
    cout << "sizeof(char) = "<< sizeof(char) << endl;

    return 0;
}
