/*

OlimpTel, a mobile operator, wants to determine the number of subscribers in its network.
Each phone number consists of a "+" sign followed by 12 digits, such as: +381234567890.
For convenience, phone numbers may include separator symbols like "-", for example:

+38-123-456-78-90.

The template for a phone number assigned to OlimpTel is represented as a standard phone number, where some digits are replaced with the symbols "X", "Y", "Z":

X – represents any digit from 0 to 9;

Y – represents any digit from 0 to 5;

Z – represents any digit from 6 to 9;

Given the template of an OlimpTel phone number, calculate the total number of phone numbers that conform to this template.

Input
The first line contains a string representing the phone number template.

Output
Print the total number of phone numbers that match the provided template.

Examples

Input #1
+380905064X86

Answer #1
10

*/

#include <assert.h>

typedef unsigned long long uvlong;

uvlong
solve(const char *s)
{
	uvlong r;

	for (r = 1; *s; s++) {
		switch (*s) {
		case 'X':
			r *= 10;
			break;

		case 'Y':
			r *= 6;
			break;

		case 'Z':
			r *= 4;
			break;
		}
	}
	return r;
}

int
main()
{
	assert(solve("+380905064X86") == 10);

	return 0;
}
