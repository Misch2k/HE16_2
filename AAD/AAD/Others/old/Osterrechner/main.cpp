#include <iostream>

using namespace std;

void osterrechner(int y);

int main()
{
    int y(0);


    cout << "Geben sie ein Jahr ein zwischen 1900 - 2099 und ich sage Ihnen an welchem Datum Ostern waren/sind." << endl;
    cin >> y;

    osterrechner(y);
}



void osterrechner(int y){
    int a(0),b(0),k(0),m(0),n(0),q(0),w(0);

    if(y<1900||y>2099){
        cout << "Geben sie ein Datum zwischen 1900 und 2099 ein!" << endl;
    }

    a=n%19;
    b=(7*a+1)/19;
    m=(11*a+4-b)%29;
    q=n/4;
    w=(n+q+31-m)%7;

    k=25-m-w;

    if(k<=0){
        cout << 31-k << ".März " << y << " war Ostern" << endl;
    }
    else if(k>0){
        cout << k << ".April " << y << " war Ostern" << endl;
    }
}
