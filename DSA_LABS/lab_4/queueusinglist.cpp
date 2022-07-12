#include <iostream>
using namespace std;

class Queue
{
    struct node
    {
        int data;
        node * next = nullptr;
    };

    node * Front = nullptr;
    node * Rear = nullptr;

public:
	void enqueue( int x )
	{
		node * newNode = new node;
		newNode->data = x;

		if( Front == nullptr )
            Front = Rear = newNode;
        else
        {
            Rear->next = newNode;
            Rear = newNode;
        }

		cout<<"Enqueued element: " << Rear->data << endl;
	}

	int dequeue()
	{
	    if( Front == nullptr )
            throw "ERROR: Queue is empty\n";

	    int info = Front->data;
	    node * tempNode = Front;
	    Front = Front->next;
	    delete tempNode;

	    return info;
	}
};

int main()
{
    Queue q;

    try
    {
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);
        q.enqueue(4);

        cout << endl << endl;

        cout << "dequeued element: " << q.dequeue() << endl;
        cout << "dequeued element: " << q.dequeue() << endl;
        cout << "dequeued element: " << q.dequeue() << endl;
        cout << "dequeued element: " << q.dequeue() << endl;
        cout << "dequeued element: " << q.dequeue() << endl;
    }
    catch(const char* msg)
    {
        cerr << msg << endl;
        return -1;
    }

    return 0;
}

