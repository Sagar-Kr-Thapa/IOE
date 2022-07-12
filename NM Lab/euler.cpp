#include <iostream>
#include <cmath>

using namespace std;

float slope(float x, float y)
{
    //return x+y;
    //return ((y-x)/(y+x));
    return (y+exp(x));

}
int main()
{
    float x,y;
    cout << "Enter initial value of x and y:";
    cin >> x >> y;

    float h ;
    cout << "Enter step size h:";
    cin >> h;

    float xf;
    cout << "Enter final value of x:";
    cin >> xf;

    while ( x <= xf) {
        cout << x << ' ' << y <<endl;
        y += h * slope(x,y);
        x += h;
    }

    cout << "The value of y at x = " << xf << " is " << y;

    return 0;
}
