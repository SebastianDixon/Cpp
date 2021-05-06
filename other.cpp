//
// Created by SebDixon on 21/04/2021.
//

#include <iostream> // < > around iostream indicates we did not create this
#include <string>   // for std::string and std::getline
#include <cmath>    // for std::pow and std::abs
#include "constants.h"
#include "circle.h"
#include <ctime> // for std::time()
#include <cstdlib>  // for std::rand() and std::srand()
#include <cassert>  // for assert()
#define BOB_NAME    // this is a macro pre processor directive
//using namespace std, is discouraged as it introduces namespace errors

int g_x{1};
// this global variable has file scope, and has external linkage by default
// global variables are 0 initialised by default
static int g_y{2};
// this global variable is static, meaning it can only be accessed inside this file
// this called having internal linkage
constexpr int g_z{};    // const and constexpr global variables have internal linkage by default

extern constexpr int g_num{};   // constant global variables can be given external linkage using extern keyword

extern int g_value;     // forward declaration for global variable in other.cpp

int divide(int x, int y);   // forward declaration function prototype

void preprocessor(){
#ifdef BOB_NAME     // BOB_NAME is defined, therefore the conditional is satisfied
    std::cout << "Bob" << '\n';
#endif
#ifndef BOB_NAME    // if not defined
    std::cout << "Not Bob" << '\n';
#endif
}

bool isBoolean(){
    bool b1{};      // default value false
    bool b2{true};
    std::cout << "input your boolean"; std::cin >> b1;
    std::cout << b1 << '\n';
    // boolean inputs are 1 or 0 by default, not true or false
    return b1;
}

int stringz(){
    std::string name{};     // string initialisation using {}
    std::cout << "full name:";
    std::getline(std::cin >> std::ws, name);
    // std::ws is an input manipulator which tells std::cin to ignore whitespace
    auto nameLength = name.length();    //.length() is from #include <string> and is a member function
    std::cout << name << " has "<< nameLength << " characters\n";

    return 0;
}

double circleArea(double x){
    double area = constants::pi * (x * x);
    return area;
}

void changeType(){
    int num1 {7};
    int num2 {3};
    std::cout << "int/int " << num1 / num2 << '\n';
    std::cout << "double/int " << static_cast<double>(num1) / num2 << '\n';
    std::cout << "int/double " << num1 / static_cast<double>(num2) << '\n';
    std::cout << "double/double " << static_cast<double>(num1) / static_cast<double>(num2) << '\n';
    // this shows that if either operand is of double type, the output is double type, not integer
}

void maths(){
    std::cout << "5%3= " << 5 % 3 << '\n';
    std::cout << "5^2= " << std::pow(5.0, 2.0) << '\n'; // std::pow uses double type parameters
}

void plusplus(){
    int x{ 5 };
    int y = x++;    // y assigned value of x value 5, x incremented to 6, postfix operator
    std::cout << y << x <<'\n';

    int z{ 5 };
    int p = ++z;    // p assigned z incremented value of 6, prefix operator (preferred)
    std::cout << p << z << '\n';
}

void ops(){
    int x{5}, y{8};
    std::cout << (++x, ++y) << '\n';
    std::cout << x <<'\n';
    // process left term, then right term, the right term is returned (used in for loops)

    int c{1}, d{2};
    int z{};
    z = ((d > c) ? x : y);  // if statement is true; evaluate x, else evaluate y
    std::cout << "z = "<< z << '\n';
    // use parentheses to ensure correct operation given low precedence of ? operator
}

bool almostequal(double a, double b, double epsilon);

bool compareFloat(){
    double num1{}, num2{};
    num1 = (10-9.99);
    num2 = (1-0.99);
    // floating point numbers are rounded differently, although they are both close to 0.01
    // != and == operators are not for floating point numbers

    double e{1e-8};
    bool result = almostequal(num1, num2, e);
    std::cout << "num1 and num2 are close: "<< std::boolalpha << result << '\n';
    return result;
}

