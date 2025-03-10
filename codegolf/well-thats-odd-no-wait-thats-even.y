/*

Preamble
Integers are always either even or odd. Even integers are divisible by two, odd integers are not.

When you add two integers you can infer whether the result will be even or odd based on whether the summands were even or odd:

Even + Even = Even
Even + Odd = Odd
Odd + Even = Odd
Odd + Odd = Even
Likewise, when you multiply two integers you can infer whether the result will be even or odd based on whether the factors were even or odd:

Even * Even = Even
Even * Odd = Even
Odd * Even = Even
Odd * Odd = Odd
Thus, if you know the evenness or oddness of all the variables in a math expression that only involves addition and multiplication, you can infer whether the result will be even or odd.

For example, we can confidently say that (68 + 99) * 37 results in an odd because an even plus an odd (68 + 99) is an odd, and that odd times another odd (odd * 37) gives an odd.

Challenge
Write a program or function that takes in a string only containing the four characters eo+*.
This string represents a mathematical expression given in prefix notation involving only addition (+) and multiplication (*). Each e represents some arbitrary even number, and each o represents some arbitrary odd number.

Your task is to simplify the expression, printing or returning a single e or o based on whether the result of the expression is even or odd.

You can assume that the input will always be in valid prefix notation. Specifically, each + and * will always have two corresponding operands occurring after it. These operands may be a single e or o, or another + or * expression that in turn has operands.

For example, the input *+eoo could be read as mul(add(e, o), o), or (e + o) * o in normal infix notation. The e and the first o are the operands corresponding to the +, and +eo and the last o are the operands corresponding to the *.

Just to make it clear, here are some invalid inputs that have incorrect prefix notation:

eo
ooe
o+e
ee*
+*oe
+e*o
A single trailing newline in the output is fine, but otherwise a plain e for even or o for odd is all that should be output.

The shortest code in bytes wins.

Test Cases
(Empty lines are only to help visually separate similar cases.)

e -> e
o -> o

+ee -> e
+eo -> o
+oe -> o
+oo -> e
*ee -> e
*eo -> e
*oe -> e
*oo -> o

+e+ee -> e
+e+eo -> o
+e+oe -> o
+e+oo -> e
+e*ee -> e
+e*eo -> e
+e*oe -> e
+e*oo -> o

+o+ee -> o
+o+eo -> e
+o+oe -> e
+o+oo -> o
+o*ee -> o
+o*eo -> o
+o*oe -> o
+o*oo -> e

*e+ee -> e
*e+eo -> e
*e+oe -> e
*e+oo -> e
*e*ee -> e
*e*eo -> e
*e*oe -> e
*e*oo -> e

*o+ee -> e
*o+eo -> o
*o+oe -> o
*o+oo -> e
*o*ee -> e
*o*eo -> e
*o*oe -> e
*o*oo -> o

++eee -> e
++eeo -> o
++eoe -> o
++eoo -> e
++oee -> o
++oeo -> e
++ooe -> e
++ooo -> o

+*eee -> e
+*eeo -> o
+*eoe -> e
+*eoo -> o
+*oee -> e
+*oeo -> o
+*ooe -> o
+*ooo -> e

*+eee -> e
*+eeo -> e
*+eoe -> e
*+eoo -> o
*+oee -> e
*+oeo -> o
*+ooe -> e
*+ooo -> e

**eee -> e
**eeo -> e
**eoe -> e
**eoo -> e
**oee -> e
**oeo -> e
**ooe -> e
**ooo -> o

+e+e+e+ee -> e
+o+o+o+oo -> o
*e*e*e*ee -> e
*o*o*o*oo -> o
+e+o+e+oe -> e
+o+e+o+eo -> o
*e*o*e*oe -> e
*o*e*o*eo -> e
+e*e+e*ee -> e
+o*o+o*oo -> o
*e+e*e+ee -> e
*o+o*o+oo -> o

+**++*+*eeoeeooee -> e
+**++*+***eooeoeooeoe -> e
+**+***+**++**+eooeoeeoeeoeooeo -> o

+e*o*e**eoe -> e
+*e+e+o+e**eeoe -> e
**o++*ee*++eoe*eo+eoo -> o

*/

%{

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
	const char *p;
	int r;
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
	int v;
}

%left '+' '*'

%type <v> expr

%%
top:
	expr
	{
		ln->r = $1;
	}

expr:
	'e'
	{
		$$ = 'e';
	}
|
	'o'
	{
		$$ = 'o';
	}
|
	'+' expr expr
	{
		$$ = ($2 == $3) ? 'e' : 'o';
	}
|
	'*' expr expr
	{
		$$ = ($2 == 'o' && $3 == 'o') ? 'o' : 'e';
	}
%%

int
yylex(YYSTYPE *lv, YYLTYPE *ll, Line *ln)
{
	int t;

	while (isspace(ln->p[0]))
		ln->p++;

	t = 0;
	switch (ln->p[0]) {
	case '\0':
	case 'e':
	case 'o':
	case '+':
	case '*':
		t = ln->p[0];
		break;

	default:
		yyerror(ll, ln, "invalid input");
		break;
	}
	ln->p++;

	return t;

	(void) lv;
}

