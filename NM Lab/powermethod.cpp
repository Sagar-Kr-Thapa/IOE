#include <iostream>
#include <cmath>
#include <cstdlib>

#define SIZE 20

using namespace std;

float getMax(float A[], int n)
{
    float Max = A[0];
    for(int i=1; i<n; ++i)
    {
        if(fabs(Max) < fabs(A[i]))
            Max = A[i];
    }

    return Max;
}

int main()
{
    int n;
    int count = 0;
    float err = 0.001;
    float A[SIZE][SIZE];
    float X[SIZE];
    float Z[SIZE] = {0};
    float Y[SIZE] = {0};
    float lambda = 0;
    float D[SIZE]= {0};
    float Dmax = 0;

    cout << "Enter the order of matrix: ";
    cin >> n;

    cout << "Enter the elements of matrix\n";
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
            cin >> A[i][j];
    }

    cout << "Enter initial eigen vector\n";
    for(int i=0; i<n; ++i)
        cin >> X[i];

    do
    {
        for(int i=0; i<n; ++i)
        {
            float sum = 0;
            for(int j=0; j<n; ++j)
            {
                sum += A[i][j]*X[j];
            }

            Z[i]=sum;
        }

        lambda = getMax(Z,n);

        for(int i=0; i<n; ++i)
        {
            Y[i] = Z[i]/lambda;
            D[i] = fabs(Y[i]-X[i]);
            X[i] = Y[i];
        }

        Dmax = getMax(D,n);

        ++count;
        if( count > 10000)
        {
            cerr << "Values not found\n";
            break;
        }
    }while(Dmax > err);

    cout << "Dominant Eigen value: " << lambda << endl;
    cout << "The corresponding Eigen vector is\n";

    for(int i=0; i<n; ++i)
        cout << Y[i] << endl;

    return 0;
}
