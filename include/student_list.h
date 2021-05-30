#ifndef STUDENT_LIST_H
#define STUDENT_LIST_H

#include "../include/student.h"

int compare_by_average(const void *a, const void *b) {
	student *student_1 = (student *)a;
	student *student_2 = (student *)b;

	if (student_1->average < student_2->average) {
		return -1;
	} else if (student_1->average > student_2->average) {
		return 1;
	} else {
		return 0;
	}
}

void sort_by_age(student *student_array, num_of_students) {
}

void sort_by_average(student *student_array, num_of_students) {
}

void sort_by_semester(student *student_array, num_of_students) {
}

void sort_by_year(student *student_array, num_of_students) {
}

//int compare_by_average(const void *a, const void *b);
//void sort_by_average(student *student_array[], int student_number);
#endif
