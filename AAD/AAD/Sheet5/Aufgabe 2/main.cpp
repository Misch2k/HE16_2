#include <iostream>
#include <vector>
#include "../../myFunctions/functions.h"

using namespace std;

class TreeUtil {
public:
    static bool isBinarySearchTree(vector<int> values);

    static bool upperValues(vector<int> &values, int i, int value);
};

bool TreeUtil::upperValues(vector<int> &values, int i, int value) {
    if (i <= 0) return true;
    if (i % 2 == 0) {
        // I am the right element
        i = (i - 2) / 2;
        // values[i] = a parent element
        if (values[i] > value) {
            return false;
        }

    } else {
        // I am the left element
        i = (i - 1) / 2;
        // values[i] = a parent element
        if (values[i] <= value) {
            return false;
        }
    }
    return upperValues(values, i, value);
}

bool TreeUtil::isBinarySearchTree(vector<int> values) {
    for (int i = 1; i < values.size(); i++) {
        if (!upperValues(values, i, values[i])) return false;
    }
    return true;
};

int main() {
    bool result;
    vector<int> values = {100, 50, 150, 25, 75, 125, 175, 12, 37, 62, 87, 112, 137, 162, 187, 10, 14, 35, 39, 60, 64,
                          85, 89, 110, 114, 135, 139, 160, 164, 185, 189, 9, 11, 13, 15, 34, 36, 38, 40, 59, 61, 63, 65,
                          84, 86, 88, 90, 109, 111, 113, 115, 134, 136, 138, 140, 159, 161, 163, 165, 184, 186, 188,
                          190};
    auto start = myTime::start();
    result = TreeUtil::isBinarySearchTree(values);
    myTime::stop(start, 2);
    cout << (result ? "SearchTree" : "No SearchTree") << endl;
    return 0;
}