bool almostequal(double a, double b, double epsilon){
    return (std::abs(a - b) <= (std::max(std::abs(a), std::abs(b)) * epsilon));
    // std::abs finds the absolute difference between parameters
    // epsilon is a parameter of value 1e-8 used for determining equality between float values
    // a scaling function using std::max has been made to ensure appropriate values of epsilon given a and b
}

bool logicalweather(){
    bool rain{};
    bool sun{};
    std::cout << "raining? 1/0:"; std::cin >> rain;
    std::cout << "sunny? 1/0:"; std::cin >> sun;
    bool monkeywedding = rain && sun;   // AND operator &&
    std::cout << "monkey wedding?:" << std::boolalpha << monkeywedding << '\n';
    bool notmonkeywed = !(rain && sun);
    std::cout << "not monkey wedding?:" << notmonkeywed << '\n';

    int choice{};
    std::cout << "choose a number:"; std::cin >> choice;
    if (choice == 0 || choice == 1){
        std::cout << "you chose 1 or 0" << '\n';
    } else std::cout << "you chose other than 1 or 0" << '\n';

    int x{1}, y{2};
    if (x == 2 && y++ == 3){
        // do something
    }   // c++ uses short circuit evaluation where by if the first term evaluates to false in an AND statement,
    // the second term is never evaluated, therefore here y++ is never processed
    return monkeywedding;
}

void blockTime(){
    int num{};  // this local variable has block scope
    std::cout << "num:"; std::cin >> num;
    if (num != 0){  // conditional statement example of block
        std::cout << "non 0 value" << '\n';
        if (num == 1){
            std::cout << "num = 1" << '\n'; // multiple nesting allowed
        }
    } else{
        std::cout << "0 value";
        ++num;
    }
    // block indicated with { } around multiple statements where one is accepted

    int orange{5};
    {
        std::cout << orange << '\n';    // outer block orange value
        int orange{7};  // this nested variable shadows the outer block orange value
        std::cout << orange << '\n';    // nested block orange value
        ++orange;   // evaluates the nested orange value
        std::cout << orange << '\n';
    }
    std::cout << orange << '\n' << '\n';    // outer block orange value

    int banana{3};
    {
        std::cout << banana << '\n';    // outer block banana value
        ++banana;   // evaluates outer block banana value
        std::cout << banana << '\n';
    }
    std::cout << banana << '\n';    // outer block banana value still evaluated to nested block value

}

void someCircles(){
    namespace curvyobject = circle::sphere; // curvyobject now refers to the nested namespace for ease of code

    double c1 = 5.5;
    double circlearea = circle::area(c1);
    std::cout << circlearea << '\n';

    double s1 = 1.5;
    double spherearea = circle::sphere::spherearea(s1);
    std::cout << spherearea << '\n';

    double s2 = 1.7;
    double spherearea2 = curvyobject::spherearea(s2);
    std::cout << spherearea2 << '\n';
}

void globalvars(){
    int g_x{10};    // global variable shadowed by local with same name
    std::cout << g_x << '\n';   // local variable value
    std::cout << ::g_x << '\n';   // global variable identified using global namespace scope operator
}

static int add(int x, int y){
    return x + y;   // static applied to functions gives internal linkage, called internal functions
}

int localstatics(){
    static int s_num{1};  // static initialiser only executes once
    ++s_num;  // increment operation evaluated each call of function
    std::cout << s_num << '\n';
    return s_num;
}   // static keyword, num not destroyed here, unlike automatic duration

int generateID(){
    static int s_itemID{0};
    return s_itemID++;  // this example function assigns unique ID's for items in a game
}

void typedefsStuff(){
    typedef double decimalnumber_t; // a typedef assigns "decimalnumber" double representation
    double x{};
    decimalnumber_t y{};    // variables x and y are of the same type

    using wholenumber_t = int;  // alternative method for assigning typedefs called type alliases
    // typedefs are useful for code maintenance, changing the type of many items at once
    // they can also be shorthand for long complex types
}

