#include <iostream>
#include <string>

using namespace std;

int main()
{
    int base;
    int power;

    cout << "What is your base? :" << endl;
    cin >> base;
    int output = base;

    cout << "What is your exponent? :" << endl;
    cin >> power;

    for(int count = power -1; count > 0; --count)
    {
        output *= base;
        cout << output << endl;
    }
    cout << "Answer is: " << output << endl;
    
    return 0;
}
