#include <iostream>
#include "class.h"

using namespace std;



int main()
	
	class Tier Hund1, Hund2, Henne;

	
	Hund1.Gewicht = 15;
	Hund2.Gewicht = 30;
	Henne.Gewicht = 2;
	
	Hund1.Beine = 4;
	Hund2.Beine = 4;
	Henne.Beine = 2;

	cout << "Das Gewicht von Hund1 ist " << Hund1.Gewicht << "\n";
	cout << "Das Gewicht von Hund2 ist " << Hund2.Gewicht << "\n";
	cout << "Das Gewicht von Hund3 ist " << Henne.Gewicht << "\n";
	
return 0;
}