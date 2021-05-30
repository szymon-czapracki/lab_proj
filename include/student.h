#ifndef STUDENT_H
#define STUDENT_H

typedef struct student {
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

student generate_student();
student change_serial_number(student var_student);
student change_name(student var_student);
student change_surname(student var_student);
student change_age(student var_student);
student change_birth_date(student var_student);
student change_year(student var_student);
student change_semester(student var_student);
student change_marks(student var_student);
student change_additional_data(student var_student);
void print_student();

#endif
