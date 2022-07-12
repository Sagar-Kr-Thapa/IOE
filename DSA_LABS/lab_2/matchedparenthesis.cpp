#include <iostream>
#include <string>
#define SIZE 20

using namespace std;

class Stack{
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

char pairOf(char ch)
{
    if(ch==')')
        return '(';
    else if(ch == '}')
        return '{';
    else
        return '[';

}

int main()
{
string exp;
cout << "Enter an exp: " ;
cin >> exp;

Stack s;
for(int i = 0; i<exp.length(); i++)
{
    if((exp[i] == '(')||(exp[i] == '{')||(exp[i] == '[')) s.Push(exp[i]);
    else if((exp[i] == ')')||(exp[i] == '}')||(exp[i] == ']') && s.Top()!=-1)
        if(s.TopElement() == pairOf(exp[i])) s.Pop();

}
if(s.Top() == -1)
{
    cout << "Balanced parenthesis" << endl;
}
else
    cout << "Unbalanced parenthesis" << endl;
}
