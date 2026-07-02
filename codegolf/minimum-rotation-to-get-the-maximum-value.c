/*

I recently solved a coding challenge in one of the challenge papers that my IT teacher gave to us. It was a seemingly simple, but fun challenge, so I thought it will make fun golfing.

The task

Given an input of a 2x2 matrix that contains 4 strictly positive integers (i.e. non-negative and non-zero), like this:

[a b]
[c d]

We call the value of the matrix given is ⌊ac⌋−⌊bd⌋.

Your task is to calculate the amount of rotation needed to get the maximum value of the matrix.

A rotation rotates the matrix 90 degrees clockwise.

Input and Output
The input can be a 2x2 matrix (as shown above), a flattened list [a b c d], or any other reasonable input.

Note that with the case of flattened lists, the numbers can be in any order you preferred. (e.g. [a b d c]).

The output must show a number that is the amount of rotation required.

Clarifications
In case of a tie, we will choose the one with the least amount of rotation needed.

In case where no rotation is required, we simply output 0 or 4 (the maximal rotation).

The division used here is integer division (i.e. the result of the division will always be an integer).

Examples
[a b c d] -> output
[1 2 3 4] -> 3
[5 7 9 2] -> 1
[5 6 7 8] -> 0 or 4
[1 9 2 3] -> 3
[2 5 6 8] -> 3
These examples are hand-calculated and written, so correct me if I'm wrong!

As always, standard loopholes are forbidden.

*/

#include <assert.h>

int
next(int *a, int *b, int *c, int *d)
{
	int A, B, C, D, r;

	r = (*a / *c) - (*b / *d);

	A = *c;
	B = *a;
	C = *d;
	D = *b;

	*a = A;
	*b = B;
	*c = C;
	*d = D;

	return r;
}

int
rotations(int a, int b, int c, int d)
{
	int i, r, u, v;

	r = 0;
	u = next(&a, &b, &c, &d);
	for (i = 1; i < 4; i++) {
		v = next(&a, &b, &c, &d);
		if (v > u) {
			r = i;
			u = v;
		}
	}

	return r;
}

int
main(void)
{
	assert(rotations(1, 2, 3, 4) == 3);
	assert(rotations(5, 7, 9, 2) == 1);
	assert(rotations(5, 6, 7, 8) == 0);
	assert(rotations(1, 9, 2, 3) == 3);
	assert(rotations(2, 5, 6, 8) == 3);

	return 0;
}
