#include <iostream>

class calculator_manager;
class coordinate;

class calculator{
private:
	coordinate *mul_result;
	coordinate *div_result;
	coordinate *sub_result;
	coordinate *add_result;
public:
	coordinate add(const coordinate &, const coordinate &);
	//friend functions with global scope
	friend coordinate multiply(calculator &, const coordinate &, const coordinate &);
	friend coordinate divide(calculator &, const coordinate &, const coordinate &);
	friend coordinate subtract(calculator &, const coordinate &, const coordinate &);
	//friend class
	friend class calculator_manager;
};

class coordinate{
private:
	int xpos;
	int ypos;
public:
	coordinate(int x=0, int y=0):xpos(x), ypos(y) {}
	
	friend coordinate calculator::add(const coordinate &, const coordinate &);//friend function of class calculator
	//friend functions which with global scope 
	friend coordinate multiply(calculator &, const coordinate &, const coordinate &);
	friend coordinate divide(calculator &, const coordinate &, const coordinate &);
	friend coordinate subtract(calculator &, const coordinate &, const coordinate &);

	void display_coordinates() const{
		std::cout << "(" << xpos << ", " << ypos << ")";
	}

};


class calculator_manager{
public:
	void Print(const calculator &CALC){
		std::cout << std::endl << " **Result of last calculation performed by the calculator** " << std::endl;
		std::cout << "Addition: "; CALC.add_result->display_coordinates(); std::cout << std::endl;
		std::cout << "Subtraction: "; CALC.sub_result->display_coordinates(); std::cout << std::endl;
		std::cout << "Multiplication: "; CALC.mul_result->display_coordinates(); std::cout << std::endl;
		std::cout << "Division: "; CALC.div_result->display_coordinates(); std::cout << std::endl;
	}
	
	void free_mem(calculator &CALC){
		delete CALC.add_result;
		delete CALC.sub_result;
		delete CALC.mul_result;
		delete CALC.div_result;
	}
};

coordinate calculator::add(const coordinate &c1, const coordinate &c2){
	add_result = new coordinate(c1.xpos + c2.xpos, c1.ypos + c2.ypos);
	return *add_result;
}

coordinate multiply(calculator &CALC, const coordinate &c1, const coordinate &c2){
	CALC.mul_result = new coordinate (c1.xpos * c2.xpos, c1.ypos * c2.ypos);
	return *CALC.mul_result;
}

coordinate subtract(calculator &CALC, const coordinate &c1, const coordinate &c2){
	CALC.sub_result = new coordinate (c1.xpos - c2.xpos, c1.ypos - c2.ypos);
	return *CALC.sub_result;
}

coordinate divide(calculator &CALC, const coordinate &c1, const coordinate &c2){
	if(c2.xpos == 0 || c2.ypos == 0){
		CALC.div_result = new coordinate ();
	}else
		CALC.div_result = new coordinate (c1.xpos / c2.xpos, c1.ypos / c2.ypos);
	return *CALC.div_result;
}

int main(){
	int x, y;
	calculator CALC;
	calculator_manager calc_mgr;

	std::cout << "Enter x & y coordinates for first object in the format [x y]: ";
	std::cin >> x >> y;
	coordinate c1(x, y);

	std::cout << "Enter x & y coordinates for second object in the format [x y]: ";
	std::cin >> x >> y;
	coordinate c2(x, y);
	
	CALC.add(c1, c2);
	//three functions acting bridge between class calculator and class coordinate
	subtract(CALC, c1, c2);
	multiply(CALC, c1, c2);
	divide(CALC, c1, c2);

	calc_mgr.Print(CALC);
	calc_mgr.free_mem(CALC);

	return 0;
}
