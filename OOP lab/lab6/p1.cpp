#include <iostream>
#include <cmath>
using namespace std;

class Distance{

private: 
	int meter;
	int centimeter;
public:
	Distance(int m, int cm):meter(m), centimeter(cm){}
	Distance(float m){ //convert type float to type Distance
		meter = m;
		centimeter = round((m-meter)*100);
	}
	operator float(){ //to convert type Distance to type float
		float m = meter + centimeter/100.0;
		return m;
	}
	void display()
  	{
    	cout << meter << "m " << centimeter << "cm" << endl;
  	}
};

int main(){
	 float m;
	 float cm;
	 cout << "Enter distance in meters: ";
	 cin >> m;

	 Distance d1 = m;
	 cout << "Distance in m & cm: ";
	 d1.display();

	 cout << "Enter distance in meters and centimeters [m cm] format: ";
	 cin >> m >> cm;
	 //m = static_cast<int>(m);
	 Distance d2(m, cm);
	 float meter = static_cast<float>(d2);
	 cout << m << "m " << cm << "cm = " << meter << "m" << endl;

	 return 0;
}