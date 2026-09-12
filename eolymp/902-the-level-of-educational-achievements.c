/*

Determine the level of educational achievements of a pupil (initial, average, sufficient, high) based on the given grade (1 to 12).

Input
One integer — the pupil's grade.

Output
Print Initial for the initial level (grade from 1 to 3), Average for the average level (grade from 4 to 6),
Sufficient for the sufficient level (grade from 7 to 9), and High for the high level (grade from 10 to 12).

Examples

Input #1
12

Answer #1
High

*/

#include <stdio.h>

const char *
solve(int n)
{
	if (n <= 3)
		return "Initial";
	if (4 <= n && n <= 6)
		return "Average";
	if (7 <= n && n <= 9)
		return "Sufficient";
	return "High";
}

int
main()
{
	puts(solve(12));

	return 0;
}
