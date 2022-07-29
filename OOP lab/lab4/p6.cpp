#include <iostream>
using namespace std;

class Number{
	private:
		unsigned int serial_number;
		static unsigned int counter;
	public:
		//static unsigned int count;
		Number(){
			counter++;
			serial_number=counter;
			cout<<"Object "<<serial_number<<" created."<<endl;
		}

		static unsigned total(){
			return counter; //accessing static data member
		}
};

unsigned int Number::counter; //definition of count

int main(){
	Number n1;
	Number n2;
	Number n3;
	Number n4;

	cout<<"Total no. of objects: "<<Number::total()<<endl; //static member function call
	return 0;
}
