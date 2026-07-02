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
%left '*'

%type <v> expression component factor
%token <v> LNUM

%%
top:
	expression
	{
		ln->r = $1;
	}

expression:
	component
	{
		$$ = $1;
	}
|
	component '+' expression
	{
		$$ = $1 + $3;
	}

component:
	factor
	{
		$$ = $1;
	}
|
	factor '*' component
	{
		$$ = $1 * $3;
	}

factor:
	LNUM
	{
		$$ = $1;
	}
|
	'(' expression ')'
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
		lv->v = strtol(ln->p, &ep, 10);
		ln->p = ep;
		return LNUM;
	}

	t = 0;
	switch (ln->p[0]) {
	case '\0':
	case '+':
	case '*':
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
yyerror(YYLTYPE *, Line *ln, const char *)
{
	ln->e = 1;
}

long
eval(const char *s)
{
	Line ln = { s, 0, 0 };
	if (yyparse(&ln) || ln.e)
		return -1;
	return ln.r;
}

int
main()
{
	printf("%ld\n", eval("32"));
	printf("%ld\n", eval("12+34"));
	printf("%ld\n", eval("1*(2+3)+3"));
	printf("%ld\n", eval("1(2+3)+3"));
	printf("%ld\n", eval("qwe323"));

	return 0;
}
