#pragma once
#include <string>
#include "Person.h"
using namespace std;

class Teacher : public Person
{
public:
    Teacher();
    Teacher(std::string first_name, std::string last_name, int age, std::string race, int phone);
    ~Teacher();

    virtual void OutputIdentity();
    virtual int OutputAge(int age);
    int getAge();
};