/*
 * MK - 25.08.2017
 *
 * Aufgabe 3
 *
 * Implement a function who check a string to unique chars
 *
 *  static bool checkUniqueness(string s);
 */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "../myFunctions/functions.h"

using namespace std;

class StringUtil {
public:
    unsigned int position = 0;
    unsigned int counter = 0;
    bool moreThenOnce = false;

    StringUtil(unsigned int);

    void update();

    static bool checkUniqueness2(string);
};

StringUtil::StringUtil(unsigned int max) {
    this->position = max;
    this->counter = 0;
}


void StringUtil::update() {
    this->counter++;
    if (this->counter > 1) {
        moreThenOnce = true;
    }
};



bool StringUtil::checkUniqueness2(string s) {
    StringUtil alphabet[26](s.length()+1);

    for (unsigned int i = 0; i < s.length(); i++) {
        if (alphabet[s.at(i) - 'A'].moreThenOnce) continue;
        int index = s.at(i) - 'A';
        alphabet[index].update();
        if (i < alphabet[index].position) {
            alphabet[index].position = i;
        }
    }

    int temp = -1;
    unsigned int temp2 = s.length() + 1;

    for (int i = 0; i < 26; i++) {
        if (alphabet[i].counter == 1 && alphabet[i].position < temp2) {
            temp = i;
            temp2 = alphabet[i].position;
        }

    }
    cout << "Buchstabe : " << (char) (temp + 'A') << endl;
    return temp != -1;


}


string createString(unsigned int size) {
    string text = "";
    for (unsigned int i = 0; i < size; i++) {
        text += ('A' + rand() % 25);
    }
    text += "ZPPDLJFSDLFJK";

    return text;
}

int main() {

    string test = createString(500000000);
    clock_t start, stop;

    for (int i = 0; i < 5; i++) {

        start = clock();

        StringUtil::checkUniqueness2(test) ? cout << "Unique" << endl : cout << "Not unique" << endl;

        stop = clock();

        double time = (double) (stop - start) / CLOCKS_PER_SEC;
        cout << "Runtime Analyse 2 = " << time << endl;

    }

    return 0;
}
