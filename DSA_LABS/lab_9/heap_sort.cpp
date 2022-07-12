#include <iostream>
#include <algorithm>

#define SIZE 10

using namespace std;

void heapSort( int [] );

template<class T>
void Swap(T& a, T& b)
{
    T temp = b;
    b = a;
    a = temp;
}

template<class T>
void moveDown (T data[], int first, int last)
{
    int largest = 2*first + 1;

    while (largest <= last)
    {
        if (largest < last && data[largest] < data[largest+1]) 
            largest++; 

        if (data[first] < data[largest])
        {   
            Swap(data[first],data[largest]); 
            first = largest; 
            largest = 2*first+1;
        }
        else largest = last+1; 
    } 
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
    heapSort(arr);
    prettyPrint(arr);

    return 0;
}

void heapSort( int arr[] )
{   
    for( int i=SIZE/2-1; i>=0; --i )
        moveDown(arr, i, SIZE-1 );
    
    for( int i=SIZE-1; i>=1; --i )
    {
        Swap( arr[0],arr[i] ); 
        moveDown(arr, 0, i-1); 
    }
}