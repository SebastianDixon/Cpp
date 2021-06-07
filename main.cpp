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
    std::string p1{"seb"};
    Teacher teacher{p1};
    {
        Subject math{teacher};  // into scope, destroyed out of scope
        std::cout << math.get_teacher().get_name() << '\n';
    }
    std::cout << teacher.get_name(); // Teacher object still exists
}

int main(){
    aggregation();
    return 0;
}

