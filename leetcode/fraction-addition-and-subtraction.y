/*

Given a string expression representing an expression of fraction addition and subtraction, return the calculation result in string format.

The final result should be an irreducible fraction. If your final result is an integer, change it to the format of a fraction that has a denominator 1. So in this case, 2 should be converted to 2/1.

Example 1:

Input: expression = "-1/2+1/2"
Output: "0/1"
Example 2:

Input: expression = "-1/2+1/2+1/3"
Output: "1/3"
Example 3:

Input: expression = "1/3-1/2"
Output: "-1/6"

Constraints:

The input string only contains '0' to '9', '/', '+' and '-'. So does the output.
Each fraction (input and output) has the format ±numerator/denominator. If the first input fraction or the output is positive, then '+' will be omitted.
The input only contains valid irreducible fractions, where the numerator and denominator of each fraction will always be in the range [1, 10]. If the denominator is 1, it means this fraction is actually an integer in a fraction format defined above.
The number of given fractions will be in the range [1, 10].
The numerator and denominator of the final result are guaranteed to be valid and in the range of 32-bit int.

*/

%{

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
	long n, d;
} Rat;

typedef struct {
	const char *p;
	Rat r;
	int e;
} Line;

Rat ratnew(long, long);
Rat ratadd(Rat, Rat);
Rat ratsub(Rat, Rat);

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
	Rat r;
	long v;
}

%left '+' '-'

%type <r> expr
%token <v> LNUM

%%
top:
	expr
	{
		ln->r = $1;
	}

expr:
	LNUM '/' LNUM
	{
		$$ = ratnew($1, $3);
	}
|
	'+' LNUM '/' LNUM
	{
		$$ = ratnew($2, $4);
	}
|
	'-' LNUM '/' LNUM
	{
		$$ = ratnew(-$2, $4);
	}
|
	expr '+' expr
	{
		$$ = ratadd($1, $3);
	}
|
	expr '-' expr
	{
		$$ = ratsub($1, $3);
	}
%%

long
gcd(long a, long b)
{
	long t;

	while (b) {
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}

Rat
ratcanon(Rat r)
{
	long m;

	m = gcd(labs(r.n), labs(r.d));
	r.n /= m;
	r.d /= m;
	return r;
}

Rat
ratnew(long n, long d)
{
	Rat r;

	r.n = n;
	r.d = d;
	return ratcanon(r);
}

Rat
ratadd(Rat a, Rat b)
{
	Rat r;

	r.n = (a.n * b.d) + (b.n * a.d);
	r.d = a.d * b.d;
	return ratcanon(r);
}

Rat
ratsub(Rat a, Rat b)
{
	Rat r;

	r.n = (a.n * b.d) - (b.n * a.d);
	r.d = a.d * b.d;
	return ratcanon(r);
}

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
	case '-':
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

Rat
eval(const char *s)
{
	Line ln;

	memset(&ln, 0, sizeof(ln));
	ln.p = s;
	if (yyparse(&ln) || ln.e)
		memset(&ln.r, 0, sizeof(ln.r));
	return ln.r;
}

void
test(const char *s, const char *r)
{
	char b[128];
	Rat x;

	x = eval(s);
	snprintf(b, sizeof(b), "%ld/%ld", x.n, x.d);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("-1/2+1/2", "0/1");
	test("-1/2+1/2+1/3", "1/3");
	test("1/3-1/2", "-1/6");
	test("10/5", "2/1");
	test("-100/5+-100/10-200/10", "-50/1");

	return 0;
}
