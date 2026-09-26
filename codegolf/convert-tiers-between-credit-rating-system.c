/*

Related: Sort these bond ratings
https://codegolf.stackexchange.com/questions/71723/sort-these-bond-ratings

Credit rating agencies assign ratings to bonds according to the credit-worthiness of the issuer. The rating business is mostly controlled by "Big Three" credit rating agencies (i.e. Fitch Ratings, Moody's, and Standard & Poor's (S&P)), which use a similar tiered rating system.

Task
For this challenge, we will consider only long-term non in-default tiers of two rating formats, Moody's and Fitch/S&P. NA-style ratings such as NR or WR will not be included.

Your task is to design a program that takes as input a rating tier in one of the two format and outputs the equivalent tier in the other format. Your program must support both formats in input and output, i.e. your program cannot be able only to convert from Moody's to Fitch/S&P or vice versa.

The following table shows the tier pairs.

Moody's Fitch/S&P
------- ---------
Aaa     AAA
Aa1     AA+
Aa2     AA
Aa3     AA−
A1      A+
A2      A
A3      A−
Baa1    BBB+
Baa2    BBB
Baa3    BBB-
Ba1     BB+
Ba2     BB
Ba3     BB−
B1      B+
B2      B
B3      B−
Caa     CCC
Ca      CC
Ca      C

Notes
there are no tiers in the two formats that are identical;
for each rating tier (except Ca) there is one (and only one) equivalent tier in the other format;
Ca is equivalent to either CC or C, depending on the specific case;
when your program takes as input Ca, it must output CC or C indifferently;
your program must output Ca when the input is CC or C.

Rules and scoring
This is code golf, so lowest byte count wins, standard loopholes disallowed.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

const char *
conv(const char *s)
{
	static const char *lut[][2] = {
	    {"Aaa", "AAA"},
	    {"Aa1", "AA+"},
	    {"Aa2", "AA"},
	    {"Aa3", "AA-"},
	    {"A1", "A+"},
	    {"A2", "A"},
	    {"A3", "A-"},
	    {"Baa1", "BBB+"},
	    {"Baa2", "BBB"},
	    {"Baa3", "BBB-"},
	    {"Ba1", "BB+"},
	    {"Ba2", "BB"},
	    {"Ba3", "BB-"},
	    {"B1", "B+"},
	    {"B2", "B"},
	    {"B3", "B-"},
	    {"Caa", "CCC"},
	    {"Ca", "CC"},
	    {"Ca", "C"},
	};

	size_t i;
	const char **p;

	for (i = 0; i < nelem(lut); i++) {
		p = lut[i];
		if (!strcmp(s, p[0]))
			return p[1];

		if (!strcmp(s, p[1]))
			return p[0];
	}
	return NULL;
}

void
test(const char *s, const char *r)
{
	const char *p;

	p = conv(s);
	assert(!strcmp(p, r));
}

int
main(void)
{
	test("Baa1", "BBB+");
	test("Ca", "CC");
	test("CC", "Ca");
	test("C", "Ca");
	test("Aa3", "AA-");

	return 0;
}
