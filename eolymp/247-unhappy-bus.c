/*

Victor lives quite far from school, so to avoid being late for lessons, he goes by bus.
Victor is a very observant boy and tries to notice all the interesting coincidences that happen in life.

One day he noticed that when he sits on a bus whose number, in binary representation,
has a 1 as the second digit from the right, he is always called to the board to answer the lesson.
And who likes to go to the board? Especially if, the day before, you spent your time at the computer and didn't prepare the lesson!
Obviously, in this case, a deuce is threatened...

Help Victor compile a list of buses which he considers unlucky.

Input
The first line contains the number N (0≤N≤100000) — the number of buses.
Then each of the next N lines contains a bus number m i (0≤mi≤2^31-1).

Output
Output the numbers of the unlucky buses.

Examples
Input #1
2
0
3

Answer #1
1

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

size_t
solve(int *a, size_t n)
{
	size_t i, r;

	for (i = r = 0; i < n; i++)
		r += !!(a[i] & 0x2);
	return r;
}

int
main()
{
	int a1[] = { 0, 3 };

	assert(solve(a1, nelem(a1)) == 1);

	return 0;
}
