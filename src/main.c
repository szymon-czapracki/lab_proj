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
	char *file_option = (char*) malloc(10 * sizeof(char));
	int num_of_students, decider;
	student *student_array;
	char *gen = "gen";
	char *load = "load";

	srand(time(NULL) + getpid());

	printf("Do you want to generate new database or load from file"
			"[gen/load]: ");
	scanf("%s", file_option);

	while (!strcmp(file_option, gen) || !strcmp(file_option, load)) {
		scanf("%s", file_option);
	}

	if (strcmp(file_option, gen)) {
		printf("\nHow many students in database?\n");
		scanf("%d", &num_of_students);
		while (num_of_students <= 0) {
			scanf("%d", &num_of_students);
		}
		student_array = generate_student_list(num_of_students);
	} else if (strcmp(file_option, load)) {
		// TODO add option to load from file
	}


	while (decider != 0) {
		printf("\nWhich function would you want to tests?\n");
		printf("1 - Test printing database onto screen\n");
		printf("2 - Test finding individual student\n");
		printf("3 - Test database sorting\n");
		printf("4 - Test changing student info\n");
		printf("5 - Test saving database to file\n");
		printf("6 - Test adding student by user input\n");
		printf("0 - Exit\n");
		scanf("%d", &decider);

		switch (decider) {
			case 1:
				print_student_list(student_array,
							num_of_students);
				break;
			case 2:
				// TODO
				break;
			case 3:
				// TODO
				break;
			case 4:
				// TODO
				break;
			case 5:
				// TODO
				break;
			case 6:
				// TODO
				break;
			default:
				break;
		}
	}
	return (0);
}
