#include <iostream>
#include <string>
#include "Person.h"
#include "BankAccount.h"
#include <cstdlib>
#include <ctime>

using namespace std;

void game(){
    srand((unsigned) time(0));
    int num = (rand() % 100) + 1;
    int guess;
    int top = 100;
    int bottom = 1;
    int centre;

    do {
        centre = (top + bottom) /2;
        cout << num << endl;
        cout << "guess my number between " << bottom << " and " << top << " inclusive: ";
        cin >> guess;


        if (num > centre){
            bottom = centre;
        }
        else{
            top = centre;
        }


    } while (num != guess);

    cout << "congratulations" << endl;
}

int main() {
    game();

    return 0;
}
