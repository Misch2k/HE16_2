#include <iostream>
#include <cmath>
using namespace std;


int main() {
 
 
 
int ein,preis;
float rabatt;

	cout << "Guten Tag" << endl;

	cout << "Wir können Ihnen ab rabatte geben, die sich der Bestellmenge anpassen." << endl;

	cout << "Wie viele KG Bananen möchten sie bestellen?" << endl;

	cin >> ein;
	cout << "Was Kostet 1 KG Bananen?" << endl;
	cin >> preis;

	if (ein >= 10 && ein <= 100){
		rabatt = 0.9;
	}
	
	if (ein >= 100 && ein <= 1000){
		rabatt = 0.8;
	}	
	if (ein >= 1000){
		rabatt = 0.7;
	}
	
	cout << "Sie bekommen " << ein << " KG Bananen für " << ein*preis*rabatt << " cfr. Rabatt beträgt: " << 100-100*rabatt <<" %." << endl;


return 0;
}