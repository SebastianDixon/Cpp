#pragma once

#include "BankAccount.h"

class Log
{
public:
    virtual void log(const string & message) const = 0;
};