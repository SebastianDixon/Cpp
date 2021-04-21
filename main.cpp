#include <iostream> // < > around iostream indicates we did not create this
#include <string>   // for std::string and std::getline
#include <cmath>    // for std::pow and std::abs
#include "constants.h"
#include "circle.h"
#define BOB_NAME    // this is a macro pre processor directive
//using namespace std, is discouraged as it introduces namespace errors

int g_x{1};
// this global variable has file scope, and has external linkage by default
// global variables are 0 initialised by default
static int g_y{2};
// this global variable is static, meaning it can only be accessed inside this file
// this is known as having internal linkage
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

int isBoolean(){
    bool b1{};      // default value false
    bool b2{true};
    std::cout << "input your boolean"; std::cin >> b1;
    std::cout << b1 << '\n';
    // boolean inputs are 1 or 0 by default, not true or false
    return 0;
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
    // a scaling function using std::max has been made to ensure appropriate values of epsilon given parameters a and b
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
        num++;
    }
    // block indicated with { } around multiple statements where one is accepted

    int orange{5};
    {
        std::cout << orange << '\n';    // outer block orange value
        int orange{7};  // this nested variable shadows the outer block orange value
        std::cout << orange << '\n';    // nested block orange value
        orange++;   // evaluates the nested orange value
        std::cout << orange << '\n';
    }
    std::cout << orange << '\n' << '\n';    // outer block orange value

    int banana{3};
    {
        std::cout << banana << '\n';    // outer block banana value
        banana++;   // evaluates outer block banana value
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

int main(){     // execution starts at the top of the main function
    globalvars();
    return 0;       // return 0 or EXIT_SUCCESS if the program ran normally, return EXIT_FAILURE if not
}

int divide(int x, int y){
    return x / y;
    // this function is defined after call, however the function prototype allows it to be known to main()
}

