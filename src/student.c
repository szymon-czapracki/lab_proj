#include "../include/student.h"
#include "../include/student_list.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <stdio.h>


int generate_day()
{
	return (rand() % (30 - 1 + 1)) + 1;
}

int generate_month()
{
	return (rand() % (12 - 1 + 1)) + 1;
}

int generate_year()
{
	return (rand() % (2000 - 1965 + 1)) + 1965;
}

int generate_age()
{
	return 2020 - generate_year();
}

int generate_study_year()
{
	return (rand() % (5 - 1 + 1)) + 1;
}

int generate_semester(int year)
{
	int semester;

	switch (year) {
		case 1:
			semester = (rand() % (2 - 1 + 1)) + 1;
			break;
		case 2:
			semester = (rand() % (4 - 3 + 1)) + 3;
			break;
		case 3:
			semester = (rand() % (6 - 5 + 1)) + 5;
			break;
		case 4:
			semester = (rand() % (8 - 7 + 1)) + 7;
			break;
		case 5:
			semester = (rand() % (10 - 9 + 1)) + 9;
			break;
		default:
			semester = 1;
			break;

	}
	return semester;
}

void generate_marks(float **marks)
{
	*marks = malloc(5 * sizeof(float));

	for (int i = 0; i < 5; i++) {
		(*marks)[i] = ((float)rand()) / ((float)RAND_MAX) * 6.00;
	}
}

int generate_serial_number()
{
	return (rand() % (2300 - 2199 + 1)) + 2199;
}

char *generate_name()
{

	char *name;

	char *names_table[] = {"Szymon", "Jacek", "Adam", "Grzegorz",
					"Janusz", "Agata", "Beata",
					"Alicja", "Judyta", "Olga",
					"Aleksandra", "Marian", "Kamil"};

	int random_index = rand() % 13;

	name = names_table[random_index];

	return name;
}

int generate_year_of_birth(int age)
{
	return 2020 - age;
}

float calculate_average(float *marks)
{

	float sum = 0.0;

	for (int i = 0; i < 5; i++) {
		sum += marks[i];
	}
	return sum / 5;
}

char *generate_surname()
{

	char *surname;

	char *surnames[] = {"Kubik", "Lewa", "Szewin", "Malys",
				"Kulej", "Szurko", "Konopa", "Boniek",
				"Deyna", "Gollob", "Zasada", "Lato"};

	int random_index = rand() % 12;

	surname = surnames[random_index];

	return surname;
}

student generate_student()
{

	student *new_student = malloc(sizeof(*new_student));

	new_student->serial_number = generate_serial_number();
	new_student->name = generate_name();
	new_student->surname = generate_surname();
	new_student->age = generate_age();
	new_student->day_of_birth = generate_day();
	new_student->month_of_birth = generate_month();
	new_student->year_of_birth = generate_year_of_birth(new_student->age);
	new_student->year = generate_study_year();
	new_student->semester = generate_semester(new_student->year);
	generate_marks(&new_student->marks);
	new_student->average = calculate_average(new_student->marks);

	return *new_student;
}

void print_student(student new_student)
{
	printf("| | No. %-4d | | Name: %-10s | | Surname: %-10s |"
			"| Age: %-6d | ", new_student.serial_number,
			new_student.name, new_student.surname,
			new_student.age);


	printf("| Birth: %02d/%02d/%d | ", new_student.day_of_birth,
				new_student.month_of_birth,
				new_student.year_of_birth);

	printf("| Year: %-3d | | Semester: %-4d |", new_student.year,
							new_student.semester);

	printf(" | Marks: ");
	for (int i = 0; i < 5; i++) {
		printf(" %-10.2f ", new_student.marks[i]);
	}
	printf(" | | Average: %-4.2f | |\n", new_student.average);
}

