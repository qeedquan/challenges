/*

A little while back we had a programming challenge to convert an infix expression (also known as "normal" math) to a postfix expression (also known as Reverse Polish Notation). Today we'll do something a little different: We will write a calculator that takes RPN input, and outputs the result.

Formal input
The input will be a whitespace-delimited RPN expression. The supported operators will be:

+ - addition

- - subtraction

*, x - multiplication

/ - division (floating point, e.g. 3/2=1.5, not 3/2=1)

// - integer division (e.g. 3/2=1)

% - modulus, or "remainder" division (e.g. 14%3=2 and 21%7=0)

^ - power

! - factorial (unary operator)

Sample input:

0.5 1 2 ! * 2 1 ^ + 10 + *
Formal output
The output is a single number: the result of the calculation. The output should also indicate if the input is not a valid RPN expression.

Sample output:

7
Explanation: the sample input translates to 0.5 * ((1 * 2!) + (2 ^ 1) + 10), which comes out to 7.

Challenge 1
Input: 1 2 3 4 ! + - / 100 *

Output: -4

Challenge 2
Input: 100 807 3 331 * + 2 2 1 + 2 + * 5 ^ * 23 10 558 * 10 * + + *

Finally...
Hope you enjoyed today's challenge! Have a fun problem or challenge of your own? Drop by r/dailyprogrammer_ideas and share it with everyone!

*/

%{

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <float.h>

typedef long long vlong;

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
%left '*' 'x' '/' LIDIV '%'
%right '^'

%type <v> expr
%token <v> LNUM LIDIV

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
	expr '!'
	{
		$$ = tgamma($1 + 1);
	}
|
	expr expr '+'
	{
		$$ = $1 + $2;
	}
|
	expr expr '-'
	{
		$$ = $1 - $2;
	}
|
	expr expr '*'
	{
		$$ = $1 * $2;
	}
|
	expr expr 'x'
	{
		$$ = $1 * $2;
	}
|
	expr expr '/'
	{
		$$ = $1 / $2;
	}
|
	expr expr LIDIV
	{
		vlong a, b;

		$$ = 0;
		a = $1;
		b = $2;
		if (b != 0)
			$$ = a / b;
	}
|
	expr expr '%'
	{
		vlong a, b;

		$$ = 0;
		a = $1;
		b = $2;
		if (b != 0)
			$$ = a % b;
	}
|
	expr expr '^'
	{
		$$ = pow($1, $2);
	}
%%

int
yylex(YYSTYPE *lv, YYLTYPE *ll, Line *ln)
{
	char *ep;
	int t;

	while (isspace(ln->p[0]))
		ln->p++;

	if (isdigit(ln->p[0]) || (ln->p[0] == '-' && isdigit(ln->p[1])) || ln->p[0] == '.') {
		lv->v = strtod(ln->p, &ep);
		ln->p = ep;
		return LNUM;
	}

	t = 0;
	switch (ln->p[0]) {
	case '\0':
	case '!':
	case '+':
	case '-':
	case '*':
	case 'x':
	case '%':
	case '^':
		t = ln->p[0];
		break;
	
	case '/':
		t = ln->p[0];
		if (ln->p[1] == '/') {
			t = LIDIV;
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
		return NAN;
	return ln.r;
}

int
main(void)
{
	printf("%f\n", eval("0.5 1 2 ! * 2 1 ^ + 10 + *"));
	printf("%f\n", eval("1 2 3 4 ! + - / 100 *"));
	printf("%f\n", eval("100 807 3 331 * + 2 2 1 + 2 + * 5 ^ * 23 10 558 * 10 * + + *"));
	printf("%f\n", eval("3 5 %"));
	printf("%f\n", eval("3 19 4 // +"));
	printf("%f\n", eval("5 ! 10 ! +"));

	return 0;
}
