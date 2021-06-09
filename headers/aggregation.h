//
// Created by SebDixon on 07/06/2021.
//

#ifndef UNTITLED_AGGREGATION_H
#define UNTITLED_AGGREGATION_H

#include <iostream>
#include <string>
#include <vector>
#include <functional>

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
    std::vector<std::reference_wrapper<const Teacher>> m_teachers;  // std::reference type cannot be anonymous
public:

    std::vector<std::reference_wrapper<const Teacher>> get_teacher() {
        return m_teachers;
    }

    friend std::ostream& operator<<(std::ostream& out, const Subject& sub) {
        for (const auto& teacher : sub.m_teachers) {
            out << teacher.get().get_name() << ' ';
        }
        out << '\n';
        return out;
    }

    void add(const Teacher &t) {
        m_teachers.push_back(t);
    }
};

/*
 * aggregations are not responsible for creating/destroying members
 * aggregations typically use pointer or reference members
 */

#endif //UNTITLED_AGGREGATION_H