void
yyerror(YYLTYPE *ll, Line *ln, const char *msg)
{
	ln->e = 1;

	(void) ll;
	(void) msg;
}

int
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
	assert(eval("e") == 'e');
	assert(eval("o") == 'o');

	assert(eval("+ee") == 'e');
	assert(eval("+eo") == 'o');
	assert(eval("+oe") == 'o');
	assert(eval("+oo") == 'e');
	assert(eval("*ee") == 'e');
	assert(eval("*eo") == 'e');
	assert(eval("*oe") == 'e');
	assert(eval("*oo") == 'o');
	
	assert(eval("+e+ee") == 'e');
	assert(eval("+e+eo") == 'o');
	assert(eval("+e+oe") == 'o');
	assert(eval("+e+oo") == 'e');
	assert(eval("+e*ee") == 'e');
	assert(eval("+e*eo") == 'e');
	assert(eval("+e*oe") == 'e');
	assert(eval("+e*oo") == 'o');

	assert(eval("+o+ee") == 'o');
	assert(eval("+o+eo") == 'e');
	assert(eval("+o+oe") == 'e');
	assert(eval("+o+oo") == 'o');
	assert(eval("+o*ee") == 'o');
	assert(eval("+o*eo") == 'o');
	assert(eval("+o*oe") == 'o');
	assert(eval("+o*oo") == 'e');

	assert(eval("*e+ee") == 'e');
	assert(eval("*e+eo") == 'e');
	assert(eval("*e+oe") == 'e');
	assert(eval("*e+oo") == 'e');
	assert(eval("*e*ee") == 'e');
	assert(eval("*e*eo") == 'e');
	assert(eval("*e*oe") == 'e');
	assert(eval("*e*oo") == 'e');

	assert(eval("*o+ee") == 'e');
	assert(eval("*o+eo") == 'o');
	assert(eval("*o+oe") == 'o');
	assert(eval("*o+oo") == 'e');
	assert(eval("*o*ee") == 'e');
	assert(eval("*o*eo") == 'e');
	assert(eval("*o*oe") == 'e');
	assert(eval("*o*oo") == 'o');

	assert(eval("++eee") == 'e');
	assert(eval("++eeo") == 'o');
	assert(eval("++eoe") == 'o');
	assert(eval("++eoo") == 'e');
	assert(eval("++oee") == 'o');
	assert(eval("++oeo") == 'e');
	assert(eval("++ooe") == 'e');
	assert(eval("++ooo") == 'o');

	assert(eval("+*eee") == 'e');
	assert(eval("+*eeo") == 'o');
	assert(eval("+*eoe") == 'e');
	assert(eval("+*eoo") == 'o');
	assert(eval("+*oee") == 'e');
	assert(eval("+*oeo") == 'o');
	assert(eval("+*ooe") == 'o');
	assert(eval("+*ooo") == 'e');

	assert(eval("*+eee") == 'e');
	assert(eval("*+eeo") == 'e');
	assert(eval("*+eoe") == 'e');
	assert(eval("*+eoo") == 'o');
	assert(eval("*+oee") == 'e');
	assert(eval("*+oeo") == 'o');
	assert(eval("*+ooe") == 'e');
	assert(eval("*+ooo") == 'e');

	assert(eval("**eee") == 'e');
	assert(eval("**eeo") == 'e');
	assert(eval("**eoe") == 'e');
	assert(eval("**eoo") == 'e');
	assert(eval("**oee") == 'e');
	assert(eval("**oeo") == 'e');
	assert(eval("**ooe") == 'e');
	assert(eval("**ooo") == 'o');

	assert(eval("+e+e+e+ee") == 'e');
	assert(eval("+o+o+o+oo") == 'o');
	assert(eval("*e*e*e*ee") == 'e');
	assert(eval("*o*o*o*oo") == 'o');
	assert(eval("+e+o+e+oe") == 'e');
	assert(eval("+o+e+o+eo") == 'o');
	assert(eval("*e*o*e*oe") == 'e');
	assert(eval("*o*e*o*eo") == 'e');
	assert(eval("+e*e+e*ee") == 'e');
	assert(eval("+o*o+o*oo") == 'o');
	assert(eval("*e+e*e+ee") == 'e');
	assert(eval("*o+o*o+oo") == 'o');

	assert(eval("+**++*+*eeoeeooee") == 'e');
	assert(eval("+**++*+***eooeoeooeoe") == 'e');
	assert(eval("+**+***+**++**+eooeoeeoeeoeooeo") == 'o');

	assert(eval("+e*o*e**eoe") == 'e');
	assert(eval("+*e+e+o+e**eeoe") == 'e');
	assert(eval("**o++*ee*++eoe*eo+eoo") == 'o');

	return 0;
}
