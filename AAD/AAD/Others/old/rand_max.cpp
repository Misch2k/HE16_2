#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
	int rand_max=0;
	int rand1;
	cout << RAND_MAX << " ist RAND_MAX." << endl;
	for (int i=0; i<50000; i++){
		rand1 = rand();
		if(rand1 == RAND_MAX){
			rand_max++;
		}
	}
	cout << rand_max << endl;
	cout << "RAND_MAX wurde so viel mal erreicht" << endl;

return 0;
}