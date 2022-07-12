#include <iostream>

using namespace std;

int fibonacci( int x, int a = 0, int b = 1 )
{
    if( x == 0 )
        return a;
    if( x == 1 )
        return b;
    
    return fibonacci( x-1, b, a+b );
}

int main()
{
    int n;

    cout << "Enter the term to find: ";
    cin >> n;

    cout << fibonacci(n) << endl;
    
    return 0;
}