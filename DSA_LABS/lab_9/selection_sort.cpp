#include <iostream>
#include <algorithm>

#define SIZE 10

using namespace std;

void selectionSort( int [] );

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
    selectionSort(arr);
    prettyPrint(arr);

    return 0;
}

void selectionSort( int arr[] )
{
    for( int j=SIZE-1; j>0; --j ) 
    {
        int key = 0;
        for( int i=1; i<=j; ++i) 
        {
            if( arr[key]<arr[i] )
                key = i;
        }
        int temp = arr[j];
        arr[j] = arr[key];
        arr[key] = temp;
    }
}