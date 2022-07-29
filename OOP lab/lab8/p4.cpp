#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

struct Student{
	char name[15];
	int id;
	char department[15];
	char address[12];

};

void prettyPrint(Student& s){
	cout << left << setw(6) << "Name: " << setw(20) << s.name << endl;
	cout << setw(6) << "ID: " << setw(20) << s.id << endl;
	cout << setw(12) << "Department: " << setw(20) << s.department << endl;
	cout << setw(12) << "Address: " << setw(20) << s.address << endl;
}

int main(){
			Student s1;
	char ch;
	//int i = 0, n = 0;

	ofstream file;
	file.open("Student.dat", ios::out|ios::binary);

	cout << "Enter Student Info: " << endl;

	do{	
		cout << "Enter name: ";
		cin >> s1.name;
		cout << "Enter id: ";
		cin >> s1.id;
		cout << "Enter department's name: ";
		cin >> s1.department;
		cout << "Enter address: ";
		cin >> s1.address; 

		file.write(reinterpret_cast<char *>(&s1), sizeof(s1));
		cout << "More? ";
		cin >> ch;

	}while(ch == 'y' || ch == 'Y');

	file.close();

	Student s2;
	ifstream ifile;
	ifile.open("Student.dat", ios::in|ios::binary);
	while(!ifile.eof()){
		cout << endl << endl;
		ifile.read(reinterpret_cast<char *>(&s2), sizeof(s2));
		if(ifile)prettyPrint(s2);
	}
	ifile.close();

	cout << endl;
	return 0;
}