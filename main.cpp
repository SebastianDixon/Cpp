#include <iostream>
#include <string>

using namespace std;

class Person
{
    protected:
    string name;
    int age;

    public:
    virtual void displayProp() const;

    Person(){}

    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    ~Person(){}

};

void Person::displayProp() const
{
    cout << name << '\n' << age << endl;
}

class Student:public Person
{
    private:
    string college;

    public:
    virtual void displayProp() const;

    Student(){}

    Student(string college, string name,  int age)
    {
        this->college = college;
        this->name = name;
        this->age = age;
    }

    ~Student(){}

};

void Student::displayProp() const
{
    cout <<'\n';
    Person::displayProp();
    cout << college << endl;
}


int main()
{

    Person p1{"Rick", 50};
    p1.displayProp();

    Student s1{"UCL", "Fred", 19};
    s1.displayProp();
    

    return 0;
}
