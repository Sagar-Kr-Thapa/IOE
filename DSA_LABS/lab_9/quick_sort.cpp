#include <iostream>
#include <algorithm>

#define SIZE 500

using namespace std;

void quickSort( int [] );

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
    quickSort(arr);
    prettyPrint(arr);

    return 0;
}

void quickSort( int arr[], int first, int last)
{
    int lower = first+1;
    int upper = last;

    Swap(arr[first], arr[(first+last)/2]); //bound is chosen as the mid-index of the array
    int bound = arr[first];

    while( lower<=upper )
    {
        while( arr[lower]<bound )
            lower++;
        while( arr[upper]>bound )
            upper--;
        if( lower<upper )
            Swap( arr[lower++], arr[upper--] ); 
        else lower++; //to end the outer loop
    }

    Swap( arr[first], arr[upper] ); //bound gets its final postion
    if( upper+1<last )
        quickSort( arr, upper+1, last );
    if( upper-1>first )
        quickSort( arr, first, upper-1 );
}

void quickSort( int arr[] ) //preparing the array for real quick sort 
{
    int max = 0;
    for( int i=1; i<SIZE; ++i )
    {
        if( arr[i]>arr[max] )
            max = i;
    }
    Swap( arr[max], arr[SIZE-1] ); //max element of the matrix is the dead end for lower variable in original quicksort function
    quickSort( arr, 0, SIZE-2 ); //max element is already on the last position 
}