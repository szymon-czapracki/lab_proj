#include <stdio.h>
#include <time.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/student.h"
#include "../include/student_list.h"



int main()
{
	srand(time(NULL) + getpid());
	int num_of_students;


	printf("Enter number of students\n");
	scanf("%d", &num_of_students);

	while (num_of_students < 0) {
		scanf("%d", &num_of_students);
	}

	student *student_array = malloc(num_of_students * sizeof(*student_array));

	for (int i = 0; i < num_of_students; i++) {
		student_array[i] = generate_student();
	}

	for (int i = 0; i < num_of_students; i++) {
		printf("%-3d ", i);
		print_student(student_array[i]);
	}

	printf("Select sort method\n")

	printf("1 - sort by average mark\n")
	printf("2 - sort by age\n")
	printf("3 - sort by year\n")
	printf("4 - sort by semester\n")

	scanf("%d", &sort_method);
	while (sort_method < 1 || sort_method > 4) {
		scanf("%d", &num_of_students);
	}

	qsort(student_array, num_of_students, sizeof(*student_array), compare_by_average);

	printf("\n\n\n");

	for (int i = 0; i < num_of_students; i++) {
		printf("%-3d ", i);
		print_student(student_array[i]);
	}

	return (0);
}
