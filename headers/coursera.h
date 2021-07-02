//
// Created by SebDixon on 02/07/21.
//

#ifndef UNTITLED_COURSERA_H
#define UNTITLED_COURSERA_H

#include <iostream>
#include <string>

class Employee{
private:
    static int s_id;
    int m_id{};
    std::string m_name{};
public:
    explicit Employee(std::string name = "employee") : m_name{name}, m_id{++s_id} {}

    void input_name(std::string st) {
        m_name = st;
    }

    int get_id() const {
        return m_id;
    }

    std::string get_name() const {
        return m_name;
    }

    friend std::ostream& operator<<(std::ostream &out, const Employee &em);
};

int Employee::s_id{0};

std::ostream &operator<<(std::ostream &out, const Employee &em) {
    out << "ID:" << em.m_id << '\t' << "NAME:" << em.m_name << '\n';
    return out;
}

class Account : public Employee {
private:
    double m_salary{};
    double m_bonus{};
public:
    Account(std::string name, double salary, double bonus)
    : Employee{name}, m_salary{salary}, m_bonus{bonus} {}

    void input_salary(double val) {
        m_salary = val;
    }

    void input_bonus(double val) {
        m_bonus = val;
    }

    friend std::ostream& operator<<(std::ostream &out, const Account &ac);
};

std::ostream &operator<<(std::ostream &out, const Account &ac) {
    out << "ID:" << ac.get_id() << '\t' << "NAME:" << ac.get_name() << '\t';
    out << "Salary:" << ac.m_salary << '\t' << "Bonus:" << ac.m_bonus << '\n';
    return out;
}


#endif //UNTITLED_COURSERA_H
