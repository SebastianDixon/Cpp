#include <iostream>
using namespace std;


class Person
{
    private:
    string middle_name;

    public:
    string first_name;
    string last_name;

    int age;

    string get_mid()
    {
        return middle_name;
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

    Person(string first_name, string last_name, int age, string middle_name)
    {
        this->first_name = first_name;
        this->last_name = last_name;
        this->age = age;
        this->middle_name = middle_name;
    }

    ~Person()
    {
        cout << "Destroyed Function" << endl;
    }

};

int main()
{

    Person p1();
    Person p2("Fred", "Bob");
    Person p3("Billy", "Bob", 70);
    Person private_p3("Billy", "Bob", 70, "PHILLANTHROPACOUS");

    cout << p1;
    cout << p2.first_name << p2.last_name << endl;
    cout << p3.first_name << p3.last_name << p3.age << endl;
    cout << private_p3.get_mid() << endl;
    
    return 0;
}
