/*

AAAAAAAAAAAA!!!!, which is 14 A's and 4 exclamation marks, is a procedural esoteric programming with no implementations yet created by User:Zzo38 first appeared in 2006. As the language name suggests, the program syntax consists of lots of A's and exclamation marks. Today you are parsing subset of some expressions in the language.

Task
Given a string of input, parse as an AAAAAAAAAAAAAA!!!! expression. Then return its numeral value. Your program input shall follow the syntax of the expression, which is defined below.

The AAAAAAAAAAAAAA!!!! language treats only nonnegative integers as its data type.

You only need to parse expressions whose value is up to 255.

Input format: AAAAAAAAAAAAAA!!!! expressions to parse on this task
In this task you have to parse four literals and five operators1.

The syntax of an expression is2:

Input := Expression
Expression := Constant | BinaryOpExpr
Constant := Zero | One | Two | Three
BinaryOpExpr := BinaryOp FollowingTwoOperands
BinaryOp := Sum | Diff | Prod | And | Xor
FollowingTwoOperands := Space TwoOperands
TwoOperands := Expression FollowingOneOperand
FollowingOneOperand := Space Expression
Zero := "AAAA"
One := "AAA"
Two := "A"
Three := "AA A"
Sum := "AA A,"
Diff := "AA AA,"
Prod := "AAA,"
And := "AA AAA,"
Xor := "AAAA,"
Space := " "
Semantics
In the syntax above, Zero, One, Two and Three are such integer values.

The Sum operator takes two Expression-s to get its sum.

The Diff operator takes two Expression-s to get absolute value of its difference.

The Prod operator takes two Expression-s to get its production.

The And operator takes two Expression-s to get its bitwise AND. For example 132 (which is 0b1000_0100) AND 15 (which is 0b0000_1111 is 4 (0b0000_0100).

The Xor operator gets bitwise XOR of two Expression-s. For example 132 XOR 15 is 139b(0b1000_1011).

Test case generator in Bash, 2387 bytes
#!/bin/sh

# Usage: $0 [items [seed]]

set -eu
umask 0022
export LC_ALL=C UNIX_STD=2003 POSIXLY_CORRECT=1
if p="$(command -p getconf PATH 2>/dev/null)";then PATH="$p${PATH+:}${PATH:-}"
fi

# params
headN=${1:-20}
seed=${2-}

# Generate expressions and its value
awk -v seed="$seed" 'BEGIN{
  srand('"${seed:+seed+1}"');

  for (i=256;i--;) sn[i]=1; # values who can be outputted

  for (i=4;i--;) {
    s0[i] = i; # expressions to output
  }
  split("",s1,":"); # expressions to have outputted

  opr["Sum"]; opr["Prod"];
  opr["Xor"];
  opr["Diff"]; opr["And"];

  sn[0] = 3;

  for(i=10;i--;) {
    OutputS0();
    UpdateS0();
  }
}
function OutputS0( s){
  for ( s in s0 ) {
    if ( sn[s0[s]] < -2 ) continue;
    print s0[s], s;
    sn[s0[s]]--;
    s1[s] = s0[s];
  }
}
function UpdateS0( a,b,o,z,av,bv){
  split("",s0,":");
  for ( a in s1 ) {
    for ( b in s1 ) {
      for ( o in opr ) {
        av = s1[a]; bv = s1[b];
        z = o OFS a OFS b;
        if ( z in s1 ) continue;
        av = Calc(o,av,bv);
        if ( av > 255 ) continue;
        if ( sn[av] <= 0 ) continue;
        z = OptionallyWithZero(z);
        s0[z] = av;
      }
    }
  }
}
function Calc(o,a,b) {
  # Sum Diff Prod And Xor
  return o~/X/?Xor(a,b):o~/n/?And(a,b):o~/P/?a*b:o~/D/?a>b?a-b:b-a:a+b;
}
function OptionallyWithZero(v ,z,t) {
  z[0] = "Sum "; z[1] = "Diff "; z[2] = "Xor ";
  return rand()>=0.2?v:(t=z[int(rand()*3)])?rand()>=0.5?t genZero() OFS v:t v OFS genZero():0;
}
function genZero( x) {
  for ( x in s1 ) if ( s1[x] == 0 ) return x;
}
function And(x,y){return x?(x%2)*(y%2)+2*And(int(x/2),int(y/2)):0}
function Xor(x,y){return x?((x%2)+(y%2))%2+2*Xor(int(x/2),int(y/2)):y}

' |
#
# 1 value
# 2/NF expression
#
# Shuffle its order
awk -v seed="$seed" -v bufsz=128 '
BEGIN {
  srand('"${seed:+seed}"');
}
{
  v = int(rand()*bufsz);
  if ( v in buf ) {
    if ( rand()<0.5 ) {
      print $0;
      next;
    }
    print buf[v];
  }
  buf[v] = $0;
}
END {
  for ( v in buf ) print buf[v];
}
' |
head -n "$headN" |
sort -n |
sed 's/^\([0-9]*\) \(.*\)$/\2 => \1/' |
#
# Now convert to AAAA language
awk 'BEGIN {
  a[0] = "AAAA";
  a[1] = "AAA";
  a[2] = "A";
  a[3] = "AA A";
  a["Sum"] = "AA A,";
  a["Diff"] = "AA AA,";
  a["Prod"] = "AAA,";
  a["And"] = "AA AAA,";
  a["Xor"] = "AAAA,";
}
{
   r = "";
   for ( i = 1; i <= NF-2; i++ )
      r = r a[$i] OFS;
   print r, "=>", $NF;
}'
Try it online!

Test cases
The format is:

Input => Output
Here are some test cases:

AAAA => 0
AA AA, AAAA AA AAA, AAAA AAA => 0
A => 2
AA A => 3
AA A, AAA AA A => 4
AA A, AA A AAA => 4
AAAA, AA A, AA A AA A AAAA => 6
AA AA, AAAA, AAA AAAA, AAA, AA A A AAAA AA AA, AAAA AA AAA, AAAA AAA => 7
AAAA, AA A AA A, AAA AA A => 7
AAA, A AA A, AA A AAA => 8
AA A, AA A, AAA AA A AA A, A A => 8
AA A, AAAA, AAA, AA A A AAAA A => 8
AAA, AA A AA A => 9
AA A, AAA, A AA A AAA, A A => 10
AA A, AAAA, AAA, AA A A AAAA AA A, AAA AA A => 10
AA A, AAAA, AA A, AA A AA A AAAA AA A, AA A AAA => 10
AA A, A AAA, AA A AA A => 11
AA A, AA A, AA A A AAA, A AA A => 11
AAA, A AAAA, AA A, AA A AA A AAAA => 12
AA A, AAAA, AAA, AA A A AAAA AAAA, AA A, AA A AA A AAAA => 12
AAAA, AA AA, AAAA AA AAA, AAAA AAA AA A, AAA, A AA A AAA, A AA A => 12
AAAA, AA A, AAA AA A AAA, AA A AA A => 13
AA A, AAA, AA A AA A AA A, AA A A => 14
AAA, AA A AA A, AA A A => 15
AAA, AA A, AAA AA A AAA, A A => 16
AAAA, AAA, AA A, A A AA A, AAA AA A AA AA, AAAA AA AAA, AAAA AAA => 16
AAAA, AAAA, AAAA AAA, AAAA AAA AA A, AA A, AAAA, AAA, AA A A AAAA AAAA, AA A, AA A AA A AAAA AA A, A AA A => 17
AAA, AA A AAA, A AA A => 18
AAA, AA A AAAA, AAA, AA A A AAAA => 18
AAA, AAA, AA A AA A A => 18
AA AA, AA A, AAAA, AA A, AA A AA A AAAA AA A, AA A A AAA, AA A, A AA A AAAA, AAA, AA A A AAAA => 19
AAA, AAA, A A AA A, A AA A => 20
AAA, AA A, A A AA A, A AA A => 20
AAAA, AAA, AA A, AA A A AAAA, AAA, AA A A AAAA AA A, A AAA, AA A AA A => 21
AAAA, AA A, AA A A AAAA, AAA, AA A, A A AA A, AAA AA A AA AA, AAAA AA AAA, AAAA AAA => 21
AAAA, AAAA, AA A, AA A AA A AAAA AAA, AA A, AAA AA A AAA, A A => 22
AAA, AAA, A AA A AA A, AAA AA A => 24
AAA, AA A, AAA AA A AAA, A AA A => 24
AAA, AA A, A A AAAA, AA A, AA A AA A AAAA => 24
AA A, AA AA, AAAA AA AAA, AAAA AAA AAA, AAAA, AA A, AA A AA A AAAA AA A, AA A AAA => 24
AAA, AA A, A AA A AA A, AA A A => 25
AA A, AAA, AA A, AA A A AA A, AA A A AA AA, AAAA AA AAA, AAAA AAA => 25
AA AA, AAAA, AAAA AAA, AAAA AAA AA AA, AA AA, AAA, AAA, A AA A AAA, A AA A AA AA, AAAA AA AAA, AAAA AAA AA A, AAA, A AA A AAA, A A => 26
AA A, AAAA, AAA, A A AAA, AA A AA A AAAA, AA A, AAA AA A AAA, AA A AA A => 26
AA A, AAAA, AA A, AAA AA A AAA, AA A AA A AAAA, AAA, A A AAA, AA A AA A => 26
AA A, AA A, AAAA, AAA, AA A A AAAA A AAA, AA A, A A AA A, A AA A => 28
AAA, AA A, A AA A AAAA, AAA, AA A A AAAA => 30
AAA, AA A, A AA A AAAA, AA A, AA A AA A AAAA => 30
AAA, AA A, AA A A AAAA, AAA, AA A A AAAA => 30
AA A, AAAA, AAAA AAA, AAAA AAA AA AA, AA A, A AA A AA AA, AAA, AAA, A AA A AAA, A AA A AA AA, AAAA AA AAA, AAAA AAA => 31
AA A, AAA, AA A, A AA A AA A, A A AA A, AAAA, AAA, AA A A AAAA AAAA, AA A, AA A AA A AAAA => 32
AA A, AA A, AA A AAA, A A AAA, AA A, A AA A AA A, A AA A => 32
AA A, AAA, A AA A, AA A AAA AA A, AAA, AA A, AA A A AA A, AA A A AA AA, AAAA AA AAA, AAAA AAA => 33
AA A, AAAA, AA A, AAA AA A AAA, AA A AA A AAA, AA A, A A AA A, A AA A => 33
AAAA, AAAA, AA A AA A, AAA AA A AA AA, AAA, AAA, A AA A AAA, A AA A AA AA, AAAA AA AAA, AAAA AAA => 35
AAA, AAA, AA A AA A AAA, A A => 36
AA AA, AA A, AA A, AAA, A A AAA, AA A AA A AA A, AA AA, AAAA AA AAA, AAAA AAA AAA, AAAA, AA A, AA A AA A AAAA AA A, AA A AAA AAAA, AAAA AAA, AAAA AAA => 37
AA A, AAA, AA A, AAA AA A AAA, A AA A AAAA, AA A, AAA AA A AAA, AA A AA A => 37
AAAA, AAAA, AAA, AAA, AA A AA A AAA, A A AAA AAAA, AAAA AAA, AAAA AAA => 37
AA AA, AA AA, AA AA, AAAA AA AAA, AAAA AAA AAA, AAA, AA A AA A AAAA, AAA, AA A A AAAA AAAA, AAA, AA A, A A AA A, AAA AA A AA AA, AAAA AA AAA, AAAA AAA => 38
AA A, AAAA, AAA, AA A, AA A AAA AA A, A AA A AA AA, AAAA AA AAA, AAAA AAA AAA, AA A AAAA, AAA, AA A A AAAA => 38
AA A, AAA, AA A, A A AAAA, AA A, AA A AA A AAAA AAAA, AAAA, AAA, AA A A AAAA AAA, AA A AA A => 39
AA A, AAAA, AAAA AAA, AAAA AAA AA AA, AA A, AAA, AA A AA A AAAA, AA A, AA A AA A AAAA AAA, AAA, AA A AA A AAA, A AA A => 39
AA AA, AAAA, AAAA AAA, AAAA AAA AA A, AAA, AA A, A AA A AAAA, AAA, AA A A AAAA AA A, AAA, A AA A AAA, A A => 40
AA AA, AA A, AAA, AA A, AA A A AAAA, AAA, AA A A AAAA AA A, AAAA, AAA, AA A A AAAA AAAA, AA A, AA A AA A AAAA AAAA, AAAA AAA, AAAA AAA => 42
AAAA, AA A, AA A, AA A A AAA, AA A AA A AA AA, AAA, AAA, A AA A AAA, A AA A AA AA, AAAA AA AAA, AAAA AAA => 42
AA A, AA AA, AAA, AAA, A AA A AAA, A AA A AA AA, AAAA AA AAA, AAAA AAA AAAA, AA A AA A, AAA AA A => 43
AA A, AAA, AA A AAAA, AAA, AA A A AAAA AAA, AA A, A AA A AA A, A AA A => 43
AAAA, AAA, A AA A, AA A AAA AA AA, AAA, AAA, A AA A AAA, A AA A AA AA, AAAA AA AAA, AAAA AAA => 44
AAAA, AAA, AAA, AA A AA A AAA, A A AAA, A AA A, AA A AAA => 44
AAA, AA A, A AA A AAA, AA A AA A => 45
AAA, AA A, AA A A AAA, AA A AA A => 45
AAA, AAAA, AA AA, AAAA AA AAA, AAAA AAA AA A, AAA, A AA A AAA, A AA A AAA, A A => 48
AAA, AAAA, AA AA, AAAA AA AAA, AAAA AAA AA A, AAA, A AA A AAA, A AA A AA A, AA A AAA => 48
AA A, AAA, AA A, AA A A AAA, AA A AA A AA A, A A => 49
AAAA, AA A, AA A, AA A A AAA, AA A, A AA A AAA, AA A AA A AAAA, AAAA AAA, AAAA AAA => 50
AAA, AA A, AAA AA A AAAA, AA A, AAA AA A AAA, AA A AA A => 52
AAA, AAA, AA A AA A AAA, A AA A => 54
AAA, AAA, AA A AA A AAAA, AA A, AA A AA A AAAA => 54
AAA, AA A, AA A AAA AA A, AA A, A AA A AAA, AA A AA A => 56
AAAA, AAAA, AAAA AAA, AAAA AAA AA A, AAA, AA A, AA A A AAA, AA A AA A AA A, AAAA, AAA, AA A A AAAA AA A, A AA A => 56
AAAA, AAAA, AAA, AA A, AA A AAA AA A, A AA A AA AA, AAAA AA AAA, AAAA AAA AAA, AAA, AA A AA A AA A, AA A A => 57
AA A, AA A, AA A, A AA A AAA, AA A AA A AAA, AAA, AA A AA A AA A, AA A A => 59
AAAA, AAA, AAAA, AAA, AA A A AAAA AAA, AA A AA A AA A, AAAA, AAA, AA A A AAAA AA A, A AA A => 61
AA A, AAAA, AA A, AAA AA A AAA, AA A AA A AA AA, AA AA, AAAA AA AAA, AAAA AAA AAA, AAA, AA A AA A AAAA, AAA, AA A A AAAA => 67
AAA, AAA, AA A AA A AAA, AA A AA A => 81
AAA, AAA, A AA A AA A, AAA, AA A AA A AAAA, AA A, AA A AA A AAAA => 90
AAAA, AAAA, AAAA AAA, AAAA AAA AAA, AA A, AAAA, AAA, AA A A AAAA AAA, AA A AA A AA A, AA A, AA A A A => 105
AAA, AAA, AAA, AA A AA A AA A AA A, AA A AAA => 108
AAA, AAAA, AA A, AA A AA A AAAA AAA, AAA, AA A AA A A => 108
AA A, AA AA, AAA, AAAA, AA A, AA A AA A AAAA AAAA, AAA, AA A A AAAA AA AA, AAAA AA AAA, AAAA AAA AAA, AAA, AA A AA A AAA, AA A AA A => 117
AAA, AA A, A AAAA, AAA, AA A A AAAA AAAA, AAAA, AAA, AA A A AAAA AAA, AA A AA A => 120
AAA, AAAA, AAA, AA A, AA A AAA AA A, A AA A AA AA, AAAA AA AAA, AAAA AAA AAA, A AA A => 120
AAA, AA A, AAAA, AA A, AA A AA A AAAA AA A, AA A A AA A, AAAA, AAA, AA A A AAAA AAAA, AA A, AA A AA A AAAA => 132
AAA, AAA, AAA, AA A AA A AA A AA A, AA A A => 135
AA AA, AAAA, AAAA AAA, AAAA AAA AAA, AA A, AA A, AA A A AAA, AA A AA A AAAA, AA AA, AAAA AA AAA, AAAA AAA AAA, A AA A, AA A A => 140
AAAA, AAAA, AAAA AAA, AAAA AAA AAA, AAA, A AAAA, AA A, AA A AA A AAAA AA A, AAAA, AAA, AA A A AAAA AAAA, AA A, AA A AA A AAAA => 144
AAAA, AAA, AAA, AA A, AAA AA A AAA, A A AAAA, AA AA, AAAA AA AAA, AAAA AAA AAA, A AA A, AA A A AAAA, AAAA AAA, AAAA AAA => 160
AA AA, AAAA, AAAA AAA, AAAA AAA AAA, AA A, AAAA, AAA, AA A A AAAA AAAA, AA A, AA A AA A AAAA AA A, AAA, AA A AA A AAAA, AA A, AA A AA A AAAA => 180
AA A, AAAA, AAAA AAA, AAAA AAA AAA, AA A, AAA, A A AAA, AA A AA A AAA, AA A, A A AA A, A A => 208
Rules
code-golf
Standard loopholes
Standard I/O
Footnotes
The AAAAAAAAAAAA!!!! has three more operands and three more operators who do something with control flows.
The article says as if there must not be a leading space and there must be a trailing space for comma token, but since the syntax is unambiguous I think leading and trailing spaces for the comma token is optional.

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

	long binop(long, long, long);
}

%union
{
	long v;
}

%type <v> expr con binop
%type <v> sum diff prod and xor
%type <v> zero one two three

%%

top:
	expr
	{
		ln->r = $1;
	}

expr:
	con
|
	binop ' ' expr ' ' expr
	{
		$$ = binop($1, $3, $5);
	}

binop:
	sum | diff | prod | and | xor

con:
	zero | one | two | three

sum:
	'A' 'A' ' ' 'A' ','
	{
		$$ = '+';
	}

diff:
	'A' 'A' ' ' 'A' 'A' ','
	{
		$$ = '-';
	}

prod:
	'A' 'A' 'A' ','
	{
		$$ = '*';
	}

and:
	'A' 'A' ' ' 'A' 'A' 'A' ','
	{
		$$ = '&';
	}

xor:
	'A' 'A' 'A' 'A' ','
	{
		$$ = '^';
	}

zero:
	'A' 'A' 'A' 'A'
	{
		$$ = 0;
	}

one:
	'A' 'A' 'A'
	{
		$$ = 1;
	}

two:
	'A'
	{
		$$ = 2;
	}

three:
	'A' 'A' ' ' 'A'
	{
		$$ = 3;
	}

%%

long
binop(long op, long a, long b)
{
	switch (op) {
	case '+':
		return a + b;
	case '-':
		return labs(a - b);
	case '*':
		return a * b;
	case '&':
		return a & b;
	case '^':
		return a ^ b;
	}
	return 0;
}

int
yylex(YYSTYPE *, YYLTYPE *ll, Line *ln)
{
	int t;

	t = 0;
	switch (ln->p[0]) {
	case '\0':
	case 'A':
	case ',':
	case ' ':
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
	Line ln = { s, 0, 0 };
	if (yyparse(&ln) || ln.e)
		return -1;
	return ln.r;
}

void
test(const char *s, long r)
{
	long v;

	v = eval(s);
	printf("'%s' -> %ld %ld\n", s, v, r);
	assert(v == r);
}

int
main()
{
	test("AAAA", 0);
	test("AA AA, AAAA AA AAA, AAAA AAA", 0);
	test("A", 2);
	test("AA A", 3);
	test("AA A, AAA AA A", 4);
	test("AA A, AA A AAA", 4);
	test("AAAA, AA A, AA A AA A AAAA", 6);
	test("AA AA, AAAA, AAA AAAA, AAA, AA A A AAAA AA AA, AAAA AA AAA, AAAA AAA", 7);
	test("AAAA, AA A AA A, AAA AA A", 7);
	test("AAA, A AA A, AA A AAA", 8);
	test("AA A, AA A, AAA AA A AA A, A A", 8);
	test("AA A, AAAA, AAA, AA A A AAAA A", 8);
	test("AAA, AA A AA A", 9);
	test("AA A, AAA, A AA A AAA, A A", 10);
	test("AA A, AAAA, AAA, AA A A AAAA AA A, AAA AA A", 10);
	test("AA A, AAAA, AA A, AA A AA A AAAA AA A, AA A AAA", 10);
	test("AA A, A AAA, AA A AA A", 11);
	test("AA A, AA A, AA A A AAA, A AA A", 11);
	test("AAA, A AAAA, AA A, AA A AA A AAAA", 12);
	test("AA A, AAAA, AAA, AA A A AAAA AAAA, AA A, AA A AA A AAAA", 12);
	test("AAAA, AA AA, AAAA AA AAA, AAAA AAA AA A, AAA, A AA A AAA, A AA A", 12);
	test("AAAA, AA A, AAA AA A AAA, AA A AA A", 13);
	test("AA A, AAA, AA A AA A AA A, AA A A", 14);
	test("AAA, AA A AA A, AA A A", 15);
	test("AAA, AA A, AAA AA A AAA, A A", 16);
	test("AAAA, AAA, AA A, A A AA A, AAA AA A AA AA, AAAA AA AAA, AAAA AAA", 16);
	test("AAAA, AAAA, AAAA AAA, AAAA AAA AA A, AA A, AAAA, AAA, AA A A AAAA AAAA, AA A, AA A AA A AAAA AA A, A AA A", 17);
	test("AAA, AA A AAA, A AA A", 18);
	test("AAA, AA A AAAA, AAA, AA A A AAAA", 18);
	test("AAA, AAA, AA A AA A A", 18);
	test("AA AA, AA A, AAAA, AA A, AA A AA A AAAA AA A, AA A A AAA, AA A, A AA A AAAA, AAA, AA A A AAAA", 19);
	test("AAA, AAA, A A AA A, A AA A", 20);
	test("AAA, AA A, A A AA A, A AA A", 20);
	test("AAAA, AAA, AA A, AA A A AAAA, AAA, AA A A AAAA AA A, A AAA, AA A AA A", 21);
	test("AAAA, AA A, AA A A AAAA, AAA, AA A, A A AA A, AAA AA A AA AA, AAAA AA AAA, AAAA AAA", 21);
	test("AAAA, AAAA, AA A, AA A AA A AAAA AAA, AA A, AAA AA A AAA, A A", 22);
	test("AAA, AAA, A AA A AA A, AAA AA A", 24);
	test("AAA, AA A, AAA AA A AAA, A AA A", 24);
	test("AAA, AA A, A A AAAA, AA A, AA A AA A AAAA", 24);
	test("AA A, AA AA, AAAA AA AAA, AAAA AAA AAA, AAAA, AA A, AA A AA A AAAA AA A, AA A AAA", 24);
	test("AAA, AA A, A AA A AA A, AA A A", 25);
	test("AA A, AAA, AA A, AA A A AA A, AA A A AA AA, AAAA AA AAA, AAAA AAA", 25);
	test("AA AA, AAAA, AAAA AAA, AAAA AAA AA AA, AA AA, AAA, AAA, A AA A AAA, A AA A AA AA, AAAA AA AAA, AAAA AAA AA A, AAA, A AA A AAA, A A", 26);
	test("AA A, AAAA, AAA, A A AAA, AA A AA A AAAA, AA A, AAA AA A AAA, AA A AA A", 26);
	test("AA A, AAAA, AA A, AAA AA A AAA, AA A AA A AAAA, AAA, A A AAA, AA A AA A", 26);
	test("AA A, AA A, AAAA, AAA, AA A A AAAA A AAA, AA A, A A AA A, A AA A", 28);
	test("AAA, AA A, A AA A AAAA, AAA, AA A A AAAA", 30);
	test("AAA, AA A, A AA A AAAA, AA A, AA A AA A AAAA", 30);
	test("AAA, AA A, AA A A AAAA, AAA, AA A A AAAA", 30);
	test("AA A, AAAA, AAAA AAA, AAAA AAA AA AA, AA A, A AA A AA AA, AAA, AAA, A AA A AAA, A AA A AA AA, AAAA AA AAA, AAAA AAA", 31);
	test("AA A, AAA, AA A, A AA A AA A, A A AA A, AAAA, AAA, AA A A AAAA AAAA, AA A, AA A AA A AAAA", 32);
	test("AA A, AA A, AA A AAA, A A AAA, AA A, A AA A AA A, A AA A", 32);
	test("AA A, AAA, A AA A, AA A AAA AA A, AAA, AA A, AA A A AA A, AA A A AA AA, AAAA AA AAA, AAAA AAA", 33);
	test("AA A, AAAA, AA A, AAA AA A AAA, AA A AA A AAA, AA A, A A AA A, A AA A", 33);
	test("AAAA, AAAA, AA A AA A, AAA AA A AA AA, AAA, AAA, A AA A AAA, A AA A AA AA, AAAA AA AAA, AAAA AAA", 35);
	test("AAA, AAA, AA A AA A AAA, A A", 36);
	test("AA AA, AA A, AA A, AAA, A A AAA, AA A AA A AA A, AA AA, AAAA AA AAA, AAAA AAA AAA, AAAA, AA A, AA A AA A AAAA AA A, AA A AAA AAAA, AAAA AAA, AAAA AAA", 37);
	test("AA A, AAA, AA A, AAA AA A AAA, A AA A AAAA, AA A, AAA AA A AAA, AA A AA A", 37);
	test("AAAA, AAAA, AAA, AAA, AA A AA A AAA, A A AAA AAAA, AAAA AAA, AAAA AAA", 37);
	test("AA AA, AA AA, AA AA, AAAA AA AAA, AAAA AAA AAA, AAA, AA A AA A AAAA, AAA, AA A A AAAA AAAA, AAA, AA A, A A AA A, AAA AA A AA AA, AAAA AA AAA, AAAA AAA", 38);
	test("AA A, AAAA, AAA, AA A, AA A AAA AA A, A AA A AA AA, AAAA AA AAA, AAAA AAA AAA, AA A AAAA, AAA, AA A A AAAA", 38);
	test("AA A, AAA, AA A, A A AAAA, AA A, AA A AA A AAAA AAAA, AAAA, AAA, AA A A AAAA AAA, AA A AA A", 39);
	test("AA A, AAAA, AAAA AAA, AAAA AAA AA AA, AA A, AAA, AA A AA A AAAA, AA A, AA A AA A AAAA AAA, AAA, AA A AA A AAA, A AA A", 39);
	test("AA AA, AAAA, AAAA AAA, AAAA AAA AA A, AAA, AA A, A AA A AAAA, AAA, AA A A AAAA AA A, AAA, A AA A AAA, A A", 40);
	test("AA AA, AA A, AAA, AA A, AA A A AAAA, AAA, AA A A AAAA AA A, AAAA, AAA, AA A A AAAA AAAA, AA A, AA A AA A AAAA AAAA, AAAA AAA, AAAA AAA", 42);
	test("AAAA, AA A, AA A, AA A A AAA, AA A AA A AA AA, AAA, AAA, A AA A AAA, A AA A AA AA, AAAA AA AAA, AAAA AAA", 42);
	test("AA A, AA AA, AAA, AAA, A AA A AAA, A AA A AA AA, AAAA AA AAA, AAAA AAA AAAA, AA A AA A, AAA AA A", 43);
	test("AA A, AAA, AA A AAAA, AAA, AA A A AAAA AAA, AA A, A AA A AA A, A AA A", 43);
	test("AAAA, AAA, A AA A, AA A AAA AA AA, AAA, AAA, A AA A AAA, A AA A AA AA, AAAA AA AAA, AAAA AAA", 44);
	test("AAAA, AAA, AAA, AA A AA A AAA, A A AAA, A AA A, AA A AAA", 44);
	test("AAA, AA A, A AA A AAA, AA A AA A", 45);
	test("AAA, AA A, AA A A AAA, AA A AA A", 45);
	test("AAA, AAAA, AA AA, AAAA AA AAA, AAAA AAA AA A, AAA, A AA A AAA, A AA A AAA, A A", 48);
	test("AAA, AAAA, AA AA, AAAA AA AAA, AAAA AAA AA A, AAA, A AA A AAA, A AA A AA A, AA A AAA", 48);
	test("AA A, AAA, AA A, AA A A AAA, AA A AA A AA A, A A", 49);
	test("AAAA, AA A, AA A, AA A A AAA, AA A, A AA A AAA, AA A AA A AAAA, AAAA AAA, AAAA AAA", 50);
	test("AAA, AA A, AAA AA A AAAA, AA A, AAA AA A AAA, AA A AA A", 52);
	test("AAA, AAA, AA A AA A AAA, A AA A", 54);
	test("AAA, AAA, AA A AA A AAAA, AA A, AA A AA A AAAA", 54);
	test("AAA, AA A, AA A AAA AA A, AA A, A AA A AAA, AA A AA A", 56);
	test("AAAA, AAAA, AAAA AAA, AAAA AAA AA A, AAA, AA A, AA A A AAA, AA A AA A AA A, AAAA, AAA, AA A A AAAA AA A, A AA A", 56);
	test("AAAA, AAAA, AAA, AA A, AA A AAA AA A, A AA A AA AA, AAAA AA AAA, AAAA AAA AAA, AAA, AA A AA A AA A, AA A A", 57);
	test("AA A, AA A, AA A, A AA A AAA, AA A AA A AAA, AAA, AA A AA A AA A, AA A A", 59);
	test("AAAA, AAA, AAAA, AAA, AA A A AAAA AAA, AA A AA A AA A, AAAA, AAA, AA A A AAAA AA A, A AA A", 61);
	test("AA A, AAAA, AA A, AAA AA A AAA, AA A AA A AA AA, AA AA, AAAA AA AAA, AAAA AAA AAA, AAA, AA A AA A AAAA, AAA, AA A A AAAA", 67);
	test("AAA, AAA, AA A AA A AAA, AA A AA A", 81);
	test("AAA, AAA, A AA A AA A, AAA, AA A AA A AAAA, AA A, AA A AA A AAAA", 90);
	test("AAAA, AAAA, AAAA AAA, AAAA AAA AAA, AA A, AAAA, AAA, AA A A AAAA AAA, AA A AA A AA A, AA A, AA A A A", 105);
	test("AAA, AAA, AAA, AA A AA A AA A AA A, AA A AAA", 108);
	test("AAA, AAAA, AA A, AA A AA A AAAA AAA, AAA, AA A AA A A", 108);
	test("AA A, AA AA, AAA, AAAA, AA A, AA A AA A AAAA AAAA, AAA, AA A A AAAA AA AA, AAAA AA AAA, AAAA AAA AAA, AAA, AA A AA A AAA, AA A AA A", 117);
	test("AAA, AA A, A AAAA, AAA, AA A A AAAA AAAA, AAAA, AAA, AA A A AAAA AAA, AA A AA A", 120);
	test("AAA, AAAA, AAA, AA A, AA A AAA AA A, A AA A AA AA, AAAA AA AAA, AAAA AAA AAA, A AA A", 120);
	test("AAA, AA A, AAAA, AA A, AA A AA A AAAA AA A, AA A A AA A, AAAA, AAA, AA A A AAAA AAAA, AA A, AA A AA A AAAA", 132);
	test("AAA, AAA, AAA, AA A AA A AA A AA A, AA A A", 135);
	test("AA AA, AAAA, AAAA AAA, AAAA AAA AAA, AA A, AA A, AA A A AAA, AA A AA A AAAA, AA AA, AAAA AA AAA, AAAA AAA AAA, A AA A, AA A A", 140);
	test("AAAA, AAAA, AAAA AAA, AAAA AAA AAA, AAA, A AAAA, AA A, AA A AA A AAAA AA A, AAAA, AAA, AA A A AAAA AAAA, AA A, AA A AA A AAAA", 144);
	test("AAAA, AAA, AAA, AA A, AAA AA A AAA, A A AAAA, AA AA, AAAA AA AAA, AAAA AAA AAA, A AA A, AA A A AAAA, AAAA AAA, AAAA AAA", 160);
	test("AA AA, AAAA, AAAA AAA, AAAA AAA AAA, AA A, AAAA, AAA, AA A A AAAA AAAA, AA A, AA A AA A AAAA AA A, AAA, AA A AA A AAAA, AA A, AA A AA A AAAA", 180);
	test("AA A, AAAA, AAAA AAA, AAAA AAA AAA, AA A, AAA, A A AAA, AA A AA A AAA, AA A, A A AA A, A A", 208);

	return 0;
}
