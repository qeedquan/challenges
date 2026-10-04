/*

Why is the number 6174 so interesting? As defined by Wikipedia

Take any four-digit number, using at least two different digits. (Leading zeros are allowed.)
Arrange the digits in ascending and then in descending order to get two four-digit numbers, adding leading zeros if necessary.
Subtract the smaller number from the bigger number.
Go back to step 2.
The above process, known as Kaprekar's routine, will always reach 6174 in at most 7 iterations. Once 6174 is reached, the process will continue yielding it.

Write a program which runs the Kaprekar's routine against a given four-digit number (see definition above) printing out each step of the routine.

Rules:

Submissions must be complete programs.
Input must be read from standard input. Piping from echo is OK.
Input should be in numeric form.
Printing out leading zeros is required. (See examples below.)
Last line should say how many iterations were needed. Punctuation is required.
Examples:

> 2607
7620 - 0267 = 7353
7533 - 3357 = 4176
7641 - 1467 = 6174
Iterations: 3.

> 1211
2111 - 1112 = 0999
9990 - 0999 = 8991
9981 - 1899 = 8082
8820 - 0288 = 8532
8532 - 2358 = 6174
Iterations: 5.

> 6174
7641 - 1467 = 6174
Iterations: 1.
Any programming language is welcome. Extra points for esoteric ones + a small bounty.

Update 1: There is already a similar question.
https://codegolf.stackexchange.com/questions/1255/hitting-495-kaprekar

Update 2: Added example for 6174 as input. Thanks to Peter Taylor for the notice.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int
mincmp(const void *a, const void *b)
{
	char x, y;

	x = *(char *)a;
	y = *(char *)b;
	if (x < y)
		return -1;
	if (x > y)
		return 1;
	return 0;
}

int
maxcmp(const void *a, const void *b)
{
	return -mincmp(a, b);
}

int
iterations(int n)
{
	char a[128], b[128];
	int na, nb;
	int c;

	for (c = 1; c < INT_MAX; c++) {
		na = snprintf(a, sizeof(a), "%04d", n);
		nb = snprintf(b, sizeof(b), "%04d", n);

		qsort(a, na, sizeof(*a), mincmp);
		qsort(b, nb, sizeof(*b), maxcmp);

		n = atoi(b) - atoi(a);
		if (n == 6174)
			break;
	}
	return c;
}

int
main()
{
	assert(iterations(2607) == 3);
	assert(iterations(1211) == 5);
	assert(iterations(6174) == 1);

	return 0;
}
