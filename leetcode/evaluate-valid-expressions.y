/*

You are given a string expression that represents a nested mathematical expression in a simplified form.

A valid expression is either an integer literal or follows the format op(a,b), where:

op is one of "add", "sub", "mul", or "div".
a and b are each valid expressions.
The operations are defined as follows:

add(a,b) = a + b
sub(a,b) = a - b
mul(a,b) = a * b
div(a,b) = a / b
Return an integer representing the result after fully evaluating the expression.

Example 1:

Input: expression = "add(2,3)"

Output: 5

Explanation:

The operation add(2,3) means 2 + 3 = 5.

Example 2:

Input: expression = "-42"

Output: -42

Explanation:

The expression is a single integer literal, so the result is -42.

Example 3:

Input: expression = "div(mul(4,sub(9,5)),add(1,1))"

Output: 8

Explanation:

First, evaluate the inner expression: sub(9,5) = 9 - 5 = 4
Next, multiply the results: mul(4,4) = 4 * 4 = 16
Then, compute the addition on the right: add(1,1) = 1 + 1 = 2
Finally, divide the two main results: div(16,2) = 16 / 2 = 8
Therefore, the entire expression evaluates to 8.


Constraints:

1 <= expression.length <= 10^5
expression is valid and consists of digits, commas, parentheses, the minus sign '-', and the lowercase strings "add", "sub", "mul", "div".
All intermediate results fit within the range of a long integer.
All divisions result in integer values.

*/

%{

#include <assert.h>
#include <stdio.h>
#include <string.h>
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

%type <v> expr
%token <v> LADD LSUB LMUL LDIV
%token <v> LNUM
%precedence UMINUS

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
	LADD '(' expr ',' expr ')'
	{
		$$ = $3 + $5;
	}
|
	LSUB '(' expr ',' expr ')'
	{
		$$ = $3 - $5;
	}
|
	LMUL '(' expr ',' expr ')'
	{
		$$ = $3 * $5;
	}
|
	LDIV '(' expr ',' expr ')'
	{
		$$ = 0;
		if ($5 != 0)
			$$ = $3 / $5;
	}
|
	'-' expr %prec UMINUS
	{
		$$ = -$2;
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

	if (!strncmp(ln->p, "add", 3)) {
		ln->p += 3;
		return LADD;
	} else if (!strncmp(ln->p, "sub", 3)) {
		ln->p += 3;
		return LSUB;
	} else if (!strncmp(ln->p, "mul", 3)) {
		ln->p += 3;
		return LMUL;
	} else if (!strncmp(ln->p, "div", 3)) {
		ln->p += 3;
		return LDIV;
	}

	t = 0;
	switch (ln->p[0]) {
	case '\0':
	case '-':
	case ',':
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
	assert(eval("add(2, 3)") == 5);
	assert(eval("-42") == -42);
	assert(eval("div(mul(4,sub(9,5)),add(1,1))") == 8);

	return 0;
}
