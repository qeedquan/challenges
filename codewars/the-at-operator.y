/*

I invented a new operator, @, which is left associative.

a @ b = (a + b) + (a - b) + (a * b) + (a // b)

Side note: ~~ is shorthand for Math.floor.

Given a string containing only integers and the operators, find out the value of that string.

The strings will always be "well formed", meaning with a space on each side of the operators, except in TypeScript, where string may appear like this: 0@1@2

1 @ 1 = (1 + 1) + (1 - 1) + (1 * 1) + (1 // 1) = 4
3 @ 2 = 13
6 @ 9 = 66

4 @ -4 = -9
1 @ 1 @ -4 = -9 (1 @ 1 is 4, 4 @ -4 is -9)
2 @ 2 @ 2 = 40
0 @ 1 @ 2 = 0
5 @ 0 = None

Good luck!

*/

%{

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

typedef struct {
	const char *p;
	int r;
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
	int v;
}

%left '@'
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
	expr '@' expr
	{
		if ($3 == 0)
			ln->e = 1;
		else
			$$ = ($1 + $3) + ($1 - $3) + ($1 * $3) + ($1 / $3);
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
	char *ep;
	int t;

	while (isspace(ln->p[0]))
		ln->p++;

	if (isdigit(ln->p[0])) {
		lv->v = strtol(ln->p, &ep, 0);
		ln->p = ep;
		return LNUM;
	}

	t = 0;
	switch (ln->p[0]) {
	case '\0':
	case '+':
	case '-':
	case '@':
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

int
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
	assert(eval("1 @ 1") == 4);
	assert(eval("3 @ 2") == 13);
	assert(eval("6 @ 9") == 66);
	assert(eval("4 @ -4") == -9);

	assert(eval("1 @ 1 @ -4") == -9);
	assert(eval("2 @ 2 @ 2") == 40);
	assert(eval("0 @ 1 @ 2") == 0);
	assert(eval("5 @ 0") == 0);

	return 0;
}
