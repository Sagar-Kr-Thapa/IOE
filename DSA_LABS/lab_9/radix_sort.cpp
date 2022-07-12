#include <iostream>
#include <algorithm>

#define SIZE 1000

using namespace std;

void radixSort( int [] );

void prettyPrint( int arr[] )
{
    for( int i=0; i<SIZE; ++i )
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

template<class T>
class Queue
{
private:
	struct Node
	{
		T data;
		struct Node *next;
	};
	struct Node *front=NULL;
	struct Node *rear=NULL;
public:
	Queue(){};
    bool empty(){return front==NULL; }

	void enqueue(int value)
	{
		struct Node *newNode= new Node;

		newNode->data=value;
		newNode->next=NULL;

		if (front==NULL)
			front=rear=newNode;
		else{
			rear->next= newNode;
			rear= newNode;
		}
	}

	T dequeue()
	{
		if(front==NULL)
			cout<<"Underflow"<<endl;
		else
		{
			struct Node *temp= front;
            T data = temp->data; 
			front=front->next;
			delete temp;

            return data;
		}
	}
};

int main()
{
    int arr[SIZE];
    for ( int i=0; i<SIZE; ++i )
    {
        arr[i] = i+1;
    }

    random_shuffle( arr, arr+SIZE );

    prettyPrint(arr);
    radixSort(arr);
    prettyPrint(arr);

    return 0;
}

void radixSort( int arr[] )
{
    const int RADIX = 10; //in decimal system there are 10 digits, also max digits in 4-byte int is 10
    int factor = 1;
    Queue<int> q[RADIX];

    for( int j=0; j<RADIX; ++j, factor*=RADIX )
    {
        for( int i=0; i<SIZE; ++i )
        {
            int pos = arr[i];
            pos /= factor; //extract digits till d from MSB's place ; d is the digit of concern
            pos %= RADIX;    //extract d 
            q[pos].enqueue(arr[i]);
        }
        for( int i=0, k=0; i<RADIX; ++i )
        {
            while( !q[i].empty() )
                arr[k++] = q[i].dequeue();
            
        }
    }

}