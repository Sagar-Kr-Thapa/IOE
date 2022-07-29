#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

class Account{
private:
	unsigned accNo;
	char lastName[10];
	char firstName[10];
	double balance;
public:
/*	Account()
	{
		accNo = 0;
		strcpy(lastName, " ");
		strcpy(firstName, " ");
		balance = 0;
	}*/
/*	Account(unsigned aN, char lN[], char fN[], double blnc): 
	accNo(aN),
	balance(blnc)
	{
		strncpy(lastName, lN, 10);
		strncpy(firstName, fN, 10);
	}*/

	static void addRecord()
	{
		char ch;
		ofstream file;
		file.open("Transaction.dat", ios::app|ios::out|ios::binary);
		if(file)
		{	
			do{
				Account a1;

				cout << "Enter first name: ";
				cin >> a1.firstName;
				cout << "Enter last name: ";
				cin >> a1.lastName;
				cout << "Enter account number: ";
				cin >> a1.accNo;
				cout << "Enter balance: ";
				cin >> a1.balance;

				file.write(reinterpret_cast<char *>(&a1), sizeof(a1));
				cout << "More? ";
				cin >> ch;
			}while(ch == 'y' || ch == 'Y');
		}
		file.close();
	}

	static void delRecord()
	{
		char name[10];
		Account a1;
		fstream file("Transaction.dat", ios::in|ios::binary);
		fstream newFile("temp.dat", ios::app|ios::out|ios::binary);

		cout << "Enter first name of the person whose record you wish to delete: ";
		cin >> name;
		while(!file.eof())
		{
			file.read(reinterpret_cast<char *>(&a1), sizeof(a1));
			if(file)
			{
				if(strcmp(name, a1.firstName) != 0)
				{
					newFile.write(reinterpret_cast<char *>(&a1), sizeof(a1));
				}
				else if(strcmp(name, a1.firstName) == 0)
				{
					cout << "\nRecord deleted successfully.\n";
				}
			}
		}
		file.close();
		newFile.close();

		remove("Transaction.dat");
		rename("temp.dat", "Transaction.dat");
	}

	static void modRecord()
	{	
		int pos = -1;
		char name[10];
		Account a1;
		fstream file("Transaction.dat", ios::out|ios::in|ios::binary);

		cout << "Enter first name of the person whose record you wish to modify: ";
		cin >> name;
		
		while(!file.eof())
		{	
			file.read(reinterpret_cast<char *>(&a1), sizeof(a1));
			if(file)
			{
				if(strcmp(name, a1.firstName) == 0)
				{
					pos = file.tellg();
					break;
				}
			}
		}
		if(pos != -1)
		{
			cout << "Enter new account number: ";
			cin >> a1.accNo;
			cout << "Enter new balance: ";
			cin >> a1.balance;

			file.seekp(pos-sizeof(a1));
			file.write(reinterpret_cast<char *>(&a1), sizeof(a1));

			cout << "\nRecord updated successfully.\n";
		}else
			cout << "Record not found.\n";
		file.close();
	}

	static void displayRecords()
	{	
		Account a2;
		fstream file("Transaction.dat", ios::in|ios::binary);
		while(!file.eof())
		{
			file.read(reinterpret_cast<char *>(&a2), sizeof(a2));
			if(file)
			{
				cout.setf(ios::fixed);
				cout << endl;
				cout << a2;
				cout << endl;
			}
		}
		file.close();
	}

	friend ostream& operator << (ostream&, Account&);
};

ostream& operator << (ostream& s, Account& a1)
{
	s << endl << "Name: " << a1.firstName << " " << a1.lastName << endl
	<< "Account Number: " << a1.accNo << endl << "Balance: " << a1.balance << endl;

	return s;

}

int main(){
	int ch;
	bool quit = false;
/*	unsigned accNo;
	char lName[10];
	char fName[10];
	double blnc;*/

/*	fstream file;
	file.open("Transaction.dat", ios::app|ios::in|ios::out|ios::binary);*/

	do
	{
		cout << "\n CHOOSE: \n";
		cout << "1. Add records\n2. Update record\n3. Delete record\n4. Display records\n5. Quit\n";
		cout << "Your choice: ";
		cin >> ch;

		switch(ch)
		{
			case 1:
			Account::addRecord();
			break;
			case 2:
			Account::modRecord();
			break;
			case 3:
			Account::delRecord();
			break;
			case 4:
			Account::displayRecords();
			break;
			case 5:
			quit = true;
			break;
			default:
			cout << "\n Choose a number between 1 and 5.\n";
			break;
		}
	}while(!quit);

	cout << endl;
	return 0;
}