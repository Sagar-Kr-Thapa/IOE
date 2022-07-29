#include <iostream>
#include <string>
using namespace std;

class Musicians{
protected:
	std::string str[5];
	std::string wnd[5];
	std::string per[5];
public:
	void string(){
		std::string str1[] = {"veena", "guitar", "sitar", "sarod", "mandolin"};
		cout << "String Instruments: ";
		for(int i = 0; i < 5; i++){
			str[i] = str1[i];
			cout << str[i] << ", ";
		}
	}

	void wind(){
		std::string str2[] = {"flute", "clarinet", "saxophone", "nadhaswaram", "piccolo"};
		cout << "Wind Instruments: ";
		for(int i = 0; i < 5; i++){
			wnd[i] = str2[i];
			cout << wnd[i] << ", ";
		}
	}

	void perc(){
		std::string str3[] = {"tabla", "mridangam", "bangos", "drums", "tambour"};
		cout << "Percussion Instruments: ";
		for(int i = 0; i < 5; i++){
			per[i] = str3[i];
			cout << per[i] << ", ";
		}
	}
};

class TypeIns: public Musicians{
private:
	char choice;
public:
	void get(){
		cout << "Types of intruments to be displayed " << endl 
		<< "a. String intruments" << endl << "b. Wind instruments"
		<< endl << "c. Percussion instruments" << endl;

		cout << "What's your choice? ";
		cin >> choice;
	}
	void display_stringIns(){
		cout << "String Instruments: ";
		for(int i = 0; i < 5; i++){
			cout << str[i] << ", ";
		}
	}

	void display_windIns(){
		cout << "Wind Instruments: ";
		for(int i = 0; i < 5; i++){
			cout << wnd[i] << ", ";
		}
	}

	void display_percIns(){
		cout << "Percussion Instruments: ";
		for(int i = 0; i < 5; i++){
			cout << per[i] << ", ";
		}
	}
	void show();
};

void TypeIns::show(){
	switch(choice){
		case 'a':
			display_stringIns();
			cout << endl;
			break;
		case 'b':
			display_windIns();
			cout << endl;
			break;
		case 'c':
			display_percIns();
			cout << endl;
			break;
		default:
			cout << endl << "Enter a valid choice: [a-c]\n";
			break;
	}
}

int main(){
	TypeIns Ins;

	Ins.string();
	cout << endl;
	Ins.wind();
	cout << endl;
	Ins.perc();
	cout << endl;

	cout << endl;
	Ins.get();
	Ins.show();

	cout << endl;
	return 0;
}