#include <iostream>
#include <string>
#include "headers/composition.h"
#include "headers/aggregation.h"

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

int main(){
    aggregation();
    return 0;
}

