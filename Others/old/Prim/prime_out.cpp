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

   
	unsigned long long int maxnumber = 7500000;
	unsigned long int prim;
	unsigned long long int count=1;
	unsigned long long int i,index;

		ifstream in("number", ios::in | ios::binary);
		ofstream out("prim_neu.txt", ios::out | ios::app);
		if(!in) {
			cout << "Cannot open file.";
		return 1;
		}
		for (index = 0; in >> prim; index++){
			out << "&prim \n";
		}
	in.close();
	
	
	t = time(NULL);
	ts = localtime(&t);
	printf("%s", asctime(ts));
	cout << count << " Primzahlen wurden gespeichert." << endl;
	cout << count << "\n" << i << "/n";
	
return 0;
}