/*

Inspired by this excellent challenge (from which the bulk of this text is blatantly duct-taped) – and my highschool philosophy project...

I define the following operators:

Fuzzy Conjunction a ×F b is a × b

Fuzzy Division a ÷F b is a ÷ b

Fuzzy Negation –F b is 1 – b

Fuzzy Disjunction a +F b is –F ((–F a) ×S (–F b) which is equivalent to 1 – (1 – a) × (1 – b)

With all this in mind, create an interpreter that will evaluate infix expressions that use the following operators (i.e., a + b, not a b + or + a b). Alternatively, extend the language of your choice to include the notation.

×    Multiplication
÷    Division
–    Subtraction
+    Addition
×F   Fuzzy Conjunction
÷F   Fuzzy Division
–F   Fuzzy Negation
+F   Fuzzy Disjunction
Notice that a -F b is not defined. You may leave it undefined, or define it as you see fit.

You may substitute * for × and/or - for – and/or / for ÷, (or use whatever single symbols your language uses for the four basic arithmetic operations) as long as you stay consistent: You may not use * and ×F together.

You may choose to require or prohibit spacing around tokens.

You may choose any of the following rules for order of precedence:

As normal mathematics, and each Fuzzy operator has a higher order precedence than their normal counterpart.

As normal mathematics, and each Fuzzy operator has a lower order precedence than their normal counterpart.

As normal mathematics, and the Fuzzy operators all have higher order precedence than all the normal operators.

As normal mathematics, and the Fuzzy operators all have lower order precedence than all the normal operators.

Strict left-to-right.

Strict right-to-left.

Normal and Fuzzy operators have the same precedence and are evaluated left-to-right.

Normal and Fuzzy operators have the same precedence and are evaluated right-to-left.

Leave a comment if you desire another precedence rule.

Test cases using precedence rule 6:

> 5 +F 10 + 3
-47     // 1 - (1 - 5) × (1 - 13)
> 10 × 2
20      // 2 × 10
> 10 ×F 1
10      // 1 × 10
> 23 × 3
69      // 23 × 3
> 123 ×F 2 × 3
738     // 123 × 2 × 3
> 5 + 3 +F 2
4       // 5 + 1 - (1 - 3) × (1 - 2)
> 150 ÷F 3
50      // 150 ÷ 3
> 150 ÷ 53
2.83    // 150 ÷ 53
> -F -F -F 0
1       // 1 - (1 - (1 - 0))
> -500
-500    // - 500
> -F 6 - 1
-4      // 1 - 5
> 12 +F 633 ×F 3
-20877  // 1 - (1 - 12) × (1- 633 × 3)
This is a code-golf, so the shortest program in bytes wins.

*/

%{

package main

import (
	"errors"
	"strconv"
	"strings"
	"text/scanner"
)

%}

%union {
	line  *Line
	value int
}

%type <line> top
%type <value> expr

%right '+' '-' '×' '÷' FZADD FZSUB FZMUL FZQUO

%token <value> NUM

%%

top:
	expr
	{
		$$.root = $1
	}

expr:
	NUM
	{
		$$ = $1
	}
|
	'+' expr
	{
		$$ = $2
	}
|
	'-' expr
	{
		$$ = -$2
	}
|
	FZSUB expr
	{
		$$ = 1 - $2
	}
|
	expr '+' expr
	{
		$$ = $1 + $3
	}
|
	expr '-' expr
	{
		$$ = $1 - $3
	}
|
	expr '×' expr
	{
		$$ = $1 * $3
	}
|
	expr '÷' expr
	{
		$$ = 0
		if $3 != 0 {
			$$ = $1 / $3
		}
	}
|
	expr FZADD expr
	{
		$$ = 1 - (1 - $1) * (1 - $3)
	}
|
	expr FZMUL expr
	{
		$$ = $1 * $3 
	}
|
	expr FZQUO expr
	{
		$$ = 0
		if $3 != 0 {
			$$ = $1 / $3
		}
	}
|
	'(' expr ')'
	{
		$$ = $2
	}
%%

func main() {
	assert(eval("5 +F 10 + 3") == -47)
	assert(eval("5 × 2") == 10)
	assert(eval("10 ×F 1") == 10)
	assert(eval("23 × 3") == 69)
	assert(eval("123 ×F 2 × 3") == 738)
	assert(eval("5 + 3 +F 2") == 4)
	assert(eval("150 ÷F 3") == 50)
	assert(eval("150 ÷F 53") == 2)
	assert(eval("-F -F -F 0") == 1)
	assert(eval("-500") == -500)
	assert(eval("-F 6 - 1") == -4)
	assert(eval("12 +F 633 ×F 3") == -20877)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func eval(s string) int {
	l := &Line{}
	l.sc.Init(strings.NewReader(s))
	if yyParse(l) != 0 || l.err != nil {
		return 0
	}
	return l.root
}

type Line struct {
	root int
	sc   scanner.Scanner
	err  error
}

func (l *Line) Lex(lv *yySymType) int {
	fzops := map[rune]int{'+': FZADD, '-': FZSUB, '×': FZMUL, '÷': FZQUO }

	tok := l.sc.Scan()
	lv.line = l
	switch tok {
	case scanner.EOF:
		return 0
	case scanner.Int:
		lv.value, _ = strconv.Atoi(l.sc.TokenText())
		return NUM
	case '+', '-', '×', '÷':
		if l.sc.Peek() == 'F' {
			l.sc.Next()
			return fzops[tok]
		}
		return int(tok)
	}
	return int(tok)
}

func (l *Line) Error(s string) {
	l.err = errors.New(s)
}
