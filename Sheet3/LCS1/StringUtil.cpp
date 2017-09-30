//
// Created by mkugler on 21.09.2017.
//

#include "StringUtil.h"
#include <iostream>

using namespace std;

string StringUtil::lcs(string first, string second) {
    unsigned int count = 0;
    unsigned int stringStart = 0;
    unsigned int stringLength = 0;
    unsigned int firstIndex = 0;
    unsigned int secondIndex = 0;
    //long long counter = 0;
    //long long whileCounter = 0;

    // First while loops true the hole String
    // Second while loops also true the hole string but:
    // When a letter matches, it compares all following letter
    while (firstIndex < first.length()) {
        while (secondIndex < second.length()) {
            //counter++;
            count = 0;
            if (first[firstIndex] == second[secondIndex]) {
                if (first[firstIndex + stringLength] == second[secondIndex + stringLength]) {
                    while ((firstIndex + count < first.length() && secondIndex + count < second.length()) &&
                           (first[firstIndex + count] == second[secondIndex + count])) {
                        count++;
                        //whileCounter++;
                    };
                    if (count > stringLength) {
                        stringLength = count;
                        stringStart = firstIndex;
                    }
                    secondIndex += count + 1;
                } else {
                    secondIndex += stringLength + 1;
                }
            } else {
                secondIndex++;
            }
        }
        firstIndex += count != 0 ? count : 1;
        secondIndex = 0;
    }


    //cout << "Max durchläufe = " << counter + whileCounter << endl;
    //cout << "string1.length() * string2.length() = " << first.length() * second.length() << endl;

    return first.substr(stringStart, stringLength);
};
