#include<iostream>
#define SIZE 20

using namespace std;

class Stack
{
	int arr[SIZE];
	int TOP;
	public:
	Stack()
	{
		TOP = -1;
	}
	void Push(int element)
	{
		if(TOP == SIZE - 1)
		{
			cout<<"Stack Overflow!!"<<endl;
		}
		else
		{
			TOP += 1;
			arr[TOP] = element;
			cout<<"Pushed Element: "<<element<<endl;
		}
	}
	void Pop()
	{
		if(TOP == -1)
		{
			cout<<"Stack Underflow!!"<<endl;
		}
		else
		{
			cout<<"Popped Element: "<<arr[TOP]<<endl;
			TOP-=1;
		}
	}
	int Size()
	{
		return TOP + 1;
	}
	int Peek()
	{
		cout<<arr[TOP]<<endl;
	}
};

int main()
{
	Stack s;
	s.Push(5);
	s.Push(10);
	s.Pop();
	for(int i = 0;i < 5;i++)
	{
		s.Push(i+1);
	}

	for(int i = 0; i<5; i++)
        s.Pop();

	s.Peek();
	return 0;
}
