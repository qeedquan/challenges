/*

(Challenge taken from a multiplayer game (clash of code) at codingame.com)

The challenge
Find the n-th term of the following sequence: 1, 1, 2, 1, 2, 3, 1, 2, 3, 4... or, to make it more obvious, {1}, {1,2}, {1,2,3}, {1,2,3,4}...

The sequence is made up from concatenated ranges from 1 to x, starting from 1, all the way up to infinity.

Rules / IO
Input and output can be in any format, as long as it's distinguishable. Input can be taken from any appropriate source: STDIN, file, etc...

The input can be 0- or 1-indexed, and the selected indexing must be mentioned in the post.

You will have to handle at least up to a result of 255 inclusive (meaning the 0-indexed maximum input is 32640). Anything over that has to be handled, if your language supports it.

This is code-golf so the shortest byte count wins!

Test cases (0-based indexing)
0 -> 1
1 -> 1
5 -> 3
10 -> 1
59 -> 5
100 -> 10
1001 -> 12

*/

#include <assert.h>
#include <math.h>

typedef unsigned long long uvlong;

/*

https://oeis.org/A002260

@rahnema1

Explanation:

Consider this sequence:

1   1   2   1   2   3   1   2   3   4   1   2   3   4   5
if we count number of element of subsequences we have

1   2        3          4               5
so using Gauss formula for triangular number we can form a formula for z:

z=n*(n+1)/2
that is a quadratic equation if we solve it for n we have

n=(sqrt(8*z+1)-1)/2

*/

uvlong
risereset(uvlong n)
{
	uvlong x;

	n = n + 1;
	x = ceil(sqrt((8 * n) + 1) / 2 - 0.5);
	return n - (x * (x - 1)) / 2;
}

int
main(void)
{
	assert(risereset(0) == 1);
	assert(risereset(1) == 1);
	assert(risereset(5) == 3);
	assert(risereset(10) == 1);
	assert(risereset(59) == 5);
	assert(risereset(100) == 10);
	assert(risereset(1001) == 12);

	return 0;
}
