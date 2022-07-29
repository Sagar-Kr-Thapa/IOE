#include <iostream>
#include <cstring>
using namespace std;

int main(){
	const char *str="idea without execution is worthless";
	for(int i=0; i<strlen(str)-1; i++, str++){
		if (*str=='c'){
			cout << "The position of \'c\' in the string is: "<< i+1 <<endl;
			break;	
		}
	}
	return 0;	
}
