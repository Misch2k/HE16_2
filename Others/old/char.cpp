#include <iostream>
#include <limits>

using namespace std;

int main(){
	
	for(int i = 0; i<=256; i++){
		cout << i << "   ";
		wcout << wchar_t(i) << endl;
	}
return 0;
}