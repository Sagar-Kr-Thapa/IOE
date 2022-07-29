/*Write any program that demonstrates the use of multiple catch handling, re-throwing an exception, and catching all exception.*/
//this program can only deal with positive integers
#include <iostream>
using namespace std;

class DIVIDE1{};
class DIVIDE2{};

int main()
{
  int a, b;
  int ans;
  try 
  {
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    
    try 
    {
      if(b < 0)
        throw DIVIDE2();
      if(b == 0)
        throw DIVIDE1();
      ans = a/b;
      cout << "a/b = " << ans << endl;
    }
    catch (DIVIDE1)
    {
      cerr << "Indeterminate." << endl;
      //rethrowing exception;
      throw; 
    }
    catch (DIVIDE2)
    {
      cerr << "The program doesn't let you to divide by negative number."<< endl;
      //rethrowing exception
      throw;
    }

  }
  catch (...) 
  {
    cerr << "All exceptions caught.\n";
  }

  return 0;
}