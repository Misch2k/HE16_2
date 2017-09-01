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

using namespace std;


class StringUtil {
public:
    static bool checkUniqueness(string);

};

bool StringUtil::checkUniqueness(string s) {

    //Full ASCII table to count chars
    int ray[256]{0};

    for (unsigned int i = 0; i < s.length(); ++i) {
        // Increment the (int) value of this char
        // + 128 to fix the negative value of casted char
        // Check if letter comes the second time
        // return false when it happens
        if(++ray[((int)s.at(i))+128] > 1) return false;
    }

    // when nothing is double return true
    return true;
};


int main() {

    // Create a String with each ASCII letter inside.
    string text = "";
    for (unsigned int i = 0; i < 255; i++) {
        text += (char)(i+1);
    }

    // Type in a Letter to get it doubled
    text += "1";

    // For time capture
    clock_t start, stop;

    for (int i = 0; i < 200; i++) {

        // Time capture
        start = clock();

        StringUtil::checkUniqueness(text) ? cout << "Unique" << endl : cout << "Not unique" << endl;

        stop = clock();

        // Calculate the runtime of this function
        double time = (double) (stop - start) / CLOCKS_PER_SEC;
        cout << "Runtime Analyse (Durchgang: " << i+1 << ") => " << time << endl;

    }

    return 0;
}

