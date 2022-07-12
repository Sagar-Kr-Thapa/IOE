#include<iostream>
using namespace std;

template<class T>

class Queue
{
private:
	int front;
	int rear;
	int size;

	T* queue;
public:
	Queue(int s)
	{
		size=s;
		front=-1;
		rear=-1;

		queue=new T[size];
	}
	~Queue(){
		delete queue;
	}

	void enqueue(T a)
	{
		if((front==0&&rear==size-1) || (front==rear+1))
		{
			cout<<"OVERFLOW"<<endl;
			exit(0);
		}
		if(front==-1 && rear==-1)
		{
			front=0;
			rear=0;
		}
		else
		{
			if(rear==size-1)
				rear=0;
			else
				rear++;
		}
		queue[rear]=a;
	}

	T dequeue()
	{
		T r;
		if(front==-1)
		{
			cout<<"Underflow"<<endl;
			exit(0);
		}
		else if(front==rear)
		{
			r= queue[front];
			front=rear=-1;
		}
		else{
			if(front==size-1)
			{
				r=queue[front];
				front=0;
			}
			else
			{
				r=queue[front];
				front++;
			}
		}

		return r;

	}
};

int main()
{
	Queue<int> q(5);
	q.enqueue(1);
	cout << q.dequeue() << endl;
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	q.enqueue(0);

	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	cout << q.dequeue() << endl;

	return 0;
}