void setters_handler(student *student_array, int num_of_students)
{
	int decider = 0;
	int new_ser_no, age, search_ser_no, study_year, semester;
	int day, month, year;
	char decision;
	char *new_name = (char*) malloc(12 * sizeof(char));
	char *new_surname = (char*) malloc(12 * sizeof(char));

	printf("Type in serial number of student to modify\n");
	scanf("%d", &search_ser_no);

	student *var_student = find_by_serial_no(student_array,
							num_of_students,
							search_ser_no);

	if (var_student != NULL) {
		printf("Select which value do you want to change\n");
		printf("1 - serial number\n");
		printf("2 - name\n");
		printf("3 - surname\n");
		printf("4 - age\n");
		printf("5 - birth_date\n");
		printf("6 - year\n");
		printf("7 - semester\n");
		printf("8 - marks\n");

		scanf("%d", &decider);
		while (decider < 0 || decider > 8) {
				scanf("%d", &num_of_students);
		}

		switch (decider) {
			case 1:
				printf("Enter new serial number\n");
				scanf("%d", &new_ser_no);
				change_serial_number(var_student, new_ser_no);
				break;
			case 2:
				printf("Enter new name\n");
				scanf("%s", new_name);
				change_name(var_student, new_name);
				break;
			case 3:
				printf("Enter new surname\n");
				scanf("%s", new_surname);
				change_surname(var_student, new_surname);
				break;
			case 4:
				printf("Enter new age\n");
				scanf("%d", &age);
				change_age(var_student, age);
				break;
			case 5:
				printf("Enter new day\n");
				scanf("%d", &day);
				printf("Enter new month\n");
				scanf("%d", &month);
				printf("Enter new year\n");
				scanf("%d", &year);
				change_birth_date(var_student, day, month,
									year);
				break;
			case 6:
				printf("Enter new year\n");
				scanf("%d", &study_year);
				change_year(var_student, study_year);
				break;
			case 7:
				printf("Enter new semester\n");
				scanf("%d", &semester);
				change_semester(var_student, semester);
				break;
			case 8:
				change_marks(var_student);
				break;
			default:
				printf("No valid decision\n");
				printf("Do you want to try again [y/n] ");
				scanf("%c", &decision);

				while (decision != 'y' || decision != 'n') {
					scanf("%c", &decision);
				}
				if (decision == 'n') {
					return;
				}
				if (decision == 'y') {
					setters_handler(student_array,
							num_of_students);
				}
		}
	} else {
		printf("No student with that serial number present\n");
		printf("Do you want to try again [y/n] ");
		scanf("%c", &decision);

		while (decision != 'y' || decision != 'n') {
			scanf("%c", &decision);
		}
		if (decision == 'n') {
			return;
		}
		if (decision == 'y') {
			setters_handler(student_array, num_of_students);
		}
	}
}

void change_serial_number(student *student, int new_serial_number)
{
	student->serial_number = new_serial_number;
}

void change_name(student *var_student, char *new_name)
{
	var_student->name = new_name;
}

void change_surname(student *var_student, char *new_surname)
{
	var_student->surname = new_surname;
}

void change_age(student *var_student, int new_age)
{
	var_student->age = new_age;
	var_student->year_of_birth = 2021 - new_age;
}

void change_birth_date(student *var_student, int new_day, int new_month,
								int new_year)
{
	var_student->day_of_birth = new_day;
	var_student->month_of_birth = new_month;
	var_student->year_of_birth = new_year;
	var_student->age = generate_age(new_year);
}

void change_year(student *var_student, int new_year)
{
	var_student->year = new_year;
	var_student->semester = generate_semester(new_year);

}

void change_semester(student *var_student, int new_semester)
{
	var_student->semester = new_semester;

	if (new_semester == 1 || new_semester == 2) {
		var_student->year = 1;
	} else if (new_semester == 3 || new_semester == 4) {
		var_student->year = 2;
	} else if (new_semester == 5 || new_semester == 6) {
		var_student->year = 3;
	} else if (new_semester == 7 || new_semester == 8) {
		var_student->year = 4;
	}  else if (new_semester == 9 || new_semester == 10) {
		var_student->year = 5;
	}
}

void change_marks(student *var_student)
{
	char dec[5];
	float new_mark;

	for (int i = 0; i < 5; i++) {

		printf("Do you want to change mark at %d (%.2f)? [y/n] ", i,
							var_student->marks[i]);
		scanf("%s", dec);

		while (strcmp(dec, "y") != 0 && strcmp(dec, "n") != 0) {
			scanf("%s", dec);
		}
		if (strcmp(dec, "y") == 0) {
			printf("Please enter new mark");
			scanf("%f", &new_mark);
			var_student->marks[i] = new_mark;
		} else {
			continue;
		}
	}
	var_student->average = calculate_average(var_student->marks);
}
