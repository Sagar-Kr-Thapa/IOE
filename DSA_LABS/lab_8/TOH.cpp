#include <iostream>
using namespace std;

void toh( int n , char src, char aux, char dest )
{
	if ( n == 0 )
		return;
	else 
	{
		toh( n-1, src, dest, aux );
		cout<<"Move disk "<<n<<" from "<<src<<" to "<<dest<<endl;
		toh( n-1, aux, src, dest );
	}
}

int main()
{
	cout<<"Tower Of Hanoi\n";
	toh( 3, 'A', 'B', 'C' );
}
