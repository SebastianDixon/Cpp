#include "BankAccount.h"

using namespace std;

std::string Account::TermsandConditions()
{}

Account::~Account(){}

Account::Account(){}


void Account::Deposit(double amount)
{
    balance += amount;
}

void Account::Withdraw(double amount)
{
    balance -= amount;
}
