#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <map>

using namespace std;


string generateDNA(int size) {
    char v[4] = {'A', 'C', 'G', 'T'};
    string pla = "";
    for (int i = 0; i < size; i++) {
        pla += v[rand() % 4];
    }
    return pla;
}

int match(string t, string p) {

    for (int i = 0; i < t.size() - p.size() + 1; i++) {
        string s = "";
        for (int j = 0; j < p.size(); j++) {
            s += t[i + j];
        }

        if (s == p) {
            return i;
        }
    }
    return -1;
}

map<char, int> patternToMap(string &p) {
    map<char, int> pattern;
    for (unsigned int i = 0; i < p.size() - 1; i++) {
        pattern[p.at(i)] = p.size() - (1 + i);
    }
    return pattern;
};

int bm(string &t, string &p) {
    // create map, preprocess pattern
    auto pattern = patternToMap(p);
    for(auto val : pattern){
        cout << val.first << " : " << val.second << endl;
    }
    int index = 0;
    while(index < t.size() - p.size() + 1) {
        bool matchFound = true;
        for (int j = p.size() -1; j >= 0; j--) {
            if (p[j] != t[j + index]) {
                matchFound = false;
                break;
            }
        }
        if (!matchFound) {
            if(pattern.find(p.at(p.size() - 1)) == pattern.end()){
                index += p.size() -1;
            }else{
                index += pattern[p.at(p.size() -1)];
            }
        } else {
            return index;
        }
    }
    return -1;
}


int main(int argc, char **argv) {

    string t = generateDNA(100000000);
    string p = t.substr(68979689, 100000);
    //string p = "AGTGCGCTGGCAAGTGGGTAGCCCGATCAACCAGGCCGGGGGGCGAAGGCTTTTCTTCTGTCAATTGGCAGAGGGACGAGCCAATTGTACGTCTATTCTCTCTCTACTGAAGGTGGTGCGGATTTAGTTAACCTGAAGTGAGATCCCGCGGAAGTGTCCTAATTTATGCTACACTCTCCATCCATTGGAGAAACGGTGGGTGATATTTTGCTAGGGCAAAGAGGGTCTTTGCACGAGCGGCTTACAATCTCTGCAAGTGGTGCGTTTCGACCGGCGCCCTACCATTGGCTAGCTCGCATGGGACCGAGAATCATTGCAAGGAGTTCTCATGGACTCGTTTTCTGATATCGGCCTCGAGTGTGTGAACGCCAGCAACATATGATGTGCTCCAGTAACAGAATACGGCATCCTTACAGTTGCCGAATGTAGCGGTAAAGACAGTCTTTCACCTCACCCTGCGCAACGCGAGCATTTCGACGGGTGGGTAATCGAGTCATAGC";

    //string t = "er sagte abrakadabra aber";
    //string p = "aber";

    clock_t start, stop;

    start = clock();
    cout << bm(t, p) << endl;
    stop = clock();

    cout << "runtime = ";
    cout << (double) (stop - start) / CLOCKS_PER_SEC << endl;

    return 0;
}

