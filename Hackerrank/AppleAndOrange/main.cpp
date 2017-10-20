#include <iostream>
#include <vector>

using namespace std;

vector<int> countHits (int houseStart, int houseEnd, int appleTree, int orangeTree, vector<int> apples, vector<int> oranges){
    vector<int> result;
    result.push_back(0);
    result.push_back(0);

    for(int apple : apples){
        if(appleTree + apple >= houseStart && appleTree + apple <= houseEnd) result[0]++;
    }
    for(int orange : oranges){
        if(orangeTree + orange >= houseStart && orangeTree + orange <= houseEnd) result[1]++;
    }
    return result;
}

int main(){
    int s;
    int t;
    cin >> s >> t;
    int a;
    int b;
    cin >> a >> b;
    unsigned int m;
    unsigned int n;
    cin >> m >> n;
    vector<int> apple(m);
    for(int apple_i = 0; apple_i < m; apple_i++){
        cin >> apple[apple_i];
    }
    vector<int> orange(n);
    for(int orange_i = 0; orange_i < n; orange_i++){
        cin >> orange[orange_i];
    }

    vector<int> result = countHits(s,t,a,b,apple,orange);
    for (int i = 0; i < 2; ++i) {
        cout << result[i] << endl;
    }
    return 0;
}
