#include <iostream>
#include <vector>
#include "../../myFunctions/functions.h"
using namespace std;

class TreeUtil{
private:
    static pair<int,string> sumOfChildren(vector<int> &values, int max, int i);
public:
    static void printMaximumPath(vector<int> values);
};

void TreeUtil::printMaximumPath(vector<int> values){
    pair<int,string> result(sumOfChildren(values, values.size(), 0));
    cout << "Resultat: ";
    for(int i(0), j(0); i <= result.second.size(); i++){
        cout << values[j] << " ";
        if(result.second[i] == 'l'){
            j = 2*j+1;
        }else{
            j = 2*j+2;
        }
    }
    cout << "(Dieser Pfad ergibt die maximale Summe " << result.first << ")" << endl;
}

pair<int,string> TreeUtil::sumOfChildren(vector<int> &values, int max, int i){
    if(2*i+1 >= max) return make_pair(values[i], "");
    pair<int,string> left = TreeUtil::sumOfChildren(values, max, 2*i+1);
    if(2*i+2 >= max) return make_pair(left.first += values[i], "l" + left.second);
    pair<int,string> right = TreeUtil::sumOfChildren(values, max, 2*i+2);
    if(left.first > right.first) return make_pair(left.first += values[i], "l" + left.second);
    return make_pair(right.first += values[i], "r" + right.second);
};


int main() {
    vector<int> values = {40,100,200,20,40,70,80,50,10,60};
    for(int i = 0; i < 10000000; i++){
        values.push_back(rand()%1000);
    }
    auto start = myTime::start();
    TreeUtil::printMaximumPath(values);
    myTime::stop(start, 3);
    return 0;
}