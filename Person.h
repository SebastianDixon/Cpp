#pragma once
#include <string>
using namespace std;


class Person{
protected:
    string first_name;
    string last_name;

public:
    Person() = default;

    Person(string fname, string lname)
            : first_name(fname)
            , last_name(lname){}

    ~Person() = default;
};

