/*

A simple but hopefully not quite trivial challenge:

Write a program or function that adds up the kth powers dividing a number n. More specifically:

Input: two positive integers n and k (or an ordered pair of integers, etc.)
Output: the sum of all of the positive divisors of n that are kth powers of integers
For example, 11! = 39916800 has six divisors that are cubes, namely 1, 8, 27, 64, 216, and 1728. Therefore given inputs 39916800 and 3, the program should return their sum, 2044.

Other test cases:

{40320, 1} -> 159120
{40320, 2} -> 850
{40320, 3} -> 73
{40320, 4} -> 17
{40320, 5} -> 33
{40320, 6} -> 65
{40320, 7} -> 129
{40320, 8} -> 1
{46656, 1} -> 138811
{46656, 2} -> 69700
{46656, 3} -> 55261
{46656, 4} -> 1394
{46656, 5} -> 8052
{46656, 6} -> 47450
{46656, 7} -> 1
{1, [any positive integer]} -> 1
This is code golf, so the shorter your code, the better. I welcome golfed code in all kinds of different languages, even if some other language can get away with fewer bytes than yours.

*/

#include <assert.h>
#include <math.h>

typedef long long vlong;

vlong
sdp(vlong n, vlong k)
{
	vlong i, m, r;

	r = 0;
	for (i = 1; i <= n; i++) {
		m = pow(i, k);
		if (!(n % m))
			r += m;
	}
	return r;
}

int
main()
{
	assert(sdp(39916800, 3) == 2044);
	assert(sdp(40320, 1) == 159120);
	assert(sdp(40320, 2) == 850);
	assert(sdp(40320, 3) == 73);
	assert(sdp(40320, 4) == 17);
	assert(sdp(40320, 5) == 33);
	assert(sdp(40320, 6) == 65);
	assert(sdp(40320, 7) == 129);
	assert(sdp(40320, 8) == 1);
	assert(sdp(46656, 1) == 138811);
	assert(sdp(46656, 2) == 69700);
	assert(sdp(46656, 3) == 55261);
	assert(sdp(46656, 4) == 1394);
	assert(sdp(46656, 5) == 8052);
	assert(sdp(46656, 6) == 47450);
	assert(sdp(46656, 7) == 1);

	return 0;
}
