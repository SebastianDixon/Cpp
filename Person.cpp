#include <iostream>
#include "Person.h"
#include "Dog.h"

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

void Person::sayHello()
{
    cout << "Hello" << endl;
}

void Person::setfName(string fName)
{
    this->first_name = fName;

    cout << this->first_name << endl;
}

//DOG

Dog::Dog()
{

}

Dog::Dog(string first_name, string last_name)
{
    this->first_name = first_name;
    this->last_name = last_name;
}

void Dog::sayHello()
{
    cout << "Woof" << endl;
}

Dog::~Dog()
{

}


int main()
{

    Person * p1 = new Person("Rick", "Gervais", 50);

    p1->sayHello();

    Dog * p2 = new Dog("Good", "boy");

    p2->sayHello();

    p1->setfName("Boris");


    delete p1;
    delete p2;

    return 0;
}
