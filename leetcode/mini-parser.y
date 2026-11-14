/*

Given a string s represents the serialization of a nested list, implement a parser to deserialize it and return the deserialized NestedInteger.

Each element is either an integer or a list whose elements may also be integers or other lists.

Example 1:

Input: s = "324"
Output: 324
Explanation: You should return a NestedInteger object which contains a single integer 324.
Example 2:

Input: s = "[123,[456,[789]]]"
Output: [123,[456,[789]]]
Explanation: Return a NestedInteger object containing a nested list with 2 elements:
1. An integer containing value 123.
2. A nested list containing two elements:
    i.  An integer containing value 456.
    ii. A nested list with one element:
         a. An integer containing value 789


Constraints:

1 <= s.length <= 5 * 10^4
s consists of digits, square brackets "[]", negative sign '-', and commas ','.
s is the serialization of valid NestedInteger.
All the values in the input are in the range [-10^6, 10^6].

*/

%{

package main

import (
	"errors"
	"container/list"
	"fmt"
	"strconv"
	"strings"
	"text/scanner"
)

%}

%union {
	line   *Line
	list   *list.List
	value  any
	number int
}

%type <line> top
%type <value> expr
%type <list> exprlist

%token <number> NUM

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
	'+' NUM
	{
		$$ = $2
	}
|
	'-' NUM
	{
		$$ = -$2
	}
|
	'[' exprlist ']'
	{
		var r []any
		for l := $2.Front(); l != nil; l = l.Next() {
			r = append(r, l.Value)
		}
		$$ = r
	}

exprlist:
	expr
	{
		$$ = list.New()
		$$.PushBack($1)
	}
|
	expr ',' exprlist
	{
		$3.PushFront($1)
		$$ = $3
	}

%%

func main() {
	fmt.Println(construct("324"))
	fmt.Println(construct("[123,[456,[789]]]"))
	fmt.Println(construct("[123,[456,789]]"))
	fmt.Println(construct("[123,456,789]"))
	fmt.Println(construct("[123,[-456,[-789,91,2,[3]]]]"))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func construct(s string) any {
	l := &Line{}
	l.sc.Init(strings.NewReader(s))

	if yyParse(l) != 0 || l.err != nil {
		return nil
	}
	return l.root
}

type Line struct {
	root any
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
		lv.number, _ = strconv.Atoi(text)
		return NUM
	}
	return int(text[0])
}

func (l *Line) Error(s string) {
	l.err = errors.New(s)
}
