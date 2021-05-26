#include <iostream>
#include <vector>

class DateClass{    // similar to struct, blueprint for objects, OOP style
public:
    int day{};    // member variables
    int month{};
    int year{};

    void printDate(){   // member functions which are normally common operations for the class data
        std::cout << day << "/" << month << "/" << year << '\n';
    }

    void set(int d, int m, int y){
        day = d;
        month = m;
        year = y;
    }
};

void objectcreation(){
    DateClass bday{};    // member object initialisation
    bday.set(22, 7, 2002);
    bday.printDate();   // the member function takes the class object passed to it
    bday.day = 5;   // public member variables are able to be changed outside of the class member functions
}

class Calc{
public:
    using datatype = int;   // a local alias namespace can be used, faster change of data type later

    std::vector<datatype> op_history{};

    datatype add(datatype x, datatype y){
        datatype result{x + y};
        op_history.push_back(result);
        return result;
    }
};

void addnums(){
    Calc operation{};
    operation.add(5, 6);
    operation.add(3, 9);

    for (Calc::datatype iterator : operation.op_history) {
        std::cout << iterator << " ";
    }
}

int main(){
    objectcreation();
    return 0;
}