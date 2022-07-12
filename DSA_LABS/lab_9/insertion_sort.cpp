#include <iostream>
#include <cmath>
#include <algorithm>

#define SIZE 1000

using namespace std;

void insertionSort( int arr[] );

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
    insertionSort(arr);
    prettyPrint(arr);

    return 0;
}

void insertionSort( int arr[] )
{
    int j=0;
    for( int marker=1; marker<SIZE; ++marker ) 
    {
        int temp = arr[marker];
        for( j=marker-1; j>=0 && arr[j]>temp; --j )
        {
            arr[j+1] = arr[j];
        }
        arr[j+1] = temp;
    }
}