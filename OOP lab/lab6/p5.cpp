#include <iostream>
using namespace std;

class complexSub;

class complex{
protected:
	int num = 100;
public:
	float real;
	float img;

	void getData(){
		cout << "Enter a complex number [eg. a + ib] in the format: a b : ";
		cin >> real >> img;
	}

	void showData(){
		cout << real << " + " << "(" << img << ")" << "j";
	}
};

class complexAdd: public complex{
public:
	void getData(){
		complex::getData();
	}
	complex operator + (const complex c1){
		complex temp;
		temp.real = real + c1.real;
		temp.img = img + c1.img;
		return temp;
	}
	friend class complexSub;
};

class complexSub{
public: 
	static void getData(complexAdd& c1){
		cout << c1.num << endl;
		//c1.getData();
	}
	static complex minus(complexAdd c1, complex c2){
		complex temp;
		temp.real = c1.real - c2.real;
		temp.img = c1.img - c2.img;
		return temp;
	}
};

int main(){
	complex num1;
	num1.getData();
	complexAdd num2;
	num2.getData();

	cout << endl;
	num2.showData(); cout << " + "; num1.showData();
	cout << " = "; (num2 + num1).showData();

	cout << endl;
	num2.showData(); cout << " - "; num1.showData();
	cout << " = "; complexSub::minus(num2, num1).showData();

	cout << endl;
	return 0;
}