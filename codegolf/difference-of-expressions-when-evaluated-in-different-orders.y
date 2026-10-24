/*

We all know the standard order of operations for math functions (PEMDAS), but what if we instead evaluated expressions left-to-right?

The Challenge
Given a string through standard input or through command line args, find the difference between the traditional evaluation (PEMDAS) and the in-order (left-to-right) evaluation of that expression.

Details
You will be given a string in a format such as:

"1 + 2 * 3 ^ 2 - 11 / 2 + 16"
To simplify things, there will be:

a space between each number and operator
no leading or trailing spaces
no decimal numbers or negative numbers (non-negative integers only)
no operators beyond +(plus), -(minus), *(multiply), /(divide), ^(exponentiation)
no parens to worry about
you may remove the spaces if it's easier for you to handle, but no other modification of the input format will be allowed.
You must provide the absolute value of the difference between the two evaluations of the string

Your division can either be floating-point or integer division - both will be accepted
Your program can not use any sort of expression evaluation library.

To clarify - any sort of built-in eval function in which your language evaluates a string that is valid code for the same language IS acceptable

Explanations of your code are preferred
Shortest code by byte count wins
Winner will be chosen Saturday (July 19, 2014)

Examples:
A: 1 + 2 * 3 ^ 2 - 11 / 2 + 16 (using floating-point division)

In traditional order of operations:

1 + 2 * 3 ^ 2 - 11 / 2 + 16   -->   1 + 2 * 9 - 11 / 2 + 16   -->

1 + 18 - 5.5 + 16             -->   29.5
In-order traversal yields:

1 + 2 * 3 ^ 2 - 11 / 2 + 16   -->   3 * 3 ^ 2 - 11 / 2 + 16   -->

9 ^ 2 - 11 / 2 + 16           -->   81 - 11 / 2 + 16          -->

70 / 2 + 16                   -->   35 + 16                   -->

51

Resulting difference: 51 - 29.5 = 21.5

B: 7 - 1 * 3 ^ 2 + 41 / 3 + 2 * 9 * 2 (using integer division)

In traditional order of operations:

7 - 1 * 3 ^ 2 + 41 / 3 + 2 * 9 * 2   -->   7 - 1 * 9 + 41 / 3 + 2 * 9 * 2   -->

7 - 9 + 13 + 18 * 2                  -->   7 - 9 + 13 + 36                  -->

47

In-order traversal yields:

7 - 1 * 3 ^ 2 + 41 / 3 + 2 * 9 * 2   -->   6 * 3 ^ 2 + 41 / 3 + 2 * 9 * 2   -->

18 ^ 2 + 41 / 3 + 2 * 9 * 2          -->   324 + 41 / 3 + 2 * 9 * 2         -->

365 / 3 + 2 * 9 * 2                  -->   121 + 2 * 9 * 2                  -->

123 * 9 * 2                          -->   1107 * 2                         -->

2214

Resulting difference: 2214 - 47 = 2167

*/

%{

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

typedef struct {
	const char *p;
	double r;
	int t;
	int err;
} Line;

%}

%define api.pure full
%locations
%param { Line *ln };

%code
{
	int yylex(YYSTYPE *, YYLTYPE *, Line *);
	void yyerror(YYLTYPE *, Line *, const char *);
	double binop(int, double, double);
}

%union
{
	int op;
	double v;
}

%left LOP1 LOP2
%left LOP3 LOP4
%right LOP5

%type <v> expr val
%token <v> LNUM
%token <op> LOP1 LOP2 LOP3 LOP4 LOP5

%%

top:
	expr
	{
		ln->r = $1;
	}

expr:
	val
	{
		$$ = $1;
	}
|
	expr LOP1 expr
	{
		$$ = binop($2, $1, $3);
	}
|
	expr LOP2 expr
	{
		$$ = binop($2, $1, $3);
	}
|
	expr LOP3 expr
	{
		$$ = binop($2, $1, $3);
	}
|
	expr LOP4 expr
	{
		$$ = binop($2, $1, $3);
	}
|
	expr LOP5 expr
	{
		$$ = binop($2, $1, $3);
	}

val: LNUM

%%

int
yylex(YYSTYPE *lv, YYLTYPE *ll, Line *ln)
{
	static const int prec[] = { LOP1, LOP2, LOP3, LOP4, LOP5 };
	static const char ops[] = "+-*/^";

	char *ep, *p;
	int t;

	while (isspace(ln->p[0]))
		ln->p++;

	if (ln->p[0] == '\0')
		return 0;

	if (isdigit(ln->p[0])) {
		lv->v = strtod(ln->p, &ep);
		ln->p = ep;
		return LNUM;
	}

	p = strchr(ops, *ln->p++);
	if (!p) {
		yyerror(ll, ln, "invalid input");
		return 0;
	}
	lv->op = *p;
	
	t = LOP1;
	if (ln->t == 0)
		t = prec[p - ops];
	
	return t;
}

void
yyerror(YYLTYPE *ll, Line *ln, const char *msg)
{
	ln->err = 1;

	(void) ll;
	(void) ln;
	(void) msg;
}

double
binop(int op, double x, double y)
{
	switch (op) {
	case '+':
		return x + y;
	case '-':
		return x - y;
	case '*':
		return x * y;
	case '/':
		return x / y;
	case '^':
		return pow(x, y);
	}
	return 0;
}

double
eval(const char *s)
{
	Line ln1, ln2;

	memset(&ln1, 0, sizeof(ln1));
	memset(&ln2, 0, sizeof(ln2));
	ln2.t = 1;
	ln1.p = s;
	ln2.p = s;

	if (yyparse(&ln1) || ln1.err)
		return -1;
	if (yyparse(&ln2) || ln2.err)
		return -1;
	return ln2.r - ln1.r;
}

void
test(const char *s, double r)
{
	double v;
	
	v = eval(s);
	printf("'%s' -> %f %f\n", s, v, r);
	assert(fabs(v - r) < 1e-6);
}

int
main(void)
{
	test("1 + 2 * 3 ^ 2 - 11 / 2 + 16", 21.5);
	test("7 - 1 * 3 ^ 2 + 41 / 3 + 2 * 9 * 2", 2178.333333);

	return 0;
}
