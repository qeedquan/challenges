/*

Background
A triangular grid is a grid formed by tiling the plane regularly with equilateral triangles of side length 1. The picture below is an example of a triangular grid.

https://i.stack.imgur.com/pmooq.gif

A triangular lattice point is a vertex of a triangle forming the triangular grid.

The origin is a fixed point on the plane, which is one of the triangular lattice points.

Challenge
Given a non-negative integer n, find the number of triangular lattice points whose Euclidean distance from the origin is less than or equal to n.

Example
The following figure is an example for n = 7 (showing only 60-degree area for convenience, with point A being the origin):

https://imgur.com/D1kUGxq


Test Cases
Input | Output
---------------
    0 |       1
    1 |       7
    2 |      19
    3 |      37
    4 |      61
    5 |      91
    6 |     127
    7 |     187
    8 |     241
    9 |     301
   10 |     367
   11 |     439
   12 |     517
   13 |     613
   14 |     721
   15 |     823
   16 |     931
   17 |    1045
   18 |    1165
   19 |    1303
   20 |    1459
   40 |    5815
   60 |   13057
   80 |   23233
  100 |   36295
  200 |  145051
  500 |  906901
 1000 | 3627559
Hint: This sequence is not OEIS A003215.

Rules
Standard rules for code-golf apply. The shortest submission wins.

Please include how you solved the challenge in your submission.

*/

#include <assert.h>
#include <stdio.h>

typedef unsigned long long uvlong;

/*

@Lynn

f(n) = 1 + 6*Sum[a=0, Inf] [floor(n^2/(3a + 1)) - floor(n^2/(3a + 2))]

A proof of its correctness, and an explanation of how xnor managed to express it in 43 bytes of Python, can be found here.

Long story short: we count Eisenstein integers of norm 1≤N≤n^2, by factoring N=(x+yω)(x+yω∗) into Eisenstein primes and counting how many solutions for (x,y) come out of the factorization.
We recognize the number of solutions as being equal to 6×((# of divisors of N≡1 (mod 3))−(# of divisors of N≡2 (mod 3)))
and apply a clever trick to make that really easy to compute for all integers between 1 and n^2 at once. This yields the formula above.
Finally, we apply some Python golf magic to end up with the really tiny solution xnor found.

*/

uvlong
trilat(uvlong n)
{
	uvlong a, v;

	v = 0;
	for (a = 0; a <= n * n; a++) {
		v += (n * n) / ((3 * a) + 1);
		v -= (n * n) / ((3 * a) + 2);
	}
	return 1 + (6 * v);
}

int
main(void)
{
	assert(trilat(0) == 1);
	assert(trilat(1) == 7);
	assert(trilat(2) == 19);
	assert(trilat(3) == 37);
	assert(trilat(4) == 61);
	assert(trilat(5) == 91);
	assert(trilat(6) == 127);
	assert(trilat(7) == 187);
	assert(trilat(8) == 241);
	assert(trilat(9) == 301);
	assert(trilat(10) == 367);
	assert(trilat(11) == 439);
	assert(trilat(12) == 517);
	assert(trilat(13) == 613);
	assert(trilat(14) == 721);
	assert(trilat(15) == 823);
	assert(trilat(16) == 931);
	assert(trilat(17) == 1045);
	assert(trilat(18) == 1165);
	assert(trilat(19) == 1303);
	assert(trilat(20) == 1459);
	assert(trilat(40) == 5815);
	assert(trilat(60) == 13057);
	assert(trilat(80) == 23233);
	assert(trilat(100) == 36295);
	assert(trilat(200) == 145051);
	assert(trilat(500) == 906901);
	assert(trilat(1000) == 3627559);

	return 0;
}
