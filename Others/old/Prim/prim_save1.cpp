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
	unsigned int primcount = 400000;
	unsigned int maxnumber = 200000000;
	cout << 1 << endl;
	unsigned long int prim[primcount] ={};
	cout << 2 << endl;
	unsigned int count=2;
	unsigned int teiler=2;
	unsigned int i,x;
	unsigned long long int a;
	prim[0]=1;
	prim[1]=2;
	
	a = sizeof(prim);
	cout << a << endl;
	
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