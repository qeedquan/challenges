/*

In a medieval city, it was decided to install a special display on the main square to show the current year.
Since there were no computers in the Middle Ages, this display was made of stone.

The display has four digits, allowing any year up to 9999 to be shown.
To ensure that the residents of the city could easily see the current year, the digits were made large and heavy.

This display was not electronic; the digits had to be changed manually using rather primitive mechanical devices.
These devices consisted of various blocks and levers, mysteriously interconnected. Each device was designed for changing exactly one digit,
and was so fragile that it immediately broke after use.

As the city's chief sage and astrologer, your task is to calculate how many such devices are needed for the display to
operate properly if it is to be used from year n to year 9999 inclusive.

Input
The input file contains an integer n (1000≤n≤9999).

Output
Output the answer to the problem in the output file.

Examples

Input #1
9989

Answer #1
11

*/

#include <assert.h>

int
solve(int n)
{
	int a, b, c, t;

	if (!(1000 <= n && n <= 9999))
		return 0;

	t = 10000 - n - 1;
	a = t / 10;
	b = t / 100;
	c = t / 1000;
	return t + a + b + c;
}

int
main()
{
	assert(solve(9989) == 11);

	return 0;
}
