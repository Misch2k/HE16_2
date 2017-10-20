#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
	
	long a = 0;
	long count = 0;
	int countmax = 0;
	int countmax1 = 0;
	int countb = 0;
	int countc = 0;

	cout << "RAND_MAX = " << RAND_MAX << endl;
	while(count != 100000){
		count++;
		a=rand();
		/*cout << a << endl;
		if (count%100 == 0){
			cout << count << "das ist der counter" << endl;
		}*/
		if (a == 32767){ 
		countmax++;
		}
		if (a == 32768){
		countmax1++;
		}
		if (a == 10000){ 
		countb++;
		}
		if (a == 1) { 
		countc++;}
	}
	
	cout << count << " * Counter" << endl;
	cout << countmax << " * RAND_MAX" << endl;
	cout << countmax1 << " * RAND_MAX + 1 " << endl;
	cout << countb << " * 10000" << endl;
	cout << countc << " * 1" << endl;
	
	
	
	
return 0;	
}