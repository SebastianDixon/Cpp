#include <iostream>
#include "Person.h"
using namespace std;


Person::Person()
{
    cout << "Person\n" << endl;
}

Person::Person(string first_name, string last_name)
{
    this->first_name = first_name;
    this->last_name = last_name;
}

Person::Person(string first_name, string last_name, int age)
{
    this->first_name = first_name;
    this->last_name = last_name;
    this->age = age;
}

Person::~Person()
{
}

void Person::get_iD()
{
    cout << first_name << last_name << age << endl;
}


int main()
{

    return 0;
}
