/*

Implement a program to evaluate a postfix expression.

Input Format

The first input will be a single integer N denoting the number of test cases to take. After this there will be exactly N lines, each line a valid postfix string. The string will be a valid postfix expression consisting of only integers and binary operators (+, -, *, / and ?).

Every integer and operator will be compulsorily separated by a SPACE. The symbol ‘?’ denotes the end of expression.

Constraints

NA

Output Format

Exactly N lines, each line denoting the output of the expression. In case the output is in fractions, please print only the integer part of the output.

Sample Input 0

1
31 4 50 + * ?
Sample Output 0

1674
Sample Input 1

5
12 23 + 14 - ?
2 43 12 * + 12 + ?
12 3 + 12 3 + * 12 3 + / ?
32 34 12 * + 1 2 + * 1 1 + / 23 21 - * ?
12 10 * 12 / ?
Sample Output 1

21
530
15
1320
10

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

%left '+' '-'
%left '*' '/'

%type <v> expr
%token <v> LNUM

%%
top:
	expr '?'
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

%%

int
yylex(YYSTYPE *lv, YYLTYPE *ll, Line *ln)
{
	char *ep;
	int t;

	while (isspace(ln->p[0]))
		ln->p++;

	if (isdigit(ln->p[0]) || (ln->p[0] == '-' && isdigit(ln->p[1]))) {
		lv->v = strtol(ln->p, &ep, 10);
		ln->p = ep;
		return LNUM;
	}

	t = 0;
	switch (ln->p[0]) {
	case '\0':
	case '+':
	case '-':
	case '*':
	case '/':
	case '?':
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

long
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
	assert(eval("12 23 + 14 - ?") == 21);
	assert(eval("2 43 12 * + 12 + ?") == 530);
	assert(eval("12 3 + 12 3 + * 12 3 + / ? ") == 15);
	assert(eval("32 34 12 * + 1 2 + * 1 1 + / 23 21 - * ?") == 1320);
	assert(eval("12 10 * 12 / ?") == 10);

	return 0;
}
