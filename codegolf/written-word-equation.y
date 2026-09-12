/*

Word equations, but not as you know it! Given a sentence which will include two numbers, numerically, and a spelt operator, in the order seen in the examples, your goal is to give the numerical answer

The operators will be spelt as: "add", "minus", "times" and "divide"

Any real number integer may be used, as suggested by caird and Jonathan

The solution must take one input and give one output

Examples:

Input: 7 add 8         Output: 15
Input: 9 times -2      Output: -18
Input: 24 divide 2     Output: 12
Input: 4 minus 5       Output: -1
You are not required to deal with divide by zero errors.

If you use a method that parses the expression, such as the python eval or exec, there will be no penalties, but if possible try to give a another interesting solution

Scoring:

Fewest bytes will win

*/

%{

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	const char *p;
	long r;
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
	long v;
}

%left '+' '-'
%left '*' '/'
%precedence UPLUS UMINUS

%type <v> expr
%token <v> LNUM

%%
top:
	expr
	{
		ln->r = $1;
	}

expr:
	LNUM
	{
		$$ = $1;
	}
|
	expr '+' expr
	{
		$$ = $1 + $3;
	}
|
	expr '-' expr
	{
		$$ = $1 - $3;
	}
|
	expr '*' expr
	{
		$$ = $1 * $3;
	}
|
	expr '/' expr
	{
		$$ = 0;
		if ($3 != 0)
			$$ = $1 / $3;
	}
|
	'(' expr ')'
	{
		$$ = $2;
	}
|
	'-' expr %prec UMINUS
	{
		$$ = -$2;
	}
|
	'+' expr %prec UPLUS
	{
		$$ = $2;
	}
%%

int
yylex(YYSTYPE *lv, YYLTYPE *ll, Line *ln)
{
	static const char *ops[] = { "add", "minus", "times", "divide" };
	static const size_t oplen[] = { 3, 5, 5, 6 };
	static const char sym[] = "+-*/";

	char *ep;
	int t;
	size_t i;

	while (isspace(ln->p[0]))
		ln->p++;

	if (isdigit(ln->p[0])) {
		lv->v = strtol(ln->p, &ep, 10);
		ln->p = ep;
		return LNUM;
	}

	for (i = 0; i < nelem(ops); i++) {
		if (!strncmp(ln->p, ops[i], oplen[i])) {
			ln->p += oplen[i];
			return sym[i];
		}
	}

	t = 0;
	switch (ln->p[0]) {
	case '\0':
	case '-':
	case '(':
	case ')':
		t = ln->p[0];
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

long
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
	assert(eval("7 add 8") == 15);
	assert(eval("9 times -2") == -18);
	assert(eval("24 divide 2") == 12);
	assert(eval("4 minus 5") == -1);

	return 0;
}
