/*

Introduction
In this challenge, we will be dealing with a certain ordering of the positive integers. The ordering goes like this:

   3,    5,    7,    9,    11, ...
 2*3,  2*5,  2*7,  2*9,  2*11, ...
 4*3,  4*5,  4*7,  4*9,  4*11, ...
 8*3,  8*5,  8*7,  8*9,  8*11, ...
16*3, 16*5, 16*7, 16*9, 16*11, ...
 ...
... 64, 32, 16, 8, 4, 2, 1
We first list all odd integers greater than 1 in ascending order. Then we list two times odd integers greater than 1, then 4 times, then 8 times, and so on: for all k, we list 2k times the odd integers greater than 1 in ascending order. Finally, we list the powers of two in descending order, ending at 1. Every positive integer occurs in this "list" exactly once.

More explicitly, consider two distinct positive integers A = n·2p and B = m·2q, where n, m ≥ 1 are odd, and p, q ≥ 0. Then A comes before B in the ordering, if one of the following conditions holds:

n > 1, m > 1 and p < q
1 < n < m and p = q
n > m = 1
n = m = 1 and p > q
This ordering appears in the surprising mathematical result known as Sharkovskii's theorem, which concerns the periodic points of dynamical systems. I will not go into the details here.

The task
Your task in this challenge is to compute the above ordering. Your inputs are two positive integers A and B, which may be equal. Your output is a truthy value if A comes before B in the ordering, and a falsy value otherwise. If A = B, your output should be truthy. You can take A and B in either order, as long as you're consistent.

You don't have to worry about integer overflow, but your algorithm should theoretically work for arbitrarily large inputs.

Test cases
Truthy instances

3 11
9 6
48 112
49 112
158 158
36 24
14 28
144 32
32 32
32 8
3 1
1 1

Falsy instances

1 2
1 5
11 5
20 25
2 8
256 255
256 257
72 52
2176 1216
2176 2496

*/

#include <assert.h>
#include <stdbool.h>

/*

@Neil

Explanation:

If b is 1, then a precedes (or equals) b
Otherwise, if a is 1, then a does not precede b
Otherwise, if both a and b are odd, then use regular inequality check
Otherwise, if a is odd, then it precedes b
Otherwise, if b is odd, then a does not precede b
Otherwise, divide both a and b by 2 and try again.

*/

bool
less(int a, int b)
{
	while (a > 0 && b > 0) {
		if (b == 1)
			return true;
		if (a == 1)
			return false;
		if ((a & 1) && (b & 1))
			return a <= b;
		if (a & 1)
			return true;
		if (b & 1)
			return false;

		a >>= 1;
		b >>= 1;
	}
	return a <= b;
}

int
main(void)
{
	assert(less(0, 0) == true);
	assert(less(3, 11) == true);
	assert(less(9, 6) == true);
	assert(less(48, 112) == true);
	assert(less(49, 112) == true);
	assert(less(158, 158) == true);
	assert(less(36, 24) == true);
	assert(less(14, 28) == true);
	assert(less(144, 32) == true);
	assert(less(32, 32) == true);
	assert(less(32, 8) == true);
	assert(less(3, 1) == true);
	assert(less(1, 1) == true);

	assert(less(1, 2) == false);
	assert(less(1, 5) == false);
	assert(less(11, 5) == false);
	assert(less(20, 25) == false);
	assert(less(2, 8) == false);
	assert(less(256, 255) == false);
	assert(less(256, 257) == false);
	assert(less(72, 52) == false);
	assert(less(2176, 1216) == false);
	assert(less(2176, 2496) == false);

	return 0;
}
