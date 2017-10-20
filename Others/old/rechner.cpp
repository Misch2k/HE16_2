#include <iostream>
using namespace std;

main(){
	
float a, b, result;
char op;

cout << "Geben sie eine Rechnung ein." << endl;
cin >> a >> op >> b;

	if(op == '+'){
		result = a+b;
	}
	else if(op == '-'){
		result = a-b;
	}
	else if(op == '*'){
		result = a*b;
	}
	else if(op == '/'){
		result = a/b;
	}
cout << result << endl;

return 0;
}