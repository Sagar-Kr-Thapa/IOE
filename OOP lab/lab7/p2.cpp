#include <iostream>
#include <string>

using namespace std;

class Person{
public:
	void setInfo()
	{
		cout << "Enter name: ";
		cin >> name;
		cout << "Enter age: ";
		cin >> age;
	}

	void displayInfo()
	{
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
	}
protected:
	string name;
	int age;
};

class Employee: virtual public Person{ //virtual base classs
public:
	void setInfo()
	{
		Person::setInfo();
		cout << "Enter salary: ";
		cin >> salary;
	}

	void displayInfo()
	{
		Person::displayInfo();
		cout << "Salary: " << salary << endl;
	}
protected:
	float salary;
};

class Student: public  virtual Person{ //virtual base class
public:
	void setInfo()
	{
		Person::setInfo();
		cout << "Enter Student ID: ";
		cin >> id;
	}

	void displayInfo()
	{
		Person::displayInfo();
		cout << "Student ID: " << id << endl;
	}
protected:
	float id;
};

class Manager: public Student, public Employee{
public:
	void setInfo()
	{
		cout << "Enter name: ";
		cin >> name;
		cout << "Enter age: ";
		cin >> age;

		cout << "Enter salary: ";
		cin >> salary;

		cout << "Enter Student ID: ";
		cin >> id;

		cout << "Enter Address: ";
		cin >> addr;
	}

	void displayInfo()
	{
		Employee::displayInfo();
		cout << "Address: " << addr << endl;
	}
protected:
	string addr;
};

int main()
{	
	Manager m1;
	m1.setInfo();
	cout << endl << endl;
	m1.displayInfo();
	cout << endl;
	return 0;
}