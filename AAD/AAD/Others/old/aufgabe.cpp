#include <iostream>
#include <cstdlib>

using namespace std;

int main(){


	const int SIZE = 100;
	int values[SIZE];	
	int count=0;
	int a=0;
	
	for (int i=0; i<SIZE; i++){
		values[i]=rand()%1000;
		if (values[i] > a){
		count++;
		}
		a=values[i];
	}
	cout << count << endl;
	}		if (fach[count] > 9 && fach[count] < 100){
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
	
	
