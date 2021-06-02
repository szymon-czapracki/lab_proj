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
void change_serial_number(student *var_student, int serial_number);
void change_name(student *var_student, char *new_name);
void change_surname(student *var_student, char *new_surname);
void change_age(student *var_student, int age);
void change_birth_date(student *var_student, int day, int month, int year);
void change_year(student *var_student, int year);
void change_semester(student *var_student, int semester);
void change_marks(student *var_student);

// Helper functions
void print_student();
void print_all_students();

#endif
