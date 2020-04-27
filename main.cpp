#include <iostream>
#include <string>

using namespace std;



class Player
{
public:
    string name;
    int health{};
    int damage{};

    void print()
    {
        cout << name << " " << health<< " " << damage<< " " << '\n';
    }

    void calc(int i, int j)
    {
        auto result {i + j};

        cout << result << endl;
    }
};  


class Rectangle
{
    private:
        int width{};
        int height{};
    
    public:

        void get_width() {cout<< width;}

        void get_height() {cout<< height;}

};

class Base{
    int x;

    public:
        void getA(int a) {a = x;}
        int getX() {return x;}

};


int main()
{
    Player p3 {"Seb", 50, 100};

    p3.print();
    p3.calc(3,4);

    Rectangle small;
    small.get_height();
    
    
    return 0;

}
            