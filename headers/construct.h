//
// Created by SebDixon on 15/06/2021.
//

#ifndef UNTITLED_CONSTRUCT_H
#define UNTITLED_CONSTRUCT_H

#include <iostream>

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
    // converting constructor, a constructor eligible for implicit conversions

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
};

std::ostream& operator<< (std::ostream &out, const Organ &og) {
    out << og.m_name;
    return out;
}

void printOrgan(const Organ& og) {
    std::cout << og << '\n';
}

#endif //UNTITLED_CONSTRUCT_H
