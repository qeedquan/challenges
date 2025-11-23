/*

A boolean expression is an expression that evaluates to either true or false. It can be in one of the following shapes:

    't' that evaluates to true.
    'f' that evaluates to false.
    '!(subExpr)' that evaluates to the logical NOT of the inner expression subExpr.
    '&(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical AND of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
    '|(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical OR of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.

Given a string expression that represents a boolean expression, return the evaluation of that expression.

It is guaranteed that the given expression is valid and follows the given rules.

Example 1:

Input: expression = "&(|(f))"
Output: false
Explanation:
First, evaluate |(f) --> f. The expression is now "&(f)".
Then, evaluate &(f) --> f. The expression is now "f".
Finally, return false.

Example 2:

Input: expression = "|(f,f,f,t)"
Output: true
Explanation: The evaluation of (false OR false OR false OR true) is true.

Example 3:

Input: expression = "!(&(f,t))"
Output: true
Explanation:
First, evaluate &(f,t) --> (false AND true) --> false --> f. The expression is now "!(f)".
Then, evaluate !(f) --> NOT false --> true. We return true.

Constraints:

    1 <= expression.length <= 2 * 10^4
    expression[i] is one following characters: '(', ')', '&', '|', '!', 't', 'f', and ','.

*/

%{

#include <stdbool.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Line Line;
typedef struct List List;

struct List {
	bool v;
	List *t;
};

struct Line {
	List *l;
	size_t n;

	const char *p;
	bool r;
	int e;
};

List *bval(Line *, bool);
bool bcond(int, List *);

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
	List *l;
	bool v;
}

%type <l> exprlist
%type <v> expr
%token <v> 't' 'f'

%%

expr:
	't'
	{
		$$ = ln->r = true;
	}
|
	'f'
	{
		$$ = ln->r = false;
	}
|
	'!' '(' expr ')'
	{
		$$ = ln->r = !$3;
	}
|
	'&' '(' exprlist ')'
	{
		$$ = ln->r = bcond('&', $3);
	}
|
	'|' '(' exprlist ')'
	{
		$$ = ln->r = bcond('|', $3);
	}

exprlist:
	expr
	{
		$$ = bval(ln, $1);
	}
|
	expr ',' exprlist
	{
		$$ = bval(ln, $1);
		$$->t = $3;
	}

%%

List *
bval(Line *ln, bool v)
{
	List *l;

	l = &ln->l[ln->n++];
	l->v = v;
	return l;
}

bool
bcond(int op, List *l)
{
	bool r;

	r = l->v;
	for (l = l->t; l; l = l->t) {
		if (op == '&')
			r = r && l->v;
		else if (op == '|')
			r = r || l->v;	
	}
	return r;
}

int
yylex(YYSTYPE *lv, YYLTYPE *ll, Line *ln)
{
	int t;

	while (isspace(ln->p[0]))
		ln->p++;

	t = 0;
	switch (ln->p[0]) {
	case '\0':
	case 't':
	case 'f':
	case '!':
	case '&':
	case '|':
	case '(':
	case ')':
	case ',':
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
	(void) ln;
	(void) msg;
}

bool
truth(const char *s)
{
	Line ln;

	memset(&ln, 0, sizeof(ln));
	ln.p = s;
	ln.l = calloc(strlen(s) + 1, sizeof(*ln.l));
	if (!ln.l)
		return false;

	if (yyparse(&ln) || ln.e)
		ln.r = false;

	free(ln.l);
	return ln.r;
}

int
main(void)
{
	assert(truth("t") == true);
	assert(truth("f") == false);
	assert(truth("&(|(f))") == false);
	assert(truth("|(f,f,f,t)") == true);
	assert(truth("!(&(f,t))") == true);
	assert(truth("|(&(t,t,t,t,f,f))") == false);
	assert(truth("&(&(|(&(|(&(t,t))))))") == true);
	assert(truth("!(&(|(t,t)))") == false);

	return 0;
}
