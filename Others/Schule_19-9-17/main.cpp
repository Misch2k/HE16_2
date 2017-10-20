#include <iostream>
#include <cstdlib>
#include <set>


using namespace std;

string createString(int n) {
    string result = "";
    for (int i = 0; i < n; ++i) {
        result += (char) (rand() % 26) + 'A';
    }
    return result;
};

int main() {

    string test = createString(10);

    cout << test << endl;

    set<char> cc;

    for (char ch : test) {
        cc.insert(ch);
    }

    cout << cc.size();
    return 0;
}