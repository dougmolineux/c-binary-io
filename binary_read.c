/*
 *
 * Written by Doug Molineux
 * 12/10/11
 *
 * binary_read.c
 *
 * This file will read a binary structure from a file called students.bin
 * The student structure contains a GPA integer and a string for a student id
 *
 */

#include<stdio.h>

// define the student structure
struct student {

    // define the GPA integer
	int gpa;
    
    // define the student id as a string of 50 characters
    char id[50];
    
};

int main() {
	
	// initialize the student file object
	FILE *studentFile;
	
	// create the student that be created from the binary
	struct student jack;
    
    // open file for reading in binary mode
	studentFile = fopen("students.bin","rb");
	
	// make sure we accessed the file
	if(!studentFile) {
        
        // print an error if the file could not be accessed or doesn't exist
		printf("Couldn't find or access the students file");
		
		// end the program
		return 1;
		
	}
    
    // read the student into the structure
	fread(&jack, sizeof(struct student), 1, studentFile);
	
	// print to make sure that the student was imported properly
	printf("%d %s\n", jack.gpa, jack.id);
	
	// close the students file
	fclose(studentFile);
	
	// pause so that the command line stays open
	system("PAUSE");
	
	// exit
	return 0;
}
