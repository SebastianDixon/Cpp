#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void fileWrite()
{
    ofstream ofile;

    ofile.open("file1.txt");
    if(ofile.is_open())
    {
        ofile << "Line 1" << endl;
        ofile << "Line 2" << endl << "alksdjhfalkfhkfhl" << endl;
        ofile << "Line 4" << endl;
        ofile.close();
    }
    else
    {
        cout << "couldnt open file" << endl;
    }
}

void fileRead()
{
    ifstream ifile;
    ifile.open("file1.txt");
    if(ifile.is_open())
    {
        string line;
        while(getline(ifile, line))
        {
            cout << line << endl;
        }
        ifile.close();
    }
    else
    {
        cout << "couldnt read from file" << endl;
    }
}

int main()
{
    fileWrite();
    fileRead();

    return 0;
}
