#include <iostream>

int main()
{
    int array[10];
    int array2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int array3[10] = {1, 2, 3, 4};

    int num = array3[3];

    char String[7] = {'s', 't', 'r', 'i', 'n', 'g', '\0'};
    char notString[6] = {'s', 't', 'r', 'i', 'n', 'g'};

    char aString[] = "string";
    char anotherOne[] = "notastring";

    std::cout <<aString;
    std::cout <<String;


    return 0;
}
