#include <iostream>
#include "funktionen.h"
#include <ctime>
#include <cstdlib>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;


//void counter();
//void xswap(int*);
void func_swap(double* , double*);
int laenge(double);


int main(){

    //Aufgabe 10
/*
    int a;
    int b;
    char c;
    char d;

    uberladen1(a,b);
    uberladen1(b,c);
    uberladen1(c,d);
    uberladen1(c,b);

*/


    //Aufgabe 11
    //Aufgabe 10.2
    //Eine Funktion welche den Wert zurück giebt, wie viel mal sie aufgerufen wurde

    /*
    int a(0);

    cout << "Wie viel mal wollen sie die Funktion counter aufrufen?" << endl;
    cin >> a;
    for(int i=0;i<a;i++){
        counter(a);
    }
*/


    //Aufgabe 11.1
    //4 Zahlen werden eingelesen und in einem Array gespeichert, sie werden anschliessend in umgekehrter reihenfolge ausgegeben.

    /*
    double wert[4]{0};

    for(int i=0;i<4;i++){
        cout << "Geben sie die " << i+1 << " Zahl ein." << endl;
        cin >> wert[i];
    }
    cout << "Die eingegebenen Werte un umgekehrter Reihenfolge" << endl;

    for(int i=4;i>0;i--){
        cout << wert[i-1] << endl;
    }
*/


/*

    //Aufgabe 11.2
    //

    int a[2]={0};
    a[0]=1;
    a[1]=2;

    xswap(a+0);
    cout << a[0];

*/

    //Aufgabe 12.3
    //Verschlüsselung eines Strings. Convertieren String -> Array.

/*
    int schlussel(0),schlussel2(0);                                   //Erstelle Leeren Schlüssel.
    char *dyn_ray = NULL;                               //Erstelle Pointer für Dynamischen Array.
    string wort="";                                     //Erstelle Leeren String für Wort.
    int wort_length(0);                                 //Variable für Wortlänge.

    cout << "Geben sie ein Wort ein: " << endl;
    cin >> wort;
    cout << "Geben sie eine Schluessel ein: " << endl;
    cin >> schlussel;

    wort_length= wort.length();
    dyn_ray = new char [wort_length];

    wort.copy(dyn_ray, wort_length);

    for(int i = 0; i<wort_length; i++){                 //Verschlüsseln
        dyn_ray[i] += schlussel;
    }


    for(int i = 0; i<wort_length; i++){                 //Verschlüsseltes Wort ausgeben.
        cout << dyn_ray[i];
    }
    cout << endl;

cout << "Geben sie den Schlüssel ein zum entschlüsseln: " << endl;
cin >> schlussel2;

    for(int i = 0; i<wort_length; i++){                 //Entschlsseln.
        dyn_ray[i] -= schlussel2;
    }
    cout << endl;

    for(int i = 0; i<wort_length; i++){                 //Entschlüsseltes Wort ausgeben.
        cout << dyn_ray[i];
    }
    cout << endl;
    delete dyn_ray;

*/


    //Aufgabe 13.1
    //Galtonbrett
/*
    int count=0;
    int reihen = 0;
    int kugeln = 0;
    string tab, tab2;
    srand((unsigned)time(NULL));

    cout << "Reihen?\n";
    cin >> reihen;
    cout << "Kuglen?\n";
    cin >> kugeln;
    cout << "\n\n";

    int fach[reihen] = {0};


    for (int a=0; a<kugeln; a++){
        count = 0;
        for (int i=1; i<reihen; i++){
            if (rand()%2 == 1){
                count++;
            }
        }
        fach[count]++;
    }
    count = 0;
    for (int i=0; i<reihen; i++){
        if (fach[count] > 9 && fach[count] < 100){
            tab = "  ";
        }
        else if (fach[count] > 99 && fach[count] < 1000){
            tab = " ";
        }
        else if (fach[count] > 1000){
            tab = "";
        }
        else {
            tab = "   ";
        }
        if (count+1>9){
            tab2 = "";
        }
        else {
            tab2 = " ";
        }
        cout << fach[count] << tab << "     Fach[" << count+1 << "] " << tab2 << "  -   //Im CODE Fach[" << count << "]\n";
        count++;
    }

*/

    //Test um {0} alle Elemente im Array auf NULL zu setzen.

/*
    int a[5]{0};
    int b[5]{0};
    int c[50]{0};
    for(int i=0;i<5;i++){
        cout << a[i] << endl;
    }
    for(int i=0;i<5;i++){
        cout << b[i] << endl;
    }
    for(int i=0;i<50;i++){
        cout << c[i] << endl;
    }
*/

    //Aufgabe 15.1
    //Swap mit Referenz. Erstellen sie eine SWAP Funktion welche mit Referenzen arbeitet.
/*
    double a(0),b(0);

    cout << "Geben sie den ersten Wert ein: ";
    cin >> a;
    cout << "Geben sie den zweiten Wert ein: ";
    cin >> b;

    func_swap(&a, &b);
*/

    //Aufgabe 15.2
    //Diese Stück Code analysiere und die Ausgabe aufschreiben und überprüfen.
/*
    int a(6) , b(2);
    int *pa, *pb;

    pa = &a;
    *pa +=1;
    cout<<"a = ? "<< a <<endl;

    pb = &b;
    *pb =*pb**pa;
    b= b++ + ++a;
    cout << "b = ? " << b <<endl;
*/

    //Aufgabe 15.4
    //Kleines EinMalEins mit einem Zweidimensionalen Array in einer Funktion.



    //Aufgabe 16






    //Aufgabe 17


/*
    char a = 'a';
    int ascii_a = a;

    cout << ascii_a << endl;
    cout << (char)ascii_a << endl;
*/


    /*
    #include <string>


        string wort = "Ich bin ein String :D";
        int a(0);

        a = wort.length();

        cout << a << endl;
    */

    //Aufgabe 19.2
    //Pri Berechnen
/*
    double a(0);
    double b(0);
    double result(0);
    double count(0);
    double innen(0);
    double aussen(0);

    //srand(time(NULL));

    count = 100000000;

    for(int i=0;i<count;i++){
        a = (1-((double)rand())/(RAND_MAX)*2);
        b = (1-((double)rand())/(RAND_MAX)*2);
//        cout << RAND_MAX << endl;
//        cout << rand() << endl;
//        cout << setprecision(20)<< ((((double)rand())/(RAND_MAX)*2)-1) << endl;
//        cout << a << " " << b << endl;
        result = (double)sqrt(a*a+b*b);
//        cout << result << endl;
        if(result <=1){
            innen++;}
        else{
            aussen++;}

    }
    if(innen+aussen == count)
        cout << "Ohne Fehler beendet" << endl;

    cout << setprecision(3) << 4*(innen/count) << " ist PI" << endl;

*/

/*

      long double s;
      double n;
      long double pi;
      long double backup;
      int length;

      //Startwerte
      s  = 1;
      n  = 1;
      pi = 3;

      do {
        //Ausgabe
        cout << 3*pow(2,n) << "eck: ";
        length = laenge(3*pow(2,n));
        for (int x=0;x<(9-length);x++)
          cout << " ";
        cout << setprecision(200) << pi << endl;
        //neuen Wert fuer Pi berechnen
        backup = pi;
        s = sqrt(s*s/4+(1-sqrt(1-s*s/4))*(1-sqrt(1-s*s/4)));
        pi = 3*pow(2,n)*s;
        n++;
      } while (1==1);
*/

/*

    double a(0);
    int count1(0),count0(0),countminus(0);
    srand(time(NULL));
    for(int i = 0; i<100; i++){
        a = (1-((double)rand())/(RAND_MAX)*2);

        if(a>0){
            count1++;
        };
        if(a==0){
            count0++;
        };
        if(a<0){
            countminus++;
        };

    }
    cout << count1 << endl;
    cout << count0 << endl;
    cout << countminus << endl;
*/
    return 0;
}



