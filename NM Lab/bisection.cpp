//to calculate the root of non-linear equations using bisection method

#include <iostream>
#include <cmath>
using namespace std;

inline float f(float x)
{
    //return ( pow(x,3)-3*x-9 );
    //return ( sin(x) + x*cos(x) );
    return ( log(x)-pow(x,-1) );
}

inline int no_root(float a, float b)
{
    return ( f(a)*f(b) > 0 );
}

int main()
{
    float a, b, e, c;

    cout << "Enter initial interval: " << endl;
    cin >> a >> b;

    cout << "Enter tolerable error: ";
    cin >> e;

    int itr = log(abs(b-a)/e)/log(2);
    int counter = 0;

    if(!no_root(a,b))
    {
        do
        {
            c = (a+b)/2;
            if(no_root(c,a))
                a=c;
            else
                b=c;
            counter++;
        }while(fabs(b-a) > e);
    }
    else
    {
        cout << "Root doesn't exist." << endl;
    }

    cout << "The required root is: " << c << endl;
    cout << "Required number of iterations(theoretically): " << itr << endl;
    cout << "Number of iterations in this program: " << counter << endl;


    return 0;
}
