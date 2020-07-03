#include <iostream>
#include <string>
#include "prime.h"

using namespace std;


int main() {
    string message;
    cout << "what is your message :";
    cin >> message;


    int num = 10000;
    int p1;

    p1 = prime(num);
    rsa(p1, message);
    return 0;
}
