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

    virtual ~Person();

    Person(){}

    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }


};

Person::~Person()
{
    cout << "Person object deleted" << endl;
}

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

    virtual ~Student();

};

void Student::displayProp() const
{
    cout <<'\n';
    Person::displayProp();
    cout << college << endl;
}

Student::~Student()
{
    cout << "Student object deleted" << endl;
}


void displayRef(Person & ref)
{
    ref.displayProp();
}


int main()
{

    Person * p1 = new Student{"Pointer", "Bill", 70};
    p1->displayProp();

    displayRef(*p1);

    delete p1;


    return 0;
}
