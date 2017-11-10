#include <iostream>
#include <vector>
#include <algorithm>
#include "../../myFunctions/functions.h"

using namespace std;

int calculate(string input);

int calculate(string input) {
    int multipl(26), result(0);
    vector<int> value(26);

    for (char &letter : input) {
        if (letter >= 'a' && letter <= 'z') {
            value[(int) (letter - 'a')]++;
        } else if (letter >= 'A' && letter <= 'Z') {
            value[(int) (letter - 'A')]++;
        }
    }

    sort(value.rbegin(), value.rend());
    for (int &counter : value) {
        result += counter * multipl--;
    }
    return result;
};

int main() {
    string testCase1("abcdefghijklmnopqrstuvwxyz "), testCase2("Sometimes test cases are hard to make up.");
    testCase1 = "";
    for (int i = 0; i < 10000000; i++) {
        testCase1 += (char) (rand() % 25 + 'a');
    }

    auto start = myTime::start();
    cout << "Stringlength: " << testCase1.size() << endl;
    cout << "The prettiness of this string: " << calculate(testCase1) << endl;
    myTime::stop(start, 3);

    cout << calculate(testCase2) << endl;

    return 0;
}