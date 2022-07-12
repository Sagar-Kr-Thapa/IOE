#include<iostream>
#include<string>
#define SIZE 20
using namespace std;

string postfix;

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
                        cout<<"Pushed Element: "<<element-'0'<<endl;
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
                        cout<<"Popped Element: "<<arr[TOP] - '0'<<endl;
                        TOP--;
                }
        }
        int Size()
        {
                return TOP + 1;
        }
        int TopElement()
        {
               return arr[TOP];
        }
};

bool CheckOperator(char ch)
{
        if((ch == '*')||(ch == '+')||(ch == '-')||(ch == '/')||(ch == '^'))
        {
                return true;
        }
        else return false;
}


void Evaluate(Stack s)
{

}


int main()
{
cout<<"Enter The Postfix Expression: "<<endl;
cin>>postfix;
Stack s;
//Evaluate(s);
        char c;
	float result;
        for(int i = 0;i<postfix.length();i++){
        c = postfix[i];
        if(CheckOperator(c))
        {
		int a = s.TopElement()-'0';
		s.Pop();
		int b = s.TopElement()-'0';
		s.Pop();
		switch(c)
		{
		case '+':
			result = a+b;
			break;
		case '-':
			result = b-a;
			break;
		case '*':
			result = b*a;
			break;
		case '/':
			result = b/a;
			break;
		case '^':
		{
			result = b^a;
			break;
		}
		default:
		{
			break;
		}
		break;
		}
		char temp = result + '0';
		s.Push(temp);
        }
        else
        {
		s.Push(c);
        }
	}
	cout<<"The Result of this expression is : "<<s.TopElement()-'0'<<endl;
return 0;
}

