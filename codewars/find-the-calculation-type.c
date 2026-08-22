/*

You have to create a function calcType, which receives 3 arguments: 2 numbers, and the result of an unknown operation performed on them (also a number).

Based on those 3 values you have to return a string, that describes which operation was used to get the given result.

The possible return strings are: "addition", "subtraction", "multiplication", "division".

Example:
calcType(1, 2, 3) -->   1 ? 2 = 3   --> "addition"

Notes
In case of division you should expect that the result of the operation is obtained by using / operator on the input values - no manual data type conversion or rounding should be performed.
Cases with just one possible answers are generated.
Only valid arguments will be passed to the function.
Only valid arguments will be passed to the function!

*/

#include <assert.h>
#include <string.h>

const char *
calc(int a, int b, int c)
{
	if (a + b == c)
		return "addition";
	if (a - b == c)
		return "subtraction";
	if (a * b == c)
		return "multiplication";
	if (b && a / b == c)
		return "division";
	return "unknown";
}

int
main()
{
	assert(!strcmp(calc(1, 2, 3), "addition"));
	assert(!strcmp(calc(55, 13, 42), "subtraction"));
	assert(!strcmp(calc(2, 5, 10), "multiplication"));
	assert(!strcmp(calc(6, 2, 3), "division"));

	return 0;
}
