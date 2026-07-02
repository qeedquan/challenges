/*

Construct a function that, when given a string containing an expression in infix notation, will return an identical expression in postfix notation.

The operators used will be +, -, *, /, and ^ with left-associativity of all operators but ^.

The precedence of the operators (most important to least) are : 1) parentheses, 2) exponentiation, 3) times/divide, 4) plus/minus.

The operands will be single-digit integers between 0 and 9, inclusive.

Parentheses may be included in the input, and are guaranteed to be in correct pairs.

to_postfix("2+7*5") // Should return "275*+"
to_postfix("3*3/(7+1)") // Should return "33*71+/"
to_postfix("5+(6-2)*9+3^(7-1)") // Should return "562-9*+371-^+"
to_postfix("1^2^3") // Should return "123^^"
You may read more about postfix notation, also called Reverse Polish notation, here: http://en.wikipedia.org/wiki/Reverse_Polish_notation

*/

%{

package main

import (
	"errors"
	"fmt"
	"strings"
	"text/scanner"
)

%}

%union {
	line  *Line
	value string
}

%type <line> top
%type <value> expr

%left '+' '-'
%left '*' '/'
%right '^'

%token <value> VAL

%%

top:
	expr
	{
		$$.root = $1
	}

expr:
	VAL
	{
		$$ = $1
	}
|
	'+' expr
	{
		$$ = fmt.Sprintf("+%v", $2)
	}
|
	'-' expr
	{
		$$ = fmt.Sprintf("-%v", $2)
	}
|
	expr '+' expr
	{
		$$ = fmt.Sprintf("%v%v+", $1, $3)
	}
|
	expr '-' expr
	{
		$$ = fmt.Sprintf("%v%v-", $1, $3)
	}
|
	expr '*' expr
	{
		$$ = fmt.Sprintf("%v%v*", $1, $3)
	}
|
	expr '/' expr
	{
		$$ = fmt.Sprintf("%v%v/", $1, $3)
	}
|
	expr '^' expr
	{
		$$ = fmt.Sprintf("%v%v^", $1, $3)
	}
|
	'(' expr ')'
	{
		$$ = $2
	}
%%

func main() {
	assert(in2post("2+7*5") == "275*+")
	assert(in2post("3*3/(7+1)") == "33*71+/")
	assert(in2post("5+(6-2)*9+3^(7-1)") == "562-9*+371-^+")
	assert(in2post("(5-4-1)+9/5/2-7/1/7") == "54-1-95/2/+71/7/-")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func in2post(s string) string {
	l := &Line{}
	l.sc.Init(strings.NewReader(s))
	if yyParse(l) != 0 || l.err != nil {
		return "invalid expression"
	}
	return l.root
}

type Line struct {
	root string
	sc   scanner.Scanner
	err  error
}

func (l *Line) Lex(lv *yySymType) int {
	tok := l.sc.Scan()
	lv.line = l
	switch tok {
	case scanner.EOF:
		return 0
	case scanner.Int, scanner.Ident:
		lv.value = l.sc.TokenText()
		return VAL
	}
	return int(tok)
}

func (l *Line) Error(s string) {
	l.err = errors.New(s)
}
