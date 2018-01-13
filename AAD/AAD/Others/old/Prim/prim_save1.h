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
	ofstream file("prim.txt");
	unsigned int primcount = 10000000;
	unsigned int maxnumber = 7500000000;
	unsigned int prim[primcount] ={};
	unsigned int count=2;
	unsigned int teiler=2;
	unsigned int i,x;
	
	prim[0]=1;
	prim[1]=2;
	
	cout << sizeof(prim) << endl;
	
	file << "Das sind alles Primzahlen:\n1 : 2 ;\n";
	for (i=3;i<=maxnumber;i++){
		for (x = 1; x < i; x++){
			if (i%prim[x]==0){
				break;
			}
			if (x==count-1){
				prim[count]=i;
				file << count << " : " << i << " ;\n";
				count++;
				break;
			}

		}
	
	if (count == primcount){
	break;
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