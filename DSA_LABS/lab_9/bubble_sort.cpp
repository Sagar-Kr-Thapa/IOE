#include <iostream>
#include <algorithm>

#define SIZE 10

using namespace std;

void bubbleSort( int [] );

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
    bubbleSort(arr);
    prettyPrint(arr);

    return 0;
}

void bubbleSort( int arr[] )
{
    for( int i=0; i<SIZE-1; ++i )
    {
        for( int j=SIZE-1; j>i; --j )
        {
            if( arr[j]<arr[j-1] )
            {
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }
}