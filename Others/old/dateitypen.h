#include <iostream>
#include <limits>

using namespace std;

int main(){
	
	cout << "Maximale grössen von Dateitypen:" << endl;
	cout << "char max()\n" << numeric_limits<char>::max() << endl;
	cout << "wchar_t max()\n" << numeric_limits<wchar_t>::max() << endl;
	cout << "short max()\n" << numeric_limits<short>::max() << endl;
	cout << "unsigned short max()\n" << numeric_limits<unsigned short>::max() << endl;
	cout << "int max()\n" << numeric_limits<int>::max() << endl;
	cout << "unsigned int max()\n" << numeric_limits<unsigned int>::max() << endl;
	cout << "long max()\n" << numeric_limits<long>::max() << endl;
	cout << "long long max()\n" << numeric_limits<long long>::max() << endl;
return 0;
}