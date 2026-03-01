/*

Is this a valid PZN?
A Pharmazentralnummer, or PZN, is an eight-digit code which uniquely identifies medications, medical products, and similar items in the German healthcare system.
Examples include ibuprofen tablets, insulin injectors, toothpaste, warm-and-cold compresses, all sorts of things. When a doctor issues a prescription, it's almost always using a PZN, which then is fulfilled by the Apotheke.

The challenge
Write a program or function that takes an eight-digit code as input, and returns a truthy if it is a valid PZN, or falsy if it is not.

A PZN consists of seven code-digits, and a check-digit. Each code-digit is multiplied by a weight based on its position, from 1 to 7, then each value is summed up, and reduced modulo 11.
The result is checked against the check-digit. If they are equal, then the PZN is valid.

When reducing the value modulo 11, the result could be 10. In that case, the PZN isn't valid.

Example: PZN 13724857.
The code-digits are 1, 3, 7, 2, 4, 8, 5, and the check-digit is 7.

Step 1: Multiply each code-digit by its weight.
The weight is the position of the code-digit in the PZN, from 1 to 7.

Digit | Weight | Value
1     | 1      | 1*1 = 1
3     | 2      | 3*2 = 6
7     | 3      | 7*3 = 21
2     | 4      | 2*4 = 8
4     | 5      | 4*5 = 20
8     | 6      | 8*6 = 48
5     | 7      | 5*7 = 35
Step 2: Add all the weighted values together, and reduce modulo 11
The total of the weighted values is 1 + 6 + 21 + 8 + 20 + 48 + 35 = 139

Then reduce the total modulo 11: 139 mod 11 = 7

The computed result is the same as our check-digit 7, so the PZN is valid.

Test cases
PZN      | Is valid?
00000000 | True
13724857 | True
08108754 | True
04861880 | True
16086334 | True
01349035 | True
00000001 | False
00000002 | False
06765774 | False
08108759 | False
00100010 | False

Rules
You can assume that the input will always be a code precisely eight digits long - you don't need to account for grossly invalid inputs (e.g. with letters or spaces).
However, your solution must accept a code that is precisely eight digits long, including leading zeros.
Finally, this is code-golf - the shortest solution by number of bytes wins!

*/

#include <assert.h>
#include <stdio.h>
#include <ctype.h>

bool
pzn(const char *s)
{
	size_t i;
	int v;

	v = 0;
	for (i = 0; i < 7 && s[i]; i++) {
		if (!isdigit(s[i]))
			return false;

		v += (s[i] - '0') * (i + 1);
	}

	if (i != 7)
		return false;

	v %= 11;
	if (v == 10 || v != s[7] - '0')
		return false;

	if (s[8])
		return false;

	return true;
}

int
main()
{
	assert(pzn("00000000") == true);
	assert(pzn("13724857") == true);
	assert(pzn("08108754") == true);
	assert(pzn("04861880") == true);
	assert(pzn("16086334") == true);
	assert(pzn("01349035") == true);
	assert(pzn("00000001") == false);
	assert(pzn("00000002") == false);
	assert(pzn("06765774") == false);
	assert(pzn("08108759") == false);
	assert(pzn("00100010") == false);

	return 0;
}
