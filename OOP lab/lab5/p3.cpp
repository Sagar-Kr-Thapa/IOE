#include <iostream>
using namespace std;

class Integer{
private:
	int num;
public:
	Integer(int n=0):num(n){}
	
	bool operator == (Integer n){
		if(num == n.num) return true;
		else return false;
	}
	bool operator < (Integer n){
		if(num < n.num) return true;
		else return false;
	}
	bool operator > (Integer n){
		if(num > n.num) return true;
		else return false;
	}
	bool operator <= (Integer n){
		if(num <= n.num) return true;
		else return false;
	}
	bool operator >= (Integer n){
		if(num >= n.num) return true;
		else return false;
	}
	bool operator != (Integer n){
		if(num != n.num) return true;
		else return false;
	}
};


int main(){
	
	int num1, num2;
	cout << "Enter an integer: ";
	cin >> num1;
	Integer n1(num1);

	cout << "Enter another integer: ";
	cin >> num2;
	Integer n2(num2);

	if (n1 == n2) cout << num1 << " and " << num2 << " are equal" << endl;
	if (n1 < n2) cout << num1 << " is less than " << num2 << endl;
	if (n1 > n2) cout << num1 << " is greater than " << num2 << endl;
	if (n1 <= n2) cout << num1 << " is less than or equal to " << num2 << endl;
	if (n1 >= n2) cout << num1 << " is greater than or equal to " << num2 << endl;
	if (n1 != n2) cout << num1 << " is not equal to " << num2 << endl;

	return 0;
}
