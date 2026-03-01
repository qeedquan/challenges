/*

Inspiration.
https://chat.stackexchange.com/transcript/message/39052298#39052298

Inverse.
https://codegolf.stackexchange.com/questions/84162/convert-an-expression-to-panfix-notation

Evaluate a given omnifix expression.

Omnifix is like normal mathematics' infix notation, but with additional copies of each symbol surrounding the arguments. The outer symbols take the place of parentheses, and there is therefore no need for additional parentheses.

You must support addition, subtraction, multiplication, division, and positive real numbers (negative ones can be written -0-n-) within a reasonable range for your language.

Plus and minus must be + and -, but you may use * or × for times and / or ÷ for divide. Other reasonable symbols will be allowed upon request.

Brownie points for explanation and additional features (like additional operations, negative numbers, strings, etc.) Even if your answer does not have these features, feel free to show how it could.

Please provide a link to test your solution if at all possible.

Examples
For clarity, the explanations below use high minus (¯) to indicate negative numbers. You may return negative numbers using any reasonable format.

-5-2- → 3

+2+×3×2×+ → 8 (+2+×3×2×+ → +2+6+ → 8)

-14--3-1-- → 12 (-4--3-1-- → -14-2- → 12)

+2.1+×3.5×2.2×+ → 9.8 (+2.1+×3.5×2.2×+ → +2.1+7.7+ → 9.8)

×3×÷-0-6-÷2÷× → -9 (×3×÷-0-6-÷2÷× → ×3×÷¯6÷2÷× → ×3×¯3× → ¯9)

÷4÷-3-÷1÷2÷-÷ → 1.6 (÷4÷-3-÷1÷2÷-÷ → ÷4÷-3-0.5-÷ → ÷4÷2.5÷ → 1.6)

*/

%{

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

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

%left '+' '-' '*' '/'

%type <v> expr val
%token <v> LNUM

%%
top:
	expr
	{
		ln->r = $1;
	}

expr:
	'_' val
	{
		$$ = -$2;
	}
|
	val
	{
		$$ = $1;
	}
|
	'+' expr '+' expr '+'
	{
		$$ = $2 + $4;
	}
|
	'-' expr '-' expr '-'
	{
		$$ = $2 - $4;
	}
|
	'*' expr '*' expr '*'
	{
		$$ = $2 * $4;
	}
|
	'/' expr '/' expr '/'
	{
		$$ = $2 / $4;
	}

val: LNUM

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
	case '_':
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
	(void) ln;
	(void) msg;
}

double
eval(const char *s)
{
	Line ln = { s, 0, 0 };
	if (yyparse(&ln) || ln.e)
		return -1;
	return ln.r;
}

void
test(const char *s, double r)
{
	double v;
	
	v = eval(s);
	printf("'%s' -> %f\n", s, v);
	assert(fabs(v - r) < 1e-6);
}

int
main(void)
{
	test("-5-2-", 3);
	test("+2+*3*2*+", 8);
	test("-14--3-1--", 12);
	test("+2.1+*3.5*2.2*+", 9.8);
	test("*3*/-0-6-/2/*", -9);
	test("/4/-3-/1/2/-/", 1.6);

	return 0;
}
