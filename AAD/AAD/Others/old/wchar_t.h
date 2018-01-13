#include <iostream>
#include <limits>

using namespace std;

int main(){
	int a = 0;
	int counter = 0;
	
	for(int i = 0; i<62000; i++)
		wcout << counter << "   " << wchar_t(a) << endl;
	
return 0;
}