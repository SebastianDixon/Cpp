#include "SavingsAccount.h"
#include <iostream>


using namespace std;

SavingsAccount::SavingsAccount(double initialBalance, double interestRate, bool frozen)
{
    this->balance = initialBalance;
    this->interestRate = interestRate;
    this->frozen = frozen;
}

SavingsAccount::~SavingsAccount()
{}

void SavingsAccount::earnInterest()
{
    if(!frozen)
    {
       balance *= interestRate; 
    }
}

void SavingsAccount::deposit(double amount)
{
    if(!frozen)
    {
       balance += amount;
    }
}

void SavingsAccount::withdraw(double amount)
{
    if(!frozen)
    {
       balance -= amount;
    }
}

std::string SavingsAccount::TermsandConditions()
{
    return "Terms and Condition apply, interest applicable";
}

void SavingsAccount::freeze()
{
    frozen = true;
}

void SavingsAccount::unfreeze()
{
    frozen = false;
}

void SavingsAccount::log(const std::string &message) const
{
    cout << message << endl;
}