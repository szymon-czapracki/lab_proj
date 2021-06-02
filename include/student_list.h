#ifndef STUDENT_LIST_H
#define STUDENT_LIST_H

#include "../include/student.h"

student *generate_student_list(int num_of_students);
void sort_by_age(student *student_array, int num_of_students);
void sort_by_average(student *student_array, int num_of_students);
void sort_by_semester(student *student_array, int num_of_students);
void sort_by_year(student *student_array, int num_of_students);
void sort_by_serial_no(student *student_array, int num_of_students);
void print_student_list(student *student_array, int num_of_students);
student *find_by_serial_no(student *student_array,
				int num_of_students, int serial_search);
#endif
