#include <bits/stdc++.h>

using namespace std;


vector < int > getRecord(vector < int > s){
    vector<int>result{0,0};
    vector<int>score{s[0],s[0]};
    vector<int>::iterator it;

    for(int i = 0; i < s.size(); i++){
        if(s[i] > score[0]) {
            result[0]++;
            score[0] = s[i];
        }
        if(s[i] < score[1]){
            result[1]++;
            score[1] = s[i];
        };
    }

    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    for(int s_i = 0; s_i < n; s_i++){
        cin >> s[s_i];
    }
    vector < int > result = getRecord(s);
    string separator = "", delimiter = " ";
    for(auto val: result) {
        cout<<separator<<val;
        separator = delimiter;
    }
    cout<<endl;
    return 0;
}
