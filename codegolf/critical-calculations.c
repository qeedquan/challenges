/*

Background
In the game stick ranger, there is an item which grants the character the ability to get critical hits. Each time a projectile hits an enemy, it has some probability to be a critical hit (crit). For most weapons this is calculated independently each time, but for one class (the angel) things work differently. The angel throws multiple rings per volley, and each has a chance to crit. But, (and apparently this is not a bug) once a ring crits, that crit multiplier stays. And in fact if one is lucky enough for a second ring to crit in the same volley, the crits will multiply. So if the first crit is 10X the original damage, the second will be 100X. All crits persist until the next volley is reached. This is great, but I want to know what my damage per second is given a particular set up. I know the base damage and hit rate, but this crit multiplier business is tricky, and I could use a short program to help me out.

The challenge
You will be given three inputs: the crit probability, the crit multiplier, and the number of rings. We'll assume each ring hits some enemy exactly once. You must then output the average damage per ring (or per volley) gained by having the crit applied.

Standard I/O rules apply, the inputs and output may be in any logical format including fractions, decimals, and percentages. You may assume 0<odds<1, 1<multiplier, and 0<hits.
The output from your program must be within 0.1% of the true value at least 90% of the time.

This is code-golf, so the shortest answer in bytes wins.

Worked example
Let's work through the answer with a crit chance of 0.2, multiplier of 6, and 2 rings. For this example all I/O uses decimals, and I'll find the average damage per ring. There are four distinct outcomes

outcome             damage          probability         weighted

no crits            1 + 1 = 2       0.8 * 0.8 = 0.64    2  * 0.64 = 1.28
no crit then crit   1 + 6 = 7       0.8 * 0.2 = 0.16    7  * 0.16 = 1.12
crit then no crit   6 + 6 = 12      0.2 * 0.8 = 0.16    12 * 0.16 = 1.92
two crits           6 + 36 = 42     0.2 * 0.2 = 0.04    42 * 0.04 = 1.68
                                                                    ----
total                                                               6.00
Thus our answer is 6/2 = 3 average damage per ring. This is much higher than what a simple crit system would yield 1*0.8 + 6*0.2 = 2

Test cases
odds, multiplier, hits -> output

0.2, 6, 2 -> 3
0.3, 5, 3 -> 5.896
0.5, 2, 4 -> 3.046875
0.2, 7, 5 -> 18.529984
0.15, 10, 5 -> 24.6037391875

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

/*

@xnor

A formula I derived. With crit probability p, multiplier m, and n hits, the average damage per hit is

c/n * (c^n - 1)/(c - 1)

where

c = 1 - p + p*m

*/

double
critical(double p, double m, double n)
{
	double c;

	c = 1 - p + (p * m);
	return (c / n) * (pow(c, n) - 1) / (c - 1);
}

void
test(double p, double m, double n, double r)
{
	double x;

	x = critical(p, m, n);
	printf("%f\n", x);
	assert(fabs(x - r) < 1e-8);
}

int
main(void)
{
	test(0.2, 6, 2, 3);
	test(0.3, 5, 3, 5.896);
	test(0.5, 2, 4, 3.046875);
	test(0.2, 7, 5, 18.529984);
	test(0.15, 10, 5, 24.6037391875);

	return 0;
}
