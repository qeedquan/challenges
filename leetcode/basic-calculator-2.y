/*

Given a string s which represents an expression, evaluate this expression and return its value.

The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-2^31, 2^31 - 1].

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().



Example 1:

Input: s = "3+2*2"
Output: 7
Example 2:

Input: s = " 3/2 "
Output: 1
Example 3:

Input: s = " 3+5 / 2 "
Output: 5


Constraints:

1 <= s.length <= 3 * 10^5
s consists of integers and operators ('+', '-', '*', '/') separated by some number of spaces.
s represents a valid expression.
All the integers in the expression are non-negative integers in the range [0, 2^31 - 1].
The answer is guaranteed to fit in a 32-bit integer.

*/

%{

package main

import (
	"errors"
	"fmt"
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

%left '+' '-'
%left '*' '/'

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
	expr '*' expr
	{
		$$ = $1 * $3
	}
|
	expr '/' expr
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
	test("3+2*2", 7)
	test("3/2", 1)
	test("3+5 / 2", 5)
}

func test(s string, r int) {
	p := eval(s)
	fmt.Println(p)
	assert(p == r)
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
		return -1
	}
	return l.root
}

type Line struct {
	root int
	sc   scanner.Scanner
	err  error
}

func (l *Line) Lex(lv *yySymType) int {
	tok := l.sc.Scan()
	text := l.sc.TokenText()

	lv.line = l
	switch tok {
	case scanner.EOF:
		return 0
	case scanner.Int:
		lv.value, _ = strconv.Atoi(text)
		return NUM
	}
	return int(text[0])
}

func (l *Line) Error(s string) {
	l.err = errors.New(s)
}
