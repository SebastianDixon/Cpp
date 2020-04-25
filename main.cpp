#include <iostream>
#include <string>

using namespace std;

int sum(int x, int y) //first sum function
{
    int val;
    val = x + y;
    cout << val << endl;
    return x + y;
}

int sum(int x, int y, int z) //second sum function
{
    return x + y + z;
}


int main()
{
    return sum(3, 4);
}
            