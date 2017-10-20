#include <iostream>
using namespace std;

struct rechteck {
	float hohe;
	float breite;
};

int main(){
	rechteck r1;
	
	cout << "Flaeche und Umfang von einem Rechteck berechnen." << endl;
	cout << "Geben sie die Breite ein:" << endl;
	cin >> r1.breite;
	cout << "Geben sie die Höhe ein: " << endl;
	cin >> r1.hohe;
	
	cout << "Die Fläche des Rechtecks beträgt: " << r1.breite*r1.hohe << endl;
	cout << "Der Umfang des Rehtecks beträgt: " << r1.breite*2+r1.hohe*2 << endl;
	
	
return 0;
}