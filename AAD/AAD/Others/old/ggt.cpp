#include <iostream>

using namespace std;

int main(){
	
int a,b;
int ggt=0;

cout << "GGT ausrechnen\n erste Zahl eingeben\n";
cin >> a;
cout << "Zweite Zahl eingeben\n";
cin >> b;

for (int i = a+b; i > 2; i--){
	if (a%i==0 && b%i==0){
		ggt = i;
		cout << ggt << " ist der Grösste gemeinsame Teiler\n";
		break;
	}
}
	if (ggt == 0){
		cout << "Bruch kann nicht gekürzt werden\n";
		return 0;
	}
	cout << a << "\n---\n" << b;
	
	a = a/ggt;
	b=b/ggt;
	
	cout << "\nBruch gekürtzt:\n" << a << "\n___\n" << b;
	
	
	
    return 0;

}