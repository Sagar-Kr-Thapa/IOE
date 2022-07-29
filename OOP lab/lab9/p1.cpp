/*Create a function called sum ( ) that returns the sum of the elements of an array. Make this function into a template so it will work with any numerical type. Write a main ( ) program that applies this function to data of various type.*/

#include <iostream>
using namespace std;

template < typename T>
T sum(T arr[],int n)
{
  T s= 0;
  for(int i = 0 ; i < n; i++)
  {
    s+=arr[i];
  }
  return s;
}
int main()
{
  int integer[] = {1, 2, 3, 4, 5};
  float fraction[] = {1.5, 2.5, 3.5, 4.5, 5.5};
  double dArr[] = {11111111.11, 22222222.22, 33333333.33, 44444444.44};

  cout.setf(ios::fixed);
  cout.precision(2);
  cout << sum(integer, 5) << endl;
  cout << sum(fraction, 5) << endl;
  cout << sum(dArr, 4) << endl;
  return 0;
}