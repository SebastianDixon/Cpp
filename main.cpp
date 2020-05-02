#include <iostream>
using namespace std;

void PassByValue(int val)
{
    cout << "I am in PassByValue" << endl;

    ++val;

    cout << val << " is the value in the function" << endl;
}

void PassByRef(int & val)
{
    cout << "I am in PassByRef" << endl;

    val = 50;

    cout << val << " is the value in the reference function" << endl;
}

class Person
{
    public:
        string name;
        int age;
        double height;
        double weight;

    Person()
    {
        cout << "Person" << endl;
    }

    Person(string name, int age, double height, double weight)
    {
        this->name = name;
        this->age = age;
        this->height = height;
        this->weight = weight;
    }
    
};

void ModifyPerson(Person & ob1)
{   
    cout << "inside modifyperson function" << endl;;

    ob1.name = "Bob";
}



int main()
{

    Person p1{"Fred", 20, 185.2, 75};
    cout << p1.name << '\n' << p1.age << '\n' << p1.height << '\n' << p1.weight << endl;

    ModifyPerson(p1);

    cout << p1.name << " is the name after passing to the function" << endl;


    int num1{};
    int num2{};
    int & pNum = num2;

    num1 = 3;
    pNum = 5;

    PassByValue(num1);

    cout << num1 << " is the value in the main class" << endl;

    PassByRef(pNum);

    cout << num2 << " is the value in the main class from PassByRef" << endl;

    PassByValue(pNum);

    cout << num2 << " is the value in the main class from PassByValue" << endl;

    double * pDouble = new double;

    *pDouble = 5.0;

    cout << *pDouble << " This is the value after dereferencing" << endl;

    delete pDouble;

    cout << *pDouble << " This is the value after deleting" << endl;


    return 0;
}
