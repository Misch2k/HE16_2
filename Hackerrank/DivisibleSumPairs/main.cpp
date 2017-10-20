#include <bits/stdc++.h>

using namespace std;

int divisibleSumPairs(int n, int k, vector <int> ar) {
    // Complete this function
    int arr[k]{0}, sum(0);
    //Save the Modulo Value in a Array
    for(int value : ar){
        arr[value%k]++;
    }
    //Calc Options from Numbers % k == 0;
    sum += arr[0] * (arr[0] - 1) / 2;
    //Calc options from center element
    if(k%2 == 0){
        sum += arr[k/2] * (arr[k/2] - 1) / 2;
    }
    //Calc the other elements where sum of % k value == k by multiply them
    for(int i = 1; i <(k+1)/2; i++){
        sum += arr[i] * arr[k-i];
    }
    return sum;
};

int main() {
    int n;
    int k;
    cin >> n >> k;
    vector<int> ar(n);
    for(int ar_i = 0; ar_i < n; ar_i++){
        cin >> ar[ar_i];
    }
    int result = divisibleSumPairs(n, k, ar);
    cout << result << endl;
    return 0;
}
