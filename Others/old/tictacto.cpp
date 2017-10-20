#include <iostream>
using namespace std;

struct spieler {
	string name;
	string symbol;
};

int main(){
	spieler s1;
	s1.name = "";
	spieler s2;
	s2.name="";
	char e = 88;
	char z = 79;
	int spielerstart;
	int start = 0;
	char feld[9] = {000};
	int input;
	int win = 0;
	int counter = 0;

	cout << "Guten Tag" << endl << "Heute Spielen wir eine Runde Tic Tac Toe" << endl << "Kleines Tutorial:" << endl;
	cout << "Um ein Feld auszuw\x84 \bhlen geben sie die entsprechende Zahl ein." << endl << "Feld ist wie folgt aufgebaut:" << endl;

	cout << "-----------------" << endl;
	cout << "-- 1 -- 2 -- 3 --" << endl;
	cout << "-----------------" << endl;
	cout << "-- 4 -- 5 -- 6 --" << endl;
	cout << "-----------------" << endl;
	cout << "-- 7 -- 8 -- 9 --" << endl;
	cout << "-----------------" << endl;

	cout << "Wenn sie an der Reihe sind, w\x84 \bhlen sie das Gew\x81 \bnschte Feld durch eingabe der Feldnummer." << endl;
	cout << "Spieler 1. Bitte Namen w\x84 \bhlen: ";
	cin >> s1.name;
	cout << "Spieler 2. Bitte Namen w\x84 \bhlen: ";
	cin >> s2.name;
	cout << endl;

	cout << s1.name << ", sie sind ''" << e << "''" << endl;
	cout << s2.name << ", sie sind ''" << z << "''" << endl;

	cout << "Welcher Spieler soll beginnen? 1 oder 2?" << endl;
	cin >> spielerstart;

		if (spielerstart != 1 && spielerstart != 2){
			cout << "Ist kein Spieler!!" << endl;
		}
		else if (spielerstart == 1) {
			e = 88;
			z = 79;
			cout << s1.name << " beginnt." << endl;
			cout << "M\x94 \bge der besser gewinnen! Viel Gl\x81 \bck" << endl;
		}
		else {
			e=79;
			z=88;
			cout << s2.name << " beginnt." << endl;
			cout << "M\x94 \bge der besser gewinnen! Viel Gl\x81 \bck" << endl;
		}
		
	while (counter < 9 |& win == 0){
		counter++;
		cout << "In welche Feld m\x94 \bchten sie setzen?" << endl;
				cout << "-----------------" << endl;
			cout << "-- " << feld[0] << " -- " << feld[1] << " -- " << feld[2] << " --" << endl;
			cout << "-----------------" << endl;
			cout << "-- " << feld[3] << " -- " << feld[4] << " -- " << feld[5] << " --" << endl;
			cout << "-----------------" << endl;
			cout << "-- " << feld[6] << " -- " << feld[7] << " -- " << feld[8] << " --" << endl;
			cout << "-----------------" << endl;
		cin >> input;
		input = input -1;
		feld[input] = e;
		swap(e,z);
		
			cout << "-----------------" << endl;
			cout << "-- " << feld[0] << " -- " << feld[1] << " -- " << feld[2] << " --" << endl;
			cout << "-----------------" << endl;
			cout << "-- " << feld[3] << " -- " << feld[4] << " -- " << feld[5] << " --" << endl;
			cout << "-----------------" << endl;
			cout << "-- " << feld[6] << " -- " << feld[7] << " -- " << feld[8] << " --" << endl;
			cout << "-----------------" << endl;
		
				if (feld[0]==feld[1] && feld[1]==feld[2] && feld[0] != 000){
					win = 1;
					if (e==79){
						cout << s1.name << " hat gewonnen. Herzlichen Gl\x81 \bckwunsch!" << endl;
						break;
					}
					else {
						cout << s2.name << " hat gewonnen. Herzlichen Gl\x81 \bckwunsch!" << endl;
						break;
					}
				}
				else if (feld[3]==feld[4] && feld[4]==feld[5] && feld[3] != 000){
					win = 1;
					if (e==79){
						cout << s1.name << " hat gewonnen. Herzlichen Gl\x81 \bckwunsch!" << endl;
						break;
					}
					else {
						cout << s2.name << " hat gewonnen. Herzlichen Gl\x81 \bckwunsch!" << endl;
						break;
					}
				}
				else if (feld[6]==feld[7] && feld[7]==feld[8] && feld[6] != 000){
					win = 1;
					if (e==79){
						cout << s1.name << " hat gewonnen. Herzlichen Gl\x81 \bckwunsch!" << endl;
						break;
					}
					else {
						cout << s2.name << " hat gewonnen. Herzlichen Gl\x81 \bckwunsch!" << endl;
						break;
					}
				}
				else if (feld[0]==feld[4] && feld[4]==feld[8] && feld[0] != 000){
					win = 1;
					if (e==79){
						cout << s1.name << " hat gewonnen. Herzlichen Gl\x81 \bckwunsch!" << endl;
						break;
					}
					else {
						cout << s2.name << " hat gewonnen. Herzlichen Gl\x81 \bckwunsch!" << endl;
						break;
					}
				}
				else if (feld[2]==feld[4] && feld[4]==feld[6] && feld[2] != 000){
					win = 1;
					if (e==79){
						cout << s1.name << " hat gewonnen. Herzlichen Gl\x81 \bckwunsch!" << endl;
						break;
					}
					else {
						cout << s2.name << " hat gewonnen. Herzlichen Gl\x81 \bckwunsch!" << endl;
						break;
					}
				}
				else if (feld[0]==feld[3] && feld[3]==feld[6] && feld[0] != 000){
					win = 1;
					if (e==79){
						cout << s1.name << " hat gewonnen. Herzlichen Gl\x81 \bckwunsch!" << endl;
						break;
					}
					else {
						cout << s2.name << " hat gewonnen. Herzlichen Gl\x81 \bckwunsch!" << endl;
						break;
					}
				}
				else if (feld[1]==feld[4] && feld[4]==feld[7] && feld[1] != 000){
					win = 1;
					if (e==79){
						cout << s1.name << " hat gewonnen. Herzlichen Gl\x81 \bckwunsch!" << endl;
						break;
					}
					else {
						cout << s2.name << " hat gewonnen. Herzlichen Gl\x81 \bckwunsch!" << endl;
						break;
					}
				}
				else if (feld[2]==feld[5] && feld[5]==feld[8] && feld[2] != 000){
					win = 1;
					if (e==79){
						cout << s1.name << " hat gewonnen. Herzlichen Gl\x81 \bckwunsch!" << endl;
						break;
					}
					else {
						cout << s2.name << " hat gewonnen. Herzlichen Gl\x81 \bckwunsch!" << endl;
						break;
					}
				}
		}
		
return 0;
}