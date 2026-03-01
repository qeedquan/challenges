/*

A fountain is arrangement of coins in rows so that each coin touches two coins in the row below it, or is in the bottom row, and the bottom row is connected. Here's a 21 coin fountain:

https://i.stack.imgur.com/9BBBn.gif

Your challenge is to count how many different fountains can be made with a given number of coins.

You will be given as input a positive integer n. You must output the number of different n-coin fountains that exist.

Standard I/O rules, standard loopholes banned. Solutions should be able to calculate n = 10 in under a minute.

Desired output for n = 1 ... 10:

1, 1, 2, 3, 5, 9, 15, 26, 45, 78
This sequence is OEIS A005169.

This is code golf. Fewest bytes wins.

*/

#include <assert.h>
#include <stdio.h>

typedef long long vlong;

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

vlong
recurse(vlong n, vlong i)
{
	vlong j, k, r;

	r = 0;
	k = min(i + 2, n);
	for (j = 1; j < k; j++)
		r += recurse(n - j, j);
	return max(r, 1);
}

/*

https://oeis.org/A005169

@xnor

As observed on OEIS, if you shift each row half a step relative to the row below it, the column sizes form a sequence of positive integers with a maximum upward step of 1.

The function f(n,i) counts the sequences with sum n and last number i.
These can be recursively summed for each choice of the next column size from 1 to i+1, which is range(1,i+2).
Truncating to range(1,i+2)[:n] prevents columns from using more coins than remain, avoiding needing to say that negative n's give 0.
Moreover, it avoids an explicit base case, since the empty sum is 0 and doesn't recurse, but f(0) needs to be set to 1 instead, for which or 1 suffices (as would +0**n).

*/

vlong
fountains(vlong n)
{
	if (n < 1)
		return 0;
	return recurse(n, 0);
}

int
main(void)
{
	static const vlong tab[] = {1, 1, 1, 2, 3, 5, 9, 15, 26, 45, 78, 135, 234, 406, 704, 1222, 2120, 3679, 6385, 11081, 19232, 33379, 57933, 100550, 174519, 302903, 525734, 912493, 1583775, 2748893, 4771144, 8281088, 14373165, 24946955};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(fountains(i + 1) == tab[i]);

	return 0;
}
