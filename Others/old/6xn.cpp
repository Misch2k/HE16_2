#include <iostream>
#include <cmath>

using namespace std;


int main(){

int count = 0;
int zahl = 0;
int resultat = 0;
int einer = 0;
int zehner = 0;
int hunderter = 0;
int tausender = 0;
int zehntausender = 0;
int hunderttausender = 0;
int a = 3;
int b=30;
int c=200;
int d=2000;

for (int i=0; i<1000000; i++){
	zahl = i;
	einer = zahl%10;
//	cout << i << " = i ; ";
//	cout << einer << " = EINER ; ";
	zehner = ((zahl%100)-einer)/10;
//	cout << zehner << " = ZEHNER ; ";
	hunderter = ((zahl%1000)-einer-zehner)/100;
//	cout << hunderter << " = HUNDERTER ; "<< endl;
	tausender = ((zahl%10000-einer-zehner-hunderter)/1000);
	zehntausender = ((zahl%100000-einer-zehner-hunderter-tausender)/10000);
	hunderttausender = ((zahl%1000000-einer-zehner-hunderter-tausender-zehntausender)/100000);
	
	if (i <100){
		resultat = (einer*10) + zehner;
	}
	if (i >100 && i<1000){
		resultat = (einer*100) + (zehner*10) + hunderter;
	}
	if (i > 1000 && i <10000){
		resultat = einer*1000 + zehner*100 + hunderter*10 + tausender;
	}
	if (i > 10000 && i <100000){
		resultat = einer*10000 + zehner*1000 + hunderter*100 + tausender*10 + zehntausender;
	}
	if (i>100000 && i<1000000){
		resultat = einer*100000 + zehner*10000 + hunderter*1000 + tausender*100 + zehntausender*10 + hunderttausender;
	}
	
//	cout << resultat << endl;
	
	if (i*6 == resultat){
		count++;
		cout << i << endl;
		cout << count << endl;
}
return 0;
}