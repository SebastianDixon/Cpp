#pragma once
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

void randGen(int total){
    srand(23004);

    for (int i{1}; i <= total ; ++i) {
        cout << rand() << '\t';

        if (i % 5 == 0)
            cout << '\n';

    }
}

