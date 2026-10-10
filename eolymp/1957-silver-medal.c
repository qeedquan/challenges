/*

Vasiliy competed in hokkeybol and won a silver medal in the individual event.
It is known that participants who scored the same number of points will be awarded the same awards.
It is also known that gold, silver, and bronze medals were awarded.
The rules of hokkeybol are not important for this problem.
You only need to determine how many points were scored by Vasiliy.

Input
The first line contains the number of athletes n (2≤n≤1000) participating in competitions. In the second line n integers are given - the results of competition.

Output
Print one integer - the result of Vasiliy.

Examples
Input #1
5
4 3 3 1 2

Answer #1
3

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
solve(int *a, size_t n)
{
	int m, p;
	size_t i;

	m = p = -1;
	for (i = 0; i < n; i++) {
		if (a[i] == m || a[i] == p)
			continue;
		else if (a[i] > m) {
			p = m;
			m = a[i];
		} else if (a[i] > p)
			p = a[i];
	}
	return p;
}

int
main()
{
	int a1[] = { 4, 3, 3, 1, 2 };

	assert(solve(a1, nelem(a1)) == 3);

	return 0;
}
