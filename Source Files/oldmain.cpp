#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class tempStat
{
public:
    double x,y ;

    tempStat(double X=0.0 , double Y=0.0) : x(X), y(Y)
    {}

    void binWrite(ostream & os)
    {
        os.write((char*)&x, sizeof(double));
        os.write((char*)&y, sizeof(double));
    }

    void binRead(istream & is)
    {
        is.read((char*)&x, sizeof(double));
        is.read((char*)&y, sizeof(double));
    }


};

ostream & operator << (ostream & os, const tempStat & b)
{
    os << "["<< b.x << b.y << "]";
    return os;
}

istream & operator >> (istream & is, const tempStat & b)
{
    is >> b.x >> b.y;
    return is;
}

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
    ofstream ofile("file2.bin", ios_base::binary);
    if(ofile.is_open())
    {
        tempStat(4.7, 5.6).binWrite(ofile);
        tempStat(48.7, 45.6).binWrite(ofile);

        ofile.close();
    }
    else
    {
        cout << "not open" << endl;
    }
    
    ifstream ifile("file2.bin", ios_base::binary);
    if(ifile.is_open())
    {
        while (!ifile.eof())
        {
            tempStat readObject;
        readObject.binRead(ifile);

        cout << "temp stats are: " << readObject << endl;
        }

        ifile.close();
    }
    else
    {
        cout << "didnt work / open " << endl;
    }
    

    return 0;
}
