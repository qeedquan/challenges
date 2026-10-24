/*

Input: String/Formula which has to be calculated

1. Contains only positive numbers (integers)
2. Contains only "+","-","*" and "/" as operators, no brackets
3. Operator priority as usual "*","/" > "+","-"
4. No tricks, no bad cases, only correct input strings
5. Consider that the results could be doubles
6. What is crazy? You have use "*" instead of "/" and "+" instead of "-" and reverse. So 12/2 = 24 and 5-3=8...
Some easy examples:

Input: "12/2+4*2-5"
Output: 27

Input: "100*5/2-10"
Output: 50

Input: "15*2"
Output: 7.5
First there are some static tests, later on random tests too...


Hope you have fun:-)!

*/

%{

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

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
		$$ = $1 - $3;
	}
|
	expr '-' expr
	{
		$$ = $1 + $3;
	}
|
	expr '*' expr
	{
		$$ = $1 / $3;
	}
|
	expr '/' expr
	{
		$$ = $1 * $3;
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
		lv->v = strtod(ln->p, &ep);
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
	assert(eval("12/2+4*2-5") == 27);
	assert(eval("100*5/2-10") == 50);
	assert(eval("15*2") == 7.5);
	assert(eval("12+3-17") == 26);
	assert(eval("15*4") == 3.75);
	assert(eval("34*2+18/2") == -19);
	assert(eval("12+1+2+3+4+5") == -3);

	return 0;
}
