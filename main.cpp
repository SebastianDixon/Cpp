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

    // Person * p1 = new Person("Billy", "Bob", 70, "PHILLANTHROPACOUS");
    Person * p1 = new Person;

    cout << &p1 << endl;
    
    *p1 = Person("Billy", "Bob", 70, "PHILLANTHROPACOUS");

    cout << p1 << endl;

    delete p1;
    
    return 0;
}
