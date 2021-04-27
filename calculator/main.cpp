#include "operands.h"
#include <iostream>

double calc(){
    bool repeat{true};

    while (repeat) {
        char op;
        double num1{1.0};
        double num2{1.0};

        do {
            std::cout << "Operator:";
            std::cin >> op;
        } while (op != '+' && op != '-' && op != '*' && op != '/');

        std::cout << "1st number:";
        std::cin >> num1;
        std::cout << "2nd number:";
        std::cin >> num2;

        double out{};

        if (op == '+') {
            out = add(num1, num2);
        } else if (op == '-') {
            out = subtract(num1, num2);
        } else if (op == '*') {
            out = multiply(num1, num2);
        } else if (op == '/') {
            out = divide(num1, num2);
        }

        std::cout << out << '\n';
        std::cout << "repeat? 1/0:";
        std::cin >> repeat;
    }

    return 0;
}

int main(){
    calc();
    return 0;
}