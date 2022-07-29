/*Write a class template for queue class. Assume the programmer using the queue won't make mistakes, like exceeding the capacity of the queue, or trying to remove an item when the queue is empty. Define several queues of different data types and insert and remove data from them.*/

#include <iostream>
using namespace std;

const int MAX = 25;

template <class T>
class queue
{
 private:
  T data[MAX];
  int pos;
 public:
  queue()
  {
    pos = 0;
    for(int i = 0; i < MAX; i++)
      data[i] = 0;
  }
  void enqueue( T );
  T dequeue();
};

template <class T>
void queue<T>::enqueue(T var)
{
  data[pos] = var;
  pos++;
}

template <class T>
T queue<T>::dequeue()
{
    T  var = data[0];
    for(int i = 0 ; i < pos; i++)
    {
      data[i] = data[i+1];
      
    }
    pos--;
    return var;
}

int main()
{
  queue<int> data1;
  queue<float> data2;

  //enqueueing integer values to the queue
  for(int i = 0; i < 10; i++)
  {
    data1.enqueue(i);
  }
  //displaying & removing values from the queue
  for(int i = 0; i < 5; i++)
  {
    cout << data1.dequeue() << endl;
  }

  cout.setf(ios::fixed);
  cout.precision(2);
  cout << endl;
  //enqueueing float data to the queue
  for(float i = 1.55; i < 10.55; i++)
  {
    data2.enqueue(i);
  }
  //displaying & removing values from the queue
  for(int i = 0; i < 5; i++)
  {
    cout << data2.dequeue() << endl;
  }

  return 0;
}