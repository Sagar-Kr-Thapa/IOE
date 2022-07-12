#include <iostream>

using namespace std;

unsigned factorial(unsigned x)
{
    if ( x == 0 )
        return 1;
    
    return ( x*factorial(x-1) );
}

int main()
{
    unsigned n;

    cout << "Enter a number: ";
    cin >> n;

    cout << "Factorial of " << n << " is : " << factorial(n);

    return 0;
}