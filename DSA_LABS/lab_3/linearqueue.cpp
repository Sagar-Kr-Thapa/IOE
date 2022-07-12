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
		if(rear==size-1)
			cout<<"Overflow"<<endl;
		else if(front==-1 && rear==-1)
		{
			front=rear=0;
			queue[rear]=a;
		}
		else
			queue[++rear]=a;
	}

	T dequeue()
	{
		T r;
		if(front==-1 && rear==-1)
		{
			cout<<"Underflow"<<endl;
			exit(0);
		}else if(front==rear)
		{
			r= queue[front];
			front=rear=-1;
		}
		else{
			r= queue[front];
			front++;
		}

		return r;

	}
};

int main()
{
	Queue<int> q(5);
	q.enqueue(1);
	q.dequeue();
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	q.enqueue(6);

	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;

	return 0;

}
