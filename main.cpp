#include <iostream>

using namespace std;

class Thing{
public:
    string name;
    int age;

    Thing(){}

    Thing(string name, int age) {
        this->name = name;
        this->age = age;
    }

    ~Thing()= default;

    void details() {
        cout << name << "" << age << endl;
    }
};

int main() {
    cout << "Hello, World!" << endl;
    Thing p1{"Seb", 18};

    p1.details();


    return 0;
}
