#include <bits/stdc++.h>

using namespace std;

int solve(int n, vector < int > s, int d, int m){
    int counter(0);
    int sum(0);
    queue<int> numberContainer;
    for (unsigned int i = 0; i < m; i++) {
        numberContainer.push(s[i]);
        sum += s[i];
    }
    if(sum == d) counter++;
    for (int i = m; i < n; i++){
        sum -= numberContainer.front();
        numberContainer.pop();
        numberContainer.push(s[i]);
        sum += s[i];
        if(sum == d) counter++;
    }
    return counter;
}

int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    for(int s_i = 0; s_i < n; s_i++){
        cin >> s[s_i];
    }
    int d;
    int m;
    cin >> d >> m;
    int result = solve(n, s, d, m);
    cout << result << endl;
    return 0;
}
