/*

Sofia works as a sales manager in the net of retailers.

Now the company is going to launch several brand-new items to their shops. The only trouble is that the name for new brands is yet to be choosen.

Sofia is ordered to invent these names. However, many good words are already used (like Apple, Ikea, Gillet). So she asked you to write a program which can generate a collection of funny words. She then will be able to read the list leisurely and pick some for brand names.

Let us work by following algorithm:

Let the words have arbitrary amount of letters, but letters at odd positions (1, 3, 5, ...) should be consonant, while letters at even positions (2, 4, 6, ...) - like galaban, fanero - since such words are guaranteed to be easy to pronounce.
Let us agree that consonant letters are bcdfghjklmnprstvwxz and vowels are aeiou (note q and y are skipped).
Implement simple Linear Congruential Generator with parameters A = 445, C = 700001, M = 2097152 - and initial value X0 for sequence (i.e. seed) would be given to you as input data.
To generate word consisting of N letters, generate the same amount of next random numbers with this generator, for example with X0 = 0 and N = 4 you'll get numbers 700001, 1821950, 1967079, 1537772.
convert each of these random values to letter by taking modulo 19 for consonants or 5 for vowels and selecting the letter from the strings above (see step 2) simply by index.
For example, if X0 = 0 and we are to generate the word of 4 letters, we have the following calculations:

Random Value       Letter Index        Letter
   700001         700001 % 19 = 3        F
  1821950        1821950 % 5  = 0        A
  1967079        1967079 % 19 = 9        M
  1537772        1537772 % 5  = 2        I
So resulting word is fami.

Surely, we can generate many words without reseting our random generator, since this generator has a period of about 2 million values.

Input data will contain number of words to generate at first line and seed value X0 for random generator.
Next line will contain lengths of words which should be generated, separated with spaces.
Answer should contain the words you generated, also separated by space.

Example:

input data:
3 0
4 5 6

answer:
fami wovaw kelasi
Another example:

input data:
4 2014
9 9 9 9

answer:
foravanad zibecefeb wagabenip wedivonow

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	long a;
	long c;
	long m;
	long x;
} LCG;

long
next(LCG *l)
{
	l->x = ((l->a * l->x) + l->c) % l->m;
	return l->x;
}

void
gen(LCG *lcg, char *buf, size_t len)
{
	static const char cons[] = "bcdfghjklmnprstvwxz";
	static const char vows[] = "aeiou";

	size_t i;
	long val;

	for (i = 0; i < len; i++) {
		val = next(lcg);
		if (!(i & 1))
			buf[i] = cons[val % (nelem(cons) - 1)];
		else
			buf[i] = vows[val % (nelem(vows) - 1)];
	}
	buf[i] = '\0';
}

void
test(LCG *lcg, size_t len, const char *res)
{
	char buf[16];

	gen(lcg, buf, len);
	puts(buf);
	assert(!strcmp(buf, res));
}

int
main()
{
	LCG lcg = {
		.a = 445,
		.c = 700001,
		.m = 2097152,
	};

	lcg.x = 0;
	test(&lcg, 4, "fami");
	test(&lcg, 5, "wovaw");
	test(&lcg, 6, "kelasi");

	lcg.x = 2014;
	test(&lcg, 9, "foravanad");
	test(&lcg, 9, "zibecefeb");
	test(&lcg, 9, "wagabenip");
	test(&lcg, 9, "wedivonow");

	return 0;
}
