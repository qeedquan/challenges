/*

Your task is to write a program that will take input like this:

a + b * c + a / 2
and will generate the source code for a program that takes user input and then evaluates the expression.

The expression can contain the operators +,-,*,/; single-letter lowercase variables; and integers between 0 and 32000. Standard arithmetic precedence must be correctly followed. The expression is limited to 26 unique variables a to z. However, a single variable can appear more than once.

You can assume that the input expression is valid (follows these rules).

The generated program must prompt for user input in this form, prompting only once for each variable:

a =
User input from 0 to 32000 should be handled correctly. It will then print the expression and the correct result. You can use either integer or floating point arithmetic. The calculations should be performed with at least 32 bit precision. Beyond that, you don't have to worry about overflow or divide by zero.

Example of a non-golfed generated Perl program for the above expression:

print "a = ";
my $a = <>;
print "b = ";
my $b = <>;
print "c = ";
my $c = <>;
print "a + b * c + a / 2 = " . ($a + $b * $c + $a / 2);
Example input and output of program generated for above expression:

a = 1
b = 2
c = 3
a + b * c + a / 2 = 7.5
The score is calculated as length of the program + length of the generated program for this expression:

1 + a * 4 * b + 2 / d * e - a - 3 + g / h * 32000
Lowest score wins.

Update: Just to highlight a couple of requirements of the problem, as stated above:

The output of the program must be source code for another program that evaluates the expression.
The program must print the original expression. Perhaps there is some ambiguity in this (one could argue that a+b is the same expression as a + b), but for clarity let's say that it must be the original expression with white space intact. All valid answers so far have done it that way.

*/

%{

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef unsigned long ulong;

typedef struct {
	const char *p;
	ulong m;
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

%left '+' '-'
%left '*' '/'
%precedence UPLUS UMINUS

%token <v> LVAR
%token LNUM

%%
expr:
	LVAR
	{
		ln->m |= 1UL << ($1 - 'a');
	}
|
	LNUM
|
	expr '+' expr
|
	expr '-' expr
|
	expr '*' expr
|
	expr '/' expr
|
	'(' expr ')'
|
	'-' expr %prec UMINUS
|
	'+' expr %prec UPLUS
%%

int
yylex(YYSTYPE *lv, YYLTYPE *ll, Line *ln)
{
	char *ep;
	int t;

	while (isspace(ln->p[0]))
		ln->p++;

	if (isdigit(ln->p[0])) {
		strtod(ln->p, &ep);
		ln->p = ep;
		return LNUM;
	}

	if ('a' <= ln->p[0] && ln->p[0] <= 'z') {
		lv->v = ln->p[0];
		ln->p++;
		return LVAR;
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
yyerror(YYLTYPE *, Line *ln, const char *)
{
	ln->e = 1;
}

int
gen(const char *s)
{
	Line ln = { s, 0, 0 };
	ulong i;
	int c;

	if (yyparse(&ln) || ln.e)
		return -1;

	puts("#include <stdio.h>\n");
	puts("int main() {");
	for (i = 0; i < 26; i++) {
		if (!(ln.m & (1UL << i)))
			continue;

		c = 'a' + i;
		printf("\tdouble %c;\n", c);
		printf("\tprintf(\"%c = \");\n", c);
		printf("\tscanf(\"%%lf\", &%c);\n", c);
	}

	printf("\tdouble R = %s;\n", s);
	printf("\tprintf(\"%s = %%f\\n\", R);\n", s);
	puts("\treturn 0;");
	puts("}");
	return 0;
}

int
main()
{
	gen("a + b * c + a / 2");

	return 0;
}
