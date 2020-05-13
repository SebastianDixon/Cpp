#pragma once

#include "BankAccount.h"

class Freeze
{
public:
    virtual void freeze() = 0;
    virtual void unfreeze() = 0;
};