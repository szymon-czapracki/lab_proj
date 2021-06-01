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
	int sort_method;
	int search;


	printf("Enter number of students\n");
	scanf("%d", &num_of_students);

	while (num_of_students < 0) {
		scanf("%d", &num_of_students);
	}

	student *student_array = malloc(num_of_students * sizeof(*student_array));

	for (int i = 0; i < num_of_students; i++) {
		student_array[i] = generate_student();
	}

	print_student_list(student_array, num_of_students);

	//scanf("%d", &sort_method);
	//while (sort_method < 1 || sort_method > 4) {
	//	scanf("%d", &num_of_students);
	//}

	printf("Enter serial_number\n");
	scanf("%d", &search);

	print_student(find_student_by_serial_number(student_array,
						num_of_students, search));

	//for (int i = 0; i < num_of_students; i++) {
	//	printf("%-3d ", i);
	//	print_student(student_array[i]);
	//}

	return (0);
}
