#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student{
	char * name;
	float gpa;
};

struct student * makeStudentArray(int size);

void makeStudent(struct student * entry, char * name, float gpa);

void printStudent(struct student * entry);

float averageGPA(struct student * myArray, int size);

void freeStudents(struct student * myArray, int size);

