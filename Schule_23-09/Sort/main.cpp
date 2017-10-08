#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
using namespace std;

class Sort {
public:
    virtual void sort(vector<int> & data) = 0;
};

class QuickSort : public Sort {
public:
    virtual void sort(vector<int> & data);
};

void QuickSort::sort(vector<int> & data) {
    // Abbruchbedingung
    if (data.size() <= 1) return;

    // pivot element bestimmen
    int randIndex = rand()%data.size();
    int pivot = data[randIndex];
    data[randIndex] = data[data.size()-1];
    data[data.size()-1] = pivot;

    // split in linke und rechte haelfte
    vector<int> left;
    vector<int> right;
    for (int i=0; i<data.size()-1; i++) {
        if (data[i] < pivot) {
            left.push_back(data[i]);
        } else {
            right.push_back(data[i]);
        }
    }

    // rekursiver aufruf
    sort(left);
    sort(right);

    // merge
    int index = 0;
    for (index=0; index<left.size(); index++) {
        data[index] = left[index];
    }
    data[index] = pivot;
    for (int i=0; i<right.size(); i++) {
        data[index+i+1] = right[i];
    }
}

class SelectionSort : public Sort {
public:
    virtual void sort(vector<int> & data);
};

void SelectionSort::sort(vector<int> & data) {
    for (int i=0; i<data.size()-1; ++i) {
        int value = data[i];
        int index = i;
        for (int j=i+1; j<data.size(); ++j) {
            if (value > data[j]) {
                value = data[j];
                index = j;
            }
        }
        int tmp = data[i];
        data[i] = value;
        data[index] = tmp;
    }
}

class MergeSort : public Sort {
public:
    virtual void sort(vector<int> & data);
};

void MergeSort::sort(vector<int> & data){
    //Abbruch
    if(data.size() == 1) return;
    //Splitt
    vector<int> left, right;
    for (int i = 0; i < data.size(); ++i) {
        if(i < data.size()/2){
            left.push_back(data[i]);
        }else{
            right.push_back(data[i]);
        }
    }
    sort(left);
    sort(right);
    //Merge
    if(left < right){

    }

};


void print(vector<int> & data) {
    vector<int>::iterator it;
    for (it=data.begin(); it!=data.end(); it++) {
        cout << *it << ",";
    }
    cout << endl;
}

int main(int argc, char **argv) {

    vector<int> data;
    for (int i=0; i<1000000; ++i) {
        //data.push_back(rand()%1000);
        data.push_back(i);
    }

    //print(data);
    Sort *s = new QuickSort();
    clock_t start, stop;
    start = clock();
    s->sort(data);
    stop = clock();
    cout << (double)(stop-start)/CLOCKS_PER_SEC << endl;
    //print(data);

    return 0;
}