/*

Description:

You are a devilish engineer designing a new programming language titled D++, which stands for a "Dijkstra++", named after your favorite computer scientist. You are currently working on the math-operations parsing component of your interpreter: though the language only supports infix-notation (such as "1 + 2 * 3"), your interpreter internals require you to represent all math strings in reverse polish notation (for easier, stack-based, computing). Your goal is to simply take a guaranteed valid infix-notation string of math operations and generate (printing it out) an equivalent and valid reverse polish notation string.

Formal Inputs & Outputs:

Input Description:

string MathOperations - A valid string of infix math notation.

Output Description:

Print the converted RPN form of the given math operations string.

Sample Inputs & Outputs:

"1 + 2" should be printed as "1 2 +". "(1+2)*3" should be printed as "3 2 1 + *". "(6 (7 – 2)) / 3 + 9 * 4" should be printed as "6 7 2 - * 3 / 9 4 * +".

Notes:

Do not get trapped in overly-complex solutions; there are formal solutions, though many ways of solving for this problem. Check out the Shunting Yard Algorithm for details on how to convert math-operation strings (a stack of tokens) from one notation system to another.

*/

%{

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
	const char *p;
	char *b;
	char *r;
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
	char *unary(Line *, int, const char *);
	char *binary(Line *, int, const char *, const char *);
}

%union
{
	char *v;
}

%left '+' '-'
%left '*' '/' '%'
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
	'-' LNUM %prec UMINUS
	{
		$$ = unary(ln, '-', $2);
	}
|
	'+' LNUM %prec UPLUS
	{
		$$ = unary(ln, '+', $2);
	}
|
	expr '+' expr
	{
		$$ = binary(ln, '+', $1, $3);
	}
|
	expr '-' expr
	{
		$$ = binary(ln, '-', $1, $3);
	}
|
	expr '*' expr
	{
		$$ = binary(ln, '*', $1, $3);
	}
|
	expr '/' expr
	{
		$$ = binary(ln, '/', $1, $3);
	}
|
	expr '%' expr
	{
		$$ = binary(ln, '%', $1, $3);
	}
|
	expr '^' expr
	{
		$$ = binary(ln, '^', $1, $3);
	}
|
	LNUM '(' expr ')'
	{
		$$ = binary(ln, '*', $1, $3);
	}
|
	'(' expr ')'
	{
		$$ = $2;
	}

%%

char *
unary(Line *ln, int op, const char *val)
{
	char *b;

	b = ln->b;
	ln->b += sprintf(b, "%c%s", op, val) + 1;
	return b;
}

char *
binary(Line *ln, int op, const char *lhs, const char *rhs)
{
	char *b;

	b = ln->b;
	ln->b += sprintf(b, "%s %s %c", lhs, rhs, op) + 1;
	return b;
}

int
yylex(YYSTYPE *lv, YYLTYPE *ll, Line *ln)
{
	int t;

	while (isspace(ln->p[0]))
		ln->p++;

	if (isdigit(ln->p[0])) {
		lv->v = ln->b;
		do {
			*ln->b++ = *ln->p++;
		} while (isdigit(ln->p[0]));
		*ln->b++ = '\0';
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

char *
in2post(const char *s, char *b)
{
	Line ln = { s, b, NULL, 0 };
	if (yyparse(&ln) || ln.e)
		return NULL;
	return ln.r;
}

void
test(const char *s)
{
	char b[128], *p;

	p = in2post(s, b);
	assert(p);
	printf("'%s'\n", p);
}

int
main(void)
{
	test("1 + 2");
	test("(1+2)*3");
	test("(6 (7 - 2)) / 3 + 9 * 4");
	test("5*6/3^2");

	return 0;
}
