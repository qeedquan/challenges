/*

Air balloons need a gas that is lighter than air. However, hydrogen is flammable, while helium is not sustainable, so we need a replacement! You must write code that determines whether any given gas is lighter than air.

Input: a molecular chemical formula of a gas (ASCII)

Output: true if the gas is lighter than air; false otherwise (see here for consensus on what can be used as true and false).

If the chemical formula doesn't represent a gas (at standard conditions), or if it's a nonsense, any behavior is acceptable.

That is to say, you can assume the following:

The input is a valid chemical formula
The input is a molecular chemical formula: all element symbols are mentioned only once, and there are no parentheses
The chemical substance exists at normal conditions
The chemical substance is a gas at normal conditions
As a special case, H2O (water vapor) is considered a gas, because you can mix a significant quantity of it with air at standard conditions.

Whether or not a gas is lighter than air can be determined by calculating its molar mass:

Extract the chemical element symbols from the formula. Their atomic masses are given by the following table:

H - 1
He - 4
B - 11
C - 12
N - 14
O - 16
F - 19
Ne - 20
Others - greater values
Calculate the molar mass, which is the sum of all the atomic masses. If the molar mass is less than 29, the gas is lighter than air.

Test cases:

H2      true
He      true
B2H6    true
CH4     true
C2H2    true
C2H4    true
HCN     true
N2      true
NH3     true
H2O     true
CO      true
HF      true
Ne      true
O2      false
C2H6    false
C4H10   false
H2S     false
COH2    false
CO2     false
SiH4    false
NO      false
BN      behavior nor specified: not a gas
HBO2    behavior nor specified: not a gas
F2O     behavior nor specified: incorrect formula
CH3     behavior nor specified: incorrect formula
HCOOH   behavior nor specified: not a molecular formula
B(OH)3  behavior nor specified: not a molecular formula
XYZ     behavior nor specified: nonsense
(Note: this is meant to be an enumeration of all possible inputs that generate true. If I forgot some, I'll add it. In any case, Wikipedia is the answer for questions like "Does substance X exist?", "Is it a gas?")

A related (but different) question: calculate the molar mass

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	char name[4];
	size_t nname;
	int mass;
} Element;

const Element *
lookup(const char *s)
{
	static const Element tab[] = {
	    {"He", 2, 4},
	    {"Ne", 2, 20},
	    {"H", 1, 1},
	    {"B", 1, 11},
	    {"C", 1, 12},
	    {"N", 1, 14},
	    {"O", 1, 16},
	    {"F", 1, 19},
	};

	const Element *e;
	size_t i;

	for (i = 0; i < nelem(tab); i++) {
		e = tab + i;
		if (!strncmp(s, e->name, e->nname))
			return e;
	}
	return NULL;
}

bool
lighter(const char *s)
{
	const Element *e;
	char *ep;
	long m, v;

	v = 0;
	while (*s) {
		e = lookup(s);
		if (!e)
			return false;
		s += e->nname;

		m = 1;
		if (isdigit(*s)) {
			m = strtol(s, &ep, 10);
			s = ep;
		}
		v += m * e->mass;
	}
	return v < 29;
}

int
main(void)
{
	assert(lighter("H2") == true);
	assert(lighter("He") == true);
	assert(lighter("B2H6") == true);
	assert(lighter("CH4") == true);
	assert(lighter("C2H2") == true);
	assert(lighter("C2H4") == true);
	assert(lighter("HCN") == true);
	assert(lighter("N2") == true);
	assert(lighter("HH3") == true);
	assert(lighter("H2O") == true);
	assert(lighter("CO") == true);
	assert(lighter("HF") == true);
	assert(lighter("Ne") == true);

	assert(lighter("O2") == false);
	assert(lighter("C2H6") == false);
	assert(lighter("C4H10") == false);
	assert(lighter("H2S") == false);
	assert(lighter("COH2") == false);
	assert(lighter("CO2") == false);
	assert(lighter("SiH4") == false);
	assert(lighter("NO") == false);

	return 0;
}
