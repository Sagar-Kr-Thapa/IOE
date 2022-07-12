#include <iostream>

using namespace std;

unsigned factorial( unsigned x, unsigned a = 1 )
{
    if ( x == 0 )
        return a;

    return factorial( x-1, x*a );
}

int main()
{
    unsigned n;

    cout << "Enter a number: ";
    cin >> n;

    cout << "Factorial of " << n << " is : " << factorial(n);

    return 0;
}
