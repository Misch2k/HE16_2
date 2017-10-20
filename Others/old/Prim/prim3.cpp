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
	//ofstream array1("array", ios::out | ios::binary);
	ofstream array_bin("array", ios::out | ios::app | ios::binary);
	ifstream array1("array", ios::in | ios::binary);


	unsigned int primcount = 450000;
	unsigned long long int maxnumber = 7500000000;
	unsigned long int prim[primcount] ={};
	unsigned long long int count=2;
	unsigned long int teiler=2;
	unsigned long long int i,x,y;
	unsigned int prim_count=0;

	
	prim[0]=1;
	prim[1]=2;
	prim[2]=3;
	
	file << "Das sind alles Primzahlen:\n 2 ;\n 3;\n";
	for (i=5;i<=maxnumber;i++){
			for (x = 1; x < i; x++){
				if (x<430000){
					if (prim[x]==0){
						prim[x]=i;
						file <<prim_count << "        " << i << " ;\n";
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
				if (prim_count>=430000){
					 array_bin.write((char *) &prim, sizeof prim);
				break;
				}
				if (prim_count >= 430000){
				break;
				}
		
	
	}
	file.close();
	array1.close();
	array_bin.close();
	
	t = time(NULL);
	ts = localtime(&t);
	printf("%s", asctime(ts));
	cout << prim_count << " Primzahlen wurden gespeichert." << endl;
	cout << prim_count << "\n" << i << "/n";
	
return 0;
}