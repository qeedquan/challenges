/*

Given a year Y and a month M, return how many days there are in that month.

Example 1:

Input: Y = 1992, M = 7
Output: 31

Example 2:

Input: Y = 2000, M = 2
Output: 29
Example 3:

Input: Y = 1900, M = 2
Output: 28

Note:

1583 <= Y <= 2100
1 <= M <= 12

*/

#include <assert.h>

int
isleap(int y)
{
	if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0))
		return 1;
	return 0;
}

int
days(int y, int m)
{
	if (m == 2)
		return 28 + isleap(y);
	return 31 - ((m - 1) % 7 % 2);
}

int
main()
{
	assert(days(1992, 7) == 31);
	assert(days(2000, 2) == 29);
	assert(days(1900, 2) == 28);

	return 0;
}
