/*

Introduction
There comes a point in childhood when you think you've mastered adding and multiplying, then someone comes along and informs you that:

a * b + c = (a * b) + c != a * (b + c),

and that it wasn't as simple or linear a process as you were earlier taught. You learn that there exists something called the order of operations. This is a very important way of keeping some level of consistency and in expressions, without having parentheses getting in the way of everything.

Generic storyline
One day, you wake up to the sound of panic in the streets. An extremist group under the name "The 2560" (Short for "Organisation Against the Order of Operations", with a dorky hex-ish twist) have used their evil methods to take control over all of the nuclear weapons in the world. They are holding the whole planet hostage, and they have a simple demand: reverse the accepted order of operations or face eradication (parentheses are to maintain their priority). The new system is called PSADME (parentheses, subtraction/addition, division/multiplication, exponents), and expressions evaluate right-to-left:

a - b - c = a - (b - c) = a + c - b
Days pass, and the transition is in progress. Whilst mathematicians and physicists are all busy rewriting their equations, the computer scientists are faced with the task of changing the fashion in which mathematical expressions are interpreted by computers. You belong to a secret rebel programming group which aims to cause as much torment for the new global overlords - and, by chance, you are randomly selected by The 2560 and tasked to produce the benchmark calculation program.

Your mission
Write a program (or function) which takes a (numerical) mathematical expression as input, calculates the expression using PSADME as the order of operations and outputs the result. Expressions should evaluate right-to-left, so
1−3+4=1−7=−6.
For simplicity, all numbers provided will be integers, and the calculations will produce integer outcomes.

Rules and scoring
The program should accept input up to 128 characters in length - if your language/platform has a lower maximum input length, that is an acceptable excuse.
Standard loopholes are forbidden.
The winning code will be chosen on 18th November (4 weeks from this post date).
Feel free to post code that would not be considered golf-worthy. This is about fun. If you have an interesting way of doing this but can't golf it yourself (or by the nature of your method), you can post it anyway.
As per usual, the winning code is the one with least number of bytes, with some entertainment-value bonuses:

-5 for avoiding any use of the characters in the provided expression: +,-,(,),^,*,/
-5 for making the calculations take more than 5 minutes (but no more than 10 minutes) to calculate on a standard computer, without the method being obvious (using the clock or unnecessary loops); The aim is to convince the new overlords that you are not trying to disrupt their calculations of doom.
-(5+N) for a direct offensive message (of length N, not including leading/trailing whitespace) about the members of The 2560 to be written in plain sight within your code, with some ridiculous explanation as to why it needs to be there. If it is removed, the code must not function correctly. Yes, free points for entertainment value.

Examples and explanations
[program] 2 - 2 - 2
2
2 - (2 - 2) = 2

[program] (2 + 2 * 3 + 3) / 3 + 3
4
(4 * 6)/(3 + 3) = 4

[program] 3 + 2 + 1 ^ 3
216
(3 + 2 + 1)^3 = 216

[program] -5^2
25
(-5)^2 = 25

[program] 32 / 8 * 3 - 1
2
32 / (8 * (3 - 1)) = 32 / 16 = 2

*/

%{

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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

%right '^'
%right '*' '/'
%right '+' '-'
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
	expr '+' expr
	{
		$$ = $1 + $3;
	}
|
	expr '-' expr
	{
		$$ = $1 - $3;
	}
|
	expr '*' expr
	{
		$$ = $1 * $3;
	}
|
	expr '/' expr
	{
		$$ = 0;
		if ($3 != 0)
			$$ = $1 / $3;
	}
|
	expr '^' expr
	{
		$$ = pow($1, $3);
	}
|
	'(' expr ')'
	{
		$$ = $2;
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

%%

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
	assert(eval("1 - 3 + 4") == -6);
	assert(eval("2 - 2 - 2") == 2);
	assert(eval("(2 + 2 * 3 + 3) / 3 + 3") == 4);
	assert(eval("3 + 2 + 1 ^ 3") == 216);
	assert(eval("-5 ^ 2") == 25);
	assert(eval("32 / 8 * 3 - 1") == 2);

	return 0;
}
