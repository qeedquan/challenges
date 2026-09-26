/*

You're trying to plan out your family's Easter dinners for the next few centuries.

Your grandparents use the Lunar calendar, but your parents use the Julian calender, so you only have dinner with your grandparents when the calendars synchronize.

To help you figure that out, you're going to need to compute when M Julian years has the same amount of days as N Lunar months. As it turns out, these calendars synchronize with cycles of certain numbers of years.

Some information you will need:

The time between full moons is 29.53059 days, so that is the length of one Lunar month.

A Julian year is 365 days for three years, the fourth year is a leap year of 366 days, and then the cycle repeats.

When taking the days in a number of Lunar months, you will likely get a decimal answer. Round to the nearest day.

Author: Zamarok

Formal Inputs & Outputs
Input Description
You will be given two numbers (M, N), where
M is the number of Julian years, and
N is the number of Lunar months.

You need to confirm that the number of days in M Julian years is equal to the number of days in N Lunar months.

Output Description
You will take M and N and discover if the calendars synchronize after M Julian years and N Lunar months.

When looking at how many days N Lunar months will have, round to the nearest day.

If they do synchronize with the given input, print out the number of days that will pass before this occurs.

If the calendars don't synchronize with the given input, print 0.

Sample Inputs & Outputs

Sample Input
38, 470
Sample Output
13879

Challenge Input
114, 2664 (This is wrong, 2664 should be 1410)
30, 82
Challenge Input Solution
41638
0

Note
This was a problem in my homework for an astronomy class. I decided to code a solution to generate solutions, rather than figuring out it by hand. Turned out to be a good problem to solve, and I learned a bunch while doing it. It's difficult enough to provide a good challenge and to make you think about how to approach the problem from different angles.

Let me know if anyone wants to see the original homework assignment, or my solution (about 5 lines of Haskell).

Extra Credit (optional):
Right now your program just confirms when the calendars will synchronize. You can modify your program to generate (M, N) to sequentially discover solutions. Find the largest solution for M where M is less than 500.

For even more extra credit, point out the number of years that it takes for one cycle, a cycle being the time between when these calendars synchronize. There are multiple correct answers here.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

long
easter(long m, long n)
{
	long j, l;

	j = (m * 365) + (m / 4);
	l = round(n * 29.53059);
	return (j == l) ? j : 0;
}

int
main()
{
	static const long tab[][3] = {
		{ 38, 470, 13879 },
		{ 57, 705, 20819 },
		{ 76, 940, 27759 },
		{ 95, 1175, 34698 },
		{ 114, 1410, 41638 },
		{ 133, 1645, 48578 },
		{ 152, 1880, 55518 },
		{ 171, 2115, 62457 },
		{ 190, 2350, 69397 },
		{ 209, 2585, 76337 },
		{ 247, 3055, 90216 },
		{ 266, 3290, 97156 },
		{ 323, 3995, 117975 },
		{ 388, 4799, 141717 },
		{ 445, 5504, 162536 },
		{ 464, 5739, 169476 },
	};

	const long *v;
	size_t i;

	assert(easter(38, 470) == 13879);
	assert(easter(114, 1410) == 41638);
	assert(easter(30, 82) == 0);

	for (i = 0; i < nelem(tab); i++) {
		v = &tab[i][0];
		assert(easter(v[0], v[1]) == v[2]);
	}

	return 0;
}
