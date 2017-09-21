/*
 * Aufgabe 2 - Palindrome
 *
 * In dieser Aufgabe soll eine methode implementiert werden, welche mit Hlfe
 * von Rekursion prüft ob eine Zeichenkette ein Palindrome ist.
 *
 * class StringUtil {
 * public:
 * static bool isPalindrome(string input);
 * };
 */


#include <iostream>
#include <ctime>
#include "../myFunctions/functions.h"

using namespace std;

class StringUtil {
private:
    static void checkIfPalindrome(string input, bool &result);

public:
    static bool isPalindrome(string input);
};

bool StringUtil::isPalindrome(string input) {
    bool result = true;
    // Erase all not Letter and convert the letter to lowercase
    for (unsigned int i = 0; i < input.length(); ++i) {
        if (!((input.at(i) >= 'A' && input.at(i) <= 'Z') || (input.at(i) >= 'a' && input.at(i) <= 'z'))) {
            input.erase(input.begin() + i);
            --i;
        } else if (input.at(i) >= 'a' && input.at(i) <= 'z') {
            input.at(i) -= ('a' - 'A');
        }
    }

    StringUtil::checkIfPalindrome(input, result);

    return result;
};

void StringUtil::checkIfPalindrome(string input, bool &result) {

    // cout << "Result = " << (result ? "true" : "false") << endl;
    // cout << "Input = " << input << endl;
    // cout << "Length = " << input.length() << endl;
    // cout << "First letter = " << *input.begin() << endl;
    // cout << "Last letter = " << *input.rbegin() << endl;

    if (result) {
        if (input.length() > 1) {
            if (*input.begin() == *input.rbegin()) {
                input.erase(0, 1);
                input.erase(input.length() - 1, 1);
                StringUtil::checkIfPalindrome(input, result);
            }else{
                result = false;
            }
        }
    }
}


int main() {
    time_t start;

    string testString = "Trug Tim eine so helle Hose nie mit Gurt?";

    /*string testString = "";

    for (int i = 0; i < 50000; ++i) {
        testString += 'a';
    }
    cout << testString.length();
*/

    start = clock();
    StringUtil::isPalindrome(testString) ? cout << "Palindrome" : cout << "no Palindrome" << endl;
    print_runtime(start);

    return 0;
}