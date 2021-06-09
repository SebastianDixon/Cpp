//
// Created by SebDixon on 09/06/2021.
//

#ifndef UNTITLED_OVERLOAD_H
#define UNTITLED_OVERLOAD_H

#include <iostream>

class Cent{
private:
    int m_quantity;
public:
    Cent(int quantity = 0) : m_quantity{quantity} {}

    friend Cent operator+(const Cent &obj1, const Cent &obj2);
    // friend function for overloading the + operator to work with Cent data type

    friend Cent operator-(const Cent &obj1, const Cent &obj2) {
        return {obj1.m_quantity - obj2.m_quantity};
    }
    // friend functions can be implemented inside of the class for simplicity, avoid

    friend std::ostream& operator<< (std::ostream &out, const Cent &cent);
    // overloading << operator for easy output of member variables

    int get_cents() const {
        return m_quantity;
    }
};

Cent operator+(const Cent &obj1, const Cent &obj2) {
    return {obj1.m_quantity + obj2.m_quantity};
}
// implementation of Cent overloaded + function

Cent operator*(const Cent &obj1, const Cent &obj2) {
    return {obj1.get_cents() * obj2.get_cents()};
}
// prefer overloading neither friend or inside of class, use get functions if possible

std::ostream& operator<< (std::ostream &out, const Cent &cent) {
    out << "cents: " << cent.m_quantity;    // << operator takes parameters left and right of it
    return out;
}

#endif //UNTITLED_OVERLOAD_H