auto typeinference(int x){  // auto type is not for parameters, use function templates instead
    ++x;
    auto decimalnum{5.9};   // initialised with double type, therefore takes double type
    std::cout << typeid(decimalnum).name() << '\n'; // showing decimalnum takes double type
    return x;   // return type is int, therefore function takes int type via inference
}

void implicit_conv(){
    // coercion is the compiler implicitly converting types
    long l{5};  // this long takes integer, numeric widening
    double d{0.12f};    // this double takes long, numeric promotion
    double p{5};    // this double takes integer, numeric conversion
    int x{20000};   // overflowing range of a type causes unexpected outputs
    // if an int takes double value, numeric narrowing, losing accuracy
}

void explicit_conv(){
    int y{5};
    int x{11};
    float f(x / y); // defined integer variables will produce integer output, even though float specified
    float f_cast(float(x) / y); // now x has been C cast to float type, producing float output
    float f_s_cast(static_cast<float>(x) / y);  // static cast occurs at compile time, less error prone
    std::cout << f << " " << f_cast << " " << f_s_cast << '\n';

    int i{10};
    i = static_cast<int>(i / 2.5);  // here static cast is used to avoid compiler complain about loss of data
}

int conditional(int size){
    using namespace std;
    switch (size) {
        // dont initialize variables in switch statement blocks, delcaration and assignment is ok
        case 1:
            cout << "too small";
            break;  // break exits the block
        case 2:
            cout << "just right";
            return size;
        case 3:
            cout << "too big";
            break;
        default:    // else type conditional, optional
            cout << "not a size";
            break;
    }   // compared to if statements, switch only evaluates the expression once, more efficent
    return 0;
}

bool fallthrough(char c){
    switch (c) {
        case 'a':   // no break or return creates a fallthrough to the next case
            [[fallthrough]];    // added to show intentional fallthrough and prevent warnings
        case 'e':
            // all statements in a switch have equal scope
        case 'i':
        {
            // use a block for initialisation
            int x{5};
        }
        case 'o':
        case 'u':
            return true;    // if either of these cases are satisfied, they fallthough into return statement
        default:
            return false;
    }
}

int unconditional(){
    // both goto statement and statement label must appear in the same function
    // the pair have function scope
    double x{};
    tryAgain:   // the statement label
    std::cout << "enter positive num:"; std::cin >> x;
    if (x < 0.0){
        goto tryAgain;  // the goto statement
    }
    std::cout << "The square root of " << x << " is " << sqrt(x) << '\n';

    bool dog{};
    std::cout << "own a dog? 1/0:"; std::cin >> dog;
    if (dog){
        std::cout << "dogs rule :)" << '\n';
        goto end;   // avoid goto, as it makes flow confusing
    }
    std::cout << "must be a cat person" << '\n';
    end:    // example of jumping forward
    return 0;
}

int loops(){
    int x{1};   // use signed loop variables
    while (x <= 10){    // conditional loop which repeats from top of block
        std::cout << x << '\n';
        ++x;
    }

    int y{};
    do {
        std::cout << "integer > 5:"; std::cin >> y;
    }   // do while loops ensure at least one run, only repeating if necessary
    while (y <= 5);

    return 0;
}

int pow(int base, int exponent)
{
    int total{ 1 };
    for (int i{}; i < exponent; ++i)    // (init-statement; condition; end-expression), i has loop scope
        total *= base;

    return total;
}

void floop(){
    for (int x{0}, y{10}; x <= 10; ++x, --y) {   // two iterable variables can be used
        if ((x % 2) == 0){
            continue;   // moves to the next iteration of loop
        }
        std::cout << x << ' ' << y << '\n';
    }
}

int testfunc(){
    int failed{};
    if (pow(2, 4) != 16) failed += 1;
    if (pow(3, 7) != 2187) failed += 1;
    // if (fallthrough('a') != true) failed += 1;
    // if (fallthrough('q') != false) failed += 1;

    std::cout << failed;
    return failed;  // put function tests inside function for quickly checking functionality
}

