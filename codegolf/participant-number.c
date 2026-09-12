/*

A math Olympiad will be held, and participants are being registered.
The highest number of participants is 100. Each participant is given an ID number.
It is given in a sequence like 100,97,94,91,88,....,1 , and when the first sequence is over, then 99,96,93,90,87,....,3 sequence and so on.

Let's assume one of the participant's ID number is k and he/she is the nth participant. Given the value of k, return the value of n.

Test Cases

59 -> 81
89 -> 71
16 -> 29
26 -> 92
63 -> 47
45 -> 53
91 -> 4
18 -> 62
19 -> 28
There will be no leading zero in input. Standard loopholes apply, shortest code wins. In output there can be trailing whitespace.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

int
mod(int x, int m)
{
	x %= m;
	if (x < 0)
		x += m;
	return x;
}

// Formula by @M Virts
int
pid(int n)
{
	return 101 - round(mod(n + 1, 3) * 33.3 + (n / 3.0));
}

int
main()
{
	assert(pid(59) == 81);
	assert(pid(89) == 71);
	assert(pid(16) == 29);
	assert(pid(26) == 92);
	assert(pid(63) == 47);
	assert(pid(45) == 53);
	assert(pid(91) == 4);
	assert(pid(18) == 62);
	assert(pid(19) == 28);

	return 0;
}
