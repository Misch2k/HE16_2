#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
using namespace std;

class TreeUtil{
public:
    static void printMaximumPath(vector<int> values);
    static pair<int,string> sumOfChildren(vector<int> &values, int max, int i);
};

void TreeUtil::printMaximumPath(vector<int> values){
    pair<int,string> result(sumOfChildren(values, values.size(), 0));
    cout << result.first << " " << result.second << endl;
    cout << "Resultat: " << endl;
    cout << values[0] << " ";
    int j = 0;
    for(int i = 0; i < result.second.size(); i++){
        if(result.second[i] == 'l'){
            j = 2*j+1;
        }else{
            j = 2*j+2;
        }
        cout << values[j] << " ";
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
    TreeUtil::printMaximumPath(values);

    return 0;
}