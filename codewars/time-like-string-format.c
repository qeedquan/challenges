/*

Build up a method that takes an integer and formats it to a 'time - like' format.

The method must raise an exception if its hour length is less than 3 digits and greater than 4.

Example:
solution(800); // should return '8:00'
solution(1000); // should return '10:00'
solution(1451); // should return '14:51'
solution(3351); // should return '33:51'
solution(10000); // should raise an exception

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
solution(int value, char *buffer)
{
	if (value < 100 || value > 9999)
		return NULL;

	sprintf(buffer, "%d:%02d", value / 100, value % 100);
	return buffer;
}

void
test(int value, const char *expected)
{
	char buffer[32];
	char *string;

	string = solution(value, buffer);
	if (!expected)
		assert(string == expected);
	else {
		assert(string);
		puts(string);
		assert(!strcmp(string, expected));
	}
}

int
main()
{
	test(800, "8:00");
	test(1000, "10:00");
	test(1451, "14:51");
	test(3351, "33:51");
	test(10000, NULL);

	return 0;
}
