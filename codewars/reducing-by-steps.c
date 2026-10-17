/*

Data: an array of integers, a function f of two variables and an init value.

Example: a = [2, 4, 6, 8, 10, 20], f(x, y) = x + y; init = 0

Output: an array of integers, say r, such that

r = [r[0] = f(init, a[0]), r[1] = f(r[0], a[1]), r[2] = f(r[1], a[2]), ...]

With our example: r = [2, 6, 12, 20, 30, 50]

Task:
Write the following functions of two variables

som : (x, y) -> x + y
mini : (x, y) -> min(x, y)
maxi : (x, y) -> max(x, y)
lcmu : (x, y) -> lcm(abs(x), abs(y) (see note for lcm)
gcdi : (x, y) -> gcd(abs(x), abs(y) (see note for gcd)
and

function oper_array(fct, arr, init) (or operArray or oper-array) where

fct is the function of two variables to apply to the array arr (fct will be one of som, mini, maxi, lcmu or gcdi)

init is the initial value

Examples:
a = [18, 69, -90, -78, 65, 40]
oper_array(gcd, a, a[0]) => [18, 3, 3, 3, 1, 1]
oper_array(lcm, a, a[0]) => [18, 414, 2070, 26910, 26910, 107640]
oper_array(sum, a, 0) => [18, 87, -3, -81, -16, 24]
oper_array(min, a, a[0]) => [18, 18, -90, -90, -90, -90]
oper_array(max, a, a[0]) => [18, 69, 69, 69, 69, 69]
Notes:
The form of the parameter fct in oper_array (or operArray or oper-array) changes according to the language. You can see each form according to the language in "Your test cases".

AFAIK there are no corner cases, everything is as nice as possible.

lcm and gcd see: https://en.wikipedia.org/wiki/Least_common_multiple https://en.wikipedia.org/wiki/Greatest_common_divisor

you could google "reduce function (your language)" to have a general view about the reduce functions.

In Shell bash, arrays are replaced by strings.

In OCaml arrays are replaced by lists.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef long (*fn)(long, long);

void
print(long *a, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		printf("%ld ", a[i]);
	printf("\n");
}

long
gcd(long a, long b)
{
	long t;

	while (b) {
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}

long
lcm(long a, long b)
{
	return labs(a * b) / gcd(a, b);
}

long
lcmu(long a, long b)
{
	return lcm(labs(a), labs(b));
}

long
gcdi(long a, long b)
{
	return gcd(labs(a), labs(b));
}

long
som(long a, long b)
{
	return a + b;
}

long
mini(long a, long b)
{
	return (a < b) ? a : b;
}

long
maxi(long a, long b)
{
	return (a > b) ? a : b;
}

void
operate(fn f, long *a, size_t n, long a0, long *r)
{
	size_t i;

	if (n == 0)
		return;

	r[0] = f(a0, a[0]);
	for (i = 1; i < n; i++)
		r[i] = f(r[i - 1], a[i]);
}

void
test(fn f, long *a, size_t n, long a0, long *r)
{
	long x[128];

	operate(f, a, n, a0, x);
	print(x, n);
	assert(!memcmp(x, r, sizeof(*r) * n));
}

int
main()
{
	long a1[] = { 18, 69, -90, -78, 65, 40 };

	long r1[] = { 18, 3, 3, 3, 1, 1 };
	long r2[] = { 18, 414, 2070, 26910, 26910, 107640 };
	long r3[] = { 18, 87, -3, -81, -16, 24 };
	long r4[] = { 18, 18, -90, -90, -90, -90 };
	long r5[] = { 18, 69, 69, 69, 69, 69 };

	test(gcdi, a1, nelem(a1), a1[0], r1);
	test(lcmu, a1, nelem(a1), a1[0], r2);
	test(som, a1, nelem(a1), 0, r3);
	test(mini, a1, nelem(a1), a1[0], r4);
	test(maxi, a1, nelem(a1), a1[0], r5);

	return 0;
}
