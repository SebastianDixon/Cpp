#include <iostream>
#include <string>

using namespace std;

int main()
{
    char choice;
    cout << "input your value (y, Y, n, N): " << endl;
    cin >> choice;

    switch (choice)
    {
        case 'y':
            cout << "You chose y or Y" << endl;
            break;
        case 'Y' :
            cout << "You chose y or Y" << endl;
            break;
        case 'n':
            cout << "You chose n or N" << endl;
            break;
        case 'N':
            cout << "You chose n or N" << endl;
            break;
        default:
            cout << "You didn't choose a valid option" << endl;
            break;
    }

}
