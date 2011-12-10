#include<stdio.h>

struct student {
       
	int gpa;
    
    char id[50];
    
};

int main() {
	
	FILE *studentFile;
	
	// create the student that be created from the binary
	struct student jack;
    
    // open file for reading in binary mode
	studentFile = fopen("students.bin","rb");
	
	// make sure we accessed the file
	if(!studentFile) {
                     
		printf("Couldn't find or access the students file");
		return 1;
		
	}
    
    // read the student into the structure
	fread(&jack, sizeof(struct student), 1, studentFile);
	
	// print to make sure that the student was imported properly
	printf("%d %s\n", jack.gpa, jack.id);
	
	// close the students file
	fclose(studentFile);
	
	system("PAUSE");
	
	// exit
	return 0;
}
