//
// Created by SebDixon on 21/04/2021.
//

#include "constants.h"

namespace constants{    // a namespace allows the use of namespace::object where included
    const double gravity{9.81};
    const double pi{3.14159};
    const double avogadro { 6.0221413e23 };
    // constexpr cannot be forward declared, therefore use const
}