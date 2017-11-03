#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class TreeUtil {
public:
    static bool isBinarySearchTree(vector<int> values);
    static bool upperValues(vector<int> &values, int i, int value);
};

bool TreeUtil::upperValues(vector<int> &values, int i, int value) {
    if (i <= 0)return true;
    if (i % 2 == 0) {
        // I am the right element
        i = (i-2)/2;
        // values[i] = a parent element
        if (values[i] > value) return false;
    } else {
        // I am the left element
        i = (i-1)/2;
        // values[i] = a parent element
        if (values[i] <= value) return false;

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
    vector<int> values = {20, 12, 34, 9, 19, 21, 35, 8, 13};
    cout << (TreeUtil::isBinarySearchTree(values) ? "SearchTree" : "No SearchTree") << endl;
    return 0;
}