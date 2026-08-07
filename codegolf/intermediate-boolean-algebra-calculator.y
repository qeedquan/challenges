/*

Background
With the success of Simple Boolean Algebra Calculator, I present a more difficult problem.

Boolean Algebra concerns representing values with letters and simplifying expressions. The following is a chart for the standard notation used:

https://i.stack.imgur.com/kWE7v.png

Above is what actual boolean algebra looks like. For the purposes of this code golf, this is not the exact syntax that will be used.

Your Task
Given a short boolean expression, return the solution to the expression.

There will be at most two values and one function involved in the calculator. The values may be any of 0, 1, or a capital letter(s). The functions may be /, +, or .

Any of the following may be an input: (values are demonstrated with X and Y in these examples.)

One function, One value

There is only one possibility for this, which is /X. Return NOT X. If X is a variable, return /X, otherwise compute and output. This is the only scenario where /, the backslash, will be used.
Two values

There is only one possibility for this, which is XY. Return X AND Y. If X and Y are different variables, return XY, otherwise compute and output. This is the only scenario where two values are next to each other.
One value, One function, Another value

If you've done Simple Boolean Algebra Calculator, this is exactly the same except that it now must be able to output two variable calculations.
Return the value for X (function) Y. If X and Y are different variables, output X (function) Y.
(function), the second character in this scenario, will be either "+" or ".". If "+", treat as OR. If ".", treat as AND.
Input: Either two characters or three characters.

Output: Either one character, two characters, or three characters.

Explained Examples
Input => Output
/0 => 1
/1 => 0
/P => /P
These expressions output the NOT value for the input. /P outputs /P because it cannot be simplified further.

Input => Output
0Q => 0
0Q evaluates to 0 because 0 AND Q will always be 0, regardless of what value Q takes.

Input => Output
Z1 => Z
Z1 evaluates to Z because the output for Z AND 1 depends entirely on the value of Z.

Input => Output
AH => AH (or A.H)
AH evaluates to AH because it cannot be simplified further. A.H is also a valid output.

Input => Output
A+1 => 1
A+1 evaluates to 1 because the OR statement is overridden by 1. That is, no matter what value A takes, the presence of 1 means that the statement will always evaluate to 1.

Input => Output
B+B => B
B+B evaluates to B because the OR statement is dependent on either Bs being true. If both Bs are false, then the output would also be false. So, the statement returns B since whatever value B takes, the output would return that.

Input => Output
W+L => W+L
W+L evaluates to W+L because it cannot be simplified further.

Input => Output
0.H => 0
0.H evaluates to 0 because the AND statement is overridden by 0. That is, no matter what value H takes, the presence of 0 means that the statement will always evaluate to 0.

Input => Output
1.1 => 1
1.1 evaluates 1 because the AND statement requires both inputs to be 1, and since they are both 1, 1 is returned.

Input => Output
G.L => G.L
G.L evaluates to G.L because it cannot be simplified further.

Examples/Test cases
Input => Output

/0 => 1
/1 => 0
/P => /P

00 => 0
11 => 1
0Q => 0
Z1 => Z
NN => N
AH => AH (or A.H)

A+1 => 1
B+B => B
R+0 => R
1+1 => 1
0+0 => 0
A+B => A+B
Y+Z => Y+Z

0.0 => 0
Q.Q => Q
0.A => 0
1.C => C
1.1 => 1
R.S => R.S
N.W => N.W

This is code-golf, so shortest answer wins. Good luck.

*/

%{

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>

typedef struct {
	const char *p;
	char *b;
	char *t;
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
	char *strf(Line *, const char *, ...);
	char *bnot(Line *, char *);
	char *band(Line *, char *, char *, const char *);
	char *bor(Line *, char *, char *);
}

%union
{
	char *v;
}

%left '+'
%left '.'

%type <v> expr
%token <v> LVAR

%%
top:
	expr
	{
		memmove(ln->b, $1, strlen($1) + 1);
	}

expr:
	LVAR
	{
		$$ = $1;
	}
|
	'/' LVAR
	{
		$$ = bnot(ln, $2);
	}
|
	LVAR LVAR
	{
		$$ = band(ln, $1, $2, "");
	}
|
	LVAR '.' LVAR
	{
		$$ = band(ln, $1, $3, ".");
	}
|
	LVAR '+' LVAR
	{
		$$ = bor(ln, $1, $3);
	}
%%

char *
strf(Line *ln, const char *fmt, ...)
{
	va_list ap;
	char *s;
	int n;

	va_start(ap, fmt);
	n = vsprintf(ln->t, fmt, ap);
	va_end(ap);

	s = ln->t;
	ln->t += n + 1;
	return s;
}

char *
bnot(Line *ln, char *s)
{
	if (s[0] == '0')
		s[0] = '1';
	else if (s[0] == '1')
		s[0] = '0';
	else
		return strf(ln, "/%s", s);
	return s;
}

char *
band(Line *ln, char *s, char *t, const char *sep)
{
	if (s[0] == '0' || t[0] == '0' || t[0] == '1')
		return s;
	if (s[0] == '1')
		return t;
	if (!strcmp(s, t))
		return s;
	return strf(ln, "%s%s%s", s, sep, t);
}

char *
bor(Line *ln, char *s, char *t)
{
	if (s[0] == '0' || t[0] == '1')
		return t;
	if (s[0] == '1' || t[0] == '0')
		return s;
	if (!strcmp(s, t))
		return s;
	return strf(ln, "%s+%s", s, t);
}

int
yylex(YYSTYPE *lv, YYLTYPE *ll, Line *ln)
{
	int t;
	int c;

	while (isspace(ln->p[0]))
		ln->p++;

	c = toupper(ln->p[0]);
	if (('A' <= c && c <= 'Z') || (c == '0' || c == '1')) {
		lv->v = strf(ln, "%c", ln->p[0]);
		ln->p++;
		return LVAR;
	}

	t = 0;
	switch (ln->p[0]) {
	case '\0':
	case '+':
	case '.':
	case '/':
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
	(void) ln;
	(void) msg;
}

char *
eval(const char *s, char *b)
{
	Line ln = { s, b, b, 0 };
	if (yyparse(&ln) || ln.e)
		return NULL;
	return ln.b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	assert(eval(s, b));
	printf("'%s' -> '%s'\n", s, b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("/0", "1");
	test("/1", "0");
	test("/P", "/P");

	test("00", "0");
	test("11", "1");
	test("0Q", "0");
	test("Z1", "Z");
	test("NN", "N");
	test("AH", "AH");

	test("A+1", "1");
	test("B+B", "B");
	test("R+0", "R");
	test("1+1", "1");
	test("0+0", "0");
	test("A+B", "A+B");
	test("Y+Z", "Y+Z");

	test("0.0", "0");
	test("Q.Q", "Q");
	test("0.A", "0");
	test("1.C", "C");
	test("1.1", "1");
	test("R.S", "R.S");
	test("N.W", "N.W");

	return 0;
}
