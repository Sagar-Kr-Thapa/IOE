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
    cout << "Enter elements of augmented matrix\n";

    for(int i=0; i < n; i++)
    {
        for(int j=0; j<n+1; j++)
        {
            cin >> a[i][j];
        }
    }

    float ratio;

    for(int j = 0; j<n; j++)
    {
        if( a[j][j] == 0)
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

    cout << endl << endl;

    for(int i=0; i<n; i++)
    {
        cout << "x" << i << " = " << a[i][n]/a[i][i] << endl;
    }

    return 0;
}
