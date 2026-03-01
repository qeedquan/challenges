/*

Recently I posted a question about Diffy games which has gone unanswered.
Thats fine, the question is really hard, but I would like to make an easier question about Diffy games so that we can get the ball rolling.

How Diffy works
Copied from Find Diffy Games

The Diffy game works like as follows: You start with a list of non-negative integers, in this example we will use

3 4 5 8
Then you take the absolute difference between adjacent numbers

 (8)  3   4   5   8
    5   1   1   3
Then you repeat. You repeat until you realize you have entered a loop. And then generally the game starts from the beginning again.

3 4 5 8
5 1 1 3
2 4 0 2
0 2 4 2
2 2 2 2
0 0 0 0
0 0 0 0
Most games end in a string of all zeros, which is considered to be a lose state, but a rare few games get stuck in larger loops.

Task
Given the starting state of a Diffy game determine whether or not the game eventually reaches a state of all zeros.
You should output a Truthy or Falsy value for each of the two states. Which corresponds to which does not matter.

The goal is to minimize the number of bytes in your source.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))

/*

How do we know how many diffy-game rounds R to do?
If m is the largest value in the input, notice that we will never produce an integer larger than m no matter how many rounds we do.
The total number of lists of length l of nonnegative integers all bounded by m is (m+1)^l.
So if we carry out (m+1)^l rounds of the diffy game, we are guaranteed to have seen some list twice by then, and thus will be in the periodic part of the game.
In particular, the game ends in all zeros if and only if the result of (m+1)^l rounds of the game is the all-zeros list.
That expression is what Max[1+#]^Tr[1^#] computes.

*/

bool
degen(int *a, size_t n)
{
	size_t i, j, r;
	int m, x, y;
	bool z;

	if (n == 0)
		return true;

	m = 0;
	for (i = 0; i < n; i++)
		m = max(m, abs(a[i]));

	r = pow(m + 1, n);
	for (i = 0; i < r; i++) {
		x = a[n - 1];
		z = true;
		for (j = 0; j < n; j++) {
			y = a[j];
			a[j] = abs(a[j] - x);
			x = y;
			if (a[j])
				z = false;
		}
		if (z)
			return true;
	}
	return false;
}

int
main()
{
	int a1[] = { 3, 4, 5, 8 };
	int a2[] = { 1, 1, 0, 0, 0 };
	int a3[] = { 1, 2, 0 };
	int a4[] = { 1, 0, 1 };
	int a5[] = { 7 };

	assert(degen(a1, nelem(a1)) == true);
	assert(degen(a2, nelem(a2)) == false);
	assert(degen(a3, nelem(a3)) == false);
	assert(degen(a4, nelem(a4)) == false);
	assert(degen(a5, nelem(a5)) == true);

	return 0;
}
