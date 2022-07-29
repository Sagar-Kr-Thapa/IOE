#include <iostream>
#include <string>
using namespace std;

class recordMngr;

class person{
protected:
	int age;
	string name;
public:
	void getInfo(){
		cout << "Enter name: ";
		cin >> name;
		cout << "Enter age: ";
		cin >> age;
	}

	char* getAddress(){ return (char *)this;}
	void printAddr(){
		cout << this;
	}
};

class student: public person{
private:
	string schlName;
	int stuId;
public:
	void getInfo(){
		person::getInfo();
		cout << "Enter School's Name: ";
		cin >> schlName;
		cout << "Enter Student ID: ";
		cin >> stuId;
	}
	friend class recordMngr;
};

class employee:public person{
private:
	string depart;
	float salary;
public:
	void getInfo(){
		person::getInfo();
		cout << "Enter Department: ";
		cin >> depart;
		cout << "Enter Salary: ";
		cin >> salary;
	}
	friend class recordMngr;
};

class recordMngr: public person{
public:
	void getInfo(){
		person::getInfo();
	}

	static void setStuInfo(student& r1){r1.getInfo();}
	static void setEmpInfo(employee& r1){r1.getInfo();}

	static void changeStuInfo(student& r1){r1.getInfo();}
	static void changeEmpInfo(employee& r1){r1.getInfo();}

	static void delRecord(student&);
	static void delRecord(employee&);
};
void recordMngr::delRecord(student& r1){
	r1.age = 0;
	r1.name = "";
	r1.schlName = "";
	r1.stuId = 0;
}
void recordMngr::delRecord(employee& r1){
	r1.age = 0;
	r1.name = "";
	r1.depart = "";
	r1.salary = 0;
}

int main(){
	person p1, p2;
	student s1, s2;
	employee e1, e2;

	cout << "For class \'person\': " << endl;
	p1.getInfo();
	p2.getInfo();
	cout << "Size of \'person\' class= " << sizeof(p1) << endl
	<< "Difference of addresses of two persons: "; p2.printAddr();
	cout << " - "; p1.printAddr(); cout << " = " << p2.getAddress()-p1.getAddress() << endl;;

	cout << endl << "For class \'student\': " << endl;
	recordMngr::setStuInfo(s1); 
	s2.getInfo();
	cout << "Size of \'student\' class= " << sizeof(s1) << endl
	<< "Difference of addresses of two students: "; s2.printAddr(); 
	cout << " - "; s1.printAddr(); cout << " = " << s2.getAddress()-s1.getAddress() << endl;

	cout << endl << "For class \'employee\': " << endl;
	recordMngr::setEmpInfo(e1); 
	e2.getInfo();
	cout << "Size of \'employee\' class= " << sizeof(e1) << endl
	<< "Difference of addresses of two employees: "; e2.printAddr();
	cout << " - "; e1.printAddr(); cout << " = " << e2.getAddress()-e1.getAddress() << endl;

	return 0;
}