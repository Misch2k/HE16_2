#include <iostream>
//#include <string>

using namespace std;


string negativ(){

    string text("");
    int zahl(0);

    cout << "Geben sie eine Zahl ein: ";
    cin >> zahl;

    if(zahl>0){
        cout << "1, Diese Zahl ist Positiv." << endl;
    }
    if(zahl<0){
        text = "-1, Diese Zahl ist negativ.";
    }
    if(zahl==0){
        text = "0, Diese Zahl ist 0.";
}

return negativ();
}

string getText(int vorzeichen){

    string text;


    if(vorzeichen == 1){
        text = "Bei dieser Zahl handelt es sich um eine Positive Zahl.";
    }
    if(vorzeichen == 0){
        text = "Sie haben die Null eingegeben";
    }
    if(vorzeichen == -1){
        text = "Bei dieser Zahl handelt es sich um eine Negative Zahl.";
    }
return text;
}

void aufgabe82(){
    int wert1(0),wert2(0),wert3(0);

    cout << "Geben sie den ersten Wert ein: ";
    cin >> wert1;
    cout << "Geben sie den zweiten Wert ein: ";
    cin >> wert2;
    cout << "Geben sie den dritten Wert ein: ";
    cin >> wert3;

    if(wert1<wert2 && wert1<wert3){
        cout << "Der kleinste Wert ist: " << wert1 << endl;
    }
    if(wert2<wert1 && wert2<wert3){
        cout << "Der kleinste Wert ist: " << wert2 << endl;
    }
    if(wert3<wert1 && wert3<wert2){
        cout << "Der kleinste Wert ist: " << wert3 << endl;
    }
}
