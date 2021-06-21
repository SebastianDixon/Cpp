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
    return *this;   // return *this allows chainable function calls
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

class Shop{
private:
    int m_stock;
public:
    Shop(int stock=0) : m_stock{stock} {};

    operator int() const {return m_stock;}    // overloading the typecast operator for int, conversion to int automatic
    // user defined data type overloading dont require return type or parameters

};

class BigShop{
private:
    int m_bigstock;
public:
    BigShop(int stock=0) : m_bigstock{stock} {};

    friend bool operator>(const BigShop& b1, const BigShop& b2);

    friend std::ostream& operator<<(std::ostream &out, const BigShop& b1);

    operator Shop() const {return Shop(m_bigstock * 10);}   // overloading Shop() object call, implicit casting value
};

bool operator>(const BigShop& b1, const BigShop& b2) {
    return (b1.m_bigstock > b2.m_bigstock);
}

std::ostream &operator<<(std::ostream &out, const BigShop &b1) {
    out << b1.m_bigstock;
    return out;
}

class Average{
private:
    int m_sum{};
    int m_seen{};
public:
    Average() = default;

    Average(const Average& av) {
        m_sum = av.m_sum;
        m_seen = av.m_seen;
    }

    friend std::ostream& operator<<(std::ostream &out, const Average &av);

    Average& operator+=(int num) {
        m_sum += num;
        ++m_seen;
        return *this;
    }

};

std::ostream &operator<<(std::ostream &out, const Average &av) {
    double mean = static_cast<double>(av.m_sum)
            / static_cast<double>(av.m_seen);
    out << mean;
    return out;
}

#endif //UNTITLED_OVERLOAD_H
