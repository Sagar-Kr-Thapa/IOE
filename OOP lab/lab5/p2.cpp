#include <iostream>
using namespace std;

class _3D{
private:
	int x = 0;
	int y = 0;
	int z = 0;
public:
	void set_coordinates(int xpos, int ypos, int zpos){
		x = xpos;
		y = ypos;
		z = zpos;
	}

	friend _3D operator + (_3D, _3D);
	friend _3D operator - (_3D, _3D);

	void display_coordinates(){
		cout << "(" << x << ", " << y << ", " << z << ")" << endl;
	}
};

_3D operator + (_3D c1, _3D c2){
	_3D temp;
	temp.set_coordinates(c1.x + c2.x, c1.y + c2.y, c1.z + c2.z);
	return temp;
}

_3D operator - (_3D c1, _3D c2){
	_3D temp;
	temp.set_coordinates(c1.x - c2.x, c1.y - c2.y, c1.z - c2.z);
	return temp;
}

int main(){
	int x , y, z;
  	
  	cout << "Enter coordinate x, y, z in format [x y z]:: ";
  	cin >> x >> y >> z;
  	_3D c1;
	c1.set_coordinates(x,y,z);

  	cout << "Enter coordinate x, y, z in format [x y z]:: ";
  	cin >> x >> y >> z;
  	_3D c2;
	c2.set_coordinates(x,y,z);

  	_3D S = c1 + c2;
  	cout << endl << "Sum: "; 
	S.display_coordinates();

  	_3D d = c1 - c2;
  	cout << "Difference: ";
	d.display_coordinates();

	return 0;
}
