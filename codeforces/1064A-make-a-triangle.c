/*

Masha has three sticks of length a, b and c centimeters respectively. In one minute Masha can pick one arbitrary stick and increase its length by one centimeter. She is not allowed to break sticks.

What is the minimum number of minutes she needs to spend increasing the stick's length in order to be able to assemble a triangle of positive area. Sticks should be used as triangle's sides (one stick for one side) and their endpoints should be located at triangle's vertices.

Input
The only line contains tree integers a, b and c (1≤a,b,c≤100) — the lengths of sticks Masha possesses.

Output
Print a single integer — the minimum number of minutes that Masha needs to spend in order to be able to make the triangle of positive area from her sticks.

Examples
input
3 4 5
output
0

input
2 5 3
output
1

input
100 10 10
output

81

Note
In the first example, Masha can make a triangle from the sticks without increasing the length of any of them.

In the second example, Masha can't make a triangle of positive area from the sticks she has at the beginning, but she can spend one minute to increase the length 2 centimeter stick by one and after that form a triangle with sides 3, 3 and 5 centimeters.

In the third example, Masha can take 33 minutes to increase one of the 10 centimeters sticks by 33 centimeters, and after that take 48 minutes to increase another 10 centimeters stick by 48 centimeters. This way she can form a triangle with lengths 43, 58 and 100 centimeters in 81 minutes. One can show that it is impossible to get a valid triangle faster.

*/

#include <assert.h>
#include <stdio.h>

int
semiarea(int a, int b, int c)
{
	return (a + b + c) * (-a + b + c) * (a - b + c) * (a + b - c);
}

void
swap(int *x, int *y)
{
	int t;

	t = *y;
	*y = *x;
	*x = t;
}

void
sort3(int *a, int *b, int *c)
{
	if (*b < *a)
		swap(a, b);
	if (*b < *c)
		swap(b, c);
	if (*a < *c)
		swap(a, c);
}

int
maketime(int a, int b, int c)
{
	int r;

	r = 0;
	while (semiarea(a, b, c) <= 0) {
		sort3(&a, &b, &c);
		a += 1;
		r += 1;
	}
	return r;
}

int
main(void)
{
	assert(maketime(3, 4, 5) == 0);
	assert(maketime(2, 5, 3) == 1);
	assert(maketime(100, 10, 10) == 81);

	return 0;
}
