//
// Created by SebDixon on 18/04/2021.
//

#ifndef UNTITLED_CONSTANTS_H
#define UNTITLED_CONSTANTS_H

/*
 * creating external namespace constants is better for larger scale programs
 * it prevents each file including the header with the namespace from duplicating each variable
 */

namespace constants{    // a namespace allows the use of namespace::object where included
    extern const double gravity;
    extern const double pi;
    extern const double avogadro ;
    // constexpr cannot be forward declared, therefore use const
}
#endif //UNTITLED_CONSTANTS_H
