/*

Your car starts at position 0 and speed +1 on an infinite number line. Your car can go into negative positions. Your car drives automatically according to a sequence of instructions 'A' (accelerate) and 'R' (reverse):

    When you get an instruction 'A', your car does the following:
        position += speed
        speed *= 2
    When you get an instruction 'R', your car does the following:
        If your speed is positive then speed = -1
        otherwise speed = 1
    Your position stays the same.

For example, after commands "AAR", your car goes to positions 0 --> 1 --> 3 --> 3, and your speed goes to 1 --> 2 --> 4 --> -1.

Given a target position target, return the length of the shortest sequence of instructions to get there.

Example 1:

Input: target = 3
Output: 2
Explanation:
The shortest instruction sequence is "AA".
Your position goes from 0 --> 1 --> 3.

Example 2:

Input: target = 6
Output: 5
Explanation:
The shortest instruction sequence is "AAARA".
Your position goes from 0 --> 1 --> 3 --> 7 --> 7 --> 6.

Constraints:

    1 <= target <= 10^4

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbit.h>
#include <errno.h>

typedef unsigned int uint;

#define bit(n) (1u << (n))
#define min(a, b) (((a) < (b)) ? (a) : (b))

uint
racecar(uint t)
{
	uint i, j;
	uint k, r;
	uint *p;

	if (t < 1)
		return 0;

	p = calloc(t + 1, sizeof(*p));
	if (!p)
		return -errno;

	for (i = 1; i <= t; i++) {
		k = stdc_bit_width(i);
		if (i == bit(k) - 1) {
			p[i] = k;
			continue;
		}

		p[i] = p[bit(k) - 1 - i] + k + 1;
		for (j = 0; j < k; j++)
			p[i] = min(p[i], p[i - bit(k - 1) + bit(j)] + k + j + 1);
	}
	r = p[t];

	free(p);
	return r;
}

int
main()
{
	assert(racecar(3) == 2);
	assert(racecar(6) == 5);

	return 0;
}
