/*

I'm not even sure if this is even possible, but I think it's worth a shot.

The Challenge

Code/conceptualize a pseudo-random number generator that has the potential to produce results evenly spaced out with similar frequencies... with a twist. The random number generator has to 'loop' back after Foo iterations to its beginning state then produce the exact same results. Foo is a variable of all positive integers.

For example, if the iterations amount is 4 and the random numbers generated after 4 iterations are {93,5,80,13}, then the next 4 iterations will produce {93,5,80,13}, as will the next 4 after that and so on.

Limitations

Random numbers can't be pre-defined. For example, the algorithm can't simply iterate over {1,2,3,4,...int.MaxValue}, up to the iteration amount then go back to the first value.
Similar to Limitation 1, random numbers can't be cached so a set of numbers can't be generated, saved, then repeatedly returned.
Similar to Limitation 2, the random number generator can't be 'forced' back to a certain state. Beginning seed numbers and whatnot cannot be saved.
The RNG can't use the number of iterations its run.
In other words, the Generator has to arrive back at its beginning state solely through consecutive calculations.

Objective

Shortest code wins!

*/

#include <stdio.h>

typedef struct {
	int x;
	int m;
	int i;
} Fullcycle;

int
gcd(int a, int b)
{
	int t;

	while (b) {
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}

/*

@Nejc

def generatePeriodic(seed, period):
    x = seed
    increment = findSmallestCoPrime(period)
    while True:
        x = (x + increment) % period
        yield x

This method always yields all values from [0, period - 1] and then repeats itself. Here findSmallestCoPrime is a function that returns the smallest prime p for which gcd(p, period) = 1 holds.

*/

void
fcinit(Fullcycle *c, int seed, int period)
{
	int i;

	c->x = seed;
	c->m = period;
	c->i = 1;
	for (i = 2; i <= period; i++) {
		if (gcd(i, period) == 1) {
			c->i = i;
			break;
		}
	}
}

int
fcnext(Fullcycle *c)
{
	int r;

	r = c->x;
	c->x = (c->x + c->i) % c->m;
	return r;
}

void
test(int seed, int period)
{
	Fullcycle c;
	int i;

	fcinit(&c, seed, period);
	for (i = 0; i < period; i++)
		printf("%d\n", fcnext(&c));
}

int
main(void)
{
	test(33, 1000);
	return 0;
}
