/*

Given the string "1+2+3", write a function calculate to output the result, ie. 6.

If there is no operator between 2 numbers, there will be a space instead ie. the input is "1+2 3". In this case, process the input as "1+23" and output 24.

The input will always be a string with 3 integers 0-1000, zero or more + operators, and zero or more spaces.

Assume the input will always be valid.

Note: eval and Function have been disabled; if not there would be no point to this exercise.

Examples:

Test.assertEquals(calculate("1+2+3"), 6);
Test.assertEquals(calculate("1+2 3"), 24);
Test.assertEquals(calculate("1 2 3"), 123);

*/

%{

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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

%left '+'
%left ' '

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
	expr ' ' expr
	{
		$$ = ($1 * 10) + $3;
	}

%%

int
yylex(YYSTYPE *lv, YYLTYPE *ll, Line *ln)
{
	char *ep;
	int t;

	if (ln->p[0] == ' ') {
		do {
			ln->p++;
		} while (ln->p[0] == ' ');
		return ' ';
	}

	if (isdigit(ln->p[0])) {
		lv->v = strtol(ln->p, &ep, 10);
		ln->p = ep;
		return LNUM;
	}

	t = 0;
	switch (ln->p[0]) {
	case '\0':
	case '+':
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
yyerror(YYLTYPE *, Line *ln, const char *)
{
	ln->e = 1;
}

long
calculate(const char *s)
{
	Line ln = { s, 0, 0 };
	if (yyparse(&ln) || ln.e)
		return -1;
	return ln.r;
}

int
main()
{
	assert(calculate("1+2+3") == 6);
	assert(calculate("1+2 3") == 24);
	assert(calculate("1 2 3") == 123);

	return 0;
}
