#include <iostream>
#include <limits>
using namespace std;


int main(){
	int wert01 = 32767;
	int wert02 = 1;
	
	bool sig01=(wert01&(1<<numeric_limits<short>::digits));
	
	short ergebnis = wert01+wert02;
	bool sig02=(ergebnis&(1<<numeric_limits<short>::digits));
	
	if(sig01 != sig02){
		cout << "Vorzeichen wurde gewechselt" << endl;
	}
	

return 0;
}