/*

For this game of BINGO, you will receive a single array of 10 numbers from 1 to 26 as an input. Duplicate numbers within the array are possible.

Each number corresponds to their alphabetical order letter (e.g. 1 = A. 2 = B, etc). Write a function where you will win the game if your numbers can spell "BINGO". They do not need to be in the right order in the input array. Otherwise you will lose. Your outputs should be "WIN" or "LOSE" respectively.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

const char *
bingo(int *a, size_t n)
{
	static const char word[] = "BINGO";
	static int wordmask = 0x1f;

	char *p;
	size_t i;
	int f;

	f = 0;
	for (i = 0; i < n; i++) {
		p = strchr(word, a[i] + 'A' - 1);
		if (p)
			f |= 1 << (p - word);

		if (f == wordmask)
			return "WIN";
	}
	return "LOSE";
}

void
test(int *a, size_t n, const char *r)
{
	const char *p;

	p = bingo(a, n);
	puts(p);
	assert(!strcmp(p, r));
}

int
main()
{
	int a1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int a2[] = { 21, 13, 2, 7, 5, 14, 7, 15, 9, 10 };

	test(a1, nelem(a1), "LOSE");
	test(a2, nelem(a2), "WIN");

	return 0;
}
