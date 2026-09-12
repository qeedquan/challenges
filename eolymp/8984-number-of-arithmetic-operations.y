/*

You are given a string that represents a valid arithmetic expression, which includes numbers, parentheses,
and various arithmetic operators similar to those used in Python:
+ (addition), - (subtraction), * (multiplication), ** (exponentiation), / (division), // (floor division), and % (modulus).
Your task is to determine the total number of arithmetic operations present in the expression.

Input
A string representing an arithmetic expression that includes numbers, parentheses, and arithmetic operators.

Output
An integer representing the count of arithmetic operations in the expression.

Examples

Input #1
9*8+76-54/3+2**10

Answer #1
6

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

%left '+' '-'
%left '*' '/' IDIV
%right POW
%precedence UPLUS UMINUS

<token> LNUM

%%
top:
	expr

expr:
	LNUM
|
	expr '+' expr
	{
		ln->r += 1;
	}
|
	expr '-' expr
	{
		ln->r += 1;
	}
|
	expr '*' expr
	{
		ln->r += 1;
	}
|
	expr '/' expr
	{
		ln->r += 1;
	}
|
	expr IDIV expr
	{
		ln->r += 1;
	}
|
	expr POW expr
	{
		ln->r += 1;
	}
|
	'-' expr %prec UMINUS
|
	'+' expr %prec UPLUS

%%

int
yylex(YYSTYPE *, YYLTYPE *ll, Line *ln)
{
	int t;

	while (isspace(ln->p[0]))
		ln->p++;

	if (isdigit(ln->p[0])) {
		do {
			ln->p++;
		} while (isdigit(ln->p[0]));
		return LNUM;
	}

	t = ln->p[0];
	switch (ln->p[0]) {
	case '\0':
	case '+':
	case '-':
		break;

	case '*':
	case '/':
		if (ln->p[0] == ln->p[1]) {
			t = (ln->p[0] == '*') ? POW : IDIV;
			ln->p++;
		}
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

int
solve(const char *s)
{
	Line ln = { s, 0, 0 };
	if (yyparse(&ln) || ln.e)
		return -1;
	return ln.r;
}

int
main()
{
	assert(solve("9*8+76-54/3+2**10") == 6);

	return 0;
}
