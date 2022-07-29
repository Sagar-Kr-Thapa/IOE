//to calculate the average expenditure
#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	double sum=0;

	const int Y = 3;
	const int M = 12;
	double exp_table[Y][M];
	double avg[M]={0};
	double Yearly[Y];

	const char *months[12]={"January","February","March","April","May","June","July","August","September","October","November","December"};

	cout << "Enter the expenditure for each month of each year: " <<endl;
	cout << setw(10)<< "Months"<< setw(20)<<"Expenditure"<< endl;
	
	//Asking data from the user
	for(int i=0; i<Y; i++){
		cout << endl << endl << "Year: "<< i+1 << endl;
		for(int j=0; j<M; j++){
			cout <<setw(10)<< months[j]<<setw(10)<< ":";
			cin  >> exp_table[i][j];
		}
	}

	cout<< endl<<endl<<endl;
	cout<<setw(10)<<"Months->";

	for(int i=0; i<M; i++){
		cout<<setw(10)<<months[i];
	}
	cout<<endl;
	
	//Displaying the expenditure table
	for(int i=0; i<Y; i++){
		double y_sum=0;
		cout <<setw(8)<< "Year" << i+1<<":";
		for(int j=0; j<M; j++){
			cout << setw(10) << exp_table[i][j];
			sum += exp_table[i][j];
			y_sum += exp_table[i][j];
			avg[j] += exp_table[i][j];
		}
		Yearly[i]=y_sum;
		cout << endl;
	}
	cout<<setw(10)<<"Average:";
	for(int i=0; i<M; i++){
		cout<<setw(10)<<avg[i]/Y;
	}
	cout<< endl<<endl;
	
	//Yearly sum and average
	for(int i=0; i<Y; i++){
		cout<<"Year"<<i+1<<": "<<" Sum: "<<Yearly[i]<<"  Average: "<<Yearly[i]/12<<endl;
	}	
	
	cout << "\nTotal average: "<< sum/(Y*12)<<endl;
	cout << "Toal sum: "<< sum<<endl;
	
	return 0;


}
