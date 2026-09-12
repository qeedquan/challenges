/*

A person has to complete N units of work; the nature of work is the same.

In order to get the hang of the work, he completes only one unit of work in the first day.

He wishes to celebrate the completion of work, so he decides to complete one unit of work in the last day.

He is only allowed to complete x, x+1 or x-1 units of work in a day, where x is the units of work completed on the previous day.

Your task is to create a program or function that will compute the minimum number of days will he take to complete N units of work.

Sample Input and Ouput:
input -> output (corresponding work_per_day table)
-1    -> 0      []
0     -> 0      []
2     -> 2      [1,1]
3     -> 3      [1,1,1]
5     -> 4      [1,1,2,1] or [1,2,1,1]
9     -> 5      [1,2,3,2,1]
13    -> 7      [1,2,2,2,3,2,1]
Input may be taken through STDIN or as function argument, or in any appropriate way.

Output may be printed or as the result of a function, or in any appropriate way.

This is code-golf. Shortest solution wins.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

// https://oeis.org/A000267
int
days(int n)
{
	if (n < 1)
		return 0;
	return sqrt((4 * n) - 1);
}

int
main()
{
	static const int tab[] = {1, 2, 3, 3, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 11, 11, 11, 11, 11, 11, 12, 12, 12, 12, 12, 12, 13, 13, 13, 13, 13, 13, 13, 14, 14, 14, 14, 14, 14, 14, 15, 15, 15, 15, 15, 15, 15, 15, 16, 16, 16, 16, 16, 16, 16, 16, 17, 17, 17, 17, 17};

	size_t i;

	assert(days(-1) == 0);
	assert(days(0) == 0);
	assert(days(2) == 2);
	assert(days(3) == 3);
	assert(days(5) == 4);
	assert(days(9) == 5);
	assert(days(13) == 7);

	for (i = 0; i < nelem(tab); i++)
		assert(days(i + 1) == tab[i]);

	return 0;
}
