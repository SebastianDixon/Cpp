#pragma once
#include <string>
using namespace std;
#include "Person.h"

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
        cout << first_name << " " << last_name << ", " << balance << ", " << rate << endl;
    }

    int apply_rate(){
        balance *= rate;
        return balance;
    }

};

