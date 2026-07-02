/*

Problem:
Given a string representing a mathematical expression with constants (pi, e, psi, i),
basic arithmetic operations (+, -, *, /), parentheses, fractions, and exponentiation,
write a program or function to convert a string to its equivalent LaTeX code.
The input string will only contain digits, arithmetic operators, parentheses, spaces, and constants.

Example:
Input: 2 + (3 * π) / (4 - e)^2

Output: $2 + \frac{3\cdot\pi}{(4 - e)^2}$

Input: π * 22/7 - 9.81

Output: $\pi\cdot\frac{22}{7} - 9.81$

Input: 2 - e^i + 3^(32)*(2*ψ)/(7*π)

Output: $2 - e^i + 3^{32}\cdot\frac{2\cdot\psi}{7\cdot\pi}$

Constraints:
0 < Input string < 100 chars.
You need to implement fractions using the \frac{}{} command in LaTeX.
Scoring:
This is code-golf, so the shortest code wins.

Latex commands:
\pi for the constant "π".
\psi for the constant "ψ".
e for the constant "e".
i for the constant "i".
\cdot for multiplication.
\frac{}{} for fractions.
^ operator for exponentiation. "{}" for exponents are optional.
The output should be enclosed in "$" or "$$" to indicate a math expression in LaTeX.

*/

%{

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>
#include <ctype.h>
#include <uchar.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

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
	char *strf(Line *, const char *, ...);
}

%union
{
	char *v;
}

%left '+' '-'
%left '*'
%left '/'
%right '^'
%precedence UPLUS UMINUS

%type <v> expr
%token <v> LNUM

%%
top:
	expr
	{
		ln->r = strf(ln, "$%s$", $1);
	}

expr:
	LNUM
	{
		$$ = $1;
	}
|
	expr '+' expr
	{
		$$ = strf(ln, "%s + %s", $1, $3);
	}
|
	expr '-' expr
	{
		$$ = strf(ln, "%s - %s", $1, $3);
	}
|
	expr '*' expr
	{
		$$ = strf(ln, "%s\\cdot%s", $1, $3);
	}
|
	expr '/' expr
	{
		$$ = strf(ln, "\\frac{%s}{%s}", $1, $3);
	}
|
	expr '^' expr
	{
		$$ = strf(ln, "%s^{%s}", $1, $3);
	}
|
	'(' expr ')'
	{
		$$ = strf(ln, "(%s)", $2);
	}
|
	'-' expr %prec UMINUS
	{
		$$ = strf(ln, "-%s", $2);
	}
|
	'+' expr %prec UPLUS
	{
		$$ = strf(ln, "+%s", $2);
	}

%%

char *
strf(Line *ln, const char *fmt, ...)
{
	va_list ap;
	char *p;
	int n;

	va_start(ap, fmt);
	p = ln->b;
	n = vsprintf(ln->b, fmt, ap);
	va_end(ap);
	ln->b += n + 1;
	return p;
}

char *
strn(Line *ln)
{
	const char *p;
	char *b, *r;

	b = ln->b;
	p = ln->p;
	r = ln->b;

	while (*p && (isdigit(*p) || strchr("+-eE.", *p)))
		*b++ = *p++;
	*b++ = '\0';

	ln->b = b;
	ln->p = p;
	return r;
}

int
yylex(YYSTYPE *lv, YYLTYPE *ll, Line *ln)
{
	static const void *cons[][2] = {
		{u8"π", "\\pi"},
		{u8"ψ", "\\psi"},
		{u8"i", "i"},
		{u8"e", "e"},
	};

	size_t i, n;
	int t;

	while (isspace(ln->p[0]))
		ln->p++;

	if (isdigit(ln->p[0])) {
		lv->v = strn(ln);
		return LNUM;
	}

	for (i = 0; i < nelem(cons); i++) {
		n = strlen(cons[i][0]);
		if (!strncmp(ln->p, cons[i][0], n)) {
			ln->p += n;
			lv->v = strf(ln, "%s", cons[i][1]);
			return LNUM;
		}
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
compile(const char *s, char *b)
{
	Line ln = { s, b, b, 0 };

	*b = '\0';
	if (yyparse(&ln) || ln.e)
		return NULL;
	return ln.r;
}

void
test(const void *s)
{
	char b[512];
	char *p;

	p = compile(s, b);
	assert(p);
	puts(p);
}

int
main()
{
	test(u8"2 + (3 * π) / (4 - e)^2");
	test(u8"π * 22/7 - 9.81");
	test(u8"2 - e^i + 3^(32)*(2*ψ)/(7*π)");
	return 0;
}
