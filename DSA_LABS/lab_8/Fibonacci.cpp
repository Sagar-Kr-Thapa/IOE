#include <iostream>

using namespace std;

unsigned fibonacci(unsigned x)
{
    if( x <= 1 )
        return x;
    
    return fibonacci(x-1) + fibonacci(x-2);
}

int main()
{
    unsigned n;

    cout << "Enter the term to find: ";
    cin >> n;

    cout << fibonacci(n) << endl;

    return 0;
}