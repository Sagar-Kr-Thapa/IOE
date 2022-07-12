#include <iostream>
#include <cmath>
#include <cstdlib>

#define SIZE 20
using namespace std;

int main()
{
    unsigned n;
    cout << "Enter the order of matrix: ";
    cin >> n;

    float a[SIZE][SIZE];
    cout << "Enter the elements of matrix\n";

    for(int i = 0; i<n; ++i)
    {
        for(int j=0; j< 2*n; ++j)
        {
            if( (j >= n) )
            {
                if( j == i+n )
                    a[i][j] = 1;
                else
                    a[i][j] = 0;
            }
            else
                cin >> a[i][j];
        }
    }

    float ratio;
    for(int j=0; j<n; ++j)
    {
        if(fabs(a[j][j]) < 0.001)
        {
            cout << "Pivot element is zero\n";
            exit(1);
        }
        for(int i=0; i<n; ++i)
        {
            if( i!=j)
            {
                ratio = a[i][j] / a[j][j];
                for(int k=j; k<2*n; ++k)
                    a[i][k] -= ratio * a[j][k];
            }
        }
    }

    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<2*n; ++j)
        {
//            if( j < n)
//            {
//                a[i][j] = fabs((int)a[i][j]/(int)a[i][i]);
//            }
//            else

           // a[i][j] = a[i][j]/a[i][i];
        }
       // cout << endl;

    }

    cout << "Required inverse matrix is\n";
    for(int i=0; i<n; ++i)
    {
       for(int j=n; j<2*n; ++j)
       {
           cout << a[i][j]/a[i][i] << ' ';
       }
       cout << endl;
    }
    return 0;
}
