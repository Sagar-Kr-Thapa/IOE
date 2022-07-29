//stores and retrieves the information about students using file I/O
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct students{
	unsigned int rollno;
	char name[24];
	char address[16];
	unsigned long long int phoneno;

}record;

void sort(record * collection, int size);

int main(){
	record c;
	int ch='Y';
	FILE *fp;

	fp=fopen("students.dat", "ab+");
	if (fp==NULL){
		fprintf(stderr,"Cannot open file\n");
		exit(1);
	}

	printf("Enter information about students:\n");
	//writing records to the file
	do{
		printf("Name: ");
		scanf("%[^\n]s", c.name); // read from the user until '\n' is encountered
		printf("Roll no: ");
		scanf("%d", &c.rollno);
		printf("Address: ");
		while ((getchar()) != '\n'); //clearing input buffer after scanf
		scanf("%[^\n]s", c.address);
		printf("Phone number: ");
		scanf("%llu", &c.phoneno);

		fwrite(&c, sizeof(c), 1, fp);
		printf("Do you want to enter more records::[yN]\n");
		while ((getchar()) != '\n'); 
		ch=getchar();
		while ((getchar()) != '\n'); 
	}while(ch=='y' || ch=='Y');
	
	fclose(fp);
	
	fp=fopen("students.dat","rb");
	if (fp==NULL){
		fprintf(stderr,"Unable to read the file.\n");
		exit(2);

	}

	//reading number of records in the file
	int file_size=0;
	while(fread(&c, sizeof(c), 1, fp)==1)
		file_size ++;
	if (file_size < 1) file_size=10; //checking size
	file_size += 2;

	record *collection= calloc(file_size,sizeof(record));
	if (collection==NULL){
	       	fprintf(stderr,"\nUnable to allocate space to retrieve file.\n");
		exit(3);
	}
	
	rewind(fp);
	
	//reading records from the file
	int size=0;
	while(fread(collection+size, sizeof(record), 1, fp)==1)
		size++;
	
	//sorting the records 
	sort(collection, size);

	//displaying the records
	for(int i=0; i<size; i++){
		printf("\n");
		printf("Name: %s\n",(collection+i)->name);
		printf("Roll no: %d\n",(collection+i)->rollno);
		printf("Addresss: %s\n",(collection+i)->address);
		printf("Telephone: %llu\n",(collection+i)->phoneno);
	}

	free(collection);
	fclose(fp);
	
	return 0;
		
}

//uses bubble sort algorithm to sort the records
void sort(record * collection, int size){
	record temp;
	int i=0;
	int j=0;

	for(i=0; i<size-1; i++){
		for(j=0; j<size-i-1; j++){
			if (strcmp((collection+j)->name, (collection+j+1)->name)>0){
				temp= collection[j];
				collection[j]=collection[j+1];
				collection[j+1]=temp;
			}	
		}
	}
}
