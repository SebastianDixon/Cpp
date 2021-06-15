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
    Skeleton(int bones = 0) : m_bones{bones} {}

    Skeleton(const Skeleton& skeleton) : m_bones{skeleton.m_bones} {}
    // constructor takes class object as parameter, copying contents of other object

    operator int() const {return m_bones;}
};

#endif //UNTITLED_CONSTRUCT_H
