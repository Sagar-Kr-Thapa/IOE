#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main(){
	char name[20];
	string date;

	string items[10];
	int qty[10];
	float price[10];
	float total[10];
	float GrandTotal = 0;
	int i = 0;

	char more;

	cout << "Enter your name: ";
	cin.getline( name, 20 );
	cout << "Enter date: ";
	cin >> date;

	do
	{	
		cout << "Name of item: ";
		cin >> items[i];
		cout << "Quantity: ";
		cin >> qty[i];
		cout << "Price: ";
		cin >> price[i];
		total[i] = qty[i] * price[i];
		GrandTotal += total[i];

		cout << "More? ";
		cin >> more;

		i++;
	}while((more == 'y' || more == 'Y') && ( i < 10));

	cout << endl << endl;
	cout.setf(ios::left);
	cout.setf(ios::showpoint);
	cout.setf(ios::fixed);
	cout.precision(2);
	cout << "-----------------------------------------------------------\n";
	cout << setw(40) << "***********Madhu General Store***********" << endl;
	cout << "Name: " << setw(15) << name << setw(25) << ' ' << "Date: " << date << endl;
	cout << "-----------------------------------------------------------\n";
	cout << endl;

	cout << "|" << setw(20) << "Particulars" << "|" << setw(5) << "Qty" << "|" << setw(12) << "Price" << "|"  << setw(15) << "Sub total" << "|" << endl;
	cout << "-----------------------------------------------------------\n";
	for (int x = 0; x < i; x++)
	{
		cout << "|" << setw(20) << items[x] << "|" << setw(5) << qty[x] << "|" << setw(12) << price[x] << "|" << setw(15) << total[x] << "|" << endl;
	}
	cout << "-----------------------------------------------------------\n";

	cout.setf(ios::right, ios::adjustfield);
	cout.width(40);
	cout << "GrandTotal: " << GrandTotal;
	cout << endl;
	return 0;
}