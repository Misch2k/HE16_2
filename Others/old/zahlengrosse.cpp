#include <iostream>
#include <cstdlib>
using namespace std;


int main(){
	
	int a,b,c,d,e,f,g,h,i,j;
	int counter = 0;
	
	cout << "Geben sie 10 Zahlen ein und ich sage Ihnen die Kleinste" << endl;
	cin >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j;
	
	
	while((a*b*c*d*e*f*g*h*i*j) != 0){
		counter = counter + 1;
		a--;
		b--;
		c--;
		d--;
		e--;
		f--;
		g--;
		h--;
		i--;
		j--;
	};
	cout << "Die kleinste Zahl die sie eingegeben haben ist: " << counter << endl;
return 0;	
}
