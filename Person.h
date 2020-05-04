#include <iostream>
#include <string>
using namespace std;
#pragma once

class Person
{
    private:
    string first_name;
    string last_name;

    int age;

    public:

    void get_iD();

    Person();


    Person(string first_name, string last_name);


    Person(string first_name, string last_name, int age);

    ~Person();

};
