/*

A double precision floating-point type (double) has the following format:

> Sign (1 bit)
| > Exponent (11 bits)
| |           > Mantissa (52 bits)
| |           |
s eeeeeeeeeee mmmmmmmmmmmmmmmmm...mm
Given a double value, extract its exponent part and return the value as an int.

Restrictions
You can't use any of the characters +-* /%&|^~<>#? in your code, which means:

You can't do any arithmetic/bitwise operations.
You can't do any pointer/address operations.
You can't include any extra files.

*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <float.h>

typedef unsigned _BitInt(52) uint52;
typedef unsigned _BitInt(11) uint11;
typedef unsigned _BitInt(1) uint1;

typedef union {
	double value;
	struct {
		uint52 mantissa;
		uint11 exponent;
		uint1 sign;
	};
} IEEE754LE;

typedef union {
	double value;
	struct {
		uint1 sign;
		uint11 exponent;
		uint52 mantissa;
	};
} IEEE754BE;

uint11
exple(double value)
{
	IEEE754LE ieee754;

	memcpy(&ieee754, &value, sizeof(value));
	return ieee754.exponent;
}

uint11
expbe(double value)
{
	IEEE754BE ieee754;

	memcpy(&ieee754, &value, sizeof(value));
	return ieee754.exponent;
}

int
main()
{
	double value;

	value = DBL_MAX;
	printf("%b %b\n", (int)exple(value), (int)expbe(value));
	return 0;
}
