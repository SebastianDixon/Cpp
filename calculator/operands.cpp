//
// Created by SebDixon on 15/04/2021.
//
#include "operands.h"
#include <iostream>

double add(double x, double y){
    return x + y;
}

double subtract(double x, double y){
    return x - y;
}

double multiply(double x, double y){
    return x * y;
}

double divide(double x, double y){
    if (x == 0 || y == 0){
        std::cerr << "Error: could not divide by zero\n";
        return 0.0;
    }
    return x / y;
}
