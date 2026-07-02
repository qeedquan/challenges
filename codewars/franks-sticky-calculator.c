/*

Frank just bought a new calculator. But, this is no normal calculator. This is a 'Sticky Calculator.

Whenever you add add, subtract, multiply or divide two numbers the two numbers first stick together:

For instance:

50 + 12 becomes 5012
and then the operation is carried out as usual:

(5012) + 12 = 5024

Task
It is your job to create a function which takes 3 parameters:

stickyCalc(operation, val1, val2)
which works just like Frank's sticky calculator

Some Examples
stickyCalc('+', 50, 12)     // Output: (5012 + 12) = 5024
stickyCalc('-', 7, 5)       // Output: (75 - 5) = 70
stickyCalc('*', 13, 20)     // Output: (1320 * 20 ) = 26400
stickyCalc('/', 10, 10)     // Output: (1010 / 10) = 101

Note
The calculator only works for positive integers only.
The calculator rounds any non-integer before operating.
The calculator rounds any output to nearest integer.

For example:

stickyCalc('/', 12.1, 6.8), 18;

12.1 and 6.8 are rounded to 12 and 7 respectively & they 'stick together' to make 127.


Although 127 / 7 = 18.1428 ; 18 is outputted instead.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

int
stickycalc(int op, double x, double y)
{
	double p;
	int r;

	if (x < 0 || y < 0)
		return 0;

	p = ceil(log10(y + 1));
	x = x * pow(10, p) + y;
	switch (op) {
	case '+':
		r = x + y;
		break;
	case '-':
		r = x - y;
		break;
	case '*':
		r = x * y;
		break;
	case '/':
		r = x / y;
		break;
	default:
		r = 0;
		break;
	}
	return round(r);
}

int
main()
{
	assert(stickycalc('+', 50, 12) == 5024);
	assert(stickycalc('-', 7, 5) == 70);
	assert(stickycalc('*', 13, 20) == 26400);
	assert(stickycalc('/', 10, 10) == 101);
	assert(stickycalc('/', 12.1, 6.8) == 18);
	return 0;
}
