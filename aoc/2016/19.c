/*

--- Day 19: An Elephant Named Joseph ---
The Elves contact you over a highly secure emergency channel. Back at the North Pole, the Elves are busy misunderstanding White Elephant parties.

Each Elf brings a present. They all sit in a circle, numbered starting with position 1. Then, starting with the first Elf, they take turns stealing all the presents from the Elf to their left. An Elf with no presents is removed from the circle and does not take turns.

For example, with five Elves (numbered 1 to 5):

  1
5   2
 4 3
Elf 1 takes Elf 2's present.
Elf 2 has no presents and is skipped.
Elf 3 takes Elf 4's present.
Elf 4 has no presents and is also skipped.
Elf 5 takes Elf 1's two presents.
Neither Elf 1 nor Elf 2 have any presents, so both are skipped.
Elf 3 takes Elf 5's three presents.
So, with five Elves, the Elf that sits starting in position 3 gets all the presents.

With the number of Elves given in your puzzle input, which Elf gets all the presents?

The first half of this puzzle is complete! It provides one gold star: *

--- Part Two ---
Realizing the folly of their present-exchange rules, the Elves agree to instead steal presents from the Elf directly across the circle. If two Elves are across the circle, the one on the left (from the perspective of the stealer) is stolen from. The other rules remain unchanged: Elves with no presents are removed from the circle entirely, and the other elves move in slightly to keep the circle evenly spaced.

For example, with five Elves (again numbered 1 to 5):

The Elves sit in a circle; Elf 1 goes first:
  1
5   2
 4 3
Elves 3 and 4 are across the circle; Elf 3's present is stolen, being the one to the left. Elf 3 leaves the circle, and the rest of the Elves move in:
  1           1
5   2  -->  5   2
 4 -          4
Elf 2 steals from the Elf directly across the circle, Elf 5:
  1         1
-   2  -->     2
  4         4
Next is Elf 4 who, choosing between Elves 1 and 2, steals from Elf 1:
 -          2
    2  -->
 4          4
Finally, Elf 2 steals from Elf 4:
 2
    -->  2
 -
So, with five Elves, the Elf that sits starting in position 2 gets all the presents.

With the number of Elves given in your puzzle input, which Elf now gets all the presents?

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <errno.h>

typedef long long vlong;

vlong
highestpow3(vlong n)
{
	vlong x;

	x = 3;
	while (x <= n)
		x *= 3;
	return x / 3;
}

// https://oeis.org/A006257
vlong
part1(vlong n)
{
	vlong x;

	if (n < 1)
		return 0;

	x = log2(n);
	return 2 * (n - (1 << x)) + 1;
}

vlong
part1bf(vlong n)
{
	vlong *p, i, l;

	if (n < 1)
		return 0;

	p = calloc(n, sizeof(*p));
	if (!p)
		return -1;

	for (i = 0; i < n; i++)
		p[i] = 1;

	i = 0;
	for (;;) {
		while (p[i] == 0)
			i = (i + 1) % n;

		l = (i + 1) % n;
		while (p[l] == 0)
			l = (l + 1) % n;

		if (i == l)
			break;

		p[i] += p[l];
		p[l] = 0;
		i = (l + 1) % n;
	}
	free(p);

	return i + 1;
}

// https://oeis.org/A334473
vlong
part2(vlong n)
{
	vlong x;

	if (n < 1)
		return 0;

	x = highestpow3(n);
	if (x == n)
		return x;

	if (n < 2 * x)
		return n % x;
	return x + (2 * (n % x));
}

vlong
part2bf(vlong n)
{
	vlong *e;
	vlong i, j;
	vlong x, y;
	vlong r;

	if (n < 1)
		return 0;

	e = calloc(n, sizeof(*e));
	if (!e)
		return -errno;

	for (i = 0; i < n; i++)
		e[i] = i;

	for (i = 0; n > 1; i = (i + 1) % n) {
		x = e[i];
		j = (i + (n / 2)) % n;
		y = e[j];
		if (x == y)
			break;

		memmove(e + j, e + j + 1, (n - j - 1) * sizeof(*e));
		n -= 1;

		if (i > j)
			i -= 1;
	}
	r = e[0] + 1;

	free(e);
	return r;
}

int
main()
{
	vlong n;

	n = 3014387;
	printf("%lld\n", part1(n));
	printf("%lld\n", part2(n));
	for (n = 0; n <= 2000; n++) {
		assert(part1(n) == part1bf(n));
		assert(part2(n) == part2bf(n));
	}

	return 0;
}
