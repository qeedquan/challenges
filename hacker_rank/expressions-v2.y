/*

Once Kazama had written a basic calculator, he read further about other operators and operator precedence. Now he is writing a new calculator with following details:

Binary addition: x + y
Binary subtraction: x - y
Multiplication: x * y
Division: x / y
Unary operators: + and -
Brackets: (...)

Operator precedence

(unary operators, brackets) > (multiplication, division) > (binary addition, binary subtraction)

Associativity
Now all operators are right associative.
That is
p - q - r = p - (q - r)
p / q / r = p / (q / r)

Formally it has following grammar:

 Expression ::= Term [+-] Expression
              | Term

 Term       ::= Factor [* /] Term
              | Factor

 Factor     ::= Number
              | [+-] Factor
              | '(' Expression ')'


He needs your help to verify it.
He wants you to solve some expressions for him using the above grammar and he will cross check the results.
Since you are also lazy, you will write another computer program which will solve the expressions.
Since the output value can be too large, you have to tell output modulo 10^9 + 7.


Note:
10^9 + 7 is a prime.
1/b = b^-1 = b^(p-2) (mod p) where p is prime and b < p

Input Format

Input will contain a valid expression.

Constraints

Length of expression will not exceed 10^5.
1 <= number <= 10^9
There can be 0 or more whitespaces between operators/operands.
Tests are designed such that there will be no divide by zero case.
Each factor will be accompanied by at-most one unary operator. That is "-+-4" is an invalid case.

Output Format

Print the result of expression modulo 10^9 + 7

Sample Input 0
22 * 79 - 21
Sample Output 0
1717

Sample Input 1
4/-2/2 + 8
Sample Output 1
4

Sample Input 2
55+3-45*33-25
Sample Output 2
999998605

Sample Input 3
4/-2/(2 + 8)
Sample Output 3
999999987

*/

%{

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
	const char *p;
	long r;
	long m;
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
	
	long modadd(long, long, long);
	long modsub(long, long, long);
	long modmul(long, long, long);
	long moddiv(long, long, long);
	long modexp(long, long, long);
}

%union
{
	long v;
}

%right '+' '-'
%right '*' '/'
%precedence UPLUS UMINUS

%type <v> expr
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
		$$ = $1;
	}
|
	'-' expr %prec UMINUS
	{
		$$ = -$2;
	}
|
	'+' expr %prec UPLUS
	{
		$$ = $2;
	}
|
	expr '+' expr
	{
		$$ = modadd($1, $3, ln->m);
	}
|
	expr '-' expr
	{
		$$ = modsub($1, $3, ln->m);
	}
|
	expr '*' expr
	{
		$$ = modmul($1, $3, ln->m);
	}
|
	expr '/' expr
	{
		$$ = moddiv($1, $3, ln->m);
	}
|
	'(' expr ')'
	{
		$$ = $2;
	}
%%

long
mod(long x, long m)
{
	x %= m;
	if (x < 0)
		x += m;
	return x;
}

long
modadd(long a, long b, long m)
{
	return mod(mod(a, m) + mod(b, m), m);
}

long
modsub(long a, long b, long m)
{
	return mod(mod(a, m) - mod(b, m), m);
}

long
modmul(long a, long b, long m)
{
	return mod(mod(a, m) * mod(b, m), m);
}

long
moddiv(long a, long b, long m)
{
	return modmul(a, modexp(b, m - 2, m), m);
}

long
modexp(long a, long b, long p)
{
	long r;

	if (p == 0)
		return 0;

	r = 1;
	a %= p;
	if (a == 0)
		return 0;

	while (b > 0) {
		if (b & 1)
			r = (r * a) % p;

		b >>= 1;
		a = (a * a) % p;
	}
	return r;
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
yyerror(YYLTYPE *, Line *ln, const char *)
{
	ln->e = 1;
}

long
eval(const char *s)
{
	Line ln = { s, 0, 1000000007, 0 };
	if (yyparse(&ln) || ln.e)
		return 0;
	return ln.r;
}

int
main()
{
	assert(eval("22 * 79 - 21") == 1717);
	assert(eval("4/-2/2 + 8") == 4);
	assert(eval("55+3-45*33-25") == 999998605);
	assert(eval("4/-2/(2 + 8)") == 999999987);

	return 0;
}
