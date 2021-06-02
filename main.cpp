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

class Simple {
    int id;
public:
    Simple() = default;

    Simple(int id) {
        this->id = id;  // the this keyword here seperates the member variables and parameters
    }

    int getID() {
        return id;
    }

    void setID(int x) { // a hidden this parameter inside the constuctor holds the object type being used
        id = x; // the this keyword is automatically added and always points to the object being worked on
    }
};

class Chain {
    int value;
public:
    Chain& plus(int val) {
        value += val;
        return *this;   // return this pointer allows for chaining of member functions
    }
    Chain& minus(int val) {
        value -= val;
        return *this;
    }

    int get_val() {
        return value;
    }

};

void callsChain() {
    Chain maths{};
    maths.plus(5).minus(3).plus(10);    // chain calling member functions
    std::cout << maths.get_val() << '\n';
}

// header file
class headerClass { // seperate class definition and implementation, users only need to know how member functions work
    int m_val;
public:
    headerClass(int val);   // define constructors in header file, implement in cpp file

    void set_val(int val);  // implement setters later

    int get_val() const;   // const keyword for member functions before body

    int get_val() {return m_val;}   // overload function for non-const alternative
};
// end of header file

headerClass::headerClass(int val) { // cpp file holds implementation of member functions using scoping operator ::
    set_val(val);
}

void headerClass::set_val(int val) {
    m_val = val;
}

int headerClass::get_val() const {  // const member functions use const keyword in definition and implementation
    return m_val;   // body of getter function obvious to user, preferably store in header file
}

void callconstobject() {
    const headerClass jeremy{456};  // const class object can only call const member functions
    std::cout << jeremy.get_val() << '\n';

    headerClass bill{590};
    std::cout << bill.get_val() << '\n';
}

class StaticGuy {
private:
    static int s_id; // static member variables arent associated with class objects, forward declaration for s_value
    int m_id;
public:
    StaticGuy() : m_id{++s_id} {}

    int get_id() {
        return m_id;
    }

    static int get_total_id();  // static member functions dont have *this pointer, they dont belong to objects

};

int StaticGuy::s_id{0};  // class identifier and scope resolution operator used to specify static member variable

int StaticGuy::get_total_id() {return s_id;}    // static member implementation dont include keyword

void staticmember() {
    StaticGuy object1;
    StaticGuy object2;

    std::cout << object1.get_id() << '\n';
    std::cout << object2.get_id() << '\n';

    std::cout << "number of ID's: " << StaticGuy::get_total_id() << '\n';
}

class AnotherFriend;    // class prototype, allowing friend function forward delcaration to work

class FriendlyClass {
    int value;
public:
    FriendlyClass(int val = 0) : value{val} {}

    int get_val(){return value;}

    friend void resetfunc(FriendlyClass &obj, AnotherFriend &obj2);   // friend keyword,forward declaration for function
};

class AnotherFriend {
    int open_total;
public:
    AnotherFriend(int val = 0) : open_total{val} {}

    int get_val(){return open_total;}

    friend void resetfunc(FriendlyClass &obj, AnotherFriend &obj2);
};

void resetfunc(FriendlyClass &obj, AnotherFriend &obj2){    // friend function able to be friend of many classes
    obj.value = 0;   // able to access private members
    obj2.open_total = 0;
}

void showfriend(){
    FriendlyClass obj1{5};
    AnotherFriend obj2{10};
    resetfunc(obj1, obj2);
    std::cout << obj1.get_val() << " " << obj2.get_val() << '\n';
}

int main(){
    showfriend();
    return 0;
}