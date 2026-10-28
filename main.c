#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "students.h"

int main(void){
	char * names[] = {"Anna", "Ben", "Omar", "Ali"};
	float gpas[] = {3.5f, 2.8f, 3.9f, 3.1f};
	int size = 4;

	struct student *arr = makeStudentArray(size);
	if (!arr){
		return 1; //failure
	}

	for (int i=0; i<size; i++) {
		makeStudent(&arr[i], names[i], gpas[i]);
	}

	printf("Students in datatbase:\n");
	for (int i=0; i<size; i++){
		printStudent(&arr[i]);
	}

	printf("\nThe average gpas is %.2f\n", averageGPA(arr, size));

	freeStudents(arr, size);
	return 0; //success
}

