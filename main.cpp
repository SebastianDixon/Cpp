#include <iostream>
#include <vector>
#include <array>

class DateClass{    // similar to struct, blueprint for objects
    // private members can be only be accessed by other members, preventing misuse
    // encapusulation occurs where member variables are private, only member functions known to user
private:
    std::array<int,3> date{};
public: // class members are private by default, public keyword overwrites this

    DateClass() = default;  // default constructor passed if no arguments given in class object creation

    DateClass(std::array<int, 3>& array){   // contructor with parameter for initialisation
        date = array;
    }

    void set_date(int d = 1, int m = 1, int y = 2000){  // public members can be accessed by anyone, setter function
        date[0] = d;    // set() can access private member day, given it is a member of the same class
        date[1] = m;
        date[2] = y;
    }

    void read_date(){
        std::cout << date[0] << "/" << date[1] << "/" << date[2] << '\n';
    }

    int get_day(){ // getter function, return by value or const reference
        return date[0]; // returning by value
    }

    void copy(const DateClass &d){  // access function
        date = d.date;
    }
};

class Stock{
private:
    const double m_open;
    double m_close;
    DateClass dayofprice;
public:
    Stock(): m_open{0}, m_close{0}, dayofprice{} {
    }    // default constructor with member initialisation list

    Stock(double open, double close, std::array<int, 3> &date)   // non default constructor
        : m_open{open}, m_close{close}, dayofprice{date} {
    }

    Stock(std::array<int, 3> &date) : Stock{0, 0, date} {
    }   // prevent overlapping constructor by delegating a defined contructor

    ~Stock(){
    } // destructor

    void read_stock(){
        std::cout << "open:$" << m_open << " close:$" << m_close << '\n';
        dayofprice.read_date();
    }
};

void objectcreation(){
    DateClass bday{};    // member object initialisation
    bday.set_date(22, 7, 2002);
    bday.read_date();   // the member function takes the class object passed to it

    DateClass invitationDate{};
    invitationDate.copy(bday);

    DateClass misc{};   // default constructor parameters assigned

    std::array<int, 3> currentdate{12, 2, 2020};
    DateClass today{currentdate};
    today.read_date();

    Stock AAPL{};
    AAPL.read_stock();

    std::array<int, 3> currentday{12, 3, 2012};
    Stock MSFT{35, 14, currentday};
    MSFT.read_stock();
}

class Calc{
public:
    Calc() = default;

    using datatype = int;   // a local alias namespace can be used, faster change of data type later
    std::vector<datatype> op_history{};

    datatype add(datatype x, datatype y){
        datatype result{x + y};
        op_history.push_back(result);
        return result;
    }
};


int main(){
    objectcreation();
    return 0;
}