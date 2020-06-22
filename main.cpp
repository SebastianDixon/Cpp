#include <iostream>
#include <istream>
#include <string>
#include "BinarySearch.h"

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

    for (int i = 0; i < len; ++i) {
        if (userNum[i] == 32){
            cout << ", ";
        }
        else {
            cout << userNum[i] << " ";
        }
    }

    return 0;

}

int main() {
    string wordz;

    cout << "what is your string: ";
    getline(cin, wordz);

    character(wordz);
    return 0;
}
