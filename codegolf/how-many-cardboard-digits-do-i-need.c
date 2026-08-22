/*

I need to prepare digits made of cardboard to display some number (example). I don't know beforehand which number I should display - the only thing I know is that it's not greater than n.

How many cardboard digits should I prepare?

Example: n = 50

To display any number in the range 0...50, I need the following digits:

A zero, for displaying the number 0, or any other round number
Two copies of digits 1, 2, 3 and 4, for displaying the corresponding numbers
One copy of digits 5, 6, 7 and 8, for the case they appear as least significant digit in the number
The digit 9 is never needed, because I can use the inverted digit 6 instead
Total: 13 digits

Test cases (each line is a test case in the format "input; output")

0 1
1 2
9 9
11 10
50 13
99 17
100 18
135 19
531 22
1000 27
8192 34
32767 38

*/

#include <assert.h>
#include <math.h>

typedef unsigned long long uvlong;

uvlong
diglen(uvlong n)
{
	uvlong r;

	r = 0;
	do {
		r += 1;
		n /= 10;
	} while (n);

	return r;
}

/*

@xnor

lambda n:9*len(`n`)-9+(n*9+8)/10**len(`n`)+(n<10)

A clumsy arithmetical formula. Assume that n fits within an int so that an L isn't appended.

Thanks to Neil for saving 5 bytes by pointing out that 9's being unused could be handled by doing n*9+8 instead of n*9+9, so that, say, 999*9+8=8999 doesn't roll over to 9000.

*/

uvlong
cbd(uvlong n)
{
	uvlong l, r;

	l = diglen(n);
	r = (9 * l) - 9 + (n * 9 + 8) / pow(10, l);
	if (n < 10)
		r += 1;
	return r;
}

int
main()
{
	assert(cbd(0) == 1);
	assert(cbd(1) == 2);
	assert(cbd(9) == 9);
	assert(cbd(11) == 10);
	assert(cbd(50) == 13);
	assert(cbd(99) == 17);
	assert(cbd(100) == 18);
	assert(cbd(135) == 19);
	assert(cbd(531) == 22);
	assert(cbd(1000) == 27);
	assert(cbd(8192) == 34);
	assert(cbd(32767) == 38);

	return 0;
}
