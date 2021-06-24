//
// Created by SebDixon on 23/06/21.
//

#ifndef UNTITLED_INHERIT_H
#define UNTITLED_INHERIT_H

#include <string>

enum Sex{
    MALE,
    FEMALE,
};

class Person  {
private:
    std::string m_name{};
    int m_age{};
    Sex m_sex{};
public:
    explicit Person(const std::string &name = "", int age = 0, Sex sex = MALE)
    : m_name{name}, m_age{age}, m_sex{sex} {
        std::cout << "base class constructor called first\n";
    }

    const std::string& get_name() const {
        return m_name;
    }

    int get_age() const {
        return m_age;
    }

    Sex get_sex() const {
        return m_sex;
    }
};

class Athlete : public Person {
private:
    std::string m_sport{};
    double m_weight{};
public:
    // call base class constructor of choice to initialise base class variables
    Athlete(const std::string &name, int age, Sex sex,
            const std::string &sport, double weight)
    : Person{name, age, sex}, m_sport{sport}, m_weight{weight} {
        std::cout << "child class constructor called next\n";
    }

    std::string get_sport() const {
        return m_sport;
    }

    double get_weight() const {
        return m_weight;
    }
};

class ParaAthlete : public Athlete {
private:
    std::string m_disability{};
public:
    ParaAthlete(const std::string &name, int age, Sex sex,
                const std::string &sport, double weight, std::string dis)
                : Athlete(name, age, sex, sport, weight), m_disability{dis} {}
};

#endif //UNTITLED_INHERIT_H
