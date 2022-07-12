#include <iostream>
#include <cmath>
#include <cstdlib>

#define SIZE 100

using namespace std;

void gaussJordan(float a[][SIZE], int n)
{
    float ratio;

    for(int j = 0; j<n; j++)
    {
        if( fabs(a[j][j]) < 0.001 )
        {
            cout << "Pivot Element is equal to zero\n";
            exit(1);
        }

        for(int i=0; i<n; i++)
        {
            if(i != j)
            {
                ratio = a[i][j]/a[j][j];
                for(int k=j; k<n+1; k++)
                {
                    a[i][k] = a[i][k] - ratio*a[j][k];
                }
            }
            }
    }

    for(int i=0; i<n; i++)
    {
        a[i][n] /= a[i][i];
    }
}

int main()
{
    int n, d;
    cout << "Enter degree of polynomial: ";
    cin >> d;

    cout << "Enter number of data points: ";
    cin >> n;

    float a[SIZE][SIZE] = {0};
    float x[SIZE] = {0};
    float y[SIZE] = {0};

    cout << "Enter data" << endl;

    for(int k=0; k<n; ++k)
        cin >> x[k] >> y[k];

    for(int i=0; i<=d; ++i)
    {
        for(int j=0; j<=d; ++j)
        {
            for(int k=0; k<n; ++k)
                a[i][j] += pow( x[k], i+j );
        }
    }

    for(int i=0; i<=d; ++i)
    {
        for(int k=0; k<n; ++k)
            a[i][d+1] += pow( x[k], i ) * y[k];
    }

    //solving matrix using Gauss Jordan
    gaussJordan(a, d+1);

    //displaying result
    for(int i=0; i<=d; i++)
    {
        cout << "a" << i << " = " << a[i][d+1] << endl;
    }

    return 0;
}
