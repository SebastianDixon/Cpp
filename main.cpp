#include <iostream>
using namespace std;


class Person
{
    public:
    string first_name;
    string last_name;

    int age;

    void get_name()
    {
        cout << first_name << last_name << endl;
    }

    void get_age()
    {
        cout << age << endl;
    }

    Person()
    {
        cout << "Person\n";
    }

    Person(string first_name, string last_name)
    {
        this->first_name = first_name;
        this->last_name = last_name;
    }

    Person(string first_name, string last_name, int age)
    {
        this->first_name = first_name;
        this->last_name = last_name;
        this->age = age;
    }

};

int main()
{

    Person p1();
    Person p2("Fred", "Bob");
    Person p3("Billy", "Bob", 70);

    cout << p1;
    cout << p2.first_name << p2.last_name << endl;
    cout << p3.first_name << p3.last_name << p3.age << endl;
    
    return 0;
}
