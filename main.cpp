#include <iostream>
#include <string>

using namespace std;


int pow(int base, int power)
{
    int output = base;

    if (power < 0)
    {
        cout << "Positive exponent? :" << endl;
        cin >> power;
    }
    else if (power == 0)
    {
        cout << "Answer is: 1" << endl;
        return 1;
    }

    for(int count = power -1; count > 0; --count)
    {
    output *= base;
    }
    cout << "Answer is: " << output << endl;

    return output;
}


int sinCalc(double opp, double hyp)
{
    double sin;

    if (opp == 0 || opp < 0) 
    {
        cout << "Positive opposite side value? :" << endl;
        cin >> opp;
    }

    else if (hyp == 0 || hyp < 0) 
    {
        cout << "Positive hypotenuse value? :" << endl;
        cin >> hyp;
    }

    sin = opp / hyp;
    cout << "Sin value is: " << sin << endl;
    return sin;
}

int main()
{
    pow( 5,10 );
    sinCalc (1.5, 9);

    return 0;
}
            