double squareroot(double x){
    assert(x > 0 && "cant square root 0 or negatives");  // assertion is true, if false, exit program
    double val = sqrt(x);
    std::cout << "square root = " << val;
    return val;
}

enum Colour{    // enumeration is user defined data type, capitalised name
    colour_red, // enumerators define all the possible values this type can hold
    colour_green,   // each value has a default integer assignment 0, 1, 2, ...
    colour_blue,    // value can be assigned to enumerations overriding default
};

enum Flower{
    flower_tulip,
    flower_rose,
    flower_daisy,
};

void compareEnum(){
    Flower f1{flower_tulip};
    Colour c1{colour_red};
    // std::cout << (f1 == c1 ? "these are equal\n" : "these are not equal\n");
    // comparison gives warning, different data types, but is possible since evaluated as integer
}

void seeColour(Colour c){   // function for returning intended string representation for enum type
    switch (c){
        case colour_blue:
            std::cout << "Blue\n";
            break;
        case colour_red:
            std::cout << "Red\n";
            break;
        case colour_green:
            std::cout << "Green\n";
            break;
        default:
            std::cout << "unknown\n";
    }
}

void colours(){
    Colour carpaint = colour_red;   // assignment and initialisation of enum type variable
    Colour wallpaint{colour_green};
    int sky_colour{colour_blue};    // enum holds integer type, so can be assigned to integer variables
    std::cout << carpaint << " " << wallpaint << " " << sky_colour << '\n';
    // this outputs integer values of each enum value

    int inputColour{};
    std::cout << "input your colour (0, 1, 2):";
    std::cin >> inputColour;
    auto switch_colour{ static_cast<Colour>(inputColour) };    // workaround for inputting enum type with std::cin
    seeColour(switch_colour);

}

void toCompareEnumOrNot(){
    enum class Car{ // enum classes are strongly typed and strongly scoped, scoped enumeration
        ferrari,    // ferrari is inside the scope of Car
        ford,   // enum values no longer use enum name prefix
        fiat,
    };

    Car firstcar{Car::ford};    // ford not directly accessible, scope must be specified for enum class
    std::cout << static_cast<int>(firstcar);
    // enum class values not implicitly converted to integer, therefore static_cast needed

}

struct Person{ // a structure is an aggregate data type
    std::string name{}; // members of the struct
    int age{};
    bool sex{}; // true = M, false = F
    double heightMeters{0.0}; // default values can be given to non static members
};

bool isAdult(Person x){
    if (x.age >= 18){
        return true;
    } else {
        return false;
    }
}

void outputPerson(Person p1){
    std::cout << "name:" << p1.name << '\n';
    std::cout << "age:" << p1.age << '\n';
    std::cout << "sex:" << p1.sex << '\n';
    std::cout << "height:" << p1.heightMeters << '\n' << '\n';
}

void People(){
    Person fred{};   // declaration of fred using type Student
    fred.name = "Frederick";    // assignment of member values using . operator
    fred.sex = true;
    fred.heightMeters = 1.75;

    std::cout << "how old is " << fred.name << ":";
    std::cin >> fred.age;
    bool alcohol = isAdult(fred);   // struct passed as parameter
    std::cout << "alcohol license:" << alcohol << '\n';

    Person girl{"girl", 10, false, 1.5};    // initialiser list
    Person guy{girl};   // copy struct values into another
    guy.name = "guy";
    guy.sex = true;

    outputPerson(girl);
    outputPerson(guy);
}

struct coord{   // struct delcarations dont take any memory, often kept in header files
    double latitude{};
    double longitude{};
};

struct home{
    coord location{};   // coord struct inside home struct
    std::string postcode{};
};

void inputHome(){
    home eton{{1.0, -2.0}, "postcode"}; // initialisation of nested struct
    std::cout << eton.location.longitude << '\n';   // scoping for struct member inside struct
}

coord uselessfunction(coord x){
    ++x.latitude;
    ++x.longitude;
    std::cout << x.latitude << '\n' << x.longitude << '\n';
    return x;   // return multiple values using struct method
}

