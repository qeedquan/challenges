/*

Most of us get used to using infix math notation while writing arithmetic expressions, like this:

2 * 4 + 9 / 3
Meanwhile in programming the concept of postfix notation is often exploited. This form (often called also Reverse Polish Notation) was used in many programmable calculators and in some languages (e.g. Forth) to simplify processing. Moreover one of the popular ways of parsing and executing of infix notation is via conversion to postfix one.

Some languages (like LISP) also use prefix notation which gives similar advantages.

Let us see few examples. Operation on two values is simply written after them:

2 4 *           multiply 2 by 4

9 3 /           divide 9 by 3

8 3 +           sum 8 and 3
More complex expression:

5 2 3 * +       5 + 2 * 3

5 2 + 3 *       (5 + 2) * 3
You see, Polish notation does not need brackets (parentheses) since the order of operation is always determined.

Processing of RPN
Simple way to evaluate expression in RPN is by using stack and the following algorithm:

loop through all tokens of the expression;
if the next token is a value, it is pushed onto stack;
if it is operation, then a pair of values are popped from stack, operation is done on them and result is pushed back;
after the whole expression is processed, stack contains a single value which is the result of evaluation.
It is also easy to extend these rules for using unary operations - for them only one value should be popped from the stack instead of two. So for example formula for root of quadratic equation:

(sqrt(b * b - 4 * a * c) - b) / (2 * a)
Could be written as:

b b * 4 a * c * - sqrt b - 2 a * /
Your Goal
You are given a long expression in postfix notation, which contains integer values and operations:

add and sub for + and -;
mul, div and mod for *, / and remainder;
sqrt for taking square root.
You are to calculate the result.

Input data contains the expression, which may consist of few hundreds tokens.
Answer should contain single integer value - the result.

Example:

input data:
70 11 mul 5 div 219 add 28 26 6 sub 6 sub div mul 448 7 mul sqrt add

answer:
802

*/

%{

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

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

%left '+' '-'
%left '*' '/' '%'

%type <v> expr
%token <v> LNUM LSQRT

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
	expr expr '/'
	{
		$$ = 0;
		if ($2 != 0)
			$$ = $1 / $2;
	}
|
	expr expr '%'
	{
		$$ = 0;
		if ($2 != 0)
			$$ = $1 % $2;
	}
|
	expr LSQRT
	{
		$$ = sqrt($1);
	}
%%

int
yylex(YYSTYPE *lv, YYLTYPE *ll, Line *ln)
{
	static const char *ops[] = { "add", "sub", "mul", "div", "mod", "sqrt" };
	static const size_t oplen[] = { 3, 3, 3, 3, 3, 4 };
	static const int sym[] = { '+', '-', '*', '/', '%', LSQRT };

	char *ep;
	int t;
	size_t i;

	while (isspace(ln->p[0]))
		ln->p++;

	if (((ln->p[0] == '+' || ln->p[0] == '-') && isdigit(ln->p[1])) || isdigit(ln->p[0])) {
		lv->v = strtol(ln->p, &ep, 10);
		ln->p = ep;
		return LNUM;
	}

	for (i = 0; i < nelem(ops); i++) {
		if (!strncmp(ln->p, ops[i], oplen[i])) {
			ln->p += oplen[i];
			return sym[i];
		}
	}

	t = 0;
	switch (ln->p[0]) {
	case '\0':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
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
yyerror(YYLTYPE *, Line *ln, const char *)
{
	ln->e = 1;
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
main()
{
	assert(eval("70 11 mul 5 div 219 add 28 26 6 sub 6 sub div mul 448 7 mul sqrt add") == 802);
	return 0;
}
