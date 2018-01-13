#include <iostream>
#include <cstdlib>
using namespace std;


int main(){
	
	short a,b,c,d,e,f,g,h,i,j;
	int counter = 0;

	a=60;
	b=rand();
	c=rand();
	d=rand();
	e=rand();
	f=rand();
	g=rand();
	h=rand();
	i=rand();
	j=rand();
	
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << d << endl;
	cout << e << endl;
	cout << f << endl;
	cout << g << endl;
	cout << h << endl;
	cout << i << endl;
	cout << j << endl;
	
	while((a*b*c*d*e) != 0){
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
