/*

Write code to evaluate whether a chain of inequalities is true or false. An example input is the string

3<=4!=9>3==3

This is true because each of its components is true:

(3<=4) and (4!=9) and (9>3) and (3==3)

Input:

A string that represents a chain of one or more inequalities. The allowed comparison operators are

==   equals
!=   does not equal
>    is greater than
>=   is greater than or equal to
<    is less than
<=   is less than or equal to

The allowed numbers are single-digit numbers 0 through 9. There won't be any spaces, parentheses, or other symbols.

Output:

The correctness of the inequality as a consistent Truthy or Falsey value. Consistent means every Truthy output is the same and every Falsey output is the same.

Restriction:

The intent of this challenge is for you to write code that processes the inequalities, rather than have them be evaluating them as code, even for a single inequality in the chain. As such, methods like Python's eval and exec that evaluate or execute code are banned. So are functions which look up a method or operator given its name as a string. Nor is it allowed to launching processes or programs to do the evaluation for you.

Test cases:

3<=4!=9>3==3
True

3<=4!=4
False

5>5
False

8==8<9>0!=2>=1
True

*/

%{

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
	long op;
	long x, y;
	bool b;
} Cmp;

typedef struct {
	const char *p;
	Cmp r;
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
	Cmp chain(int, long, Cmp);
	Cmp cmp(int, long, long);
}

%union
{
	Cmp c;
	long v;
}

%type <c> expr
%type <v> val
%token <v> LNUM LCMP
%token LEQ LNE LLE LGE

%%
top:
	expr
	{
		ln->r = $1;
	}

expr:
	val LCMP expr
	{
		$$ = chain($2, $1, $3);
	}
|
	val LCMP val
	{
		$$ = cmp($2, $1, $3);
	}

val: LNUM

%%

Cmp
chain(int op, long x, Cmp c)
{
	Cmp r;

	r = cmp(op, x, c.x);
	r.b = r.b && c.b;
	return r;
}

Cmp
cmp(int op, long x, long y)
{
	Cmp c;

	c.op = op;
	c.x = x;
	c.y = y;
	c.b = false;
	switch (op) {
	case '<':
		c.b = x < y;
		break;
	case '>':
		c.b = x > y;
		break;
	case LEQ:
		c.b = x == y;
		break;
	case LNE:
		c.b = x != y;
		break;
	case LGE:
		c.b = x >= y;
		break;
	case LLE:
		c.b = x <= y;
		break;
	}
	return c;
}

int
yylex(YYSTYPE *lv, YYLTYPE *ll, Line *ln)
{
	char *ep;
	int t;

	while (isspace(ln->p[0]))
		ln->p++;

	if (isdigit(ln->p[0])) {
		lv->v = strtol(ln->p, &ep, 0);
		ln->p = ep;
		return LNUM;
	}

	t = LCMP;
	lv->v = ln->p[0];
	switch (ln->p[0]) {
	case '\0':
		t = 0;
		break;

	case '>':
	case '<':
		if (ln->p[1] == '=') {
			lv->v = (ln->p[0] == '>') ? LGE : LLE;
			ln->p++;
		}
		break;
	
	case '=':
	case '!':
		if (ln->p[1] == '=') {
			lv->v = (ln->p[0] == '=') ? LEQ : LNE;
			ln->p++;
			break;
		}
	
		[[fallthrough]];
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
	(void) ln;
	(void) msg;
}

bool
eval(const char *s)
{
	Line ln = {s, {}, 0};
	if (yyparse(&ln) || ln.e)
		return false;
	return ln.r.b;
}

void
test(const char *s, bool r)
{
	bool b;
	
	b = eval(s);
	printf("'%s' -> %d\n", s, b);
	assert(b == r);
}

int
main(void)
{
	test("3<=4!=9>3==3", true);
	test("3<=4!=4", false);
	test("5>5", false);
	test("8==8<9>0!=2>=1", true);
	test("2<3<4<5<6>7", false);
	test("2<3<4<5<6>1<8", true);
	test("1<2<3<4<5<6<10", true);
	test("1!=2!=3!=4!=5!=6", true);
	test("0==0==0==0==0", true);

	return 0;
}
