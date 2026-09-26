/*

Your mission, if you choose to accept it, is to construct a simple truth evaluator for the following logical operators:

----------------------------------------------------------------------------------
  Logical Name          |  Gate Name   |  Symbol  |  Symbol Name  |  Truth Table
----------------------------------------------------------------------------------
  Identity              |  is          |          |  (none)       |  10
  Negation              |  not         |    ~     |  tilde        |  01
  Conjunction           |  and         |    &     |  ampersand    |  1000
  Disjunction           |  or          |    |     |  pipe         |  1110
  Negative Conjunction  |  nand        |    ^     |  caret        |  0111
  Joint Denial          |  nor         |    v     |  "vee"        |  0001
  Exclusive Disjunction |  xor         |    x     |  "ecks"       |  0110
  Equivalence           |  equals/xnor |    =     |  equals       |  1001
  Implication           |  implies     |    >     |  greater than |  1011

Truth tables are in the following order:

1 1
1 0
0 1
0 0
Input will come as a simple string of 0, 1, and the symbol. You can either accept input as a parameter or read it from the user on stdin. Here are some sample input/output pairs:

Input: 1
Output: 1

Input: ~1
Output: 0

Input: 0|1
Output: 1

Input: 1>0
Output: 0
The unary operator (negation) will always appear before the boolean value, while the binary operators will always appear between the two boolean values. You can assume that all input will be valid. Strings are regular ASCII strings.

If you prefer, you can use T and F rather than 1 and 0. -6 to your character count if you support both.

This is code-golf: shortest code in any language wins!

*/

%{

#include <assert.h>
#include <stdio.h>
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

%left '&' '|' '^' 'v' 'x' '=' '>'
%left '~'

%type <v> expr
%token <v> LNUM

%%

top:
	expr
	{
		ln->r = $1 & 1;
	}

expr:
	LNUM
	{
		$$ = $1;
	}
|
	expr '&' expr
	{
		$$ = $1 & $3;
	}
|
	expr '|' expr
	{
		$$ = $1 | $3;
	}
|
	expr '^' expr
	{
		$$ = ~($1 & $3);
	}
|
	expr 'v' expr
	{
		$$ = ~($1 | $3);
	}
|
	expr 'x' expr
	{
		$$ = $1 ^ $3;
	}
|
	expr '=' expr
	{
		$$ = ~($1 ^ $3);
	}
|
	expr '>' expr
	{
		$$ = ~$1 | $3;
	}
|
	'(' expr ')'
	{
		$$ = $2;
	}
|
	'~' expr
	{
		$$ = ~$2;
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

	t = 0;
	switch (ln->p[0]) {
	case '\0':
	case '~':
	case '&':
	case '|':
	case '^':
	case 'v':
	case 'x':
	case '=':
	case '>':
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
yyerror(YYLTYPE *, Line *ln, const char *)
{
	ln->e = 1;
}

long
eval(const char *s)
{
	Line ln = { s, 0, 0 };
	if (yyparse(&ln) || ln.e)
		return -1;
	return ln.r;
}

void
test(const char *s, long r)
{
	long v;
	
	v = eval(s);
	printf("'%s' -> %ld\n", s, r);
	assert(v == r);
}

int
main()
{
	test("0", 0);
	test("1", 1);
	test("~0", 1);
	test("~1", 0);

	test("0|0", 0);
	test("0|1", 1);
	test("1|0", 1);
	test("1|1", 1);

	test("0&0", 0);
	test("0&1", 0);
	test("1&0", 0);
	test("1&1", 1);

	test("0x0", 0);
	test("0x1", 1);
	test("1x0", 1);
	test("0x0", 0);

	test("0^0", 1);
	test("0^1", 1);
	test("1^0", 1);
	test("1^1", 0);

	test("0v0", 1);
	test("0v1", 0);
	test("1v0", 0);
	test("1v1", 0);

	test("0=0", 1);
	test("0=1", 0);
	test("1=0", 0);
	test("1=1", 1);

	test("0>0", 1);
	test("1>0", 0);
	test("0>1", 1);
	test("1>1", 1);

	return 0;
}
