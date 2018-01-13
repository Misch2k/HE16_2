#include <iostream>
using namespace std;


struct Fraction{
	int numerator;
	int denominator;
};

int main(){
	
	Fraction f1;
	f1.numerator;
	f1.denominator;
	
	Fraction f2;
	f2.numerator;
	f2.denominator;
	
	cout << "Geben sie den ersten Bruch ein: ";
	cin >> f1.numerator >> f1.denominator;
	cout << "Geben sie den zweiten Bruch ein: " << endl;
	cin >> f2.numerator >> f2.denominator;
	cout << "Multiplikation -> F1 * F2" << endl;
	cout << f1.numerator*f2.numerator << "/" << f1.denominator*f2.denominator << endl;
	cout << "Division - F1 / F2" << endl;
	cout << f1.numerator*f2.denominator << "/" << f1.denominator*f2.numerator << endl;
	
return 0;	
}
