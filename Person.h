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

    Person();


    Person(string first_name, string last_name);


    Person(string first_name, string last_name, int age);

    ~Person();

    void get_iD();

    void sayHello();

    void setfName(string fName);




};
