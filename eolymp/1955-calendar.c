/*

Little Nikifor constantly forgets how old he is. That is why his parents hung a calendar in his room with his birthday specially marked.
However, Nikifor does not know how to calculate his age based on his birth date and the current date. Help him!

Input
The first line of the input file contains three natural numbers: the day, month, and year of Nikifor's birth.
The second line contains the current date in the same format.
The years in both dates do not exceed 10^5.
It is guaranteed that Nikifor's birth date is strictly earlier than the current date.

Output
Print a single number — Nikifor's age.

Examples

Input #1
12 4 2003
17 7 2010

Answer #1
7

Input #5
12 4 2003
30 3 5010

Answer #5
3006

*/

#include <assert.h>

int
solve(int d1, int m1, int y1, int d2, int m2, int y2)
{
	int r;

	r = y2 - y1;
	if (!(m2 > m1 || (m2 == m1 && d2 >= d1)))
		r -= 1;
	return r;
}

int
main()
{
	assert(solve(12, 4, 2003, 17, 7, 2010) == 7);
	assert(solve(12, 4, 2003, 30, 3, 5010) == 3006);

	return 0;
}
