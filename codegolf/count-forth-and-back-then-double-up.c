/*

Let's count...

Count up to 2 and back to 1
Count up to 4 and back to 1
Count up to 6 and back to 1
... ok you got it...

put all these together and you'll get the following sequence

 {1,2,1,2,3,4,3,2,1,2,3,4,5,6,5,4,3,2,1,2,3,4,5,6,7,8,7,6,5,4,3,2,1,2,3...}
Challenge
Given an integer n>0
for 1-indexed (or n>=0 for 0-indexed), output the nth term of this sequence

Test cases

Input->Output

1->1
68->6
668->20
6667->63
10000->84
Rules

your program must be able to compute solutions up to n=10000 in under a minute

This is code-golf, so the shortest code in bytes wins!

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
forth(int n)
{
	int a, b, c, i;

	if (n < 1)
		return 0;

	a = 1;
	b = 2;
	c = 1;
	for (i = 1; i < n; i++) {
		if (a >= b && c > 0) {
			b += 2;
			c = -c;
		} else if (a <= 1 && c < 0)
			c = -c;
		a += c;
	}
	return a;
}

int
main(void)
{
	static const int tab[] = {1, 2, 1, 2, 3, 4, 3, 2, 1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1, 2, 3, 4, 5, 6, 7, 8, 7, 6, 5, 4, 3, 2, 1, 2, 3};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(forth(i + 1) == tab[i]);

	assert(forth(1) == 1);
	assert(forth(68) == 6);
	assert(forth(668) == 20);
	assert(forth(6667) == 63);
	assert(forth(10000) == 84);

	return 0;
}
