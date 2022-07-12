#include<iostream>
#include<string>
#define SIZE 20
using namespace std;

string postfix;
string infix;

class Stack
{
	char arr[SIZE];
        int TOP;
        public:
        Stack()
        {
                TOP = -1;
        }
        void Push(char element)
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
                        TOP--;
                }
        }
        int Size()
        {
                return TOP + 1;
        }
        char TopElement()
        {
               return arr[TOP];
        }
	int Top()
	{
		return TOP;
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

int CheckPriority(char ch)
{
	if((ch == '+')||(ch == '-')) return 3;
	else if((ch == '*')||(ch == '/')) return 2;
	else if(ch == '^') return 1;
	else return 4;
}

void Convert(Stack s)
{

}

int main()
{
cout<<"Enter The Infix Expression"<<endl;
cin>>infix;
Stack s;
//Convert(s);

	char c;
	if(s.Top()==-1) s.Push('(');
	for(int i = 0;i<=infix.length();i++){
	if(i==infix.length()) c = ')';
	else c = infix[i];
	if(CheckOperator(c))
	{
		if(CheckOperator(s.TopElement())){
		if(CheckPriority(c)>=CheckPriority(s.TopElement()))
		{
			postfix+=s.TopElement();
			s.Pop();
		}
		}
		s.Push(c);
	}
	else if(c == '(')
	{
		s.Push(c);
	}
	else if(c == ')')
	{
		while(s.TopElement() != '(')
		{
			postfix+=s.TopElement();
			s.Pop();
		}
		s.Pop();
	}
	else
	{
		postfix+=c;
	}

	}
	cout<<"Top:"<<s.Top()<<endl;
	cout<<"Result:"<<postfix<<endl;

return 0;
}

