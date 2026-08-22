/*

Unlike most languages, Python evaluates a<b<c as it would be done in mathematics, actually comparing the three numbers, as opposed to comparing the boolean a<b to c.
The correct way to write this in C (and many others) would be a<b && b<c.

In this challenge, your task is to expand such comparison chains of arbitrary lengths from the Python/intuitive representation, to how it would be written in other languages.

Specifications
Your program will have to handle the operators: ==, !=, <, >, <=, >=.
The input will have comparison chains using only integers.
Don't worry about the trueness of any of the comparisons along the way, this is purely a parsing/syntactical challenge.
The input won't have any whitespace to prevent answers that trivialize parsing by splitting on spaces.
However, your output may have a single space surrounding either just the &&'s, or both the comparison operators and the &&'s, or neither, but be consistent.
Test Cases
Input                  Output
---------------------------------------------------------------

3<4<5                  3<4 && 4<5
3<4<5<6<7<8<9          3<4 && 4<5 && 5<6 && 6<7 && 7<8 && 8<9
3<5==6<19              3<5 && 5==6 && 6<19
10>=5<7!=20            10>=5 && 5<7 && 7!=20
15==15==15==15==15     15==15 && 15==15 && 15==15 && 15==15

This is code-golf, so shortest code in bytes wins!

*/

package main

import (
	"bytes"
	"fmt"
	"go/ast"
	"go/parser"
	"strings"
)

func main() {
	test("a<b<c", "a<b && b<c")
	test("3<4<5", "3<4 && 4<5")
	test("3<4<5<6<7<8<9", "3<4 && 4<5 && 5<6 && 6<7 && 7<8 && 8<9")
	test("3<5==6<19", "3<5 && 5==6 && 6<19")
	test("10>=5<7!=20", "10>=5 && 5<7 && 7!=20")
	test("15==15==15==15==15", "15==15 && 15==15 && 15==15 && 15==15")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(s, r string) {
	p := expand(s)
	fmt.Println(p)

	p = strings.Replace(p, " ", "", -1)
	r = strings.Replace(r, " ", "", -1)
	assert(p == r)
}

func expand(s string) (r string) {
	defer func() {
		if err := recover(); err != nil {
			r = s
		}
	}()

	e, err := parser.ParseExpr(s)
	if err != nil {
		panic(err)
	}

	w := new(bytes.Buffer)
	walk(w, e)

	r = w.String()
	r = strings.TrimSuffix(r, "&& ")
	return r
}

func walk(w *bytes.Buffer, e ast.Expr) string {
	switch e := e.(type) {
	case *ast.BinaryExpr:
		x := walk(w, e.X)
		y := walk(w, e.Y)
		fmt.Fprintf(w, "%v %v %v && ", x, e.Op, y)
		return y
	case *ast.Ident:
		return e.Name
	case *ast.BasicLit:
		return e.Value
	}
	panic("invalid expression")
}
