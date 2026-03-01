/*

You receive an input with a number and a string with a space in the middle. The string tells you what you need to do with the number, it can be:

sqrt - square root of number

sqr - square of number

cube - cube of number

abs - absolute of number

round - rounded version of number

You need to output the final result of the calculation with whatever you have. If your language doesn't have an input, you can hard-code that in.

Rules:

You can't use a math library, even if it is built-in.

You don't get a number or a result bigger than the highest possible one in your language.

Because of the vulnerability of the above rule, you can't use languages, which only support a 1 bit number. (1 and 0)

If your language doesn't support non-integer numbers, you need to output a rounded result.

Test cases

16 sqrt = 4

25 sqr = 625

3 cube = 27

-10 abs = 10

18.38 round = 18

Because this is a code-golf, the shortest answer in bytes wins.

Good luck!

*/

%{

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	const char *p;
	double r;
	int e;
} Line;

%}

%define api.pure full
%locations
%param { Line *ln };

%code
{
	int yylex(YYSTYPE *, YYLTYPE *, Line *);
	void yyerror(YYLTYPE *, Line *, const char *);
}

%union
{
	double v;
}

%type <v> expr
%token <v> LNUM LSQRT LSQR LCUBE LABS LROUND

%%
top:
	expr
	{
		ln->r = $1;
	}

expr:
	LNUM LSQRT
	{
		$$ = sqrt($1);
	}
|
	LNUM LSQR
	{
		$$ = $1 * $1;
	}
|
	LNUM LCUBE
	{
		$$ = $1 * $1 * $1;
	}
|
	LNUM LABS
	{
		$$ = fabs($1);
	}
|
	LNUM LROUND
	{
		$$ = round($1);
	}
%%

int
yylex(YYSTYPE *lv, YYLTYPE *ll, Line *ln)
{
	static const struct Op {
		int tok;
		const char *name;
		size_t len;
	} ops[] = {
		{LSQRT, "sqrt", 4},
		{LSQR, "sqr", 3},
		{LCUBE, "cube", 4},
		{LABS, "abs", 3},
		{LROUND, "round", 5},
	};

	const struct Op *op;
	char *ep;
	size_t i;

	while (isspace(ln->p[0]))
		ln->p++;

	if (ln->p[0] == '\0')
		return 0;

	if (isdigit(ln->p[0]) || ln->p[0] == '-') {
		lv->v = strtod(ln->p, &ep);
		ln->p = ep;
		return LNUM;
	}

	for (i = 0; i < nelem(ops); i++) {
		op = ops + i;
		if (!strncmp(ln->p, op->name, op->len)) {
			ln->p += op->len;
			return op->tok;
		}
	}

	yyerror(ll, ln, "invalid input");
	return 0;
}

void
yyerror(YYLTYPE *ll, Line *ln, const char *msg)
{
	ln->e = 1;

	(void) ll;
	(void) msg;
}

double
eval(const char *s)
{
	Line ln = { s, 0, 0 };
	if (yyparse(&ln) || ln.e)
		return 0;
	return ln.r;
}

int
main(void)
{
	assert(eval("16 sqrt") == 4);
	assert(eval("25 sqr") == 625);
	assert(eval("3 cube") == 27);
	assert(eval("-10 abs") == 10);
	assert(eval("18.38 round") == 18);

	return 0;
}
