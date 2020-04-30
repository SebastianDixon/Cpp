#include <iostream>
using namespace std;


int main()
{
    int * pInt = new int;
    double * pDouble = new double;

    *pInt = 3;
    *pDouble = 4.2;

    delete pInt;
    delete pDouble;

    
    return 0;
}
