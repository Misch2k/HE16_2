#include <iostream>

using namespace std;

int main()
{
    //Aufgabe: Schreiben sie ein Programm welches "gerade"/"ungerade" ausgiebt, bezogen auf die eingegebene Zahl
    //Wenn die Zahl ungerade ist, prüfe ob sie "<" oder ">" 0 ist.

    int zahl(0);

    cout << "Geben sie eine Zahl ein und ich sage ihen ob sie gerade / ungerade ist." << endl;
    cin >> zahl;

    if (zahl%2==0){
        cout << "Die Zahl ist gerade" << endl;
    }
    if (zahl%2!=0){
            cout << "Die Zahl ist ungerade" << endl;
        if (zahl<0){
            cout << "Die Zahl ist kleiner als 0" << endl;
        }
        if (zahl>0){
            cout << "Die Zahl ist grösser als 0" << endl;
        }
    }


    return 0;
}
