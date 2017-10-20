#include <iostream>
#include <complex>

using namespace std;


int main(){

	complex<double> komplexeZahl (-4, 9);
	cout << norm(komplexeZahl) << endl; // Giebt das Quadrat des Betrages zurück.
	cout << abs(komplexeZahl) << endl; // Giebt den Betrag der Wurzel aus norm() zurück.
	cout << conj(komplexeZahl) << endl;  // Giebt den konjugierten Wert zurück.
	cout << arg(komplexeZahl) << endl;  // Giebt den Winkel in Polarkoordinaten zurück.
	cout << polar(komplexeZahl) << endl; // Giebt die komplexe Zahl zu Polarkoordinaten zurück.

return 0;
}