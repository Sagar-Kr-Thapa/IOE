#include <iostream>
#include <cmath>
#include <algorithm>

#define SIZE 1000

using namespace std;

void shellSort( int arr[] );

void prettyPrint( int arr[] )
{
    for( int i=0; i<SIZE; ++i )
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

int main()
{
    int arr[SIZE];
    for ( int i=0; i<SIZE; ++i )
    {
        arr[i] = i+1;
    }

    random_shuffle( arr, arr+SIZE );

    prettyPrint(arr);
    shellSort(arr);
    prettyPrint(arr);

    return 0;
}

void shellSort( int arr[] )
{
    for( int gap=SIZE/2; gap>0; gap/=2 )
    {
        int j=0; 
        for( int marker=gap; marker<SIZE; marker+=1 )
        {
            int temp = arr[marker];
            for( j=marker-gap; j>=0 && arr[j]>temp; j-=gap )
            {
                arr[j+gap] = arr[j];
            }
            arr[j+gap] = temp;
        }
    }
}