/*

The golfing language Jelly has a built-in ƭ called "tie", that cycles through a list of functions every time it's called. For example, +×ƭ will switch between + (addition) and × (multiplication) every time it's called.

ƭ can be somewhat usefully combined with the built-in \ called "scan", which cumulatively reduces a list by a function (for example, calling +\, scan by addition, on the list [1, 2, 3, 4] would give [1, 3, 6, 10]). The function +×ƭ\ will scan a list alternately between addition and multiplication - calling it on the list [1, 2, 3, 4, 5] gives [1, 3 = 1 + 2, 9 = 3 * 3, 13 = 9 + 4, 65 = 13 * 5].

ƭ can take more than two arguments - for example, +×_ƭ\ cyclically reduces by +, ×, and _ (subtraction)*. Calling it on the list [1, 2, 3, 4, 5, 6, 7] would result in [1, 3 = 1 + 2, 9 = 3 * 3, 5 = 9 - 4, 10 = 5 + 5, 60 = 10 * 6, 53 = 60 - 7].

Your challenge is to, given a list of at least 2 black-box dyadic not-necessarily-commutative functions, along with a list of at least 2 positive integers, emulate the effect of ƭ\ on them. Specifically, you should call the first function on the first two elements, the second function on the result of the previous and the third element, and so on, cycling around the list of functions as necessary and outputting intermediate values. You may assume that the integer list is strictly longer than the function list, and that all intermediate results are positive integers.

* note that this isn't the exact syntax, ƭ taking 3 or more arguments has to be prefixed with the number of arguments, for example +×_3ƭ. It doesn't matter for the purposes of this challenge.

Testcases
Here, I'm using the symbols +, *, -, /, and ^ (exponentiation) to represent the functions that take two arguments and apply those operations to them. Also, f is a function that takes x, y and returns x^2 + y.

[+, *], [1, 2, 3, 4] => [1, 3, 9, 13]
[*, +], [9, 2, 8, 6, 3] => [9, 18, 26, 156, 159]
[-, +], [18, 4, 12, 2, 16, 18] => [18, 14, 26, 24, 40, 22]
[+, *, +], [12, 5, 3, 19, 2, 5, 4] => [12, 17, 51, 70, 72, 360, 364]
[f, +], [1, 2, 3, 4, 5, 6, 7] => [1, 3, 6, 40, 45, 2031, 2038]
[^, /, -], [2, 6, 8, 2, 4, 9, 44] => [2, 64, 8, 6, 1296, 144, 100]
[+, *, -, /], [1, 2, 3, 4, 5, 6, 7, 4, 9, 10] => [1, 3, 9, 5, 1, 7, 49, 45, 5, 15]

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
dump(int *a, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int
binop(int op, int x, int y)
{
	switch (op) {
	case '+':
		return x + y;
	case '-':
		return x - y;
	case '*':
		return x * y;
	case '/':
		return x / y;
	case '^':
		return pow(x, y);
	case 'f':
		return (x * x) + y;
	}
	return 0;
}

void
tiescan(const char *ops, int *x, size_t n, int *y)
{
	const char *op;
	size_t i;

	if (n < 1)
		return;

	op = ops;
	y[0] = x[0];
	for (i = 1; i < n; i++) {
		if (*op == '\0')
			op = ops;

		y[i] = binop(*op++, y[i - 1], x[i]);
	}
}

void
test(const char *ops, int *x, size_t n, int *r)
{
	int y[128];

	tiescan(ops, x, n, y);
	dump(y, n);
	assert(!memcmp(r, y, n * sizeof(*y)));
}

int
main()
{
	int x1[] = {1, 2, 3, 4};
	int x2[] = {9, 2, 8, 6, 3};
	int x3[] = {18, 4, 12, 2, 16, 18};
	int x4[] = {12, 5, 3, 19, 2, 5, 4};
	int x5[] = {1, 2, 3, 4, 5, 6, 7};
	int x6[] = {2, 6, 8, 2, 4, 9, 44};
	int x7[] = {1, 2, 3, 4, 5, 6, 7, 4, 9, 10};

	int r1[] = {1, 3, 9, 13};
	int r2[] = {9, 18, 26, 156, 159};
	int r3[] = {18, 14, 26, 24, 40, 22};
	int r4[] = {12, 17, 51, 70, 72, 360, 364};
	int r5[] = {1, 3, 6, 40, 45, 2031, 2038};
	int r6[] = {2, 64, 8, 6, 1296, 144, 100};
	int r7[] = {1, 3, 9, 5, 1, 7, 49, 45, 5, 15};

	test("+*", x1, nelem(x1), r1);
	test("*+", x2, nelem(x2), r2);
	test("-+", x3, nelem(x3), r3);
	test("+*+", x4, nelem(x4), r4);
	test("f+", x5, nelem(x5), r5);
	test("^/-", x6, nelem(x6), r6);
	test("+*-/", x7, nelem(x7), r7);

	return 0;
}
