//
// Created by SebDixon on 07/06/2021.
//

#ifndef UNTITLED_COMPOSITION_H
#define UNTITLED_COMPOSITION_H

#include <iostream>
#include <string>

class grid2D{
private:
    int m_x;
    int m_y;    // both these x and y member variables have a unidirectional relationship with the class grid2D
public:
    grid2D(int x = 0, int y = 0) : m_x{x}, m_y{y} {
    }

    void show_loc() const {
        std::cout << "x:" << m_x << '\t' << "y:" << m_y << '\n';
    }

    void set_loc(int x, int y) {
        m_x = x;
        m_y = y;
    }
};

class Player1{
private:
    std::string m_name;
    grid2D m_position;
public:
    Player1(std::string &name, grid2D pos) : m_name{name}, m_position(pos) {
    }

    void move_pos(int x, int y) {
        m_position.set_loc(x, y);
    }

    void show_pos() {
        m_position.show_loc();
    }

};

/*
 * composition relationship the class is responsible for the existence of the member
 * if class can be designed using a composition relationship, do, robust and simple
 * compositions typically use normal member variables
 * compositions are responsible for creation/destruction of parts
 *
 * aggregations are not responsible for creating/destroying members
 * aggregations typically use pointer or reference members
 */

#endif //UNTITLED_COMPOSITION_H
