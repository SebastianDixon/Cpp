#include <iostream>
#include "SavingsAccount.h"

using namespace std;

void FreezeMe(Freeze & f)
{
    f.freeze();
}


int main()
{
    SavingsAccount a1{1000, 1.025, false};

    a1.deposit(999);
    a1.withdraw(50);
    a1.earnInterest();

    FreezeMe(a1); //this implements the freezable class

    a1.unfreeze();

    return 0;
}
