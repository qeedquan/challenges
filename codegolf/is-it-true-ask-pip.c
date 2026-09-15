/*

Title is an homage to this classic challenge

In Pip, the Scalar data type encompasses strings and numbers. A Scalar value is truthy in most cases. It is falsey only if:

It is the empty string ""; or
It is some representation of the number zero.
A Scalar is considered to be a representation of zero if:

It consists of one or more 0s; or
It consists of one or more 0s plus a single . anywhere among them.
The decimal point can be in the middle, at the beginning, or at the end.

Challenge
Given a string containing printable ASCII characters, determine whether it is a truthy Scalar or a falsey Scalar according to Pip.

The default allowable output formats for decision-problem apply: you may either output a truthy/falsey value in your language, with swapping allowed, or choose two consistent values, one representing truthy and the other representing falsey.

This is code-golf; the goal is to minimize the size of your source code, measured in bytes.

Examples
Falsey:

""
"0"
"000"
".0"
".00"
"0."
"00."
"0.00"
"0000000000000.00000000000000"
Truthy:

"a"
"0001"
"0x00"
"0e0"
" 0"
"0 "
"+0"
"-0"
"."
"0.0.0"

Reference implementation
This Python 3 code is adapted from the actual Pip interpreter:

import re
zeroRgx = re.compile(r"^(0+(\.0*)?|0*\.0+)$")
def truthy(value):
    return value != "" and not zeroRgx.match(value)

*/

#include <assert.h>
#include <stdio.h>
#include <regex.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
truth(const char *s)
{
	regex_t re;
	int r;

	if (!*s)
		return false;

	if (regcomp(&re, "^(0+(\\.0*)?|0*\\.0+)$", REG_EXTENDED | REG_NOSUB) != 0)
		return false;

	r = regexec(&re, s, 0, NULL, 0);
	regfree(&re);
	return r != 0;
}

int
main(void)
{
	static const char *falsey[] = {
	    "",
	    "0",
	    "000",
	    ".0",
	    ".00",
	    "0.",
	    "00.",
	    "0.00",
	    "0000000000000.00000000000000",
	};

	static const char *truthy[] = {
	    "a",
	    "0001",
	    "0x00",
	    "0e0",
	    " 0",
	    "0 ",
	    "+0",
	    "-0",
	    ".",
	    "0.0.0",
	};

	size_t i;

	for (i = 0; i < nelem(falsey); i++)
		assert(truth(falsey[i]) == false);

	for (i = 0; i < nelem(truthy); i++)
		assert(truth(truthy[i]) == true);

	return 0;
}
