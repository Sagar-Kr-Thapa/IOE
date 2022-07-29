#include <iostream>
#include <string>
using namespace std;

class shape
{
public:
	shape()
	{
		name = "shape";
		Area = 0;
	}
	shape(float ar, string nam = "shape")
	{
		name = nam;
		Area = ar;
	}
	virtual ~shape(){
		cout << "Shape destructed.\n";
	}

	virtual float area()
	{
		return Area;
	}
	virtual void display()
	{
		cout << "Name: " << name << endl;
		cout << "Area: " << Area << endl;
	}
protected:
	string name;
	float Area;
};

class circle: public shape
{
public:
	circle(float r, string nam = "circle")
	{
		radius = r;
		name = nam;
	}
	~circle(){
		cout << "Circle Shape destructed.\n";
	}
	float area()
	{
		Area = 3.14 * radius * radius;
		return Area;
	}
	void display()
	{
		cout << "Name: " << name << endl;
		cout << "Radius: " << radius << endl;
		cout << "Area: " << Area << endl;
	}
protected:
	float radius;
};

class rectangle: public shape
{
public: 
	rectangle(float length, float width, string nam = "rectangle")
	{
		len = length;
		wid = width;
		name = nam;
	}
	~rectangle(){
		cout << "Rectangle Shape destructed.\n";
	}
	float area()
	{
		Area = len * wid;
		return Area;
	}
	void display()
	{
		cout << "Name: " << name << endl;
		cout << "Length: " << len << " Width: " << wid << endl;
		cout << "Area: " << Area << endl;
	}
protected:
	float len;
	float wid;
};

class trapezoid: public shape
{
public:
	trapezoid(float h, float side1, float side2, string nam = "trapezoid")
	{
		height = h;
		a = side1;
		b = side2;
		name = nam;
	}
	~trapezoid(){
		cout << "Trapezoid Shape destructed.\n";
	}
	float area()
	{
		Area = (1.f/2)*(a+b)*height;
		return Area;
	}
	void display()
	{
		cout << "Name: " << name << endl;
		cout << "Height: " << height << endl;
		cout << "Area: " << Area << endl;
	}
protected:
	float height;
	float a;
	float b;
};

int main()
{	
	shape *sh;
	circle *c1 = new circle(8.f);
	rectangle *r1 = new rectangle(2.f, 5.f); //(length, breadth)
	trapezoid *t1 = new trapezoid(5.f, 12.f, 15.f);//(height, a, b)

	sh = c1;
	sh->area();
	sh->display();
	delete sh;
	cout << endl;

	sh = r1;
	sh->area();
	sh->display();
	delete sh;
	cout << endl;

	sh = t1;
	sh->area();
	sh->display();
	delete sh;

	cout << endl;
	return 0;
}