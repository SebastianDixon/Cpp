
#pragma once
#include <iostream>
#include <istream>
#include <string>
#include <cmath>

using namespace std;

int prime(int & limit){
    int p1{};
    int counter{};

    for (int x = limit; x > 2; x--) {
        counter = 0;
        for (int i = 2; i < (limit / 2); i++) {
            if (x % i != 0)
                counter++;
            else
                break;
        }
        if (counter >= ((limit/2) -2)) {
            p1 = x;
            break;
        }
    }
    cout << p1 << endl;
    return p1;
}


#pragma clang diagnostic push
#pragma ide diagnostic ignored "bugprone-integer-division"
int rsa(int & p1, string & mess){
    int limit = p1 - 1;
    int length = mess.length();
    int p2{};

    int counter{};
    for (int x = limit; x > 2; x--) {
        counter = 0;
        for (int i = 2; i < (limit / 2); i++) {
            if (x % i != 0)
                counter++;
            else
                break;
        }
        if (counter >= ((limit/2) -2)) {
            p2 = x;
            break;
        }
    }
    int n=p1*p2;
    int phi = (limit)*(p2+ (-2));
    int a = phi /2;
    int e = prime(a);

    double d1=1/e;
    double d=fmod(d1,phi);
    double c = pow(length,e);
    double m = pow(c,d);

    c=fmod(c,n);
    m=fmod(m,n);

    cout << p1 << " " << p2 << endl;
    cout<<"\n"<<"Encrypted message = "<<c;
    cout<<"\n"<<"Decrypted message = "<<m;

    return 0;
}
#pragma clang diagnostic pop
