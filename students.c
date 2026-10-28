#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "students.h"


struct student * makeStudentArray(int size){
	if (size <= 0){
		return NULL;
	}
	struct student *arr = malloc(size * sizeof(struct student));
	if (!arr){
		return NULL;
	}

	for (int i = 0; i < size; i++){
		arr[i].name = NULL;
		arr[i].gpa = 0.0f;
	}
	return arr;
}

void makeStudent(struct student * entry, char * name, float gpa){
	if ((!entry) || (!name)){
		return;
	}
	entry->name = malloc(strlen(name) + 1);

	if (entry->name == NULL){
		return;
	}
	strcpy(entry->name, name);
	entry->gpa = gpa;
}

void printStudent(struct student * entry){
	if (!entry){
		return;
	}

	printf("(%s, %g)\n", entry->name, entry->gpa);
}

float averageGPA(struct student * myArray, int size){
	if ((!myArray) || size <= 0){
		return 0.0f;
	}

	float sum = 0.0f;
	for (int i = 0; i < size; i++){
		sum += myArray[i].gpa;
	}
	sum = sum/size;
	return sum;
}


void freeStudents(struct student * myArray, int size){
	if (!myArray){
		return;
	}

	for (int i=0; i<size; i++){
		free(myArray[i].name);
	}
	free(myArray);
}
