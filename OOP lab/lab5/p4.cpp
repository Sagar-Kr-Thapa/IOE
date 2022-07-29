#include <iostream>
using namespace std;

const int days[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

class Date{
private:
	int month;
	int day;
	int year;
public: 
	Date(int d = 1, int m = 1, int y = 2021):day(d), month(m), year(y) {}

	Date operator ++ (){ //prefix unary increment operator
		++day;
		if(day > 28 && month == 2){
			if(year % 4 == 0){
				if(year % 100 == 0){
					if(year % 400 == 0){
						if(day > 29) { day = 1; ++month;}
					}
				}else{
					if(day > 29) { day = 1; ++month;}
				}
			}else{
				day = 1;
				++month;
			}
	        }else if(day > days[month]){
			day = 1;
			++month;
		}
		if(month > 12){
			++year;
			month = 1;
		}
		return *this;
	}

	Date operator ++ (int){ //postfix unary increment operator
		Date temp = *this;
		++*this;
		return temp;

	}

	void display_date(){
		cout << "DATE " << day << "/" << month << "/" << year << endl;
	}
};

int main(){
	int m, d, yr;
	cout << "Enter date in [dd mm yy] format:: ";
	cin >> d >> m >> yr;

	Date d1(d, m, yr);
	Date d2 = d1;
	
	//prefix increment
	++d1;
	++d2;
	
	cout << endl << "After prefix increment: " << endl;
	d1.display_date();
	d2.display_date();
	
	//postfix increment
	d2 = d1++;
	cout << endl << "After postfix increment: " << endl; d1.display_date();
	d2.display_date();
	return 0;
}
