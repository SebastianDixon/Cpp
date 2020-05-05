#include <iostream>
#include <string>

using namespace std;

namespace Microsoft
    {
        namespace Geometry
        {
            const double PI = 3.14159;
    
            double Area(double radius)
            {
                return PI*(radius*radius);
            }
        }
        
    }

using namespace Microsoft;


int main()
{
    double val = 5;
    double area = Geometry::Area(val);

    return 0;
}
