//
// Created by SebDixon on 09/06/2021.
//

#ifndef UNTITLED_OVERLOAD_H
#define UNTITLED_OVERLOAD_H

#include <iostream>
#include <vector>
#include <cassert>

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

    Cent operator/(int value) const;    // member function overloading

    bool operator!() const; // unary operators implement using member functions\

    friend bool operator==(const Cent &obj1, const Cent &obj2);
    // friend function for overloading two items with binary operator where only the right items is changed

    Cent& operator++(); // prefix increment operator, return reference type, member function

    Cent operator++(int);   // postfix increment operator, dummy int parameter for distinction

    int get_cents() const {
        return m_quantity;
    }
};

Cent& Cent::operator++() {
    ++m_quantity;
    return *this;
}

Cent Cent::operator++(int) {
    Cent temp{*this};   // create temporary object using this pointer
    ++(*this);  // increment actual value
    return temp;    // return temporary object, this order allows return of same value, while incrementing
}

bool operator==(const Cent &obj1, const Cent &obj2) {
    return (obj1.m_quantity == obj2.m_quantity);
}

Cent operator+(const Cent &obj1, const Cent &obj2) {
    return {obj1.m_quantity + obj2.m_quantity};
}
// implementation of Cent overloaded + function

Cent operator*(const Cent &obj1, const Cent &obj2) {
    return {obj1.get_cents() * obj2.get_cents()};
}
// prefer overloading neither friend or inside of class, use get functions if possible

std::ostream& operator<< (std::ostream &out, const Cent &cent) {
    out << "C:" << cent.m_quantity;    // << operator takes parameters left and right of it
    return out;
}

Cent Cent::operator/(int value) const {
    return {m_quantity / value};
}
// overloading using a member function uses the *this hidden parameter for identifying the object
// member functions cannot overload iostream operators

bool Cent::operator!() const {
    return (m_quantity == 0);
}

class Inventory{
private:
    std::vector<int> m_items{};
    int m_craft[3][3]{};
public:
    Inventory() = default;
    Inventory(std::vector<int> array) : m_items{array} {}

    void add_item(int value) {
        m_items.push_back(value);
    }

    void view_craft() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                std::cout << m_craft[j][i] << " ";
            }
            std::cout << '\n';
        }
    }

    int& operator() (int row, int col);

    const int& operator() (int row, int col) const;

    int& operator[] (int index);    // overload subscript operator, reference to include *this parameter

    const int& operator[] (int index) const ; // const version for const variables
};

int& Inventory::operator() (int row, int col) {
    assert(col >= 0 && col < 3);    // if condition false, terminate program
    assert(row >= 0 && row < 3);
    return m_craft[row][col];
}

const int& Inventory::operator() (int row, int col) const {
    assert(col >= 0 && col < 3);
    assert(row >= 0 && row < 3);
    return m_craft[row][col];
}

int& Inventory::operator[](int index) {
    return m_items[index];  // take place of setter and getter
}

const int& Inventory::operator[](int index) const {
    return m_items[index];
}

#endif //UNTITLED_OVERLOAD_H
