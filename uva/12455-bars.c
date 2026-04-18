/*

Some things grow if you put them together.
We have some metallic bars, theirs length known, and, if necessary, we want to solder some of them
in order to obtain another one being exactly a given length long. No bar can be cut up. Is it possible?

Input
The first line of the input contains an integer,t, 0 ≤ t ≤ 50, indicating the number of test cases. For
each test case, three lines appear, the first one contains a number n, 0 ≤ n ≤ 1000, representing the
length of the bar we want to obtain. The second line contains a number p, 1 ≤ p ≤ 20, representing the
number of bars we have. The third line of each test case contains p numbers, representing the length
of the p bars.

Output
For each test case the output should contain a single line, consists of the string ‘YES’ or the string ‘NO’,
depending on whether solution is possible or not.

Sample Input
4
25
4
10 12 5 7
925
10
45 15 120 500 235 58 6 12 175 70
120
5
25 25 25 25 25
0
2
13 567

Sample Output
NO
YES
NO
YES

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define bit(x) (1ULL << (x))

bool
solve(int *a, size_t n, int t)
{
	size_t i, j;
	int s;

	for (i = 0; i < bit(n); i++) {
		s = 0;
		for (j = 0; j < n; j++) {
			if (i & bit(j))
				s += a[j];
		}
		if (s == t)
			return true;
	}
	return false;
}

int
main()
{
	int a1[] = { 10, 12, 5, 7 };
	int a2[] = { 45, 15, 120, 500, 235, 58, 6, 12, 175, 70 };
	int a3[] = { 25, 25, 25, 25, 25 };
	int a4[] = { 13, 567 };

	assert(solve(a1, nelem(a1), 25) == false);
	assert(solve(a2, nelem(a2), 925) == true);
	assert(solve(a3, nelem(a3), 120) == false);
	assert(solve(a4, nelem(a4), 0) == true);

	return 0;
}
