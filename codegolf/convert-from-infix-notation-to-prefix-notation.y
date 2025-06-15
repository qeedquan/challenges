/*

Given an arithmetic expression, which can include parentheses (()), exponents (^), division (/) and multiplication (*), addition (+) and subtraction (-) (in that order of operation), such as

a ^ (2 / 3) * 9 * 3 - 4 * 6
output the same expression in prefix notation.

(- (* (* (^ a (/ 2 3)) 9) 3) (* 4 6))
Spaces are optional in the input as well as the output. You may assume that all operators are left-associative and that all of the numbers in the expression are single digit integers (i.e. [0-9]).

This is a code golf challenge, so the shortest solution wins.

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
		$$ = fmt.Sprintf("(+ %v %v)", $1, $3)
	}
|
	expr '-' expr
	{
		$$ = fmt.Sprintf("(- %v %v)", $1, $3)
	}
|
	expr '*' expr
	{
		$$ = fmt.Sprintf("(* %v %v)", $1, $3)
	}
|
	expr '/' expr
	{
		$$ = fmt.Sprintf("(/ %v %v)", $1, $3)
	}
|
	expr '^' expr
	{
		$$ = fmt.Sprintf("(^ %v %v)", $1, $3)
	}
|
	'(' expr ')'
	{
		$$ = $2
	}
%%

func main() {
	assert(eval("a ^ (2 / 3) * 9 * 3 - 4 * 6") == "(- (* (* (^ a (/ 2 3)) 9) 3) (* 4 6))")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func eval(s string) string {
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
