//
// Created by SebDixon on 15/06/2021.
//

#ifndef UNTITLED_CONSTRUCT_H
#define UNTITLED_CONSTRUCT_H

#include <iostream>

class Skeleton{
private:
    int m_bones;
public:
    Skeleton(int bones = 0) : m_bones{bones} {
        assert(bones > 0);  // prevent negative number of bones
    }

    Skeleton(const Skeleton& skeleton) : m_bones{skeleton.m_bones} {}
    // constructor takes class object as parameter, copying contents of other object

    operator int() const {return m_bones;}

    friend std::ostream& operator<< (std::ostream &out, const Skeleton &sk);
};

std::ostream& operator<< (std::ostream &out, const Skeleton &sk) {
    out << sk.m_bones;
    return out;
}

void printSkeleton(const Skeleton& sk) {
    std::cout << sk << '\n';
}

#endif //UNTITLED_CONSTRUCT_H
