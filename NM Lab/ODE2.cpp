//using RK4 method
#include <iostream>
#include <cmath>

#define SIZE 20

using namespace std;

float f(float x, float y, float z)
{
    return z;
}

float g(float x, float y, float z)
{
    return x+2*y+z;
    //return sin(x)-4*y-3*z;
    //return (z-8*pow(x,3)*pow(y,3))/x;
}

int main()
{
    float val_x[SIZE], val_y[SIZE], val_z[SIZE];
    int i = 0;

    //initial values of x,y,z
    float x0, y, z;
    //step size
    float h;
    //final value of x
    float x;

    cout << "Enter initial values of x, y and y' : ";
    cin >> x0 >> y >> z;
    cout << "Enter step-size h:";
    cin >> h;
    cout << "We need to find values of y and y' at x = ";
    cin >> x;

    float xn = x0;
    float m1,m2,m3,m4,m;
    float k1,k2,k3,k4,k;

    while ( abs(xn-x) >= 0.001 ) 
    {
        m1 = f(xn, y, z);
        k1 = g(xn, y, z);

        m2 = f(xn+h/2, y+m1*h/2, z+k1*h/2);
        k2 = g(xn+h/2, y+m1*h/2, z+k1*h/2);

        m3 = f(xn+h/2, y+m2*h/2, z+k2*h/2);
        k3 = g(xn+h/2, y+m2*h/2, z+k2*h/2);

        m4 = f(xn+h, y+m3*h, z+k3*h);
        k4 = g(xn+h, y+m3*h, z+k3*h);

        m = (m1 + 2*m2 + 2*m3 + m4)/6;
        k = (k1 + 2*k2 + 2*k3 + k4)/6;

        /*
        cout << xn << ' ' << y << ' ' << z << endl;   
        val_x[i] = xn;
        val_y[i] = y;
        val_z[i++] = z;
        // */

        y += h*m;
        z += h*k;

        xn += h;

    }

    /*

    val_x[i] = xn;
    val_y[i] = y;
    val_z[i++] = z;

    cout << endl << "X: ";
    for(int j=0; j<i; ++j)
    {
        cout << val_x[j] << ' ';
    }
    cout << endl << "Y: ";
    for(int j=0; j<i; ++j)
    {
        cout << val_y[j] << ' ';
    }
    cout << endl << "Y': ";
    for(int j=0; j<i; ++j)
    {
        cout << val_z[j] << ' ';
    }
    
    cout << endl;

    */

    cout << "At x = " << xn << " ,values are y = " << y << " and y' = " << z;

    return 0;
}
