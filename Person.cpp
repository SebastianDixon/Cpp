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

    Person * p3 = new Person("Rick", "Gervais", 50);

    Person u1{"Fred", "Bob", 45};

    u1.get_iD();

    p3->get_iD();


    delete p3;

    return 0;
}
