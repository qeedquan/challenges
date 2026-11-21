/*

Write a function sumTimesTables which sums the result of the sums of the elements specified in tables multiplied by all the numbers in between min and max including themselves.

For example, for sumTimesTables([2,5],1,3) the result should be the same as

2*1 + 2*2 + 2*3 +
5*1 + 5*2 + 5*3
i.e. the table of two from 1 to 3 plus the table of five from 1 to 3

All the numbers are integers but you must take in account:

tables could be empty.
min could be negative.
max could be really big.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
sumtimes(int *tab, size_t len, int min, int max)
{
	size_t i;
	int mid;
	int sum;

	mid = (max - min + 1) * ((min + max) / 2.0);
	sum = 0;
	for (i = 0; i < len; i++)
		sum += mid * tab[i];
	return sum;
}

int
main()
{
	int tab1[] = { 2, 3 };
	int tab2[] = { 1, 3, 5 };
	int tab3[] = { 1, 3, 5 };

	assert(sumtimes(tab1, nelem(tab1), 1, 3) == 30);
	assert(sumtimes(tab2, nelem(tab2), 1, 1) == 9);
	assert(sumtimes(tab3, nelem(tab3), 1, 10) == 495);

	return 0;
}
