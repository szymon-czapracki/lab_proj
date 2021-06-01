#ifndef STUDENT_LIST_H
#define STUDENT_LIST_H

#include "../include/student.h"

void sort_by_age(student *student_array, int num_of_students);
void sort_by_average(student *student_array, int num_of_students);
void sort_by_semester(student *student_array, int num_of_students);
void sort_by_year(student *student_array, int num_of_students);
void sort_by_serial_no(student *student_array, int num_of_students);
void print_student_list(student *student_array, int num_of_students);
student find_student_by_serial_number(student *student_array,
				int num_of_students, int serial_search);
#endif
