/*

The problem
Consider an equation such as      "3 ± 2 ± 4 ± 1 = 4"      and determine if there exists a sequence of pluses and minuses that makes it arithmetically correct. If it exists, exhibit it. For instance, [-, +, -] works in this case:      "3 - 2 + 4 - 1 = 4".

Sometimes it's impossible: e.g.      "3 ± 5 = 7"      has no solution. Your code needs to determine this.

Other times, multiple solutions are possible: for      "1 ± 2 ± 4 ± 3 ± 1 = 1"      , both [-, +, -, +] and [+, -, +, -] are valid. Your code only needs to exhibit one.

The challenge
Code golf: write the shortest function or program that solves the problem.

Assumptions

All numbers (both left and right of the equal sign) are non-negative integers. There may be zeroes.
There is just one number to the right of the equal sign.
There is no ± at the left of the first number.
Partial sums may be negative (but the total sum will be non-negative).
There are at least 3 numbers in the input (i.e. at least 2 on the left hand side, plus the result).
I/O

You will take a sequence of N numbers ([a1, a2, ...aN-1, aN]), where a1, a2, ...aN-1 are addends and aN is the result.

Alternatively, you may choose to get aN separately from the rest.

You are free to choose what is a "sequence" (a list, or an array, or literals via stdin separated by space or newline or comma, or ...).

If there is a solution, you should output a sequence of N-2 "plus"-signifying and "minus"-signifying constants, which may be represented as you prefer (("+", "-"), or (+1, -1,), or (+1, 0), or (NaN, 4), or ...).

There are N-2 symbols total. You must not output the (implicit) "plus" to the left of the first addend.

If there is no solution, you should have a predictable behaviour that signifies "no solution". This can be returning/printing a specific constant or throwing an exception or terminating without output.

Having a program that predictably doesn't terminate is also acceptable.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
eval(int *values, size_t nvalues, const char *ops)
{
	int result;
	size_t i;

	if (nvalues == 0)
		return 0;

	result = values[0];
	for (i = 0; i < nvalues; i++) {
		if (ops[i] == '+')
			result += values[i + 1];
		else if (ops[i] == '-')
			result -= values[i + 1];
	}
	return result;
}

int
recurse(int *values, size_t nvalues, int target, size_t depth, char *ops)
{
	static const char sym[] = "+-";
	int c;

	if (depth + 1 >= nvalues)
		return eval(values, nvalues, ops) == target;

	ops[depth + 1] = '\0';
	for (c = 0; sym[c]; c++) {
		ops[depth] = sym[c];
		if (recurse(values, nvalues, target, depth + 1, ops))
			return 1;
	}

	return 0;
}

int
solve(int *values, size_t nvalues, int target, char *ops)
{
	return recurse(values, nvalues, target, 0, ops);
}

void
test(int *values, size_t nvalues, int target, const char *result)
{
	char ops[128];
	size_t i;

	printf("[ ");
	for (i = 0; i < nvalues; i++)
		printf("%d ", values[i]);
	printf("| %d ] => ", target);

	if (solve(values, nvalues, target, ops)) {
		printf("%s\n", ops);
		assert(!strcmp(ops, result));
	} else {
		printf("no solution\n");
		assert(result == NULL);
	}
}

int
main(void)
{
	int values1[] = {3, 2, 4, 1};
	int values2[] = {3, 5};
	int values3[] = {1, 2, 4, 3, 1};
	int values4[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

	test(values1, nelem(values1), 4, "-+-");
	test(values2, nelem(values2), 7, NULL);
	test(values3, nelem(values3), 1, "+-+-");
	test(values4, nelem(values4), 53, "++++++++++-+-");

	return 0;
}
