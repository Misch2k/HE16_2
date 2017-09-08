/*
 *  Aufgabe 6
 *  Michel Kugler
 *
 *  Anagramm Check
 *
 *  In dieser Aufgabe soll eine Methode implementiert werden,
 *  welche als Parameter zwei Strings enthält.
 *  Die Methode gibt true zurück, falls diese beiden
 *  Strings Anagramme sind, sonst false.
 *
 *  class ArrayUtil {
 *  public:
 *  static bool anagramCheck(string s1, string s2);
 *  }
 *
 */

#include <iostream>
#include <string>
#include <ctime>
#include "../myFunctions/functions.h"

using namespace std;

class ArrayUtil {
public:
    static bool anagramCheck(string s1, string s2);
};

bool ArrayUtil::anagramCheck(string s1, string s2) {
    int ASCII[26]{0};

    // Make the strings to same length.
    if (s1.length() != s2.length()) {
        if (s1.length() < s2.length()) {
            for (int i = 0; s1.length() < s2.length(); ++i) {
                s1 += ".";
            }
        } else {
            for (int i = 0; s2.length() < s1.length(); ++i) {
                s2 += ".";
            }
        }
    }

    // Convert all chars to lowercase ignore everything witch is not a letter.
    // Increase value at char position from String 1
    // Decrease value at char position from String 2
    for (unsigned int i = 0; i < s1.length(); ++i) {
        if (s1.at(i) >= 'A' && s1.at(i) <= 'Z') {
            ASCII[(int) (s1.at(i) - 'A')]++;
        }
        if ((s1.at(i) >= 'a' && (s1.at(i) <= 'z'))) {
            ASCII[(int) (s1.at(i) - ('a' - 'A') - 'A')]++;
        }
        if (s2.at(i) >= 'A' && s2.at(i) <= 'Z') {
            ASCII[(int) (s2.at(i) - 'A')]--;
        }
        if ((s2.at(i) >= 'a' && (s2.at(i) <= 'z'))) {
            ASCII[(int) (s2.at(i) - ('a' - 'A') - 'A')]--;
        }
    }

    // If value is not '0' a char came more often then another
    for (int j = 0; j < 26; ++j) {
        if (ASCII[j] != 0) {
            cout << (char)(j + 'A') << endl;
            return false;
        }
    }

    return true;
};


int main() {
    string test =  "Annulo cingitur, tenui plano, nusquam cohaerente, ad eclipticam inclinato";
    string test2 = "AAAAAAA CCCCC D EEEEE G H IIIIIII LLLL MM NNNNNNNNN OOOO PP Q RR S TTTTT UUUUU";

    // With long strings
    // addLetterToString(&test, 5000000);
    // test2 = test;


    clock_t start;

    start = clock();

    cout << "It's " << (ArrayUtil::anagramCheck(test, test2) ? "" : "not ") << "an anagram" << endl;

    print_runtime(start);

    return 0;
}