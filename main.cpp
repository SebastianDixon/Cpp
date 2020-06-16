#include <iostream>
#include <string>

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

class BankAccount{
private:
    double balance{};
    double rate{};
    string user;

public:
    BankAccount()= default;

    explicit BankAccount(string user) : user(user) {}

    BankAccount(string user, double balance, double rate)
    : balance(balance)
    , rate(rate)
    , user(user) {}

    ~BankAccount()= default;

    void input_bal(double val){
        balance+=val;
    }
    void input_rate(double val){
        rate+=val;
    }
    void give_name(string guy){
        user = guy;
    }
    void overview(){
        cout << user << '\n' << balance << '\n' << rate << endl;
    }

};



int main() {
    Thing p1{"Seb", 18};
    p1.details();

    BankAccount a1;
    a1.input_rate(1.12);
    a1.give_name("Jimmy");
    a1.input_bal(0);
    a1.overview();



    return 0;
}
