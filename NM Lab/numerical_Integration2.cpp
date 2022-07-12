#include <iostream>
#include <cmath>

#define MAX 100
float y[MAX];

using namespace std;

float trapezoidal(float x0, float xn, float h, int n)
{
    float sum = y[0]+y[n];
    float x = x0;
    for( int i=1; i<n ; ++i )
    {
        sum += 2*y[i];
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
    float sum = y[0]+y[n];
    float x = x0;

    for( int i=1; i<n ;i++ )
    {
        sum += i%2==0? 2*y[i]:4*y[i];
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
    float sum = y[0]+y[n];
    float x = x0;
    for( int i=1; i<n ; ++i )
    {
        sum += i%3==0? 2*y[i]:3*y[i];
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

    cout << "Enter data-points, y[i]\n";
    for( int i=0; i<=n; ++i)
        cin >> y[i];
    
    h = (xn-x0)/n;

    cout << "The required integral is\n";
    cout << "Trapezoidal: "<< trapezoidal(x0, xn, h, n) << endl;
    cout << "1/3 : " << oneby3(x0, xn, h, n) << endl;
    cout << "3/8 : " << threeby8(x0, xn, h, n) << endl;

    return 0;
}