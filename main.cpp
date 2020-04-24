#include <iostream>
#include <string>

using namespace std;

int main()
{
     for (int i = 0; i < 10; ++i)
     {
         cout << "the name of the monkey is:" << i << endl;
     }

     float x = 5.0;
     while (x >0)
     {
         --x;
     }

     string response;
     cout << "repsonse is: " <<  '\n' << "Quit" << '\n' << "More" << endl;
     cin >> response;

     while (response != "Quit")
     {
         cout << "Looping again" << endl;
         cout << '\n';

         cout << "repsonse is: " <<  '\n' << "Quit" << '\n' << "More" << endl;
         cin >> response;
     }

     string ask;
     do
     {
         cout << "enter :" << '\n' << "More or Quit" << endl;
         cin >> ask;

     } while (ask != "Quit");


     return 0;
}
