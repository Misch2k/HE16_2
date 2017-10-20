#include <iostream>

using namespace std;


int main(){
	unsigned short wert01 = 65535;
	unsigned short wert02 = 1;
	unsigned short summe;
	bool overflow = (summe=wert01+wert02)< wert01;
	if(overflow == true){
		cout << "Achtung! Bereich wurde überschritten\n";
	}

return 0;
}