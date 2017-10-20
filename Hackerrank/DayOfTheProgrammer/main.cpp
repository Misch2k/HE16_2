#include <bits/stdc++.h>
#include <set>

using namespace std;

string solve(int year){
    int days = 256;
    bool isLeap = false;
    if(year < 1918){
        isLeap = year % 4 == 0;
    }else{
        isLeap = year%4 == 0;
        if(isLeap) isLeap = year % 100 != 0;
        if(!isLeap) isLeap = year % 400 == 0;
    }

    int index = 1;
    bool end = true;


    do{
        int day;
        switch (index){
            case 1 :
                day = 31;
                break;
            case 2 :
                if(year == 1918) day = 28-13;
                else isLeap ? day = 29 : day = 28;
                break;
            case 3:
                day = 31;
                break;
            case 4:
                day = 30;
                break;
            case 5:
                day = 31;
                break;
            case 6:
                day = 30;
                break;
            case 7:
                day = 31;
                break;
            case 8:
                day = 31;
                break;
            case 9:
                day = 30;
                break;
            case 10:
                day = 31;
                break;
            case 11:
                day = 30;
                break;
            case 12:
                day = 31;
                break;
            default:
                day = 30;
                break;
        }
        if(days - day >= 0){
            days -= day;
        }else{
            end = false;
        }
        index++;
    }while(end);

    string result = "";
    result += to_string(days);
    result += ".";
    if(index-1 < 10) result += "0";
    result += to_string(index-1);
    result += ".";
    result += to_string(year);

    return result;
}

int main() {
    int year;
    cin >> year;
    string result = solve(year);
    cout << result << endl;
    return 0;
}
