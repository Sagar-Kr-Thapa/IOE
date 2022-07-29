#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

class Vehicle{
public:
	Vehicle(string nam = "vehicle"){
		Type = nam;
	}
	virtual ~Vehicle(){}

	virtual void getInfo() = 0;
protected:
	string Type;
};

class Bus: public Vehicle{
public:
	Bus(string nam = "Bus"): Vehicle(nam){}
	~Bus(){}

	void getInfo(){
		cout << "Type: " << Type << endl;
	}
};

class Car: public Vehicle{
public:
	Car(string nam = "Car"): Vehicle(nam){}
	~Car(){}

	void getInfo(){
		cout << "Type: " << Type << endl;
	}
};

class Bike: public Vehicle{
public:
	Bike(string nam = "Bike"): Vehicle(nam){}
	~Bike(){}

	void getInfo(){
		cout << "Type: " << Type << endl;
	}
};

int main(){
	Vehicle *vh;
	Bus bs, *bus;
	Car cr, *car;
	Bike bk, *bike;

	vh = &bs;
	cout << typeid(*vh).name() << endl;
	bus = dynamic_cast<Bus *>(vh);

	vh = &cr;
	cout << typeid(*vh).name() << endl;
	car = dynamic_cast<Car *>(vh);

	vh = &bk;
	cout << typeid(*vh).name() << endl;
	bike = dynamic_cast<Bike *>(vh);

	bus->getInfo();
	car->getInfo();
	bike->getInfo();

	cout << endl;
	return 0;
}