/*

Task
In mathematics, a function is a relation between a set of inputs and a set of permissible outputs with the property that each input is related to exactly one output. In other words, for every x from the set of inputs there is exactly one element y from the set of outputs, such that the ordered pair (x, y) is contained in the set defining the function.

You are given a set of pairs that defines something. Your task is to figure out whether this something can be a function or not.

Input/Output
[input] 2D float array pairs
A non-empty set of pairs. Each pair is given as a two-element array, where the first element belongs to the set of inputs, and the second one belongs to the set of outputs.

[output] a boolean value
true if the given set can define a function and false otherwise.

Example
For pairs = [[0.5,1.5],[2.5,3.5]], the output should be true.

For pairs = [[5,1],[2.5,3.4],[5,6],[7,2]], the output should be false.

The given set can't possibly define a function, since values y = 1 and y = 6 both correspond to the value x = 5.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
cmp(const void *a, const void *b)
{
	const double *x, *y;

	x = a;
	y = b;
	if (x[0] < y[0])
		return -1;
	if (x[0] == y[0])
		return 0;
	return 1;
}

bool
isfunction(double p[][2], size_t n)
{
	size_t i;

	qsort(p, n, sizeof(*p), cmp);
	for (i = 1; i < n; i++) {
		if (p[i][0] == p[i - 1][0] && p[i][1] != p[i - 1][1])
			return false;
	}
	return true;
}

int
main()
{
	double p1[][2] = { { 0.5, 1.5 }, { 2.5, 3.5 } };
	double p2[][2] = { { 5, 1 }, { 2.5, 3.4 }, { 5, 6 }, { 7, 2 } };

	assert(isfunction(p1, nelem(p1)) == true);
	assert(isfunction(p2, nelem(p2)) == false);

	return 0;
}
