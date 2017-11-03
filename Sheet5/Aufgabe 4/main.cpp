#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calculate(string input);

int calculate(string input) {
    int multipl = 26;
    int result = 0;
    vector<int> value(26);
    transform(input.begin(), input.end(), input.begin(), ::tolower);
    for (char letter : input) {
        if ((int) letter - 'a' >= 0 && (int) letter - 'a' < 26) {
            value[(int)(letter - 'a')]++;
        }
    }

    sort(value.rbegin(), value.rend());
    for (int &counter : value) {
        result += counter * multipl--;
    }
    return result;
};


int main() {
    string testCase1("ABBCCC "), testCase2("Sometimes test cases are hard to make up.");

    cout << calculate(testCase1) << endl;
    cout << calculate(testCase2) << endl;


    return 0;
}