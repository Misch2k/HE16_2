#include <bits/stdc++.h>

using namespace std;

vector < int > solve(vector < int > grades){
    vector<int> newGrades;
    for(int grade : grades){
        if(grade >= 38){
            int modGrade = grade;
            if(grade % 5 >= 3) modGrade += 5 - grade % 5;

            newGrades.push_back(modGrade);
        }else{
            newGrades.push_back(grade);
        }
    }

    return newGrades;
}

int main() {
    unsigned int n;
    cin >> n;
    vector<int> grades(n);
    for(int grades_i = 0; grades_i < n; grades_i++){
        cin >> grades[grades_i];
    }
    vector < int > result = solve(grades);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? "\n" : "");
    }
    cout << endl;


    return 0;
}
