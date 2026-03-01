/*

Scheme Reference ( https://www.scheme.com/tspl4/start.html#./start:h2 )

Your challenge: create a function that interprets simple scheme-like math commands and returns the value resulting from the operation. We will only be working with the four main math operators (+ - * /). The main difference between these commands and actual scheme commands is that scheme commands only accept two arguments while these commands accept infinitely many arguments so as to avoid having to nest functions with like operators.

Input: string, such as '(+ 4 3)'
Output: number
Constraints: 0-15 arguments, numbers from -15 to 15 (when dividing, those will never be 0)
Edge Cases: don't forget that no arguments results in either 0 or 1 for +/- and * respectively

Syntax consists of an open parenthesis, a math operator, a space, space-separated arguments, and a close parenthesis. Example: (+ 3 4). All inputs will be valid.

If no arguments are provided, return the following (You won't get '(/)'):

'(+)'         // 0
'(-)'         // 0
'(*)'         // 1

Examples of valid commands:

'(+ 3 4)'     // 7
'(- 3 4)'     // -1
'(* 3 4)'     // 12
'(/ 3 4)'     // 0.75
'(+ 4 4 -4)'  // 4

*/

%{

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

typedef struct {
	const char *p;
	double r;
	double v[4];
	int f;
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

%type <v> expr
%token <v> LNUM

%%
top:
	expr
	{
		ln->r = $1;
	}

expr:
	'(' '+' nums ')'
	{
		$$ = ln->v[0];
	}
|
	'(' '-' nums ')'
	{
		$$ = ln->v[1];
	}
|
	'(' '*' nums ')'
	{
		$$ = ln->v[2];
	}
|
	'(' '/' nums ')'
	{
		$$ = ln->v[3];
	}

nums:
|
	nums LNUM
	{
		if (!ln->f) {
			ln->v[0] = $2;
			ln->v[1] = $2;
			ln->v[2] = $2;
			ln->v[3] = $2;
			ln->f = 1;
		} else {
			ln->v[0] += $2;
			ln->v[1] -= $2;
			ln->v[2] *= $2;
			ln->v[3] /= $2;
		}
	}

%%

int
yylex(YYSTYPE *lv, YYLTYPE *ll, Line *ln)
{
	char *ep;
	int t;

	while (isspace(ln->p[0]))
		ln->p++;
	
	if (isdigit(ln->p[0]) || ((ln->p[0] == '+' || ln->p[0] == '-') && isdigit(ln->p[1]))) {
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

double
eval(const char *s)
{
	Line ln = {
		.p = s,
		.v = {0, 0, 1, 0},
	};
	
	if (yyparse(&ln) || ln.e)
		return NAN;
	return ln.r;
}

int
main(void)
{
	printf("%f\n", eval("(+)"));
	printf("%f\n", eval("(-)"));
	printf("%f\n", eval("(*)"));
	printf("%f\n", eval("(+ 3 4)"));
	printf("%f\n", eval("(- 3 4)"));
	printf("%f\n", eval("(* 3 4)"));
	printf("%f\n", eval("(/ 3 4)"));
	printf("%f\n", eval("(+ 4 4 -4)"));

	return 0;
}
