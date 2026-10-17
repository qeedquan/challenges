/*

Given a string representing arbitrarily nested ternary expressions, calculate the result of the expression. You can always assume that the given expression is valid and only consists of digits 0-9, ?, :, T and F (T and F represent True and False respectively).

Note:

The length of the given string is ≤ 10000.
Each number will contain only one digit.
The conditional expressions group right-to-left (as usual in most languages).
The condition will always be either T or F. That is, the condition will never be a digit.
The result of the expression will always evaluate to either a digit 0-9, T or F.
Example 1:

Input: "T?2:3"

Output: "2"

Explanation: If true, then result is 2; otherwise result is 3.
Example 2:

Input: "F?1:T?4:5"

Output: "4"

Explanation: The conditional expressions group right-to-left. Using parenthesis, it is read/evaluated as:

             "(F ? 1 : (T ? 4 : 5))"                   "(F ? 1 : (T ? 4 : 5))"
          -> "(F ? 1 : 4)"                 or       -> "(T ? 4 : 5)"
          -> "4"                                    -> "4"
Example 3:

Input: "T?T?F:5:3"

Output: "F"

Explanation: The conditional expressions group right-to-left. Using parenthesis, it is read/evaluated as:

             "(T ? (T ? F : 5) : 3)"                   "(T ? (T ? F : 5) : 3)"
          -> "(T ? F : 3)"                 or       -> "(T ? F : 5)"
          -> "F"                                    -> "F"

*/

%{

#include <assert.h>
#include <stdbool.h>
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
};

%type <v> expr
%token <v> LNUM

%%

top:
	expr
	{
		ln->r = $1;
	}

expr:
	'T' '?' expr ':' expr
	{
		$$ = $3;
	}
|
	'F' '?' expr ':' expr
	{
		$$ = $5;
	}
|
	'T'
	{
		$$ = 'T';
	}
|
	'F'
	{
		$$ = 'F';
	}
|
	LNUM
	{
		$$ = $1;
	}

%%

int
yylex(YYSTYPE *lv, YYLTYPE *ll, Line *ln)
{
	int t;

	while (isspace(ln->p[0]))
		ln->p++;
	
	if (isdigit(ln->p[0])) {
		lv->v = ln->p[0];
		ln->p++;
		return LNUM;
	}

	t = 0;
	switch (ln->p[0]) {
	case '\0':
	case 'T':
	case 'F':
	case '?':
	case ':':
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

int
ternary(const char *s)
{
	Line ln = { s, 0, 0 };
	if (yyparse(&ln) || ln.e)
		return -1;
	return ln.r;
}

int
main(void)
{
	assert(ternary("T?2:3") == '2');
	assert(ternary("F?1:T?4:5") == '4');
	assert(ternary("T?T?F:5:3") == 'F');

	return 0;
}
