#include <iostream>
#include <string>
using namespace std;
#pragma once

class Dog
{
    private:
    string first_name;
    string last_name;

    public:

    void get_iD();

    void sayHello();

    Dog();

    Dog(string first_name, string last_name);

    ~Dog();

};
