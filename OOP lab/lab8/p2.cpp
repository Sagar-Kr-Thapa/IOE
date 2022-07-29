#include <iostream>
#include <iomanip>
 using namespace std;

class prettyPrint{
 private:
  int width; 
  int precision;
  char fill;
 public:
  prettyPrint(int w, int p , char f):width(w),precision(p),fill(f){}

  friend ostream& operator<<(ostream&, prettyPrint);
};

ostream& operator<<(ostream& s, prettyPrint p)
{
  s << setw(p.width) << setfill(p.fill) << setprecision(p.precision);
  return s;
}

prettyPrint swpf(int w, int p, char f)
{
  return prettyPrint(w, p, f);
}

int main()
{
  cout << swpf(7, 5, '+') << 3.14159 ;
  cout << endl;
  return 0;
}