#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class TreeUtil{
public:
    static bool isBinarySearchTree(vector<int> values);
};

bool TreeUtil::isBinarySearchTree(vector<int> values){
    for(int i = 0; 2*i+2 < values.size(); i++){
        if(values[2*i+1] >= values[i] || values[i] >= values[2*i+2]) return false;
    }
    return true;
};


int main() {
    vector<int> values = {20, 12, 34, 9, 19, 29, 35, 7};
    cout << (TreeUtil::isBinarySearchTree(values) ? "SearchTree" : "No SearchTree") << endl;
    return 0;
}