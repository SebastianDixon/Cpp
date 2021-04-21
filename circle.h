//
// Created by SebDixon on 20/04/2021.
//
#include "constants.h"

#ifndef UNTITLED_CIRCLE_H
#define UNTITLED_CIRCLE_H

void outputsmthn(){
    std::cout << "hello" << '\n';
}

namespace circle{
    double area(double r){
        return constants::pi * (r * r);
    }

    double circumference(double r){
        return 2 * constants::pi * r;
    }

    void testfunction(){
        outputsmthn();      // this function call is inside circle namespace
        ::outputsmthn();    // this function call is inside the global namespace
    }

    namespace sphere{   // nested namespace
        double spherearea(double r){
            return (4 * constants::pi) * (r*r);
        }
    }
}

#endif //UNTITLED_CIRCLE_H
