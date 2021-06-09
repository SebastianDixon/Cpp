#include <iostream>
#include <string>
#include "headers/composition.h"
#include "headers/aggregation.h"
#include "headers/overload.h"

void composition() {
    std::string p1{"seb"};
    Player1 newplayer{p1, {5, 3}};
    newplayer.show_pos();
    newplayer.move_pos(4, 2);
    newplayer.show_pos();
}

void aggregation() {
    Teacher t1{ "Bob" };
    {
        Subject math{}; // create an empty Department
        math.add(t1);
        std::cout << math;
    }
    std::cout << t1.get_name() << " still exists!\n";
}

void overloadCents() {
    Cent c1{5};
    Cent c2{2};
    Cent overloadSum{c1 + c2};
    std::cout << overloadSum << '\n';   // using overloading of << operator
}

int main(){
    overloadCents();
    return 0;
}

