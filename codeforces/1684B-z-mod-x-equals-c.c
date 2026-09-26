/*

You are given three positive integers a, b, c (a<b<c). You have to find three positive integers x, y, z such that:

x mod y = a,
y mod z = b,
z mod x = c.
Here p mod q denotes the remainder from dividing p by q. It is possible to show that for such constraints the answer always exists.

Input
The input consists of multiple test cases. The first line contains a single integer t (1≤t≤10000) — the number of test cases. Description of the test cases follows.

Each test case contains a single line with three integers a, b, c (1≤a<b<c≤10^8).

Output
For each test case output three positive integers x, y, z (1≤x,y,z≤10^18) such that x mod y=a, y mod z=b, z mod x=c.

You can output any correct answer.

Example

input
4
1 3 4
127 234 421
2 7 8
59 94 388
output
12 11 4
1063 234 1484
25 23 8
2221 94 2609

Note
In the first test case:

x mod y = 12 mod 11 = 1;
y mod z = 11 mod 4 = 3;
z mod x = 4 mod 12 = 4.

*/

#include <assert.h>
#include <stdio.h>

/*

x mod y = (a + b + c) mod (b + c)     = a   since a < b < b + c
y mod z = (b + c)     mod c           = b   since b < c
z mod x =  c          mod (a + b + c) = c   since c < (a + b + c)

*/

void
mods(int a, int b, int c, int *x, int *y, int *z)
{
	*x = a + b + c;
	*y = b + c;
	*z = c;
}

void
test(int a, int b, int c)
{
	int x, y, z;

	mods(a, b, c, &x, &y, &z);
	printf("%d %d %d\n", x, y, z);
	assert(x % y == a);
	assert(y % z == b);
	assert(z % x == c);
}

int
main(void)
{
	test(1, 3, 4);
	test(127, 234, 421);
	test(2, 7, 8);
	test(59, 94, 388);

	return 0;
}
