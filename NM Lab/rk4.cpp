#include <iostream>
#include <cmath>

using namespace std;

float slope(float x, float y)
{
    //return x+y;
    //return ((y+x)/(y-x));
    return (y+exp(x));

}
int main()
{
    cout << "Enter initial value y and x:";
    float y,x_in;
    cin >> y >> x_in;
    cout << "Enter step size h:";
    float h ;
    cin >> h;
    cout << "Find value of y at ?:";
    float x_f;
    cin >> x_f;
    float x_next = x_in;
    float m1,m2,m3,m4,m;
    while ( x_next - x_f <= 0) {
        m1 = slope(x_next, y);
        m2 = slope(x_next+h/2, y+m1 *h/2);
        m3 = slope(x_next+h/2, y+m2*h/2);
        m4 = slope(x_next+h, y+m3*h);
        m = (m1 + 2*m2 + 2*m3 + m4)/6;
        y += h*m;
        x_next += h;

       cout<<endl<<x_next<<" "<<y;

    }
    cout << "The value of y at x = " << x_f << " is " << y;


}
