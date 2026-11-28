/*

Inspired by this conversation in chat.
https://chat.stackexchange.com/transcript/240?m=26561376#26561376

Your goal in this challenge is to emulate a ninja and count how many deaths he has left.

Specs
You ninja starts out with 9 deaths left. He also gets an integral starting health as an input.

Then, he takes as input a list of events in his life that alter his health. These can be negative, positive, or zero integers.

At any point, if his health reaches at or below zero, he loses a life and his health goes back to the starting health.

Your program should report the number of deaths he has left. If he has zero or less left, you should output dead instead.

This is code-golf, so shortest code in bytes wins!

Test Cases
3, [] -> 9
100, [-20, 5, -50, 15, -30, -30, 10] -> 8
10, [-10, -10, -10, -10] -> 5
10, [-10, -10, -10, -10, -10, -10, -10, -10, -10] -> dead
0, [] -> dead
0, [1] -> dead
100, [10, -100] -> 9

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
deaths(int s, int *d, size_t n)
{
	size_t i;
	int h, r;

	if (s < 1)
		return 0;

	h = s;
	r = 9;
	for (i = 0; i < n && r >= 0; i++) {
		h += d[i];
		if (h <= 0) {
			r -= 1;
			h = s;
		}
	}
	return r;
}

int
main(void)
{
	int a1[] = {-20, 5, -50, 15, -30, -30, 10};
	int a2[] = {-10, -10, -10, -10};
	int a3[] = {-10, -10, -10, -10, -10, -10, -10, -10, -10};
	int a4[] = {1};
	int a5[] = {10, -100};

	assert(deaths(3, NULL, 0) == 9);
	assert(deaths(100, a1, nelem(a1)) == 8);
	assert(deaths(10, a2, nelem(a2)) == 5);
	assert(deaths(10, a3, nelem(a3)) == 0);
	assert(deaths(0, NULL, 0) == 0);
	assert(deaths(0, a4, nelem(a4)) == 0);
	assert(deaths(100, a5, nelem(a5)) == 9);

	return 0;
}
