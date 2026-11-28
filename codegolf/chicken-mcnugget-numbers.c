/*

Description
Chicken McNugget numbers are numbers that can be expressed as a sum of  6, 9 or 20 - the initial sizes of the famous Chicken McNuggets boxes sold by McDonald's.

In that sum, a number may occur more than once, so  6+6=12 is such a number too,
and the number must "contain" at least one of the mentioned sizes.
The first Chicken McNugget numbers are:

6
9
6+6=12
6+9=15
9+9=6+6+6=18
20
6+6+9=21…

Challenge
Your task is to write a program or function, that, given a positive integer,
determines whether this number can be expressed in the described way, therefore is such a Chicken McNugget number.
It should then output a truthy or falsy value based on its decision.

Test cases
6 -> true
7 -> false
12 -> true
15 -> true
21 -> true
40 -> true
42 -> true

This is code-golf, so the shortest answer in bytes wins and the standard loopholes apply!

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
cmp(const void *a, const void *b)
{
	int x, y;

	x = *(int *)a;
	y = *(int *)b;
	if (x < y)
		return -1;
	if (x == y)
		return 0;
	return 1;
}

/*

https://mathworld.wolfram.com/McNuggetNumber.html

All integers are McNugget numbers except 1, 2, 3, 4, 5, 7, 8, 10, 11, 13, 14, 16, 17, 19, 22, 23, 25, 28, 31, 34, 37, and 43.
The value 43 therefore corresponds to the Frobenius number of {6,9,20}.

*/

bool
iscmg(int n)
{
	static const int tab[] = {
		1, 2, 3, 4, 5, 7, 8, 10, 11, 13, 14, 16, 17, 19, 22, 23, 25, 28, 31,
		34, 37, 43
	};

	if (n < 1)
		return false;
	return bsearch(&n, tab, nelem(tab), sizeof(*tab), cmp) == NULL;
}

int
main()
{
	assert(iscmg(6) == true);
	assert(iscmg(7) == false);
	assert(iscmg(12) == true);
	assert(iscmg(15) == true);
	assert(iscmg(21) == true);
	assert(iscmg(40) == true);
	assert(iscmg(42) == true);

	return 0;
}
