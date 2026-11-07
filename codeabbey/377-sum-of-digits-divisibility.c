/*

Let's regard sum of digits for first few positive numbers, and remainders they give when divided by 10:

value   sum-of-digits   SD % 10
  1           1            1
  2           2            2
             ...
  9           9            9
 10           1            1
 11           2            2
             ...
 18           9            9
 19          10            0
             ...
 99          18            8
100           1            1
Thus the first sum-of-digits which is divisible by 10 is for number 19. The next is for number 28. It is a bit annoying that remainders do not follow exact order, you see after 99 remainder "jumps" from 8 to 1.

We want to calculate for given K the k-th number for which sum of digits is divisible by 10.

Input data: number T of the testcases to follow is in the first line.
Next T lines contain single integer each - the value K.

Answers should be given as usually, as T values separated with spaces.

Example

input data:
3
1
2
10

answer:
19 28 109

*/

#include <assert.h>
#include <stdio.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
digsum(int n)
{
	int r;

	for (r = 0; n; n /= 10)
		r += n % 10;
	return r;
}

// https://oeis.org/A052224 (related)
int
solve(int k)
{
	int i;

	if (k < 1)
		return 0;

	for (i = 1; i < INT_MAX; i++) {
		if (!(digsum(i) % 10)) {
			k -= 1;
			if (k <= 0)
				return i;
		}
	}
	return 0;
}

int
main()
{
	assert(solve(1) == 19);
	assert(solve(2) == 28);
	assert(solve(10) == 109);

	return 0;
}
