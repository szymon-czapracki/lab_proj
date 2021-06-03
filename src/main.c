#include <stdio.h>
#include <time.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../include/student.h"
#include "../include/student_list.h"
#include "../include/write_to_file.h"

int main()
{
	int decider = 0;
	student *student_array = NULL;

	srand(time(NULL) + getpid());

	while (!(decider >= 9) || !(decider <= 0)) {
		printf("\nWhich function would you want to tests?\n");
		printf("0 - Generate database\n");
		printf("1 - Test printing database onto screen\n");
		printf("2 - Test finding individual student\n");
		printf("3 - Test database sorting\n");
		printf("4 - Test changing student info\n");
		printf("5 - Test writing into text file\n");
		printf("6 - Test saving database binary\n");
		printf("7 - Test reading from database binary\n");
		printf("8 - Clear database\n");
		printf("Any other input will exit the program\n");

		scanf("%d", &decider);

		switch (decider) {
			case 0:
				student_array = user_gen_database();
				break;
			case 1:
				print_student_list(student_array);
				break;
			case 2:
				print_user_desired_student(student_array);
				break;
			case 3:
				sorting_handler(student_array);
				break;
			case 4:
				setters_handler(student_array);
				break;
			case 5:
				fprint_student_list(student_array);
				break;
			case 6:
				write_to_file(student_array);
				break;
			case 7:
				memset(student_array, 0, num_of_students);
				student_array = read_from_file();
				break;
			case 8:
				student_array = NULL;
				break;
			default:
				return 0;
		}
	}
	free(student_array);
	return (0);
}
