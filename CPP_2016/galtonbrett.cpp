#include <iostream>
#include <cstdlib>
using namespace std;

int main(){

	int count(0), reihen(0), kugeln(0);
	string tab, tab2;

	cout << "Reihen?\n";
	cin >> reihen;
	cout << "Kuglen?\n";
	cin >> kugeln;
	cout << "\n\n";
	reihen++;
	
	int fach[reihen] = {0};

	
	for (int a=0; a<kugeln; a++){
		count = 0;
		for (int i=1; i<reihen; i++){
			if (rand()%2 == 1){
				count++;
			}
		}
		fach[count]++;
	}
	count = 0;
	for (int i=0; i<reihen; i++){
		if (fach[count] > 9 && fach[count] < 100){
			tab = "  ";
		}
		else if (fach[count] > 99 && fach[count] < 1000){
			tab = " ";
		}
		else if (fach[count] > 1000){
			tab = "";
		}
		else {
			tab = "   ";
		}
		if (count+1>9){
			tab2 = "";
		}
		else {
			tab2 = " ";
		}
		cout << fach[count] << tab << "     Fach[" << count+1 << "] " << tab2 << "  -   //Im CODE Fach[" << count << "]\n";
		count++;
	}
	return 0;
}
	
	
