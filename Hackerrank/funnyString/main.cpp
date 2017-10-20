#include <bits/stdc++.h>

using namespace std;

string funnyString(string s){
    bool result = true;
    int start = 0;
    int end = 0;

    for(unsigned int i = 0; i < s.size()-1 && result; i++){
        //cout << (int)s.at(i+1) << "-" << (int)s.at(i) << " = " << (int)s.at(i+1) - (int)s.at(i) << endl;
        //cout << (int)s.at(s.size()-(i+2)) << "-" << (int)s.at(s.size()-(i+1)) << " = " << (int)s.at(s.size()-(i+2)) - (int)s.at(s.size()-(i+1)) << endl;
        start = (int)s.at(i+1) - (int)s.at(i);
        end = (int)s.at(s.size()-(i+2)) - (int)s.at(s.size()-(i+1));
        if(start < 0) start *= -1;
        if(end < 0) end *= -1;
        result = start == end;
    }
    return result ? "Funny" : "Not Funny";
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        string result = funnyString(s);
        cout << result << endl;
    }
    return 0;
}
