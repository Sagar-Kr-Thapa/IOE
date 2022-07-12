#include <iostream>
#include <algorithm>

#define SIZE 500

using namespace std;

void mergeSort( int [], int=0, int=SIZE-1 );

template<class T>
void Swap(T& a, T& b)
{
    T temp = b;
    b = a;
    a = temp;
}

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
    mergeSort(arr);
    prettyPrint(arr);

    return 0;
}

void merge( int arr[], int first, int last ) 
{
    int mid = (first+last)/2;
    int size = last-first+1;

    int i=0,j=first,k=mid+1;
    int aux[size];

    while( j<=mid && k<=last ) //when both subarrays of arr contain elements
    {
        if( arr[j] < arr[k] )
        {
            aux[i++] = arr[j++];
        }
        else 
        {
            aux[i++] = arr[k++];
        }
    }

    //load rest of the elements of arr to the auxiliary space
    while( j<=mid )
    {
        aux[i++] = arr[j++];
    }
    while( k<=last )
    {
        aux[i++] = arr[k++];
    }

    for( int l=0; l<size; ++l )
    {
        arr[first++] = aux[l];
    }
}

void mergeSort( int arr[], int first, int last )
{
    if( first<last )
    {
        int mid = (first+last)/2;
        mergeSort( arr, first, mid );
        mergeSort( arr, mid+1, last );
        merge( arr, first, last );
    }
}
