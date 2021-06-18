//
// Created by SebDixon on 15/06/2021.
//

#ifndef UNTITLED_CONSTRUCT_H
#define UNTITLED_CONSTRUCT_H

#include <iostream>
#include <cstring>

class Skeleton{
private:
    int m_bones;
    std::string m_type;
public:
    Skeleton(char) = delete;    // delete keyword prevents any construction of this type being converted

    Skeleton(int bones = 0) : m_bones{bones} {  // lack of explicit keyword to allow implicit calls
        assert(bones > 0);
    }

    Skeleton(const Skeleton& skeleton) : m_bones{skeleton.m_bones} {}

    friend std::ostream& operator<< (std::ostream &out, const Skeleton &sk);

};

std::ostream& operator<< (std::ostream &out, const Skeleton &sk) {
    out << sk.m_bones;
    return out;
}

void printSkeleton(const Skeleton& sk) {
    std::cout << sk << '\n';
}

class Organ {
private:
    std::string m_name;
public:
    explicit Organ(std::string name) : m_name{name} {   // explicit keyword only allows explicit calls
        std::cout << "*explicit call*\n";
    }

    friend std::ostream& operator<< (std::ostream &out, const Organ &og);

    Organ& operator=(const Organ &og);
};

Organ& Organ::operator=(const Organ &og) {
    m_name = og.m_name;
    return *this;   // member functions overloading operators return *this address as reference to object in use
}

std::ostream& operator<< (std::ostream &out, const Organ &og) {
    out << og.m_name;
    return out;
}

void printOrgan(const Organ& og) {
    std::cout << og << '\n';
}

class Coral {
private:
    std::string m_color;    // fixed memory allocation
public:
    explicit Coral(std::string color) : m_color{color} {}

    explicit Coral(const Coral &coral) : m_color{coral.m_color} {};
    // shallow member copying constructor
    // the value at member variables address are being copied, no new memory is allocated

    friend std::ostream& operator<< (std::ostream &out, const Coral &coral);
};

std::ostream& operator<< (std::ostream &out, const Coral &coral) {
    out << coral.m_color;
    return out;
}

class Trench {
private:
    char *m_name{};
    int m_length{};
public:
    explicit Trench(const char *name="") {   // dynamic string constructor
        assert(name);   // prevent empty empty null string
        m_length = std::strlen(name) + 1;   // +1 includes terminator char

        m_name = new char[m_length];    // new buffer for string

        for (int i = 0; i < m_length; ++i) {
            m_name[i] = name[i];
        }
        m_name[m_length-1] = '\0';  // ensures termination bit included
    }

    Trench(const Trench& tc) {
        deepCopy(tc);
    }

    ~Trench() { // destructor required for dynamic string
        delete[] m_name;
    }

    void deepCopy(const Trench& tc);

    friend std::ostream& operator<< (std::ostream &out, const Trench &trench);

};

void Trench::deepCopy(const Trench &tc) {
    delete[] m_name;    // delete current values
    m_length = tc.m_length; // shallow copy of fixed memory values

    if (tc.m_name) {    // check if not null pointer
        m_name = new char[m_length];

        for (int i{ 0 }; i < m_length; ++i)
            m_name[i] = tc.m_name[i];
    }
    else {
        m_name = nullptr;
    }
}

std::ostream& operator<< (std::ostream &out, const Trench &trench) {
    out << trench.m_name;
    return out;
}


#endif //UNTITLED_CONSTRUCT_H
