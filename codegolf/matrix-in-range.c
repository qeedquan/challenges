/*

The Challenge
Given an integer n>0 output a n+1 X n+1 matrix containing all integers from 1 to 2n as shown in the test cases bellow

Test Cases
n=1

1  2
2  2

n=2

1   2   4
2   3   4
4   4   4

n=5

1   2   3   4   5   10
2   3   4   5   6   10
3   4   5   6   7   10
4   5   6   7   8   10
5   6   7   8   9   10
10  10  10  10  10  10

n=10

1   2   3   4   5   6   7   8   9   10  20
2   3   4   5   6   7   8   9   10  11  20
3   4   5   6   7   8   9   10  11  12  20
4   5   6   7   8   9   10  11  12  13  20
5   6   7   8   9   10  11  12  13  14  20
6   7   8   9   10  11  12  13  14  15  20
7   8   9   10  11  12  13  14  15  16  20
8   9   10  11  12  13  14  15  16  17  20
9   10  11  12  13  14  15  16  17  18  20
10  11  12  13  14  15  16  17  18  19  20
20  20  20  20  20  20  20  20  20  20  20
I think that the pattern is pretty easy, so let's see who will give the shortest answer in bytes.
This is code-golf

Rules
Input must be an integer (1-indexed)

Output can be a matrix (as shown in the test cases) or a list of lists

*/

#include <stdio.h>
#include <math.h>

#define N 11

void
matdump(size_t n, unsigned m[N][N])
{
	size_t i, j;
	int l;

	l = 1;
	if (n)
		l += ceil(log2(n));

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			printf("%*d", l, m[i][j]);
		printf("\n");
	}
	printf("\n");
}

void
matrange(size_t n, unsigned m[N][N])
{
	size_t i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			m[i][j] = i + j + 1;

		m[i][n] = m[n][i] = n << 1;
	}
	m[n][n] = n << 1;
}

void
test(size_t n)
{
	unsigned m[N][N];

	matrange(n, m);
	printf("n=%zu\n", n);
	matdump(n + 1, m);
}

int
main(void)
{
	size_t i;

	for (i = 0; i < N; i++)
		test(i);

	return 0;
}
