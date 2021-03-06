#include "../include/student.h"
#include "../include/student_list.h"
#include <stdlib.h>
#include <stdio.h>

int num_of_students = 40;

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

int compare_by_age(const void *a, const void *b) {
	student *student_1 = (student *)a;
	student *student_2 = (student *)b;

	if (student_1->age < student_2->age) {
		return -1;
	} else if (student_1->age > student_2->age) {
		return 1;
	} else {
		return 0;
	}
}

int compare_by_year(const void *a, const void *b) {
	student *student_1 = (student *)a;
	student *student_2 = (student *)b;

	if (student_1->year < student_2->year) {
		return -1;
	} else if (student_1->year > student_2->year) {
		return 1;
	} else {
		return 0;
	}
}

int compare_by_serial_no(const void *a, const void *b) {
	student *student_1 = (student *)a;
	student *student_2 = (student *)b;

	if (student_1->serial_number < student_2->serial_number) {
		return -1;
	} else if (student_1->serial_number > student_2->serial_number) {
		return 1;
	} else {
		return 0;
	}
}

void sorting_handler(student *student_array) {

	int decider;

	if (student_array == NULL) {
		printf("No database present!\n");
		return;
	}

	printf("On which condition do you want to sort databse?\n");
	printf("1 - Sort by serial number\n");
	printf("2 - Sort by age\n");
	printf("3 - Sort by year\n");
	printf("4 - Sort by average mark\n");

	scanf("%d", &decider);

	while (decider < 1 || decider > 4) {
		scanf("%d", &decider);
	}

	switch (decider) {
		case 1:
			sort_by_serial_no(student_array, num_of_students);
			print_student_list(student_array);
			break;
		case 2:
			sort_by_age(student_array, num_of_students);
			print_student_list(student_array);
			break;
		case 3:
			sort_by_year(student_array, num_of_students);
			print_student_list(student_array);
			break;
		case 4:
			sort_by_average(student_array, num_of_students);
			print_student_list(student_array);
			break;
		default:
			break;
	}
}

void sort_by_age(student *student_array, int num_of_students) {
	qsort(student_array, num_of_students, sizeof(*student_array),
		compare_by_age);
}

void sort_by_average(student *student_array, int num_of_students) {
	qsort(student_array, num_of_students, sizeof(*student_array),
		compare_by_average);
}

void sort_by_year(student *student_array, int num_of_students) {
	qsort(student_array, num_of_students, sizeof(*student_array),
		compare_by_year);
}

void sort_by_serial_no(student *student_array, int num_of_students) {
	qsort(student_array, num_of_students, sizeof(*student_array),
		compare_by_serial_no);
}

void print_student_list(student *student_array) {

	if (student_array == NULL) {
		printf("No database present!\n");
		return;
	}

	printf("\n");

	for (int i = 0; i < num_of_students; i++) {
		printf("%-3d ", i);
		print_student(student_array[i]);
	}
}

void fprint_student_list(student *student_array) {

	if (student_array == NULL) {
		printf("No database present!\n");
		return;
	}

	FILE *saved = stdout;

	stdout = fopen("database.txt", "a");
	print_student_list(student_array);
	fclose(stdout);
	stdout = saved;
}

void print_user_desired_student(student *student_array) {

	int serial_no;
	student *to_print_student;

	if (student_array == NULL) {
		printf("No database present!\n");
		return;
	}

	printf("Enter desired student serial num\n");
	scanf("%d", &serial_no);

	to_print_student = find_by_serial_no(student_array, num_of_students,
								serial_no);
	if (to_print_student != NULL) {
		print_student(*to_print_student);
	} else {
		printf("No such student found\n");
	}

}

student *find_by_serial_no(student *student_array,
					int num_of_students, int serial_search)
{
	for (int i = 0; i < num_of_students; i++) {
		if (student_array[i].serial_number == serial_search) {
			return &student_array[i];
		}
	}
	return NULL;
}

student *generate_student_list(int num_of_students)
{

	student *student_array = malloc(num_of_students *
							sizeof(*student_array));

	for (int i = 0; i < num_of_students; i++) {
		student_array[i] = generate_student();
	}

	return student_array;
}

student *user_gen_database() {

	student *student_array = NULL;

	student_array = generate_student_list(num_of_students);
	printf("Database generated!\n");

	return student_array;
}
