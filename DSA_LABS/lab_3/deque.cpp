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
	void i_rear(T a)
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
	
	void i_front(T a)
	{
		if((front==0 && rear == size-1) || (front==rear+1))
		{
			cout<<"OVERFLOW"<<endl;
			exit(0);
		}
		if (front==-1 && rear==-1)
		{
			front=0;
			rear=0;
		}
		else
		{
			if(front==0)
				front=size-1;
			else
				front=front-1;
		}
		queue[front]=a;
	}
	
	void d_front()
	{
		if(front==-1)
		{
			cout<<"UNDERFLOW"<<endl;
			exit(0);
		}
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}
		else
		{
			if(front==size-1)
				front=0;
			else
				front++;
		}
	}
	void d_rear()
	{
		if(rear==-1)
		{
			cout<<"Underflow"<<endl;
		}
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}
		else
		{
			if(rear==0)
				rear=size-1;
			
			else 
				rear=rear-1;
		}
	}
};
int main()
{
	Queue<int> q(8);
	q.i_rear(1);
	q.i_rear(3);
	q.i_rear(5);
	q.i_rear(7);
	
	q.d_rear();
	q.d_rear();
	q.d_rear();
	
	q.i_front(2);
	q.i_front(4);
	q.i_front(6);
	q.i_front(8);
	
	q.d_rear();
	
	return 0;
}
