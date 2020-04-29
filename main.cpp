#include <iostream>
using namespace std;

void passByRed(int &);

int main()
{
    int num = 3;
    int * pNum;     //pointer declared using * operator

    pNum = &num;    //the pointer pNum is assigned to the address for num
    *pNum = 45;     //the value stored at the address under pNum is assigned the value 45, dereference operator

    int num2 = 3;
    int & refNum = num2;    //reference declred with & operator
    refNum = 4;

    cout << num2 << endl;
    cout << refNum << endl;
    cout << &num2 << '\n' << &refNum << endl;


    return 0;
}