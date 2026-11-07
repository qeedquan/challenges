/*

You are given a string s that contains digits 0-9, addition symbols '+', and multiplication symbols '*' only, representing a valid math expression of single digit numbers (e.g., 3+5*2). This expression was given to n elementary school students. The students were instructed to get the answer of the expression by following this order of operations:

Compute multiplication, reading from left to right; Then,
Compute addition, reading from left to right.
You are given an integer array answers of length n, which are the submitted answers of the students in no particular order. You are asked to grade the answers, by following these rules:

If an answer equals the correct answer of the expression, this student will be rewarded 5 points;
Otherwise, if the answer could be interpreted as if the student applied the operators in the wrong order but had correct arithmetic, this student will be rewarded 2 points;
Otherwise, this student will be rewarded 0 points.
Return the sum of the points of the students.

Example 1:

https://assets.leetcode.com/uploads/2021/09/17/student_solving_math.png

Input: s = "7+3*1*2", answers = [20,13,42]
Output: 7
Explanation: As illustrated above, the correct answer of the expression is 13, therefore one student is rewarded 5 points: [20,13,42]
A student might have applied the operators in this wrong order: ((7+3)*1)*2 = 20. Therefore one student is rewarded 2 points: [20,13,42]
The points for the students are: [2,5,0]. The sum of the points is 2+5+0=7.
Example 2:

Input: s = "3+5*2", answers = [13,0,10,13,13,16,16]
Output: 19
Explanation: The correct answer of the expression is 13, therefore three students are rewarded 5 points each: [13,0,10,13,13,16,16]
A student might have applied the operators in this wrong order: ((3+5)*2 = 16. Therefore two students are rewarded 2 points: [13,0,10,13,13,16,16]
The points for the students are: [5,0,0,5,5,2,2]. The sum of the points is 5+0+0+5+5+2+2=19.
Example 3:

Input: s = "6+0*1", answers = [12,9,6,4,8,6]
Output: 10
Explanation: The correct answer of the expression is 6.
If a student had incorrectly done (6+0)*1, the answer would also be 6.
By the rules of grading, the students will still be rewarded 5 points (as they got the correct answer), not 2 points.
The points for the students are: [0,0,5,0,0,5]. The sum of the points is 10.


Constraints:

3 <= s.length <= 31
s represents a valid expression that contains only digits 0-9, '+', and '*' only.
All the integer operands in the expression are in the inclusive range [0, 9].
1 <= The count of all operators ('+' and '*') in the math expression <= 15
Test data are generated such that the correct answer of the expression is in the range of [0, 1000].
Test data are generated such that value never exceeds 109 in intermediate steps of multiplication.
n == answers.length
1 <= n <= 10^4
0 <= answers[i] <= 1000

*/

%{

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	const char *p;
	int lp;
	int lm;
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

%left LP1
%left LM1
%left LM2
%left LP2

%type <v> expr
%token <v> LNUM LP1 LP2 LM1 LM2

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
	expr LP1 expr
	{
		$$ = $1 + $3;
	}
|
	expr LP2 expr
	{
		$$ = $1 + $3;
	}
|
	expr LM1 expr
	{
		$$ = $1 * $3;
	}
|
	expr LM2 expr
	{
		$$ = $1 * $3;
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
		break;
	case '+':
		t = ln->lp;
		break;
	case '*':
		t = ln->lm;
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
score(const char *s, long *a, size_t n)
{
	Line ln1 = { s, LP1, LM1, 0, 0 };
	Line ln2 = { s, LP2, LM2, 0, 0 };
	
	size_t i;
	long r;

	if (yyparse(&ln1) || ln1.e)
		return -1;
	if (yyparse(&ln2) || ln2.e)
		return -1;

	r = 0;
	for (i = 0; i < n; i++) {
		if (a[i] == ln1.r)
			r += 5;
		else if (a[i] == ln2.r)
			r += 2;
	}
	return r;
}

int
main(void)
{
	long a1[] = { 20, 13, 42 };
	long a2[] = { 13, 0, 10, 13, 13, 16, 16 };
	long a3[] = { 12, 9, 6, 4, 8, 6 };

	assert(score("7+3*1*2", a1, nelem(a1)) == 7);
	assert(score("3+5*2", a2, nelem(a2)) == 19);
	assert(score("6+0*1", a3, nelem(a3)) == 10);

	return 0;
}
