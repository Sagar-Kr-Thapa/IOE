#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

inline float f(float x)
{
    //return (pow(x,2)-4);
    //return (x*sin(x)+cos(x));
    return (log(x)*x);
}

int main()
{
    float x0, x1, x2;
    float err;
    int maxitr;
    int count = 0;

    cout << "Enter initial interval [a,b]: ";
    cin >> x0 >> x1;

    cout << "Enter max. iterations: ";
    cin >> maxitr;
    do
    {
        err = fabs(f(x0)-f(x1));
        if (err < 0.001)
        {
            cout << "Divide by zero\n";
            exit(1);
        }

        x2 = (x0*f(x1) - x1*f(x0))/(f(x1)-f(x0));
        x0 = x1;
        x1 = x2;
        ++count;

        if(count > maxitr)
        {
            cout << "Root not found.\n";
            exit(1);
        }

    }while(fabs(f(x2)) > 0.001);

    cout << "The required root is: " << x2 << endl;

    return 0;
}


































