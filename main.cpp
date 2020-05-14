#include <iostream>
#include <string>
#include "Person.h"
#include "Student.h"
#include "Teacher.h"
using namespace std;

Person::Person(){}
int Person::OutputAge(int & age)
{
    cout << age << endl;
    return age;
}
Person::~Person()
{
    cout << "Person object deleted" << endl;
}

Teacher::Teacher(){}
Teacher::Teacher(std::string first_name, std::string last_name, int age, std::string race, int phone)
{
    this->first_name = first_name;
    this->last_name = last_name;
    this->age = age;
    this->race = race;
    this->phone = phone;
}
Teacher::~Teacher()
{
    cout << "Teacher object deleted" << endl;
}
void Teacher::OutputIdentity()
{
    cout << "I am a Teacher" << endl;
}
int Teacher::OutputAge(int age)
{
    cout << "I am a Teacher and ";
    Person::OutputAge(age);
    return age;
}
int Teacher::getAge()
{
    return Teacher::age;
}

Student::Student(){}
Student::Student(std::string first_name, std::string last_name, int age, std::string race, int phone)
{
    this->first_name = first_name;
    this->last_name = last_name;
    this->age = age;
    this->race = race;
    this->phone = phone;
}
Student::~Student()
{
    cout << "Student object deleted" << endl;
}
void Student::OutputIdentity()
{
    cout << "I am a student" << endl;
}
int Student::OutputAge(int age)
{
    cout << "I am a student and ";
    Person::OutputAge(age);
    return age;
}
int Student::getAge()
{
    return Student::age;
}



int main()
{
    int const val{50};
    int const val2{90};

    Student * s1 = new Student{"RIcku", "boy", 10, "white", 9};
    s1->OutputIdentity();
    s1->OutputAge(val);

    Teacher * t1 = new Teacher{"blab", "blob", 90, "white", 90};
    t1->OutputIdentity();
    t1->OutputAge(val2);

    return 0;
}
