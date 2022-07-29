#include <iostream>
#include <cmath>
using namespace std;

class feet_in;

class meter_cm{
private:
	int meter;
	int centimeter;
public:
	meter_cm(int m, int cm):meter(m), centimeter(cm){}

	void display(){
		cout << meter << "m " << centimeter << "cm";
	}

	operator feet_in() const;
};

class feet_in{
private:
	int feet;
	int inches;
public: 
	feet_in(int f, int in):feet(f), inches(in){}

	void display(){
		cout << feet << "\'-" << inches << "\"";
	}	

	operator meter_cm() const;
};

meter_cm::operator feet_in() const {
	float m = meter + centimeter / 100.0;
	int feet = m * 3.281;
	int inches = round((m * 3.281 - feet) * 12);
	return feet_in(feet,inches);
}

feet_in::operator meter_cm() const{
	float f = feet + inches/12.0;
	int meter = f / 3.281;
	int centimeter = round((f / 3.281 - meter) * 100);
	return meter_cm(meter, centimeter);
}

int main(){

	int f, in;
	int m, cm;

	cout << "Enter distance in feet and inches: ";
	cin >> f >> in;
	feet_in d1(f, in);

	cout << "Enter distance in meter and centimeter: ";
	cin >> m >> cm;
	meter_cm d2(m, cm);

	feet_in d3 = d2; //meter-centimeter to feet-inches
	meter_cm d4 = d1; //feet-inches to meter-centimeter

	d1.display(); cout << " = "; d4.display();
	cout << endl;
	d2.display(); cout << " = "; d3.display();

	cout << endl;
	return 0;
}