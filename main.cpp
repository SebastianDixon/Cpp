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

    Person * p1 = new Person{"Pointer", 70};
    p1->displayProp();

    Student * s1 = new Student{"UCL", "Fred", 19};
    s1->displayProp();

    delete p1;
    delete s1;


    return 0;
}
