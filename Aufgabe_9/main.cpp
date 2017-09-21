/*
 * Aufgabe 10 - Längster Substring
 *
 * Eine Methode welche den längsten Substing aus zwei Substrings zurückgiebt.
 */

#include <iostream>
#include <set>
#include <ctime>
#include <cstdlib>

using namespace std;

class StringUtil {
public:
    static string lcs(string input1, string input2);
};

string StringUtil::lcs(string input1, string input2) {
    set<string> checkString;
    set<string>::iterator it;
    string longString = "NO STRING FOUND";
    int temp = 0;
    string temp1 = "";
    int count = 0;


    for (unsigned int i = 0; i < input1.length(); i++) {
        for (unsigned int j = 0; j + i < input1.length(); j++) {
            checkString.insert(input1.substr(i, j));
            count++;
        }
    }

    for (it = checkString.begin(); it != checkString.end(); ++it) {
        temp1 = *it;
        size_t found = input2.find(temp1);
        if (found != string::npos) {
            if (temp < temp1.length()) {
                temp = temp1.length();
                longString = temp1;
            }
        }

    }


    cout << "Moegliche kombinationen: " << count << endl;
    return longString;
};

int main() {
    time_t start, stop;
    string test1 = "";
    string test2 = "";
    for(int i = 0; i < 1000; i++){
        test1 += rand() % 26 + 'A';
        test2 += rand() % 26 + 'A';
    }


    start = clock();
    cout << StringUtil::lcs(test1, test2) << endl;
    stop = clock();
    cout << "Runtime = " << (double)(stop-start)/CLOCKS_PER_SEC << endl;
    cout << "String laenge = " << 1000 << endl;
    for(int i = 0; i < 1000; i++){
        test1 += rand() % 26 + 'A';
        test2 += rand() % 26 + 'A';
    }

    start = clock();
    cout << StringUtil::lcs(test1, test2) << endl;
    stop = clock();
    cout << "Runtime = " << (double)(stop-start)/CLOCKS_PER_SEC << endl;
    cout << "String laenge = " << 2000 << endl;
    return 0;
}