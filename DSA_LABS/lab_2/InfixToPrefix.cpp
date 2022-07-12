#include<iostream>
#include<string>
#define SIZE 20
using namespace std;

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

string ReverseString(string input)
{
    for(int i = 0;i<(input.length()/2);i++)
    {
        swap(input[i],input[input.length()-i-1]);
    }
    return input;
}

string OpenToClose(string str)
{
    for(int i = 0;i<str.length();i++)
    {
        if(str[i]=='(')
        {
            str[i]=')';
        }
        else if(str[i]==')')
        {
            str[i]='(';
        }
    } return str;
}

string Convert(Stack s,string str)
{
    string postfix;
	char c;
	if(s.Top()==-1) s.Push('(');
	for(int i = 0;i<=str.length();i++){
	if(i==str.length()) c = ')';
	else c = str[i];
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
	return postfix;
}

int main()
{
string infix,prefix,postfix,reversed_infix,opentoclose;
cout<<"Enter The Infix Expression: "<<endl;
cin>>infix;
Stack s;
reversed_infix = ReverseString(infix);
opentoclose = OpenToClose(reversed_infix);
postfix = Convert(s,opentoclose);
prefix = ReverseString(postfix);
cout<<"The equivalent prefix expression is: "<<prefix;
return 0;
}

