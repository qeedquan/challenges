/*

Consider N disks in the plane: C1, C2, . . . , CN such that, for all i, where 0 < i < N, we have the
center of Ci on the circumference of Ci+1, and the center of Cn on the circumference of C1.
What is the maximum number of pairs of disks (Ci, Cj ), with 1 ≤ i, j ≤ N such that Ci properly contains Cj.
Note, the set T properly contains, the set S, if and only if S ⊆ T and S ̸= T.

Input
A number of inputs (< 1000) with integer N (1 ≤ N ≤ 1000000).

Output
Output one line per input, the answer.

Sample Input
1
2
3

Sample Output
0
0
1

*/

#include <assert.h>

typedef long long vlong;

vlong
solve(vlong n)
{
	if (n < 3)
		return 0;
	return (n - 2) * (n - 1) / 2;
}

int
main()
{
	assert(solve(1) == 0);
	assert(solve(2) == 0);
	assert(solve(3) == 1);

	return 0;
}
