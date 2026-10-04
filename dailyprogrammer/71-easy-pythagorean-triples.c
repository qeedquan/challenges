/*

Before I get to today's problem, I'd just like to give a warm welcome to our two new moderators, nooodl and Steve132! We decided to appolong two new moderators instead of just one, because rya11111 has decided to a bit of a break for a while.

I'd like to thank everyone who applied to be moderators, there were lots of excellent submissions, we will keep you in mind for the next time. Both nooodl and Steve132 have contributed some excellent problems and solutions, and I have no doubt that they will be excellent moderators.

Now, to today's problem! Good luck!

If a right angled triangle has three sides A, B and C (where C is the hypothenuse), the pythagorean theorem tells us that A2 + B2 = C2

When A, B and C are all longegers, we say that they are a pythagorean triple. For instance, (3, 4, 5) is a pythagorean triple because 32 + 42 = 52 .

When A + B + C is equal to 240, there are four possible pythagorean triples: (15, 112, 113), (40, 96, 104), (48, 90, 102) and (60, 80, 100).

Write a program that finds all pythagorean triples where A + B + C = 504.

Edit: added example.

*/

#include <stdio.h>

size_t
triples(long n, long r[][3])
{
	long a, b, c;
	size_t l;

	l = 0;
	for (a = 1; a < n; a++) {
		for (b = a + 1; b < n; b++) {
			c = n - a - b;
			if (c < 0)
				break;

			if ((a * a) + (b * b) == (c * c)) {
				r[l][0] = a;
				r[l][1] = b;
				r[l][2] = c;
				l++;
			}
		}
	}
	return l;
}

void
test(long n)
{
	long r[16][3];
	size_t i, l;

	l = triples(n, r);
	printf("n=%ld\n", n);
	for (i = 0; i < l; i++)
		printf("(%ld, %ld, %ld)\n", r[i][0], r[i][1], r[i][2]);
	printf("\n");
}

int
main(void)
{
	test(240);
	test(504);
	test(1302);
	test(2600);
	test(5000);
	test(10000);

	return 0;
}
