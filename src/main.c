#include <stdio.h>
#include <time.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../include/student.h"
#include "../include/student_list.h"

int main()
{
	int num_of_students, decider = 1, serial_no;
	student *student_array;
	char *f_dec = (char*) malloc(3 * sizeof(char));

	srand(time(NULL) + getpid());

	printf("Do you want to generate new database or load from file"
			"[gen/lod]: \n");
	scanf("%s", f_dec);

	while ((strcmp(f_dec, "gen") != 0) && (strcmp(f_dec, "lod") != 0)) {
		scanf("%s", f_dec);
	}

	if (!strcmp(f_dec, "gen")) {
		printf("\nHow many students in database?\n");
		scanf("%d", &num_of_students);
		while (num_of_students <= 0) {
			scanf("%d", &num_of_students);
		}
		student_array = generate_student_list(num_of_students);
		printf("\n");
		print_student_list(student_array, num_of_students);
	} else if (!strcmp(f_dec, "load")) {
		printf("Decision load\n");
		// TODO add option to load from file
	}

	while (decider != 0) {
		printf("\nWhich function would you want to tests?\n");
		printf("1 - Test printing database onto screen\n");
		printf("2 - Test finding individual student\n");
		printf("3 - Test database sorting\n");
		printf("4 - Test changing student info\n");
		printf("5 - Test saving database to file\n");
		printf("0 - Exit\n");
		scanf("%d", &decider);

		switch (decider) {
			case 1:
				print_student_list(student_array,
							num_of_students);
				break;
			case 2:
				printf("Enter desired student serial num\n");
				scanf("%d", &serial_no);
				student *print_stud = find_by_serial_no(student_array,
							num_of_students, serial_no);
				if (print_stud != NULL) {
					printf("\n");
					print_student(*print_stud);
					printf("\n");
				} else {
					printf("No such student found\n");
				}
				break;
			case 3:
				sorting_handler(student_array,
							num_of_students);
				break;
			case 4:
				setters_handler(student_array,
							num_of_students);
				break;
			case 5:
				// TODO
				break;
			default:
				break;
		}
	}
	return (0);
}
