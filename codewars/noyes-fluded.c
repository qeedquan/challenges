/*

There is a man, and there is a boat, and there are a lot of animals.

This man wants to get his animals onto the boat, but only in pairs, and in alphabetical order. If there are any excess animals they are to be cruelly abandoned. He has developed a helpful to code to make life easier, where animals are referred to by the first letter of their name. Unfortunately there are more than 26 animals, for example there are 'g' - Gerbils and 'G' - Giraffes. These are very different animals and if they got mixed up it could be a disaster!

The animals are currently in a long and disorganised queue. like so ['g','p','h','g','c','c'] In this case we can see that there are two gerbils, one pelican, one hamster, and two cats. They are out of order.

Your job is arrange the animals into pairs like so [[‘c','c'],['g','g']] remember that animals are case sensitive! And for everyone’s convenience we want the bigger animals to come before smaller animals that occupy the same place in the alphabet. Giraffes before gerbils! alsoo please note we only want one pair of each animal, boat space is limited

Oh and one last thing, there are rumours of sneaky numbers trying to get on board.

Don't let any numbers onto the boat!!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
dump(int a[][2], size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		printf("[%c %c] ", a[i][0], a[i][1]);
	printf("\n");
}

size_t
boatloader(int a[], size_t n, int r[52][2])
{
	size_t h[256];
	size_t i, j, l;
	int c[2];

	memset(h, 0, sizeof(h));
	for (i = 0; i < n; i++) {
		if (0 <= a[i] && a[i] <= 255)
			h[a[i]]++;
	}

	for (i = l = 0; i < 26; i++) {
		c[0] = 'A' + i;
		c[1] = 'a' + i;
		for (j = 0; j < 2; j++) {
			if (h[c[j]] > 1) {
				r[l][0] = r[l][1] = c[j];
				l++;
			}
		}
	}
	return l;
}

void
test(int a[], size_t n, int r[][2], size_t nr)
{
	int p[52][2];
	size_t np;

	np = boatloader(a, n, p);
	dump(p, np);
	assert(np == nr);
	assert(!memcmp(p, r, sizeof(*r) * nr));
}

int
main()
{
	int a1[] = { 'g', 'c', 'h', 'c', 'g', 'm' };
	int a2[] = { 'a', 'd', 'G', 'V', 'X', 'F', 'g', 'h', 's', 'r', 'a', 'g', 'n', 's', 'e', 'r', 'j', 'a', 'f', 'D', 'F', 'G', 'R', 'H', 'C', 'X', 'B', 'N', 'G', 'U', 'G', 'F', 'p', 's', 'r', 'g', 'a' };
	int a3[] = { 'g', 'g', 'G', 'c', 'p', 'x', 'z', 'Z', 'G', 'c', 'g', 'g' };
	int a4[] = { 5, 6, 5, 'g', 'g', 'G', 'c', 'p', 'x', 'z', 'Z', 'G', 'c', 'g', 'g' };

	int r1[][2] = { { 'c', 'c' }, { 'g', 'g' } };
	int r2[][2] = { { 'a', 'a' }, { 'F', 'F' }, { 'G', 'G' }, { 'g', 'g' }, { 'r', 'r' }, { 's', 's' }, { 'X', 'X' } };
	int r3[][2] = { { 'c', 'c' }, { 'G', 'G' }, { 'g', 'g' } };
	int r4[][2] = { { 'c', 'c' }, { 'G', 'G' }, { 'g', 'g' } };

	test(a1, nelem(a1), r1, nelem(r1));
	test(a2, nelem(a2), r2, nelem(r2));
	test(a3, nelem(a3), r3, nelem(r3));
	test(a4, nelem(a4), r4, nelem(r4));

	return 0;
}
