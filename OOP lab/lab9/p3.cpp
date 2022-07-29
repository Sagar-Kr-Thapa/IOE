/*Modify the stack class given in the previous lab to add the exception when user tries to add item while the stack is full and when user tries to add item while the stack is empty. Throw exception in both of the cases and handle these exceptions.*/

#include<iostream>
#include<string>
using namespace std; 

const int MAX = 2;

template<class T>
class Stack
{
 private:
  T st[MAX];
  int top;
 public:
  Stack();
  void push(T var);
  T pop();

  class error{};
};

template<class T>
Stack<T>::Stack()
{
  top = -1;
}

template<class T>
void Stack<T>::push(T var)
{
  try
  {
    if(top >= (MAX-1))
    {
      top = MAX - 1;
      throw  error();
    }
    else
    {
      st[++top] = var;
    }
  }
  catch(error)
  {
    cerr << "[ERROR]: Stack is full.\n"; 
  }
}

template<class T>
T Stack<T>::pop()
{
  try
  {
    if (top < 0)
    {
      throw error();
    }
    else 
    {
      return st[top--];
    }
  }
  catch(error)
  {
    cerr << "[ERROR]: Stack is empty. [LAST_VALUE] = ";
    return st[0];
  }
}

int main()
{
  Stack<float> s1;

  s1.push(111.1F);
  s1.push(222.2F);
  s1.push(333.3F);

  cout<<"1 : "<<s1.pop()<<endl;
  cout<<"2 : "<<s1.pop()<<endl;
  cout<<"3 : "<<s1.pop()<<endl;

  cout << endl;
  Stack<long> s2;

  s2.push(123123123L);
  s2.push(234234234L);
  s2.push(345345345L);    

  cout<<"1 : "<<s2.pop()<<endl;
  cout<<"2 : "<<s2.pop()<<endl;
  cout<<"3 : "<<s2.pop()<<endl;    

  return 0;
}