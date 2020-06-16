#include <iostream>
#include <string>

using namespace std;

class Person{
protected:
    string first_name;
    string last_name;

public:
    Person() = default;

    Person(string fname, string lname)
    : first_name(fname),
    last_name(lname){}

    ~Person() = default;
};


class BankAccount : public Person{
private:
    double balance{};
    double rate{};

public:
    BankAccount()= default;

    BankAccount(double balance, double rate)
    : balance(balance)
    , rate(rate){}

    ~BankAccount()= default;

    void input_bal(double val){
        balance+=val;
    }
    void input_rate(double val){
        rate+=val;
    }
    void give_name(string first, string last){
        first_name = first;
        last_name = last;
    }
    void overview(){
        cout << first_name << " " << last_name << '\n' << balance << '\n' << rate << endl;
    }

};



int main() {

    BankAccount a1;
    a1.input_rate(1.12);
    a1.give_name("Jimmy", "Bob");
    a1.input_bal(0);
    a1.overview();



    return 0;
}
