/*

Leonardo numbers
The Leonardo numbers are a sequence of numbers defined by:

L(0) = 1 || 0
L(1) = 1 || 0
L(x) = L(x - 1) + L(x - 2) + 1

Generalizing the above a bit more:

L(x) = L(x - 1) + L(x - 2) + a

Assume a to be the add number.

Task
Return the first n Leonardo numbers as an array (vector<int> in C++)

Input
n : The number of Leonardo numbers to be shown
L0 : The initial value of L(0)
L1 : The initial value of L(1)
add : The add number

Examples
input  : n = 5 , L0 = 1 , L1 = 1 , add = 1
output : [ 1, 1, 3, 5, 9 ]

input  : n = 5 , L0 = 0 , L1 = 0 , add = 2
output : [ 0, 0, 2, 4, 8 ]

input  : n = 10 , L0 = 0 , L1 = 1 , add = 4
output : [ 0, 1, 5, 10, 19, 33, 56, 93, 153, 250 ]

input  : n = 5 , L0 = 0 , L1 = 0 , add = 0
output : [ 0, 0, 0, 0, 0 ]

Note
n will always be greater than or equal to 2

*/

#include <assert.h>
#include <string.h>

// https://oeis.org/A001595
void
leonardo(int n, int L0, int L1, int a, int *r)
{
	int L2;
	int i;

	for (i = 0; i < n; i++) {
		r[i] = L0;
		L2 = L0 + L1 + a;
		L0 = L1;
		L1 = L2;
	}
}

void
test(int n, int L0, int L1, int a, int *r)
{
	int p[128];

	leonardo(n, L0, L1, a, p);
	assert(!memcmp(p, r, sizeof(*r) * n));
}

int
main()
{
	int r1[] = {1, 1, 3, 5, 9};
	int r2[] = {0, 0, 2, 4, 8};
	int r3[] = {0, 1, 5, 10, 19, 33, 56, 93, 153, 250};
	int r4[] = {0, 0, 0, 0, 0};

	test(5, 1, 1, 1, r1);
	test(5, 0, 0, 2, r2);
	test(10, 0, 1, 4, r3);
	test(5, 0, 0, 0, r4);

	return 0;
}
