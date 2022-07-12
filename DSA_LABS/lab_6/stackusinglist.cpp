#include <iostream>
using namespace std;

class Stack
{
    struct node
    {
        int data;
        node * next = nullptr;
    };

    node * top = nullptr;

public:
	void push( int x )
	{
		node * newNode = new node;
		newNode->data = x;
        newNode->next = top;

		top = newNode;

		cout<<"Pushed element: " << top->data << endl;
	}

	int pop()
	{
	    if( top == nullptr )
            throw "ERROR: Stack is empty\n";

	    int info = top->data;
	    node * tempNode = top;
	    top = top->next;
	    delete tempNode;

	    return info;
	}
};

int main()
{
    Stack s;

    try
    {
        s.push(1);
        s.push(2);
        s.push(3);
        s.push(4);

        cout << endl << endl;

        cout << "popped element: " << s.pop() << endl;
        cout << "popped element: " << s.pop() << endl;
        cout << "popped element: " << s.pop() << endl;
        cout << "popped element: " << s.pop() << endl;
        cout << "popped element: " << s.pop() << endl;
    }
    catch(const char* msg)
    {
        cerr << msg << endl;
        return -1;
    }

    return 0;
}
