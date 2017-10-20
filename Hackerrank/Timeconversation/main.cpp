#include <bits/stdc++.h>

using namespace std;


string timeConversion(string s) {
    string time = "";

    int HH = stoi(s.substr(0,2));
    int mm = stoi(s.substr(3,2));
    int ss = stoi(s.substr(6,2));
    //cout << s.substr(s.size()-2, 2 ) << endl;
    if (s.substr(s.size() - 2, 2) == "AM") {
        time = s.substr(0, s.size() - 2);
        if(HH >= 12 && (mm >= 0 || ss >= 0)){
            time.at(0) -= 1;
            time.at(1) -= 2;
        }
    } else if (s.substr(s.size() - 2, 2) == "PM") {
        time = s.substr(0, s.size() - 2);

        if(HH >= 12 && (mm > 0 || ss > 0)){
            time.at(0) -= 1;
            time.at(1) -= 2;
        }
        time.at(0) += 1;
        time.at(1) += 2;
    } else {
        time = s;
    }

    if (time.substr(0, 2) == "24") {
        time.at(0) = '0';
        time.at(1) = '0';
    }
    return time;
}



int main() {

    string s = "12:00:00AM";
    //cin >> s;
    string result = timeConversion(s);
    cout << result << endl;
    return 0;
}
