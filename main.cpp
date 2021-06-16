#include <iostream>
#include <string>
#include "headers/composition.h"
#include "headers/aggregation.h"
#include "headers/overload.h"
#include "headers/construct.h"

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
    Cent c1{10};
    Cent c2{2};
    Cent overloadSum{c1 + c2};
    std::cout << c1 << " + " << c2 << " = " << overloadSum << '\n';   // using overloading of << operator
    std::cout << c1 / 2 << '\n';

    (!c2) ? (std::cout << "0 true\n") : (std::cout << "0 false\n");
    (c1==c2) ? (std::cout << "objects equal\n") : (std::cout << "objects not equal\n");

    std::cout << c2++ << '\t' << ++c2 <<'\n';
}

void overloadList() {
    std::vector<int> nums{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    Inventory i1{nums};
    std::cout << i1[4] << '\n';
    int newval{99};
    i1.add_item(newval);
    std::cout << i1[10] << '\n';

    const std::vector<int> mynums{0, 1, 2, 3, 4};
    std::cout << mynums[3] << '\n';

    Inventory craft{};
    craft(1, 1) = 5;   // overload of () op for matrix member variable
    craft(2, 0) = 9;
    craft.view_craft();
}

void printShop(Shop s) {
    std::cout << s;
}

void typecastOverload() {
    Shop store1{3};
    std::cout << store1 << '\n';
    int status{static_cast<int>(store1)};

    BigShop bandq{20};
    printShop(bandq);
}

void copyconstructor() {
    Skeleton human{206};
    Skeleton seb{human};
    std::cout << seb << '\n';

    printSkeleton(4);   // parameter implicit constructor call for object
}

int main(){
    copyconstructor();
    return 0;
}

