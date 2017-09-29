#include <iostream>
#include <climits>

using namespace std;

long long maxFaq(long long n){
    if(n <= 1){
        return 1;
    }

    return n * maxFaq(n-1);
}


int main() {
    int count = 1;
    while(maxFaq(count) >= 1){
        count++;
    }
    cout << maxFaq(count-1) << endl;;
    return 0;
}