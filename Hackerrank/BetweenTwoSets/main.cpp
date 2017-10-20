#include <bits/stdc++.h>

using namespace std;

int ggT(int a = 0, int b = 0){
    if(b == 0) return a;
    return (ggT(b, a % b));
}

int KgV(int a, int b){
    return a * b / ggT(a, b);
}


int MultiggT(vector <int> number){snake
    //Abbruchbedingung
    if(number.size() <= 1) return number[0];

    //Splitt vector
    vector<int>left;
    vector<int>right;
    for(int i = 0; i < number.size(); i++){
        if(i % 2 == 0){
            left.push_back(number[i]);
        }else{
            right.push_back(number[i]);
        }
    }
    //rekursiv
    return ggT(MultiggT(left),MultiggT(right));

}


int MultiKgV(vector<int> number){
    long result = number[0];
    int ggt = MultiggT(number);
    //cout << "ggT von a = " << ggt << endl;
    for (int i = 0; i < number.size(); ++i) {
        if(ggt != 1){
            result *= number[i] / ggt;
        }else{
            result = number[i];
        }

    }

    return result;
}

int getTotalX(vector <int> a, vector <int> b) {
    int KgV = MultiKgV(a);
    //cout << "KgV = " << KgV << endl;
    bool match;
    int result = 0;
    for (int i = KgV; i < 200; i += KgV) {
        match = true;
        for(int j = 0; j < b.size(); j++){
            if(b[j] % i != 0){
                match = false;
                break;
            }
        }
        if(match) {
            //cout <<"i = " << i << endl;
            result++;
        }
    }

    return result;
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
        cin >> a[a_i];
    }
    vector<int> b(m);
    for(int b_i = 0; b_i < m; b_i++){
        cin >> b[b_i];
    }
    int total = getTotalX(a, b);
    cout << total << endl;
    return 0;
}
