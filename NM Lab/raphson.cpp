//to calculate the root of non-linear equations using Newton-Raphson Method

#include <iostream>
#include <cmath>

using namespace std;

inline float f(float x)
{
    //return ( x*sin(x) + cos(x) );
    //return ( pow(x,3)-3*x-9 );
    return ( x*log(x) );
}

inline float g(float x)
{
    //return ( x*cos(x) );
   // return ( 3*pow(x,2)-3 );
    return ( log(x) + 1 );
}

int main()
{
    float x0, x1, err, e;

    cout << "Enter initial approximation: ";
    cin >> x0;
    cout << "Enter tolerable error: ";
    cin >> e;

    do
    {
        if(fabs(g(x0)) > 0.0000001)
        {
            x1 = x0 - (f(x0)/g(x0));
            err = abs(x1 - x0);
            x0 = x1;
        }
        else
        {
            cout << "Unable to determine root" << endl;
            return -1;
        }

    }while( err > e );

    cout << "Required root is: " << x0 << endl;
    return 0;
}
