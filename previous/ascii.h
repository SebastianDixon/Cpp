#pragma once
#include <iostream>
#include <istream>
#include <string>

using namespace std;

int character(string & userStr){
    int len;
    len = userStr.length();

    char userChar[len];
    int userNum[len];

    for (int i = 0; i < len; ++i) {
        userChar[i] = static_cast<int>(userStr[i]);
        userNum[i] = static_cast<int>(userChar[i]);
    }

    cout << userStr << endl;

    int total{};
    int letterTotal{};
    int spaces;

    for (int i = 0; i < len; ++i) {
        if (userNum[i] == 32){
            cout << ", ";
        }
        else {
            cout << userNum[i] << " ";
            letterTotal+= userNum[i];

        }
        total+= userNum[i];
    }

    cout  << '\n'<< letterTotal << '\n' << total << endl;
    spaces = (total - letterTotal)/32;
    cout << "there are " << spaces +1 << " words" << endl;

    return total;

}