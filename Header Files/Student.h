#pragma once
#include <string>
#include "Person.h"
using namespace std;

class Student : public Person
{
public:
    Student();
    Student(std::string first_name, std::string last_name, int age, std::string race, int phone);
    ~Student();

    virtual int OutputAge(int age);
    int getAge();

};