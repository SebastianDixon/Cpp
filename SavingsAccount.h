#pragma once

#include "BankAccount.h"
#include "Freezable.h"
#include "Loggable.h"

#include <list>

class SavingsAccount : public Account, public Freeze, public Log
{
private:
    double balance;
    double interestRate;
    bool frozen;

public:
    SavingsAccount(double initialBalance, double interestRate, bool frozen);
    virtual ~SavingsAccount();

    void earnInterest();

    virtual void deposit(double amount);
    virtual void withdraw(double amount);

    virtual string TermsandConditions();

    virtual void freeze();
    virtual void unfreeze();

    virtual void log(const string & message) const;


};