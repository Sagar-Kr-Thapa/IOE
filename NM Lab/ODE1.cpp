//using RK4 method
#include <iostream>
#include <cmath>

#define SIZE 20

using namespace std;

float f(float x, float y, float z)
{
    return 3*x+y-z;
    //return 0.5*(-x-(pow(y,3)/3)+y);
}

float g(float x, float y, float z)
{
    return 2*x-y+z;
    //return 2*y-3*z;
}
int main()
{
    //float val_x[SIZE], val_y[SIZE], val_z[SIZE];
    int i = 0;

    //initial values of x,y,z
    float x0, y, z;
    //step size
    float h;
    //final value of x
    float x;

    cout << "Enter initial values of x, y and z: ";
    cin >> x0 >> y >> z;
    cout << "Enter step-size h:";
    cin >> h;
    cout << "We need to find values of y and z at x = ";
    cin >> x;

    float xn = x0;
    float k1,k2,k3,k4,k;
    float l1,l2,l3,l4,l;

    while ( abs(xn-x) >= 0.001 ) 
    {
        k1 = h*f(xn, y, z);
        l1 = h*g(xn, y, z);

        k2 = h*f(xn+h/2, y+k1/2, z+l1/2);
        l2 = h*g(xn+h/2, y+k1/2, z+l1/2);

        k3 = h*f(xn+h/2, y+k2/2, z+l2/2);
        l3 = h*g(xn+h/2, y+k2/2, z+l2/2);

        k4 = h*f(xn+h, y+k3, z+l3);
        l4 = h*g(xn+h, y+k3, z+l3);

        k = (k1 + 2*k2 + 2*k3 + k4)/6;
        l = (l1 + 2*l2 + 2*l3 + l4)/6;

        /*
        cout << xn << ' ' << y << ' ' << z << endl;   
        val_x[i] = xn;
        val_y[i] = y;
        val_z[i++] = z;
        // */

        y += k;
        z += l;

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
    cout << endl << "Z: ";
    for(int j=0; j<i; ++j)
    {
        cout << val_z[j] << ' ';
    }

    cout << endl;

    */

    cout << "At x = " << xn << " ,values are y = " << y << " and z = " << z;

    return 0;
}
