#include <iostream>
#include <cmath>

using namespace std;

float f(float x)
{
    0 return x*sin(x)+cos(x)+5;
    //return cos(x);
}

float trapezoidal(float x0, float xn, float h)
{
    float sum = f(x0)+f(xn);
    float x = x0;
    for( int i=1; ; ++i )
    {
        x = x0+i*h;
        if(x==xn) break;
        sum += 2*f(x);
    }
    sum *= (h/2);
    return sum;
}

float oneby3(float x0, float xn, float h, int n)
{
    if( n%2!=0 )
    {
        cout << "No. of data points is not divisible by 2\n";
        exit(1);
    }
    float sum = f(x0)+f(xn);
    float x = x0;

    for( int i=1; ; i++ )
    {
        x = x0+i*h;
        if(x==xn) break;
        sum += i%2==0? 2*f(x):4*f(x);
    }
    sum *= (h/3);
    return sum;
}

float threeby8(float x0, float xn, float h, int n)
{
    if( n%3!=0 )
    {
        cout << "No. of data points is not divisible by 3\n";
        exit(1);
    }
    float sum = f(x0)+f(xn);
    float x = x0;
    for( int i=1; ; ++i )
    {
        x = x0+i*h;
        if(x==xn) break;
        sum += i%3==0? 2*f(x):3*f(x);
    }
    sum *= 3*(h/8);
    return sum;
}

int main()
{
    int n;
    float x0, xn, h;
    cout << "Enter the endpoints of interval, x0 and xn : ";
    cin >> x0 >> xn;
    
    cout << "Enter number of strips: ";
    cin >> n;
    
    h = (xn-x0)/n;

    cout << "The required integral is\n";
    cout << "Trapezoidal: "<< trapezoidal(x0, xn, h) << endl;
    cout << "1/3 : " << oneby3(x0, xn, h, n) << endl;
    cout << "3/8 : " << threeby8(x0, xn, h, n) << endl;

    return 0;
}