/*

Your task is to create a polish notation calculator.

For those who don't know what is polish notation, it's a mathematical notation where operators are before the operands.

Eg: + 1 2 = 1 + 2

Your calculator should implement integer addition, substraction multiplication and division.

Standard loopholes are forbidden but you are allowed to use a language even if it's newer than the challenge. Using eval is also forbidden.

Test cases:

Input: + 1 2
Output: 3

Input: * + 3 4 2
Output: 14

Input: / * + - 3 2 9 3 2
Output: 15

Since this is code-golf, the answer with the less bytes win !

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

%left '+' '-'
%left '*' '/'

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
	'+' expr expr
	{
		$$ = $2 + $3;
	}
|
	'-' expr expr
	{
		$$ = $2 - $3;
	}
|
	'*' expr expr
	{
		$$ = $2 * $3;
	}
|
	'/' expr expr
	{
		$$ = 0;
		if ($3 != 0)
			$$ = $2 / $3;
	}

%%

int
yylex(YYSTYPE *lv, YYLTYPE *ll, Line *ln)
{
	char *ep;
	int t;

	while (isspace(ln->p[0]))
		ln->p++;

	if (isdigit(ln->p[0]) || (ln->p[0] == '-' && isdigit(ln->p[1]))) {
		lv->v = strtol(ln->p, &ep, 10);
		ln->p = ep;
		return LNUM;
	}

	t = 0;
	switch (ln->p[0]) {
	case '\0':
	case '+':
	case '-':
	case '*':
	case '/':
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
	assert(eval("+ 1 2") == 3);
	assert(eval("* + 3 4 2") == 14);
	assert(eval("/ * + - 3 2 9 3 2") == 15);

	return 0;
}
