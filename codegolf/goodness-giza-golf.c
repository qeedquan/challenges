/*

A "Giza number", also colloquially known as a Timmy Number is any number where the digits represent a pyramid (A134810). For example, "12321" is a giza number because it can be visualized like this:

  3
 2 2
1   1
However, something like "123321" is not a Giza number because there are two digits at the top of the pyramid

  33
 2  2
1    1
In other words, a number is a Giza number if all of the following conditions are met:

It has an odd number of digits, and the center digit is the largest

It's palindromic (the same read forwards or backwards), and

The first half of the digits are strictly increasing by one. (Since it must be palindromic, this means the second half of the digits must be strictly decreasing by one)

You must write a full program or a function that takes a positive integer as input, and determine if it is a Giza number or not. You may take the input as a string or as a number. If it is a Giza number, output a truthy value. Otherwise, a falsy value.

There are a total of 45 Giza numbers, so any one of these inputs should result in a truthy value:

1
2
3
4
5
6
7
8
9
121
232
343
454
565
676
787
898
12321
23432
34543
45654
56765
67876
78987
1234321
2345432
3456543
4567654
5678765
6789876
123454321
234565432
345676543
456787654
567898765
12345654321
23456765432
34567876543
45678987654
1234567654321
2345678765432
3456789876543
123456787654321
234567898765432
12345678987654321

Any other input should give a falsy value. Of course, you do not have to handle invalid inputs, such as non-positive numbers, non-integers, or non-numbers.

As usual, this is code-golf, so standard loopholes are banned, and the shortest answer in bytes wins!

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

int
cmp(const void *a, const void *b)
{
	uvlong x, y;

	x = *(uvlong *)a;
	y = *(uvlong *)b;
	if (x < y)
		return -1;
	if (x == y)
		return 0;
	return 1;
}

// https://oeis.org/A134810
bool
giza(uvlong n)
{
	static const uvlong tab[] = {
	    1,
	    2,
	    3,
	    4,
	    5,
	    6,
	    7,
	    8,
	    9,
	    121,
	    232,
	    343,
	    454,
	    565,
	    676,
	    787,
	    898,
	    12321,
	    23432,
	    34543,
	    45654,
	    56765,
	    67876,
	    78987,
	    1234321,
	    2345432,
	    3456543,
	    4567654,
	    5678765,
	    6789876,
	    123454321,
	    234565432,
	    345676543,
	    456787654,
	    567898765,
	    12345654321,
	    23456765432,
	    34567876543,
	    45678987654,
	    1234567654321,
	    2345678765432,
	    3456789876543,
	    123456787654321,
	    234567898765432,
	    12345678987654321,
	};

	return bsearch(&n, tab, nelem(tab), sizeof(*tab), cmp) != NULL;
}

int
main()
{
	static const uvlong tab[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 121, 232, 343, 454, 565, 676, 787, 898, 12321, 23432, 34543, 45654, 56765, 67876, 78987, 1234321, 2345432, 3456543, 4567654, 5678765, 6789876};

	uvlong i, j, n;

	n = tab[nelem(tab) - 1];
	for (i = j = 0; i <= n; i++) {
		if (i == tab[j]) {
			assert(giza(i) == true);
			j += 1;
		} else
			assert(giza(i) == false);
	}

	return 0;
}
