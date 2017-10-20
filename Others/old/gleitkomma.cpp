#include <iostream>

using namespace std;


int main(){
	float fval = 1000.12 / 1.2345;
	double dval = 1000.12 / 1.2345;
	
	cout.precision(30); // genauigkeit von Gleitkommazahl - 20 Stellen
	cout << fval << endl; // Ausgabe float
	cout << dval << endl; // Ausgabe double

return 0;
}