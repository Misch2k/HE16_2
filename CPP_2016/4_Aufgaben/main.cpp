#include <iostream>
#include <cmath>

using namespace std;

int main(){

    //Aufgabe: Schreibe ein Programm das die Dauer des Freienfalls berechnet.
    //Gegeben sind: const double g = 9.807. Formel: sqrt((2*h0)/g)

    const double g(9.807);
    int h0(0);
    double t(0);
    cout << "Sie Fallen von einem Dach und möchten wissen wann sie Aufschlagen.\n Um diese Aufgabe zu berechnen möchte ich von ihnen Wissen wie hoch das Gebäude ist.\n Geben sie die Höhe vom Gebäude in Meter ein:" << endl;
    cin >> h0;
    cout << "Das ist aber ein hohes Gebäude. Ganze: " << h0 << "m" <<endl;

    //Rechnung

    t=sqrt((2*h0)/g);

    cout << t << "s dauert der Flug." << endl;

    return 0;
}
