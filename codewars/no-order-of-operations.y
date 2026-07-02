/*

Imagine if there were no order of operations. Instead, you would do the problem from left to right. For example, the equation
a+b*c/d would become (((a+b)∗c)//d) (Math.floor(((a+b)*c)/d) in JS). Return None/null (depending on your language) if the equation is "".

Task:
Given an equation with a random amount of spaces greater than or equal to zero between each number and operation, return the result without order of operations.
Note that if two numbers are spaces apart, act as if they were one number: 1   3 = 13. However, if given something % 0 or something / 0, return None/null.

More about order of operations: here

Key:
^ represents **
/ represents // or math.floor because the result will always be an integer
Operations allowed:
+, -, * , /, ^, %

Example:
no_order(2 + 3 - 4 * 1 ^ 3) returns 1

because:

  2 + 3 - 4 * 1 ^ 3
= 2 + 3 - 4 * 1 ^ 3
= 5 - 4 * 1 ^ 3
= 1 * 1 ^ 3
= 1 ^ 3
= 1

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

%left '+' '-' '*' '/' '%' '^'
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
		$$ = ($3) ? $1 / $3 : 0;
	}
|
	expr '%' expr
	{
		$$ = ($3) ? $1 % $3 : 0;
	}
|
	expr '^' expr
	{
		$$ = pow($1, $3);
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
getnum(Line *ln)
{
	int r;

	r = 0;
	while (isdigit(ln->p[0]) || isspace(ln->p[0])) {
		if (isdigit(ln->p[0]))
			r = (r * 10) + (ln->p[0] - '0');
		ln->p++;
	}
	return r;
}

int
yylex(YYSTYPE *lv, YYLTYPE *ll, Line *ln)
{
	int t;

	while (isspace(ln->p[0]))
		ln->p++;

	if (isdigit(ln->p[0])) {
		lv->v = getnum(ln);
		return LNUM;
	}

	t = 0;
	switch (ln->p[0]) {
	case '\0':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case '^':
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
	assert(eval("2 + 3 - 4 * 1 ^ 3") == 1);
	assert(eval("1 3") == 13);

	return 0;
}
