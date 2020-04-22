#include <iostream>
#include <string>

using namespace std;

int main()
{
    struct coffee
    {
        string name;
        int strength;
        double price;
    };
    coffee cocoa = {"Cocoa truffle", 10, 0.47};

    coffee vanilla;
    vanilla.name = "vanilla eclair";
    vanilla.strength = 9;
    vanilla.price = 0.47;

    union aUnion
    {
        int intValue;
        long longValue;
        double doubleValue;
    };
    aUnion myUnion;

    myUnion.intValue = 3;
    //cout << myUnion.intValue << endl;
    myUnion.doubleValue = 4.5;
    //cout << myUnion.doubleValue << endl;
    //cout << myUnion.intValue; cout << endl;

    enum day {sunday, monday, tuesday, wednesday, thursday, friday, saturday};

    day noWork {saturday};

    cout<< noWork << endl;
    return 0;
}
