#ifndef STUDENT_H
#define STUDENT_H

typedef struct student
{
	int serial_number;
	char *name;
	char *surname;
	int age;
	int day_of_birth;
	int month_of_birth;
	int year_of_birth;
	int year;
	int semester;
	float *marks;
	float average;
} student;

// Generate individual student
student generate_student();

// Generate student with user specified data
student user_generate_student();

// Functions to change student's info
student change_serial_number(student var_student, int serial_number);
student change_name(student var_student, char *name, int serial_number);
student change_surname(student var_student, char *surname, int serial_number);
student change_age(student var_student, int age, int serial_number);
student change_birth_date(student var_student, int day, int month, int year,
				int serial_number);
student change_year(student var_student, int year, int serial_number);
student change_semester(student var_student, int semester, int serial_number);
student change_marks(student var_student, float *marks, int serial_number);

// Helper functions
void print_student();
void print_all_students();
student *binary_search(student *students, int l, int r, int serial_number);

#endif
