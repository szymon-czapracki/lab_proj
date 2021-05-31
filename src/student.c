#include <stdio.h>
#include "../include/student.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>


int generate_day() {
	return (rand() % (30 - 1 + 1)) + 1;
}

int generate_month() {
	return (rand() % (12 - 1 + 1)) + 1;
}

int generate_year() {
	return (rand() % (2000 - 1965 + 1)) + 1965;
}

int generate_age() {
	return 2020 - generate_year();
}

int generate_study_year() {
	return (rand() % (5 - 1 + 1)) + 1;
}

int generate_semester(int year) {
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

void generate_marks(float **marks) {

	free(*marks);

	*marks = malloc(5 * sizeof(float));

	for (int i = 0; i < 5; i++) {
		(*marks)[i] = ((float)rand()) / ((float)RAND_MAX) * 6.00;
	}
}

int generate_serial_number() {
	return (rand() % (2300 - 2199 + 1)) + 2199;
}

char *generate_name() {

	char *name;

	char *names_table[] = {"Szymon", "Jacek", "Adam", "Grzegorz",
					"Janusz", "Agata", "Beata",
					"Alicja", "Judyta", "Olga",
					"Aleksandra", "Marian", "Kamil"};

	int random_index = rand() % 13;

	name = names_table[random_index];

	return name;
}

int generate_year_of_birth(int age) {
	return 2020 - age;
}

float calculate_average(float *marks) {
	float sum;

	for (int i = 0; i < 5; i++) {
		sum += marks[i];
	}
	return sum / 5;
}

char *generate_surname() {

	char *surname;

	char *surnames[] = {"Kubik", "Lewa", "Szewin", "Malys",
				"Kulej", "Szurko", "Konopa", "Boniek",
				"Deyna", "Gollob", "Zasada", "Lato"};

	int random_index = rand() % 12;

	surname = surnames[random_index];

	return surname;
}

student generate_student() {

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

void print_student(student new_student) {
	printf("| | No. %-4d | | Name: %-10s | | Surname: %-10s | | Age: %-6d | ", new_student.serial_number,
			new_student.name, new_student.surname,
			new_student.age);


	printf("| Birth: %02d/%02d/%d | ", new_student.day_of_birth,
				new_student.month_of_birth,
				new_student.year_of_birth);

	printf("| Year: %-3d | | Semester: %-4d |", new_student.year, new_student.semester);

	printf(" | Marks: ");
	for (int i = 0; i < 5; i++) {
		printf(" %-10.2f ", new_student.marks[i]);
	}
	printf(" | | Average: %-4.2f | |\n", new_student.average);
}

