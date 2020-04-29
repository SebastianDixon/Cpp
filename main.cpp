#include <iostream>
using namespace std;

void passByRef(int &);  //function prototype shown to be given a reference argument in its parameters

int main()
{
    int num = 3;
    cout << "num starts as: " << num << endl;

    passByRef(num);

    cout << "num value referenced after function increment: " << num << endl;
    
    return num;
}

void passByRef(int & refNum)
{
    cout << "reference value passed as: " << refNum << endl;

    ++refNum;

    cout << "reference value incremented: " << refNum << endl;
}