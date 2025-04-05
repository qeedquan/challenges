/*

You are provided with a function of the form f(x) = axⁿ, that consists of a single term only and 'a' and 'n' are integers, e.g f(x) = 3x², f(x) = 5 etc.

Your task is to create a function that takes f(x) as the argument and returns the result of differentiating the function, that is, the derivative.

If f(x) = ax^n, then f′(x)=nax^(n−1)
 

Input is a string, for example "5x^4". The function f(x) consists of a single term only. Variable is denoted by x.
Output should be a string, for example "20x^3".

Examples

"3x^2"  => "6x"
"-5x^3" => "-15x^2"
"6x^-2" => "-12x^-3"
"5x"    => "5"
"-x"    => "-1"
"42"    => "0"

*/

%{

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
	const char *p;
	char *b;
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

%type <v> expr
%token <v> LNUM

%%
top:
	expr

expr:
	LNUM
	{
		sprintf(ln->b, "0");
	}
|
	LNUM 'x'
	{
		sprintf(ln->b, "%ld", $1);
	}
|
	LNUM 'x' '^' LNUM
	{
		if ($4 == 2)
			sprintf(ln->b, "%ldx", $1 * $4);
		else if ($4 == 1)
			sprintf(ln->b, "%ld", $1);
		else
			sprintf(ln->b, "%ldx^%ld", $1 * $4, $4 - 1);
	}
|
	'+' 'x'
	{
		sprintf(ln->b, "1");
	}
|
	'-' 'x'
	{
		sprintf(ln->b, "-1");
	}
|
	'x'
	{
		sprintf(ln->b, "1");
	}
%%

int
yylex(YYSTYPE *lv, YYLTYPE *ll, Line *ln)
{
	char *ep;
	int t;

	while (isspace(ln->p[0]))
		ln->p++;

	if (((ln->p[0] == '+' || ln->p[0] == '-') && isdigit(ln->p[1])) || isdigit(ln->p[0])) {
		lv->v = strtol(ln->p, &ep, 10);
		ln->p = ep;
		return LNUM;
	}

	t = 0;
	switch (ln->p[0]) {
	case '\0':
	case 'x':
	case '^':
	case '+':
	case '-':
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

char *
diff(const char *s, char *b)
{
	Line ln = { s, b, 0 };
	if (yyparse(&ln) || ln.e)
		return NULL;
	return ln.b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	assert(diff(s, b));
	printf("'%s' -> '%s'\n", s, b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("3x^2", "6x");
	test("-5x^3", "-15x^2");
	test("6x^-2", "-12x^-3");
	test("5x", "5");
	test("-x", "-1");
	test("42", "0");

	return 0;
}
