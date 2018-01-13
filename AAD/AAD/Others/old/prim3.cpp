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
	ofstream file("prim3.txt");
	ofstream array("array" ios::out | ios::binary);
	ofstream array_bin("array" ios::out | ios::app | ios:binary)
	ifstream array("array" ios::in | ios::binary);


	unsigned int primcount = 500000;
	unsigned long long int maxnumber = 7500000000;
	unsigned long int prim[primcount] ={0};
	unsigned long int prim2[primcount] = {0};
	unsigned long int prim3[primcount] = {0};
	unsigned long long int count=2;
	unsigned long int teiler=2;
	unsigned long long int i,x,y;
	unsigned int prim_count=0;

	
	prim[0]=1;
	prim[1]=2;
	
	file << "Das sind alles Primzahlen:\n1 : 2 ;\n";
	for (i=5;i<=maxnumber;i++){
			for (x = 1; x < i; x++){
				if (x<500000){
					if (prim[x]==0){
						prim[x]=i;
						file << i << " ;\n";
						array_bin.write((char *) &fnum, sizeof fnum);
						prim_count++;
						break;
					}
					if (i%prim[x]==0){
						break;
					}

				}
				/*
				if (x==500000){

				}
				if (x>500000){
					y=x-500000;
					if (prim2[y]==0){
						file << i << " ;\n";
						prim_count++;
						break;
					}
					if (i%prim2[y]==0){
						break;
					}	
				}
				*/
			}

		
	
	}
	file.close();
	array.close();
	array_bin.close();
	
	t = time(NULL);
	ts = localtime(&t);
	printf("%s", asctime(ts));
	cout << count << " Primzahlen wurden gespeichert." << endl;
	cout << count << "\n" << i << "/n";
	
return 0;
}