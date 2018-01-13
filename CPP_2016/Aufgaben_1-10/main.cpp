#include <iostream>
#include <cmath>
#include <funktionen.h>

using namespace std;

int main()
{


//Aufgaben 1.3
    //Ausgaben: Hello World
/*
    cout << "Hello World!" << endl;
    return 0;
*/

//Aufgaben 1.4
    //Fortlaufen ausdokumentieren von Programmen. Besser für die Übersicht.
    //Erledigt!!



//Aufgaben 2.1
    //Zwei Zahlen addieren und Resultat ausgeben.
/*
    int a(1),b(2);

    cout << a << "+" << b << "=" a+b << endl;
*/

//Aufgaben 2.2
    //Variable Type "double" einlesen und in Variable speichern + ausgeben.
/*
    int a(0);

    cout << "Geben sie eine Zahl ein:";
    cin >> a;
    cout << a << endl;
*/

//Aufgaben 2.3
    //Programm welches das Volumen eines Zylinders berechnet und ausgiebt.
/*
    const float pi(3.1847);
    int radius(0),hohe(0);

    cout << "Ich werden das Volumen eines Zylinders berechnen.\nBitte geben sie den Radius ein:";
    cin >> radius;
    cout << "Geben sie die Höhe ein:";
    cin >> hohe;

    cout << (radius*radius)*pi*hohe << endl;
*/



//Aufgaben 3.1
    //Ein Programm welches zu Variable "x" 1 Addiert. Drei verschiedene Operationen nutzen.
/*
    int x(0);

    cout << "x = " << x << endl;
    x++;
    cout << "x++ = " << x << endl;
    ++x;
    cout << "++x = " << x << endl;
    x+=1;
    cout << "x += 1 = " << x << endl;
*/

//Aufgaben 3.2
    //Was ergiebt: a=12, a+=++a+a++, a=a+a
/*
    int a(12);

    a+=++a+a++;
    a=a+a;
    cout << a << endl;
*/

//Aufgaben 3.3
    //Ein Programm welches das Speichervolume div. Datentypen ausgiebt.
/*
    cout << "Sizeof: char = " << sizeof(char) << endl;
    cout << "Sizeof: double = " << sizeof(double) << endl;
    cout << "Sizeof: long double = " << sizeof(long double) << endl;
    cout << "Sizeof: int = " << sizeof(int) << endl;
    cout << "Sizeof: long int = " << sizeof(long int) << endl;
    cout << "Sizeof: float = " << sizeof(float) << endl;
*/



//Aufgaben 4.1
    //Ein Programm welches die Falldauer bei Erdanziehung berechnet.
/*
    const float g(9.807);
    int hohe(0);

    cout << "Aus welcher Höhe fallen sie?";
    cin >> hohe;

    cout << sqrt(2*hohe/g) << endl;
*/

//Aufgaben 4.2
    //Das Programm sagt ob eine gerade oder ungerade&(grösser|kleiner 0 ist. Geschrieben mit "if" Anweisung.
/*
    int a(0);

    cout << "Geben sie eine Zahl ein und ich sage ihnen ob sie gerade oder ungerade ist." << endl;
    cin >> a;

    if (a%2==0){
        cout << "Die Zahl ist gerade" << endl;
    }
    else if(a%2==1){
        cout << "Die Zahl ist ungerade" << endl;
        if(a<0){
            cout << "Die Zahl ist kleiner als 0" << endl;
        }
    }
*/
//Aufgabe 4.2
    //Das gleiche Programm mit *Case*
/*
    signed int a(0);

    cout << "Geben sie eine Zahl ein und ich sage ihnen ob sie gerade oder ungerade ist:";
    cin >> a;
    a=a%2;

    switch(a){

        case 0:
            cout << "Die Zahl ist gerade." << endl;
        break;
        case 1:
            cout << "Die Zahl ist ungerade." << endl;
        break;
        case (-1):
            cout << "Die Zahl ist ungerade." << endl;
            cout << "Die Zahl ist kleiner als 0." << endl;
        break;
    }
*/

//Aufgabe 5.1
    //Schreiben sie ein Struktprogramm nach Harri-Schneidermann Methode.

//Aufgabe 5.2
    //Ein Programm das Basis und Exponent einliest und das Resultat ausgiebt.
/*
    int basis(0), exponent(0), result(1);   //Ablauf: Initialisationsschritt, Kondition,

    cout << "Geben sie die Basis ein:";
    cin >> basis;
    cout << "Genben sie den Exponent ein:";
    cin >> exponent;

    for (int i=0; i<exponent; i++){
        result*=basis;
        }
    cout << result << endl;

*/


//Aufgabe 6.1
    //Ein Programm welches die Anziehungskraft zweier Objekte berechnet.
/*
    const float gravit(6.673*pow(10, -11));
    int m1(0),m2(0),r(0);

    cout << "Geben sie die erste Masse ein:";
    cin >> m1;
    cout << "Geben sie die zweize Masse ein:";
    cin >> m2;
    cout << "Geben sie den Abstand ein:";
    cin >> r;

    cout << "Die Anziehungskraft beträgt: " << gravit*m1*m2/pow(r, 2) << endl;
*/

//Aufgabe 6.2
    //Ein Programm welches Startwert, Endwert und Schrittwert einliest und alle Zahlen ausgiebt.
/*
    int startwert(0),endwert(0),schrittwert(0);

    cout << "Geben sie den Startwert ein: ";
    cin >> startwert;
    cout << "Geben sie den Endwert ein: ";
    cin >> endwert;
    cout << "Geben sie den Schrittwert ein: ";
    cin >> schrittwert;

    while(startwert<=endwert){
        cout << startwert << endl;
        startwert+=schrittwert;
    }
*/
/*
    int a(2),b(5);              //Wenn a nicht initialisiert wird muss das Feld leer gelassen werden und mit einem Simicolon ; beendet sein.
    for( ; a<=b; a++){
        cout << a << endl;
    }
*/

//Aufgabe 6.2 mit for Schleife
    //Selbe Programm einfach mit FOR Schleife
/*
    int startwert(0),endwert(0),schrittwert(0);

    cout << "Geben sie den Startwert ein: ";
    cin >> startwert;
    cout << "Geben sie den Endwert ein: ";
    cin >> endwert;
    cout << "Geben sie den Schrittwert ein: ";
    cin >> schrittwert;

    for(int i(startwert);i<=endwert; i+=schrittwert){
        cout << i << endl;
    }
*/



//Aufgabe 7.1
    //Ein Programm welches die vorgegebene Zeichenkette ausgiebt.
/*
    char symbol('+');

    for(int i(0); i<4; i++){
        for(int j(0);j<=i;j++){
            cout << symbol;
        }
        cout << endl;
    }
*/
    //Aufgabe 7.1 einfach umgekehrt
/*
    char symbol('+');

    for(int i=5; i>0; i--){
        for(int j=i; j>0; j--){
        cout << symbol;
        }
        cout << endl;
    }
*/

//Aufgabe 7.2
    //Taschenrechner programmieren mit zwei Zahlen und allen Operanden
/*
    float wert1(0),wert2(0),result(0);
    char operand('0'), replay('y');

    while (replay=='y'){
        cout << "Wert 1  = ";
        cin >> wert1;
        cout << "Operand = ";
        cin >> operand;
        cout << "Wert 2  = ";
        cin >> wert2;

        switch(operand){
            case '+':
                result=wert1+wert2;
            break;
            case '-':
                result=wert1-wert2;
            break;
            case '*':
                result=wert1*wert2;
            break;
            case '/':
                result=wert1/wert2;
            break;
            case '%':
                result=(int)wert1%(int)wert2;
            break;
            default:
                cout << "Operand wurde nicht erkannt!" << endl;
            break;
        }
            cout << result << endl;
        cout << "Wollen sie noch eine Rechnung machen? (y/n)" << endl;
        cin >> replay;
        wert1=0;
        wert2=0;
        result=0;
    }
*/



//Aufgabe 8.1
    //Ein Programm das das kleine Einmaleins ausgiebt. 10 Spalten
/*
    int ausgabe(0);

    for(int i(1); i<=10; i++){
        for(int j(1); j<=10; j++){
            ausgabe = i*j;
            if(ausgabe/10>=10){}
            else if(ausgabe/10>=1 && ausgabe/10<10){
                cout << " ";
            }
            else if(ausgabe/10<1){
                cout << "  ";
            }
            cout << ausgabe << " ";
       }
       cout << endl;
    }
*/

//Aufgabe 8.2
    //Ein Programm welches die kleinste Zahl ausgiebt bei 3 Zahlen.
/*
    aufgabe82();

*/


//Aufgabe 9.1
    //Ein Programm welches 1 0 -1 ausgeibt falls ein Vorzeichen gesetzt ist.
/*
//    cout << negativ() << endl;
    int x(0);
    cout << "Geben sie eine Zahl ein:";
    cin >> x;

    cout << getText(x);

    int zahl(0);
    cout << "Geben sie eine Zahl ein: ";
    cin >> zahl;
*/
//    cout << "Vorzeichen = " << negativ(zahl) << endl; //negativ(zahl) ist die Funktion um das Vorzeichen zu ermitteln.


//Aufgabe 9.2
    //Ein Programm welches alle Zahlen bis x miteinander Addiert.
/*
    int result(0),x(0);

    cout << "Geben sie eine Zahl ein:";
    cin >>x;

    if(x>0){
        for(int i(0); i<=x; i++){
            result+=i;
        }
        cout << "Alle Zahlen Addiert bis " << x << " ergiebt zusammen: "<< result << endl;
    }
    else {
        cout << "Bitte geben sie eine Positive Zahl >0 ein." << endl;
    }
*/

//Aufgaben sind abgeschlossen. Geht in der nächsten Session weiter.


return 0;
}
