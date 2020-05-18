#include <iostream>
#include <string>
using namespace std;

class point
{
    public:
    int x,y;

};


std::istream & operator >> (std::istream & is, point & p)
{
    is >> p.x >> p.y;
    return is;
}

int main()
{
    string s;
    cout << "what is your string? : ";
    cin >> s;
    cout << s << " is your string" << endl;

    point p1;
    cout << "enter the x then y value for your object: ";
    cin >> p1.x >> p1.y;
    cout << p1.x << endl;
    cout << p1.y << endl;

    return 0;
}
