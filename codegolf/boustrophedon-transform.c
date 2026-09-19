/*

Background
Boustrophedon transform (OEIS Wiki) is a kind of transformation on integer sequences. Given a sequence an, a triangular grid of numbers T[n,k] is formed through the following procedure, generating each row of numbers in the back-and-forth manner:

In short, T[n,k] is defined via the following recurrence relation:

T[n, 0] = a[n]
T[n, k] = T[n, k-1], T[n-1, n-k] if 0 < k <= n

Then the Boustrophedon transform bn of the input sequence an is defined as b[n]=T[n,n].

More information (explicit formula of coefficients and a PARI/gp program) can be found in the OEIS Wiki page linked above.

Task
Given a finite integer sequence, compute its Boustrophedon transform.

Standard code-golf rules apply. The shortest code in bytes wins.

Test cases
[10] -> [10]
[0, 1, 2, 3, 4] -> [0, 1, 4, 12, 36]
[0, 1, -1, 2, -3, 5, -8] -> [0, 1, 1, 2, 7, 15, 78]
[1, -1, 1, -1, 1, -1, 1, -1] -> [1, 0, 0, 1, 0, 5, 10, 61]
Brownie points for beating or matching my 10 bytes in ngn/k or 7 bytes in Jelly.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
T(int n, int k, int *a)
{
	if (k < 1)
		return a[n];
	return T(n, k - 1, a) + T(n - 1, n - k, a);
}

void
boustrophedon(int *a, int *b, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		b[i] = T(i, i, a);
}

void
test(int *a, int *b, size_t n)
{
	int p[128];

	boustrophedon(a, p, n);
	assert(!memcmp(p, b, sizeof(*b) * n));
}

int
main(void)
{
	int a1[] = {10};
	int b1[] = {10};

	int a2[] = {0, 1, 2, 3, 4};
	int b2[] = {0, 1, 4, 12, 36};

	int a3[] = {0, 1, -1, 2, -3, 5, -8};
	int b3[] = {0, 1, 1, 2, 7, 15, 78};

	int a4[] = {1, -1, 1, -1, 1, -1, 1, -1};
	int b4[] = {1, 0, 0, 1, 0, 5, 10, 61};

	test(a1, b1, nelem(a1));
	test(a2, b2, nelem(b2));
	test(a3, b3, nelem(b3));
	test(a4, b4, nelem(b4));

	return 0;
}
