#include <iostream>
#include <string>

using namespace std;

int avg(int nums[], int length)
{
    double average{};
    int total{};
    for (int count{}; count < length; ++count)
    {
        total += nums[count];
    }
    
    average = total / length;
    cout << "Array mean = " << average << endl;
    return average;
}

int main()
{
    auto i{0};
    auto count{0};
    int temp[i] = {};
 
    cout << "how many items?: ";
    cin >> i;

    while (count < i)
    {
        double val{0};
        cout << "add an item: ";

        cin >> val;
        temp[count] = val;

        ++count;
    }

    avg(temp, i);
    
    return 0;
} 