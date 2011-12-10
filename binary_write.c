/*
 *
 * Written by Doug Molineux
 * 12/10/11
 *
 * binary_write.c
 *
 * This file will write a binary structure to a file called students.bin
 * The student structure contains a GPA integer and a string for a student id
 *
 */

#include<stdio.h>
#include<string.h>

// create the student structure
struct student {

   // give the student a gpa
   int gpa;
   
   // give the student a string id
   char id[50];
       
};

int main() {
	
	// create a pointer that will point at the student file
    FILE *studentFile;
	
	// create jack
    struct student jack;

    // open the students.bin file with "b" for binary
	studentFile = fopen("students.bin","wb");
	
	// make sure the file could be accessed
	if (!studentFile) {
                     
        // display warning if there was a problem
		printf("Couldn't access the students file");
		
		// return; cannot continue; end program
        return 1;
	}
    
    // give jack a GPA
	jack.gpa = 4;
	
	// give jack a student id
    strcpy(jack.id, "student001");
	
	// write student to the file
    fwrite(&jack, sizeof(struct student), 1, studentFile);
	
	// close the student file
	fclose(studentFile);
	
	// exit
	return 0;
}
