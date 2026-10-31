/*

We can roll up the natural numbers in a rectangular spiral:

 17--16--15--14--13
  |               |
 18   5---4---3  12
  |   |       |   |
 19   6   1---2  11
  |   |           |
 20   7---8---9--10
  |
 21--22--23--24--25
But now that we have them on a rectangular grid we can unwind the spiral in a different order, e.g. going clockwise, starting north:

 17  16--15--14--13
  |   |           |
 18   5   4---3  12
  |   |   |   |   |
 19   6   1   2  11
  |   |       |   |
 20   7---8---9  10
  |               |
 21--22--23--24--25
The resulting sequence is clearly a permutation of the natural numbers:

1, 4, 3, 2, 9, 8, 7, 6, 5, 16, 15, 14, 13, 12, 11, 10, 25, 24, 23, 22, 21, 20, 19, 18, 17, ...
Your task is to compute this sequence. (OEIS A020703, but spoiler warning: it contains another interesting definition and several formulae that you might want to figure out yourself.)

Fun fact: all 8 possible unwinding orders have their own OEIS entry.

The Challenge
Given a positive integer n, return the nth element of the above sequence.

You may write a program or function, taking input via STDIN (or closest alternative), command-line argument or function argument and outputting the result via STDOUT (or closest alternative), function return value or function (out) parameter.

Standard code-golf rules apply.

Test Cases
1       1
2       4
3       3
4       2
5       9
6       8
7       7
8       6
9       5
100     82
111     111
633     669
1000    986
5000    4942
9802    10000
10000   9802

For a complete list up to and including n = 11131 see the b-file on OEIS.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

// https://oeis.org/A020703
int
spiralperm(int n)
{
	int t;

	if (n < 1)
		return 0;

	t = sqrt(n - 1);
	return (2 * ((t * t) + t + 1)) - n;
}

int
main(void)
{
	static const int tab[] = {
		1, 4, 3, 2, 9, 8, 7, 6, 5, 16, 15, 14, 13, 12, 11, 10, 25, 24, 23, 22,
		21, 20, 19, 18, 17, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 49, 48,
		47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 64, 63, 62, 61, 60, 59, 58,
		57, 56, 55, 54, 53, 52, 51, 50, 81, 80, 79, 78, 77
	};

	size_t i;

	assert(spiralperm(100) == 82);
	assert(spiralperm(111) == 111);
	assert(spiralperm(633) == 669);
	assert(spiralperm(1000) == 986);
	assert(spiralperm(5000) == 4942);
	assert(spiralperm(9802) == 10000);
	assert(spiralperm(10000) == 9802);

	for (i = 0; i < nelem(tab); i++)
		assert(spiralperm(i + 1) == tab[i]);

	return 0;
}
