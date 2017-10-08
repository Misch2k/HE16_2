/**
 * Sheet 3 - Aufgabe 1
 *
 * Lonly Element
 *
 * Implemetieren Sie eine Methode GetLonlyElement welche als Parameter einen string bekommt.
 * Jeder Charakter in diesem string kommt zweimal vor, ausser eines.
 * Die Methode soll das Element zurückliefern, welches nur einmal vorkommt.
 *
 *
 * class StringUtil {
 * public:
 *   static char getLonelyElement(string input);
 * };
 */

#include <iostream>

using namespace std;

class StringUtil {
public:
    static char getLonelyElement(string input);
};

char StringUtil::getLonelyElement(string input) {
    int counter[255]{0};

    for (char letter : input) {
        counter[(int)letter]++;
    }

    for (int i = 0; i < 255; i++) {
        if(counter[i] == 1){
            return (char)i;
        }
    }
    return '$';
}



int main() {
    string testString = "hallowelthallowel";

    cout << StringUtil::getLonelyElement(testString);
}