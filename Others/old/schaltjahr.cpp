#include <iostream>
#include <cmath>
using namespace std;

int main() {
	
int jahr;
	cout << "Geben sie eine Jahreszahl ein und ich werde Ihnen sagen ob es ein Schaltjahr ist." << endl;
	cout << "Bitte Jahreszahl eingeben: " << endl;

	cin >> jahr;
	
	if ((jahr%100 == 0) && (jahr%400==0))
	{
		cout << "Schaltjahr" << endl;
	}
	else if ((jahr%100) != 0 & (jahr%4 == 0))
	{
		cout << "Schaltjahr" << endl;
	}
	else
	{
		cout << "Kein Schaltjahr" << endl;
	}
	
return 0;
}