void locationInput(){
    coord trafalgarSquare{51.5080, 0.1281};
    uselessfunction(trafalgarSquare);
}

void random(int total){
    std::srand(static_cast<unsigned int>(std::time(nullptr)));  // system clock seed
    // this avoids output of same random numbers with fixed seed
    // std::time returns seconds since midnight
    // null pointer parameter prevents storing in object
    for (int x{}; x < total; ++x){
        std::cout << std::rand() << '\n';
    }
}

int randomRange(int min, int max){
    std::srand(static_cast<unsigned int>(std::time(nullptr)));  // system clock seed

    static constexpr double fraction { 1.0 / (RAND_MAX + 1.0) };  // static used for efficiency
    // rand_max is the maximum random value in c++
    int output = min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
    std::cout << output << '\n';
    return output;
}

int get_max(int array[5]){
    int prev{};
    int max{};
    for (int x{}; x < 5; ++x){
        max = ((array[x] > prev) ? array[x] : prev);
        prev = array[x];
    }
    return max;
}

int get_min(int array[5]){
    int prev{};
    int min{};
    for (int x{}; x < 5; ++x){
        min = ((array[x] < prev) ? array[x] : prev);
        prev = array[x];
    }
    return min;
}

int sort_array(int array[5]){
    return 0;
}

void arrayWork(){
    Person class1[10]{};    // struct data type for array
    class1[0] = {"pupil1", 20, true, 1.8};    // first pupil in class1 array
    std::cout << class1[0].age << '\n'; // scoping for struct members indexed in array


    const int arrayexample[2]{1, 2};    // const array must use direct intialisation, assignment not possible
    int unsureofsize[]{1, 2, 3, 4, 5};  // array implicitly takes fixed allocation of 5, even though no given

    enum students{
        bob,
        stan,
        ed,
        maxstudent,
    };
    int examscores[students::maxstudent]{};
    examscores[bob] = 90;   // using indexing enum conversion to int for readable code
    // for enum class use static_cast<int> to index

    int testScores[5]{54, 62, 61, 88, 45};
    std::cout << "max:"<< get_max(testScores) << '\n';
    std::cout << "min:"<< get_min(testScores) << '\n';

    int arrayArray [][6]{  // only the left size specification can be ommited for multi dimensional arrays
            {1, 2, 3, 4, 5, 6}, // each line is a row indexed from 0
            {2, 4, 6, 8, 10, 12},
            {1, 3, 5, 7, 9, 11}
    };
    for (int i = 0; i < 3; ++i) {
        std::cout << '\n';
        for (int j = 0; j < 6; ++j) {
            std::cout << arrayArray[i][j] << ",";   // row-wise output
        }
    }
    std::cout << '\n';

    for (int i = 0; i < 6; ++i) {
        std::cout << '\n';
        for (int j = 0; j < 3; ++j) {
            std::cout << arrayArray[j][i] << ",";   // column-wise output
        }
    }
}

int c_string(){
    char name[]{"sebastian"};   // C style string, array of characters, ends with /0 inserted
    const int length{sizeof(name) / sizeof(name[0])}; // use instead if not C++17 capable
    std::cout << length << '\n';    // returns 10 given additional /0 character

    for (int i = 0; i < length; ++i) {
        std::cout << name[i] << ',';
    }
    std::cout << '\n';

    char yourname[255]; // allocate more size than thought for inputs given uncertainty
    const int l2{sizeof(yourname) / sizeof(yourname[0])}; // use instead if not C++17 capable
    std::cout << "input your name:";
    std::cin.getline(name, l2); // prevents overflow from inputs greater than variable size
    // use std::string when possible instead of c style strings
    return 0;
}

int main(){     // execution starts at the top of the main function
    c_string();
    return 0;
    // if the program ran normally return 0 or EXIT_SUCCESS, else return EXIT_FAILURE
}

int divide(int x, int y){
    return x / y;
    // this function is defined after call, however the function prototype allows it to be known to main()
}


