#include <bits/stdc++.h>

using namespace std;

int migratoryBirds(int n, vector <int> ar) {
    // Complete this function
    long birds[5]{0};

    for (int &id : ar){
        birds[id-1]++;
    }

    long *bigVal;
    bigVal = birds+4;
    for(int i = 4; i >= 0; i--){
        if(birds[i] >= *(bigVal+0)){
            bigVal = birds+i;
        }
    }

    return (int)(bigVal - birds)+1;
}

int main() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for(int ar_i = 0; ar_i < n; ar_i++){
        cin >> ar[ar_i];
    }
    int result = migratoryBirds(n, ar);
    cout << result << endl;
    return 0;
}
