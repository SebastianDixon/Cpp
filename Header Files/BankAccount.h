#pragma once

#include <string>
using namespace std;

class Account
{
protected:
    double balance;

public:
    virtual string TermsandConditions() = 0;

    virtual ~Account();

    virtual void Deposit(double amount);
    virtual void Withdraw(double amount); 

    Account();

    Account(double initialBalance);

};