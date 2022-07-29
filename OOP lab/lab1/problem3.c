//stores and retrieves data using array 
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char name[24];
	unsigned int marksC;
}student;

int main(){
	int num;
	student *record;
	printf("Enter the number of students: ");	
	scanf("%d",&num);
	
	//record is the array of data with student type
	record= calloc(num, sizeof(student));
	if (record == NULL){
		fprintf(stderr,"\nCouldn't allocate space.\n");
		exit(1);
	}

	printf("\n\nEnter information about students: \n");
	
	for(int i=0; i<num; i++){
		printf("Name: ");
		while(getchar()!='\n'); //clear input buffer due to scanf
		scanf("%[^\n]s", (record+i)->name); //read from user until '\n' is encountered
		printf("Marks in C: ");
		scanf("%u",&((record+i)->marksC));
	}
	printf("\n\n");
	
	//retrieving data from the array
	for(int i=0; i<num; i++){
		printf("\nName:  %s\n",((record+i)->name));
		printf("Marks in C:  %u\n",((record+i)->marksC));
	}

	free(record);
	
	return 0;

}
