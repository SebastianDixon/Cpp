#include <iostream>
using namespace std;

int main()
{
    int num = 3;
    int * pNum = &num;
    *pNum = 45;


    return 0;
}