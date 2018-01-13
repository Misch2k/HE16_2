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

   
	unsigned long long int maxnumber = 7500000000;
	unsigned long int prim;
	unsigned long long int count=1;
	unsigned long long int i,index;

	ofstream out("number", ios::out | ios::app | ios::binary);
		if(!out) {
			cout << "Cannot open file.";
			return 1;
		}
	out << 2 << endl;
	out << 3 << endl;	


	for (i=3;i<=maxnumber;i++){
	ifstream in("number", ios::in | ios::binary);
		if(!in) {
			cout << "Cannot open file.";
		return 1;
		}
			if(!out) {
				cout << "Cannot open file.";
			return 1;
			}
		for (index = 0; in >> prim; index++){
			if (i%prim==0){
				break;
			}
			if (prim > i/2){
				prim=i;
				out  << i << endl;
				break;
			}

		}
	in.close();
	}
	
	out.close();
	
	t = time(NULL);
	ts = localtime(&t);
	printf("%s", asctime(ts));
	cout << count << " Primzahlen wurden gespeichert." << endl;
	cout << count << "\n" << i << "/n";
	
return 0;
}