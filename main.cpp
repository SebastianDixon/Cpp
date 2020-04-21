#include <iostream>

int main()
{
    int a{2};
    a = 3.2;
    a = 2.9;
    a = -1;

    unsigned int b{1};
    b = -1;

    double c{9};
    c = 2.7;
    c = 0.3;

    bool flag{true};
    flag = false;
    flag = 2;
    flag = 0;

    const int j{ 1 };
    int const k{ 2 };

    int myInt{12};
    long myLong = long(myInt);

    char ch;
    int i{65};
    float f{6.5};
    double dbl;

    ch = static_cast<char>(i);
    dbl = static_cast<float>(f);

    int x{1};
    int y = 3 / 2;

    auto z = 3 / 2;
    auto w = 3.0 / 2;

    return 0;
}
