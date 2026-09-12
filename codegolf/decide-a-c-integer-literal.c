/*

Objective
Given an ASCII string, decide whether it is a valid C integer literal.

C integer literal
A C integer literal consists of:

One of:

0 followed by zero or more octal digits (0–7)

A nonzero decimal digit followed by zero or more decimal digits (0–9)

0X or 0x, followed by one or more hexadecimal digits (0–9, A–F, and a–f)

optionally followed by one of:

One of U or u, which are the "unsigned" suffixes

One of L, l, LL, or ll, which are the "long" and "long long" suffixes

Any combination of the above, in any order.

Note that there can be arbitrarily many digits, even though C doesn't support arbitrary-length integers. Likewise, even if the literal with l and co would overflow the long type or co, it is still considered a valid literal.

Also note that there must not be a leading plus or minus sign, for it is not considered to be a part of the literal.

Rules
It is implementation-defined to accept leading or trailing whitespaces.

Non-ASCII string falls in don't care situation.

Examples
Truthy
0

007

42u

42lu

42UL

19827489765981697847893769837689346573uLL (Digits can be arbitrarily many even if it wouldn't fit the unsigned long long type)

0x8f6aa032838467beee3939428l (So can to the long type)

0XCa0 (You can mix cases)

Falsy
08 (Non-octal digit)

0x (A digit must follow X or x)

-42 (Leading signature isn't a part of the literal)

42Ll (Only LL or ll is valid for the long long type)

42LLLL (Redundant type specifier)

42Uu (Redundant type specifier)

42Ulu (Redundant type specifier)

42lul (Redundant type specifier)

42H (Invalid type specifier)

0b1110010000100100001 (Valid C++, but not valid C)

Hello

Empty string

Ungolfed solution
Haskell
Doesn't recognize leading or trailing whitespaces.

Returns () on success. Monadic failure otherwise.

import Text.ParserCombinators.ReadP

decideCIntegerLit :: ReadP ()
decideCIntegerLit = do
    choice [
        do
            '0' <- get
            munch (flip elem "01234567"),
        do
            satisfy (flip elem "123456789")
            munch (flip elem "0123456789"),
        do
            '0' <- get
            satisfy (flip elem "Xx")
            munch1 (flip elem "0123456789ABCDEFabcdef")
        ]
    let unsigned = satisfy (flip elem "Uu")
    let long = string "l" +++ string "L" +++ string "ll" +++ string "LL"
    (unsigned >> long >> return ()) +++ (optional long >> optional unsigned)
    eof

*/

#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
cil(const char *s)
{
	static const char hex[] = "0123456789abcdef";
	static const char dec[] = "0123456789";
	static const char oct[] = "01234567";
	static const char suffixes[][4] = {
	    "u",
	    "ul",
	    "uL",
	    "ull",
	    "uLL",
	    "U",
	    "Ul",
	    "UL",
	    "Ull",
	    "ULL",
	    "l",
	    "L",
	    "lu",
	    "Lu",
	    "llu",
	    "llU",
	    "LLu",
	    "LLU",
	};

	const char *d;
	size_t i;

	if (*s == '\0')
		return false;

	d = dec;
	if (*s == '0') {
		d = oct;
		s++;
		if (tolower(*s) == 'x') {
			d = hex;
			s++;
			if (*s == '\0')
				return false;
		}
	}

	while (*s && strchr(d, tolower(*s)))
		s++;

	for (i = 0; i < nelem(suffixes); i++) {
		if (!strcmp(s, suffixes[i]))
			return true;
	}

	return *s == '\0';
}

int
main(void)
{
	assert(cil("0") == true);
	assert(cil("007") == true);
	assert(cil("42u") == true);
	assert(cil("42lu") == true);
	assert(cil("42UL") == true);
	assert(cil("19827489765981697847893769837689346573uLL") == true);
	assert(cil("0x8f6aa032838467beee3939428l") == true);
	assert(cil("0XCa0") == true);
	assert(cil("351llu") == true);
	assert(cil("0x31ULL") == true);
	assert(cil("0045UL") == true);
	assert(cil("0xa82ul") == true);
	assert(cil("123545779000ull") == true);

	assert(cil("08") == false);
	assert(cil("0x") == false);
	assert(cil("-42") == false);
	assert(cil("42Ll") == false);
	assert(cil("42LLLL") == false);
	assert(cil("42Uu") == false);
	assert(cil("42Ulu") == false);
	assert(cil("42lul") == false);
	assert(cil("42H") == false);
	assert(cil("0b1110010000100100001") == false);
	assert(cil("Hello") == false);
	assert(cil("") == false);

	return 0;
}
