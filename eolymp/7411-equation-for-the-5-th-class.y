/*

The equation for the fifth grader is a line of length 5 symbols.
The second symbol in the line is either a sign '+' (plus) or '-' (minus), the fourth symbol is a sign '=' (equals to).
Among the first, third and fifth symbols exactly two are digits in the range from 0 to 9, and one is a letter x that is a variable.

Write a program to solve the given equation with respect to x.

Input
One line with the given equation.

Output
Print one number - the value of x.

Examples

Input #1
x+5=7

Answer #1
2

Input #2
3-x=9

Answer #2
-6

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
%precedence UPLUS UMINUS

%type <v> expr
%token <v> LNUM LVAR

%%
top:
	expr
	{
		ln->r = $1;
	}

expr:
	LNUM '+' LVAR '=' LNUM
	{
		$$ = $5 - $1;
	}
|
	LNUM '-' LVAR '=' LNUM
	{
		$$ = $1 - $5;
	}
|
	LVAR '+' LNUM '=' LNUM
	{
		$$ = $5 - $3;
	}
|
	LVAR '-' LNUM '=' LNUM
	{
		$$ = $5 + $3;
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
	case '=':
		t = ln->p[0];
		break;

	case 'x':
		t = LVAR;
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
solve(const char *s)
{
	Line ln = { s, 0, 0 };
	if (yyparse(&ln) || ln.e)
		return 0;
	return ln.r;
}

int
main()
{
	assert(solve("x+5=7") == 2);
	assert(solve("3-x=9") == -6);

	return 0;
}
