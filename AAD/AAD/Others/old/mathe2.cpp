#include <iostream>
#include <cmath>

using namespace std;


int main(){

	float lange;
	float breite;
	double diagonale;
	
	cout << "Geben sie die Länge des Rechtecks in `cm` ein: ";
	cin >> lange;
	cout << "Geben se die Breite des Rechtecks in `cm` ein: ";
	cin >> breite;

	diagonale = sqrt((lange*lange)+(breite*breite));
	
	cout << "Die Diagonale beträgt: " << diagonale << " cm";


return 0;
}