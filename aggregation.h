//
// Created by SebDixon on 07/06/2021.
//

#ifndef UNTITLED_AGGREGATION_H
#define UNTITLED_AGGREGATION_H

#include <iostream>
#include <string>

class Teacher{
private:
    std::string m_name;
public:
    Teacher(const std::string &name) : m_name{name} {
    }

    std::string get_name() const {
        return m_name;
    }
};

class Subject {
private:
    const Teacher& m_teacher;   // each subject holds multiple teacher, one implemented for example
public:
    Subject(const Teacher& teacher) : m_teacher{teacher} {
    }

    Teacher get_teacher() const {
        return m_teacher;
    }
};

/*
 * aggregations are not responsible for creating/destroying members
 * aggregations typically use pointer or reference members
 */

#endif //UNTITLED_AGGREGATION_H
