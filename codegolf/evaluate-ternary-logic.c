/*

Objective
Given an expression involving ternary values, evaluate it into a ternary value.

Ternary Values
The three truth values in question are the values of Haskell's Ordering, namely LT, EQ, and GT. They stand for "less-than", "equal-to", and "greater-than", respectively. Furthermore, they themselves have an order; LT is the least, and GT is the greatest.

Operators
The binary operators for the ternary values are Haskell's min, max, compare, and (<>), all instantiated for Ordering. They're defined as:

min|LT EQ GT
---|--------
LT |LT LT LT
EQ |LT EQ EQ
GT |LT EQ GT

max|LT EQ GT
---|--------
LT |LT EQ GT
EQ |EQ EQ GT
GT |GT GT GT

compare|LT EQ GT
-------|--------
  LT   |EQ LT LT
  EQ   |GT EQ LT
  GT   |GT GT EQ

(<>)|LT EQ GT
----|--------
 LT |LT LT LT
 EQ |LT EQ GT
 GT |GT GT GT

I/O Format
Flexible. You may represent the values and the operators in an arbitrary way. In particular, the expression may be in Polish notation.

Examples
Here, the shorthands are T for LT, 0 for EQ, 1 for GT, & for min, | for max, c for compare, and s for (<>). The expressions are in Polish notation.

Expression, Evaluation

c01, T
sT1, T
|0&1T, 0
|&1T0, 0
s0s00, 0
s0s01, 1
sTcTT, T
cs10T, 1
cs01&|01T, 1

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef int (*binfn)(int, int);

enum {
	LT,
	EQ,
	GT,
};

int
tlmin(int a, int b)
{
	static const int tab[3][3] = {
	    {LT, LT, LT},
	    {LT, EQ, EQ},
	    {LT, EQ, GT},
	};
	return tab[a][b];
}

int
tlmax(int a, int b)
{
	static const int tab[3][3] = {
	    {LT, EQ, GT},
	    {EQ, EQ, GT},
	    {GT, GT, GT},
	};
	return tab[a][b];
}

int
tlcmp(int a, int b)
{
	static const int tab[3][3] = {
	    {EQ, LT, LT},
	    {GT, EQ, LT},
	    {GT, GT, EQ},
	};
	return tab[a][b];
}

int
tlneq(int a, int b)
{
	static const int tab[3][3] = {
	    {LT, LT, LT},
	    {LT, EQ, GT},
	    {GT, GT, GT},
	};
	return tab[a][b];
}

int
eval(const char *s)
{
	static const char sym[] = "T01";

	binfn binop;
	int r;
	int *stk;
	size_t sp;
	size_t n;

	n = strlen(s);
	stk = calloc(n + 1, sizeof(*stk));
	if (!stk)
		goto error;

	for (sp = 0; n > 0; n--) {
		binop = NULL;
		switch (s[n - 1]) {
		case 'T':
			stk[sp++] = LT;
			break;
		case '0':
			stk[sp++] = EQ;
			break;
		case '1':
			stk[sp++] = GT;
			break;
		case '&':
			binop = tlmin;
			break;
		case '|':
			binop = tlmax;
			break;
		case 'c':
			binop = tlcmp;
			break;
		case 's':
			binop = tlneq;
			break;
		default:
			errno = EINVAL;
			goto error;
		}

		if (binop) {
			if (sp < 2) {
				errno = ENOMEM;
				goto error;
			}

			stk[sp - 2] = binop(stk[sp - 1], stk[sp - 2]);
			sp--;
		}
	}
	r = sym[stk[0]];

	if (0) {
	error:
		r = -errno;
	}
	free(stk);

	return r;
}

int
main(void)
{
	assert(eval("c01") == 'T');
	assert(eval("sT1") == 'T');
	assert(eval("|0&1T") == '0');
	assert(eval("|&1T0") == '0');
	assert(eval("s0s00") == '0');
	assert(eval("s0s01") == '1');
	assert(eval("sTcTT") == 'T');
	assert(eval("cs10T") == '1');
	assert(eval("cs01&|01T") == '1');

	return 0;
}
