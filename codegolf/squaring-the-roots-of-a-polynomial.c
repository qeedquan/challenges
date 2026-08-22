/*

In this challenge, you are given a polynomial p(x), and you need to find a polynomial q(x) whose
roots are exactly the squares of the roots of p(x) (counted with multiplicity). In other words, if
p(x) = Product[i=1, n] (x - r[i]), then q(x) = Prod[i=1, n] (x - r[i]^2)

For example, if p(x)=x^3 - 3x^2 + 4 = (x + 1)(x - 2)^2, then the roots of p(x) are -1, 2, 2.
So the roots of q(x) are 1, 4, 4, and thus q(x) = (x-1)(x-4)^2 = x^3 - 9x^2 + 24x - 16.
Of course, 2(x-1)(x-4)^2 = 2x^3 - 18x^2 + 48x - 32 is also a valid answer, as it has the same roots with the same multiplicities.

The input p(x) is guaranteed to be a non-constant polynomial with integer coefficients, but some roots may be complex or repeated.
Your output q(x) does not need to have integer coefficients, but there is always a valid answer with integer coefficients.

You may input and output the polynomials in any reasonable format. For example, the polynomial x^4 - 4x^3 + 5x^2 - 2x may be represented as:

a list of coefficients, in descending order: [1,-4,5,-2,0];
a list of coefficients, in ascending order:[0,-2,5,-4,1];
a string representation of the polynomial, with a chosen variable, e.g., x: "x^4-4*x^3+5*x^2-2*x";
a built-in polynomial object, e.g., x^4-4*x^3+5*x^2-2*x in PARI/GP.
When you take input as a list of coefficients, the leading coefficient is guaranteed to be nonzero.

Representing a polynomial by its roots is not a reasonable format for this challenge, as it would make the task trivial.

This is code-golf, so the shortest code in bytes wins.

Test cases
The output is not unique. Your output may be a non-zero multiple of the expected output.

Here the polynomials are represented as lists of coefficients in decreasing order.

[1, 1] -> [1, -1]                           # x + 1 => x - 1
[1, 1, 1] -> [1, 1, 1]                      # x^2 + x + 1 => x^2 + x + 1
[1, -3, 4] -> [1, -1, 16]                   # x^2 - 3x + 4 => x^2 - x + 16
[1, 2, 3, 4] -> [1, 2, -7, -16]             # x^3 + 2x^2 + 3x + 4 => x^3 + 2x^2 - 7x - 16
[1, 2, 1, 0] -> [1, -2, 1, 0]               # x^3 + 2x^2 + x => x^3 - 2x^2 + x
[1, -4, 5, -2, 0] -> [1, -6, 9, -4, 0]      # x^4 - 4x^3 + 5x^2 - 2x => x^4 - 6x^3 + 9x^2 - 4x
[1, 2, 3, 4, 5] -> [1, 2, 3, 14, 25]        # x^4 + 2x^3 + 3x^2 + 4x + 5 => x^4 + 2x^3 + 3x^2 + 14x + 25

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
print(int *a, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int
pown1(int n)
{
	return (n & 1) ? -1 : 1;
}

/*

@Neil

Explanation:
Directly calculates a polynomial whose roots are the squares of the given polynomial.
Works even when the original roots do not have a closed form.

*/

void
polyrsq(int *c, size_t n, int *r)
{
	size_t i, j, k;

	for (k = 0; k < n; k++) {
		r[k] = 0;
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (i + j == 2 * k)
					r[k] += pown1(i) * c[i] * c[j];
			}
		}
	}
}

void
test(int *c, size_t n, int *r)
{
	int p[128];

	polyrsq(c, n, p);
	print(p, n);
	assert(!memcmp(p, r, sizeof(*r) * n));
}

int
main()
{
	int c1[] = { 1, 1 };
	int c2[] = { 1, 1, 1 };
	int c3[] = { 1, -3, 4 };
	int c4[] = { 1, 2, 3, 4 };
	int c5[] = { 1, 2, 1, 0 };
	int c6[] = { 1, -4, 5, -2, 0 };
	int c7[] = { 1, 2, 3, 4, 5 };

	int r1[] = { 1, -1 };
	int r2[] = { 1, 1, 1 };
	int r3[] = { 1, -1, 16 };
	int r4[] = { 1, 2, -7, -16 };
	int r5[] = { 1, -2, 1, 0 };
	int r6[] = { 1, -6, 9, -4, 0 };
	int r7[] = { 1, 2, 3, 14, 25 };

	test(c1, nelem(c1), r1);
	test(c2, nelem(c2), r2);
	test(c3, nelem(c3), r3);
	test(c4, nelem(c4), r4);
	test(c5, nelem(c5), r5);
	test(c6, nelem(c6), r6);
	test(c7, nelem(c7), r7);

	return 0;
}
