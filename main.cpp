#include <iostream>
#include <string>

using namespace std;

int main()
{
    char response{'y'};
    if (response == 'y' || response == 'Y')
    {
        cout << "correct response" << endl;
    }

    else if (response == 'n' || response == 'N')
    {
        cout << "incorrect response" << endl;
    }

    else
    {
        cout << "invalid input" << endl;
    }

    int value = 1;
    switch (value)
    {
        case '1':
            cout<< "this is a one" << endl;
            break;
        case '2':
            cout<< "this is a two not a one, wrong" << endl;
            break;
        case '4':
            cout<< "this is 4, guess again, wrong" << endl;
            break;
        default:
            cout<< "this is not a one, two or four"<< endl;
            break;
    }

    int i = 2, j = 3;
    cout << (i > j ? i : j) << " is greater" << endl;

    for(int x = 0; x<5; ++x)
    {
        cout << "x is this value:" + x << endl;
    }

    int count = 0;
    while (count<10)
    {
        count +=1;
        cout << "the value of count is:" + count << endl;
    }

    return 0;
}
