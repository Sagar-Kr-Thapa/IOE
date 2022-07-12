#include <iostream>
#include <cmath>
//#include <cstdlib>

using namespace std;

int main()
{
    unsigned int n;
    cout << "Enter number of equations: ";
    cin >> n;

    float a[n][n+1];
    cout << "Enter elements of matrix\n";

    for(int i=0; i < n; i++)
    {
        for(int j=0; j<n+1; j++)
        {
            cin >> a[i][j];
        }
    }

    float ratio;

    for(int j = 0; j< n-1; j++)
    {
        if( a[j][j] == 0)
        {
            cout << "Pivot Element is equal to zero\n";
            exit(1);
        }

        for(int i=j+1; i<n; i++)
        {
                ratio = a[i][j]/a[j][j];
                for(int k=j; k<n+1; k++)
                {
                    a[i][k] = a[i][k] - ratio*a[j][k];
                }
            }
    }

    cout << endl << endl;

//INCOMPLETE INCOMPLETE INCOMPLETE !!!!!
    float x[n];
    //float sum = 0;
    int i = 0;
    x[n-1] = a[n-1][n] / a[n-1][n-1];

    for( i=n-2; i>=0; i--)
    {
        //sum = 0;
        x[i] = a[i][n];
        for(int j = i+1; j < n ; j++)
        {
            x[i] -= a[i][j]*x[j];
        }

        x[i] /= a[i][i];

    }

    for(int i=0; i<n; i++)
        cout << "x" << i+1 << " = " << x[i] << endl;
    return 0;
}
