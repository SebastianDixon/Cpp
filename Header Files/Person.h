#pragma once
#include <string>
using namespace std;

class Person
{
public:
    string first_name;
    string last_name;
    int age;
    string race;

protected:
    int phone;

public:
    Person();
    virtual void OutputIdentity() = 0;
    virtual int OutputAge(int & age);
    virtual ~Person();

};