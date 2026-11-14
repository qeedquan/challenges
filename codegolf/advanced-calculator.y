/*

You must write a program that evaluates a string that would be entered into an advanced calculator.

The program must accept input using stdin and output the correct answer. For languages that do no have functions to accept stdin, you may assume the functions readLine and print to handle these tasks.

Requirements:

Does not use any kind of "eval" functions
Can handle floating point and negative numbers
Supports at least the +, -, *, /, and ^ operators
Supports brackets and parenthesis for overriding the normal order
Can handle input containing one or more spaces between the operators and numbers
Evaluates the input using the standard order of operations

Test Cases
Input
10 - 3 + 2
Output
9

Input
8 + 6 / 3 - 7 + -5 / 2.5
Output
1

Input
4 + [ ( -3 + 5 ) * 3.5 ] ^ 2 - 12
Output
41

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
%right '^'
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
		$$ = $1 / $3;
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
	'[' expr ']'
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
	case '^':
	case '(':
	case ')':
	case '[':
	case ']':
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
	assert(eval("10 - 3 + 2") == 9);
	assert(eval("8 + 6 / 3 - 7 + -5 / 2.5") == 1);
	assert(eval("4 + [ ( -3 + 5 ) * 3.5 ] ^ 2 - 12") == 41);

	return 0;
}
