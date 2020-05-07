#pragma once

#include "Body.h"


class Handle
{
    private:
    Body * body; //internal instance of Body class called 'body' pointer

    public:
    Handle();
    ~Handle();

    void bodyOperation();

};