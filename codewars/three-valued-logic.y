/*

Background
Three-valued logic is a multiple-valued logic system in which there are three truth values; for this kata they will be True, False and Unknown. In this kata, T stands for True, F stands for False and U stands for Unknown. They are also represented as 1, -1 and 0 respectively.

This is the basic truth table:

*---+---+-------+---------+--------+---------*
| P | Q | not P | P and Q | P or Q | P xor Q |
| T | T |   F   |    T    |   T    |    F    |
| T | U |   F   |    U    |   T    |    U    |
| T | F |   F   |    F    |   T    |    T    |
| U | T |   U   |    U    |   T    |    U    |
| U | U |   U   |    U    |   U    |    U    |
| U | F |   U   |    F    |   U    |    U    |
| F | T |   T   |    F    |   T    |    T    |
| F | U |   T   |    F    |   U    |    U    |
| F | F |   T   |    F    |   F    |    F    |
*---+---+-------+---------+--------+---------*
Commutativity holds in this three-valued logic.

For example:

T and U  is equal to  U and T.

In general:
p and q  is equal to  q and p.
Moreover, for identical operators, associativity holds in this three-valued logic.

For example:

(U or T) or F  is equal to  U or (T or F).

((T xor F) xor U) xor T  is equal to
  (T xor (F xor U)) xor T,
  T xor ((F xor U) xor T), 
  T xor (F xor (U xor T)),
  (T xor F) xor (U xor T).
Note that the law of the excluded middle and the law of non-contradiction do not hold in this three-valued logic.

For example:

U and not U  is not equal to  F.
not U or U  is not equal to  T.
Read more about three-valued logic on Wikipedia.

Task
Write a function threevl that accepts an expression ( as a string ) and returns its value ( as 1, 0, or -1 ).

For example:

"not T or U"             ->  0
"not (T or U)"           -> -1
"U and not U"            ->  0
"not (F and (U xor T))"  ->  1

Notes
Always evaluate expressions inside brackets first.
This kata only uses 4 operators not, and, xor, or.
Their priorities, from highest to lowest, are: not, and, xor, or. Hence, not T or F xor U should equal (not T) or (F xor U).
Input
0 <= the number of operators < 59
There will be no invalid inputs.
There are 300 random tests. Good luck and happy coding!

*/

%{

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	const char *p;
	int r;
	int e;
} Line;

enum {
	F = -1,
	U = 0,
	T = 1,
	I = 2,
};

%}

%define api.pure full
%locations
%param { Line *ln };

%code
{
	int yylex(YYSTYPE *, YYLTYPE *, Line *);
	void yyerror(YYLTYPE *, Line *, const char *);
	int tnot(int);
	int tor(int, int);
	int tand(int, int);
	int txor(int, int);
}

%union
{
	int v;
}

%left LOR LXOR LAND LNOT

%type <v> expr
%token <v> LVAL LNOT LOR LAND LXOR

%%
top:
	expr
	{
		ln->r = $1;
	}

expr:
	LVAL
	{
		$$ = $1;
	}
|
	LNOT expr
	{
		$$ = tnot($2);
	}
|
	expr LOR expr
	{
		$$ = tor($1, $3);
	}
|
	expr LAND expr
	{
		$$ = tand($1, $3);
	}
|
	expr LXOR expr
	{
		$$ = txor($1, $3);
	}
|
	'(' expr ')'
	{
		$$ = $2;
	}
%%

int
tnot(int x)
{
	if (x == T)
		return F;
	if (x == F)
		return T;
	if (x == U)
		return U;
	return I;
}

int
ti(int x)
{
	if (x == F)
		return 0;
	if (x == U)
		return 1;
	if (x == T)
		return 2;
	return -1;
}

int
tlut(const int tab[3][3], int x, int y)
{
	x = ti(x);
	y = ti(y);
	if (x < 0 || y < 0)
		return I;
	return tab[x][y];
}

int
tor(int x, int y)
{
	static const int tab[3][3] = {
		{F, U, T},
		{U, U, T},
		{T, T, T},
	};
	return tlut(tab, x, y);
}

int
tand(int x, int y)
{
	static const int tab[3][3] = {
		{F, F, F},
		{F, U, U},
		{F, U, T},
	};
	return tlut(tab, x, y);
}

int
txor(int x, int y)
{
	static const int tab[3][3] = {
		{F, U, T},
		{U, U, U},
		{T, U, F},
	};
	return tlut(tab, x, y);
}

int
yylex(YYSTYPE *lv, YYLTYPE *ll, Line *ln)
{
	static const struct Op {
		const char *name;
		size_t len;
		int type;
	} optab[] = {
		{"not", 3, LNOT},
		{"or", 2, LOR},
		{"and", 3, LAND},
		{"xor", 3, LXOR},
	};

	const struct Op *op;
	size_t i;
	int t;

	while (isspace(ln->p[0]))
		ln->p++;

	for (i = 0; i < nelem(optab); i++) {
		op = optab + i;
		if (!strncmp(ln->p, op->name, op->len)) {
			ln->p += op->len;
			return op->type;
		}
	}

	t = LVAL;
	switch (ln->p[0]) {
	case '\0':
	case '(':
	case ')':
		t = ln->p[0];
		break;
	
	case 'T':
		lv->v = T;
		break;
	case 'U':
		lv->v = U;
		break;
	case 'F':
		lv->v = F;
		break;
	
	default:
		yyerror(ll, ln, "invalid input");
		break;
	}
	ln->p++;

	return t;
}

void
yyerror(YYLTYPE *ll, Line *ln, const char *msg)
{
	ln->e = 1;

	(void) ll;
	(void) msg;
}

int
threevl(const char *s)
{
	Line ln = { s, 0, 0 };
	if (yyparse(&ln) || ln.e)
		return I;
	return ln.r;
}

int
main()
{
	assert(threevl("not T or U") == 0);
	assert(threevl("not (T or U)") == -1);
	assert(threevl("U and not U") == 0);
	assert(threevl("not (F and (U xor T))") == 1);

	return 0;
}
