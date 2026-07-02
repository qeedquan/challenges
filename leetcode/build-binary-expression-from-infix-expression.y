/*

A binary expression tree is a kind of binary tree used to represent arithmetic expressions. Each node of a binary expression tree has either zero or two children. Leaf nodes (nodes with 0 children) correspond to operands (numbers), and internal nodes (nodes with 2 children) correspond to the operators '+' (addition), '-' (subtraction), '*' (multiplication), and '/' (division).

For each internal node with operator o, the infix expression that it represents is (A o B), where A is the expression the left subtree represents and B is the expression the right subtree represents.

You are given a string s, an infix expression containing operands, the operators described above, and parentheses '(' and ')'.

Return the binary expression tree, which its in-order traversal reproduce s.

Please note that order of operations applies in s. That is, expressions in parentheses are evaluated first, and multiplication and division happen before addition and subtraction.

Example 1:

Input: s = "2-3/(5*2)+1"
Output: [+,-,1,2,/,null,null,null,null,3,*,null,null,5,2]

Example 2:

Input: s = "3*4-2*5"
Output: [-,*,*,3,4,2,5]

Example 3:

Input: s = "1+2+3+4+5"
Output: [+,+,5,+,4,null,null,+,3,null,null,1,2]
 

Constraints:

1 <= s.length <= 10^5
s consists of digits and the characters '+', '-', '*', '/', '(', and ')'.
Operands in s are exactly 1 digit.
It is guaranteed that s is a valid expression.

*/

%{

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

typedef struct Node Node;

struct Node {
	int t;
	int op;
	long v;
	Node *x;
	Node *y;
};

typedef struct {
	Node *b;
	size_t nb;

	const char *p;
	Node *r;
	int e;
} Line;

enum {
	LIT = 1,
	PAREN,
	UNOP,
	BINOP,
};

Node *nod(Line *, int, ...);

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
	Node *n;
	long v;
}

%left '+' '-'
%left '*' '/'

%type <n> expr
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
		$$ = nod(ln, LIT, $1); 
	}
|
	expr '+' expr
	{
		$$ = nod(ln, BINOP, '+', $1, $3);
	}
|
	expr '-' expr
	{
		$$ = nod(ln, BINOP, '-', $1, $3);
	}
|
	expr '*' expr
	{
		$$ = nod(ln, BINOP, '*', $1, $3);
	}
|
	expr '/' expr
	{
		$$ = nod(ln, BINOP, '/', $1, $3);
	}
|
	'(' expr ')'
	{
		$$ = nod(ln, PAREN, $2);
	}
|
	'+' expr
	{
		$$ = nod(ln, UNOP, '+', $2);
	}
|
	'-' expr
	{
		$$ = nod(ln, UNOP, '-', $2);
	}

%%

Node *
nod(Line *ln, int t, ...)
{
	Node *n;
	va_list ap;

	n = &ln->b[++ln->nb];
	n->t = t;

	va_start(ap, t);
	switch (t) {
	case LIT:
		n->v = va_arg(ap, long);
		break;
	case PAREN:
		n->x = va_arg(ap, Node *);
		break;
	case UNOP:
		n->op = va_arg(ap, int);
		n->x = va_arg(ap, Node *);
		break;
	case BINOP:
		n->op = va_arg(ap, int);
		n->x = va_arg(ap, Node *);
		n->y = va_arg(ap, Node *);
		break;
	}
	va_end(ap);

	return n;
}

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
yyerror(YYLTYPE *ll, Line *ln, const char *msg)
{
	ln->e = 1;

	(void) ll;
	(void) msg;
}

void
treesr(FILE *fp, Node *n)
{
	if (!n)
		return;
	
	switch (n->t) {
	case UNOP:
		fprintf(fp, "%c", n->op);
		treesr(fp, n->x);
		break;
	case BINOP:
		treesr(fp, n->x);
		fprintf(fp, "%c", n->op);
		treesr(fp, n->y);
		break;
	case PAREN:
		fprintf(fp, "(");
		treesr(fp, n->x);
		fprintf(fp, ")");
		break;
	case LIT:
		fprintf(fp, "%ld", n->v);
		break;
	default:
		assert(0);
		break;
	}
}

char *
trees(Node *r)
{
	FILE *fp;
	char *b;
	size_t n;

	fp = open_memstream(&b, &n);
	if (!fp)
		return NULL;

	treesr(fp, r);
	
	fclose(fp);
	return b;
}

Node *
parse(const char *s)
{
	Line ln;
	
	memset(&ln, 0, sizeof(ln));
	ln.p = s;
	ln.b = calloc(strlen(s) + 1, sizeof(*ln.b));
	if (!ln.b)
		goto error;
	
	if (yyparse(&ln) || ln.e)
		goto error;
	
	if (0) {
	error:
		free(ln.b);
		return NULL;
	}

	memcpy(ln.b, ln.r, sizeof(*ln.r));
	return ln.b;
}

void
test(const char *s)
{
	Node *r;
	char *b;

	r = parse(s);
	b = trees(r);
	assert(r);
	assert(b);
	
	printf("%s\n", b);
	assert(!strcmp(b, s));

	free(r);
	free(b);
}

int
main(void)
{
	test("2-3/(5*2)+1");
	test("3*4-2*5");
	test("1+2+3+4+5");
	test("-23");

	return 0;
}
