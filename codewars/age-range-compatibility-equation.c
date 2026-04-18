/*

Description:

Everybody knows the classic "half your age plus seven" dating rule that a lot of people follow (including myself). It's the 'recommended' age range in which to date someone.

Min = Age/2 + 7
Max = Age*2 + 7
Min <= Your Age <= Max

Task

Given an integer (1 <= n <= 100) representing a person's age, return their minimum and maximum age range.

This equation doesn't work when the age <= 14, so if the age <= 14, use this equation instead:

min = age - 0.10 * age
max = age + 0.10 * age

You should floor all your answers so that an integer is given instead of a float (which doesn't represent age). Return your answer in the form "[min]-[max]"
Examples:

age = 27   =>   "20-40"
age = 5    =>   "4-5"
age = 17   =>   "15-20"

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

char *
daterange(int age, char *output)
{
	if (age > 14)
		sprintf(output, "%d-%d", (age / 2) + 7, (age - 7) * 2);
	else
		sprintf(output, "%.0f-%.0f", floor(0.9 * age), floor(1.1 * age));
	return output;
}

void
test(int age, const char *expected)
{
	char output[32];

	daterange(age, output);
	puts(output);
	assert(!strcmp(output, expected));
}

int
main()
{
	test(17, "15-20");
	test(40, "27-66");
	test(15, "14-16");
	test(35, "24-56");
	test(10, "9-11");

	return 0;
}
