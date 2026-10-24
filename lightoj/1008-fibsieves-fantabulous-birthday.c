/*

Fibsieve had a fantabulous (yes, it's an actual word) birthday party this year. He had so many gifts that he was actually thinking of not having a party next year. Among these gifts there was an N x N glass chessboard that had a light in each of its cells. When the board was turned on a distinct cell would light up every second, and then go dark.

The cells would light up in the sequence shown in the diagram. Each cell is marked with the second in which it would light up.

25	24	23	22	21
10	11	12	13	20
9	8	7	14	19
2	3	6	15	18
1	4	5	16	17
In the first second the light at cell (1, 1) would be on. And in the 5th second the cell (3, 1) would be on. Now, Fibsieve is trying to predict which cell will light up at a certain time (given in seconds). Assume that N is large enough.

Input
Input starts with an integer T (≤ 200), denoting the number of test cases.

Each case will contain an integer S (1 ≤ S ≤ 10^15) which stands for the time.

Output
For each case you have to print the case number and two numbers (x, y), the column and the row number.

Sample
Input	Output
3
8
20
25

Case 1: 2 3
Case 2: 5 4
Case 3: 1 5

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

typedef long long vlong;

void
swap(vlong *a, vlong *b)
{
	vlong t;

	t = *a;
	*a = *b;
	*b = t;
}

int
solve(vlong s, vlong *x, vlong *y)
{
	vlong b, i, m;

	if (s < 1)
		return -1;

	i = sqrt(s - 1);
	b = i * i + 1;
	m = b + i;

	*x = (s > m) ? 0 : s - m;
	*y = (s > m) ? m - s : 0;
	if (!(i & 1))
		swap(x, y);
	*x += i + 1;
	*y += i + 1;
	return 0;
}

void
test(vlong s, vlong rx, vlong ry)
{
	vlong x, y;

	solve(s, &x, &y);
	printf("%lld %lld\n", x, y);
	assert(x == rx);
	assert(y == ry);
}

int
main()
{
	test(8, 2, 3);
	test(20, 5, 4);
	test(25, 1, 5);

	return 0;
}
