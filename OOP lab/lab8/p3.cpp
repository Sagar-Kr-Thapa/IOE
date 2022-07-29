#include <iostream>
using namespace std;

class Complex
{
private:
	float real;
	float img;
public:
	Complex():real(0), img(0){}
	Complex(float r, float i):real(r), img(i){}

	friend istream& operator >> (istream& s, Complex& c);
	friend ostream& operator << (ostream& s, Complex& c);
	
};

ostream& operator << (ostream& s, Complex& c)
{
	s << c.real << " + i(" << c.img << ")" << flush;
	return s;
}

istream& operator >> (istream& s, Complex& c)
{
	s>> c.real >> c.img;
	return s;
}

int main(){
	Complex c1;
	cout << "Enter a complex number: ";
	cin >> c1;

	cout << "The entered number is: " << c1 << endl;
	return 0;
}