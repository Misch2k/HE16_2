#include <iostream>
#include <stdio.h>
#include <fstream>
#include <time.h>
#include <math.h>

using namespace std;



	
int main()
{
	time_t t;
	struct tm * ts;
	t = time(NULL);
	ts = localtime(&t);
	printf("%s", asctime(ts));
	cout << "Ich fange jetzt an ein Paar Primzahlen zu errechnen.\nBitte warten:...\n";

   
	unsigned int maxnumber = 7500000000;
	unsigned int prim;
	unsigned int count=1;
	unsigned int i,index;

	ofstream out("number", ios::out | ios::app | ios::binary);

		
	for (i=3;i<=maxnumber;i++){
		ifstream in("number", ios::in | ios::binary);
			if(!out) {
				cout << "Cannot open file.";
			return 1;
			}
		for (index = 0; input >> prim; index++){
			if (i%prim==0){
				break;
			}
			if (prim > i/2){
				prim=i;
				file  >> i >> "\n";
				break;
			}

		}	
	}
	file.close();
	
	t = time(NULL);
	ts = localtime(&t);
	printf("%s", asctime(ts));
	cout << count << " Primzahlen wurden gespeichert." << endl;
	cout << count << "\n" << i << "/n";
	
return 0;
}