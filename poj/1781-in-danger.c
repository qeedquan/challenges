/*

Description

Flavius Josephus and 40 fellow rebels were trapped by the Romans. His companions preferred suicide to surrender, so they decided to form a circle and to kill every third person and to proceed around the circle until no one was left. Josephus was not excited by the idea of killing himself, so he calculated the position to be the last man standing (and then he did not commit suicide since nobody could watch).

We will consider a variant of this "game" where every second person leaves. And of course there will be more than 41 persons, for we now have computers. You have to calculate the safe position. Be careful because we might apply your program to calculate the winner of this contest!

Input

The input contains several test cases. Each specifies a number n, denoting the number of persons participating in the game. To make things more difficult, it always has the format "xyez" with the following semantics: when n is written down in decimal notation, its first digit is x, its second digit is y, and then follow z zeros. Whereas 0<=x,y<=9, the number of zeros is 0<=z<=6. You may assume that n>0. The last test case is followed by the string 00e0.

Output

For each test case generate a line containing the position of the person who survives. Assume that the participants have serial numbers from 1 to n and that the counting starts with person 1, i.e., the first person leaving is the one with number 2. For example, if there are 5 persons in the circle, counting proceeds as 2, 4, 1, 5 and person 3 is staying alive.

Sample Input

05e0
01e1
42e0
66e6
00e0

Sample Output

3
5
21
64891137

Source

Ulm Local 2004

*/

#include <assert.h>
#include <math.h>

typedef unsigned long long uvlong;
typedef long long vlong;

vlong
number(const char *s)
{
	vlong x, y, z, r;

	if (!s[0] || !s[1] || (s[2] != 'e') || !s[3])
		return -1;

	x = s[0] - '0';
	y = s[1] - '0';
	z = s[3] - '0';

	r = (10 * x) + y;
	for (; z > 0; z--)
		r *= 10;
	return r;
}

// https://oeis.org/A006257
uvlong
josephus(uvlong n)
{
	uvlong b;

	if (n < 1)
		return 0;

	b = log2(n);
	return (2 * (n - (1ULL << b))) + 1;
}

vlong
position(const char *s)
{
	vlong n;

	n = number(s);
	if (n < 0)
		return -1;
	return josephus(n);
}

int
main(void)
{
	assert(position("05e0") == 3);
	assert(position("01e1") == 5);
	assert(position("42e0") == 21);
	assert(position("66e6") == 64891137LL);

	return 0;
}
