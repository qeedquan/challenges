/*

You're going on a trip with some students and it's up to you to keep track of how much money each Student has. A student is defined like this:

class Student {
  constructor(name, fives, tens, twenties) {
    this.name = name;
    this.fives = fives;
    this.tens = tens;
    this.twenties = twenties;
  }
}
As you can tell, each Student has some fives, tens, and twenties. Your job is to return the name of the student with the most money. If every student has the same amount, then return "all".

Notes:

Each student will have a unique name
There will always be a clear winner: either one person has the most, or everyone has the same amount
If there is only one student, then that student has the most money

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	char name[32];
	int fives;
	int tens;
	int twenties;
} Student;

const char *
mostmoney(Student *students, size_t length)
{
	Student *student;
	size_t count, index;
	int maximum, amount;
	const char *result;

	result = "";
	maximum = INT_MIN;
	for (count = index = 0; index < length; index++) {
		student = students + index;
		amount = student->fives * 5;
		amount += student->tens * 10;
		amount += student->twenties * 20;
		if (amount == maximum)
			count += 1;
		else if (amount > maximum) {
			maximum = amount;
			count = 1;
			result = student->name;
		}
	}
	if (count > 1 && count == length)
		result = "all";
	return result;
}

void
test(Student *students, size_t length, const char *expected)
{
	const char *result;

	result = mostmoney(students, length);
	puts(result);
	assert(!strcmp(result, expected));
}

int
main()
{
	Student phil = {"Phil", 2, 2, 1};
	Student cam = {"Cameron", 2, 2, 0};
	Student geoff = {"Geoff", 0, 3, 0};

	Student students_1[] = {cam, geoff, phil};
	Student students_2[] = {cam, geoff};
	Student students_3[] = {geoff};

	test(students_1, nelem(students_1), "Phil");
	test(students_2, nelem(students_2), "all");
	test(students_3, nelem(students_3), "Geoff");

	return 0;
}
