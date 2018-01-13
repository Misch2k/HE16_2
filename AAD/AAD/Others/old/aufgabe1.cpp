#include <iostream>
#include <cstdlib>

using namespace std;

int main(){


	const int SIZE = 100;
	int values[SIZE];	
	int count=0;
	int a=0;
	
	for (int i=0; i<SIZE; i++){
		values[i]=rand()%1000;
		if (values[i] > a){
		count++;
		a = values[i];
		}
	}
	cout << count << endl;
	return 0;
}