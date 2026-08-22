/*

In this exercise, you will create a function that takes an integer, i. With it you must do the following:

Find all of its multiples up to and including 100,

Then take the digit sum of each multiple (eg. 45 -> 4 + 5 = 9),

And finally, get the total sum of each new digit sum.

Note: If the digit sum of a number is more than 9 (eg. 99 -> 9 + 9 = 18) then you do NOT have to break it down further until it reaches one digit.

Example (if i is 25):

Multiples of 25 up to 100 --> [25, 50, 75, 100]

Digit sum of each multiple --> [7, 5, 12, 1]

Sum of each new digit sum --> 25

If you can, try writing it in readable code.

*/

#include <assert.h>
#include <stdio.h>

int
digsum(int n)
{
	int r;

	for (r = 0; n > 0; n /= 10)
		r += n % 10;
	return r;
}

int
procedure(int n)
{
	int i, r;

	r = 0;
	for (i = 1; i <= 100; i++) {
		if (!(i % n))
			r += digsum(i);
	}
	return r;
}

int
main()
{
	assert(procedure(25) == 25);
	assert(procedure(30) == 18);
	assert(procedure(12) == 72);
	assert(procedure(49) == 30);
	assert(procedure(17) == 48);
	assert(procedure(10) == 46);

	return 0;
}
