/*

I was browsing esolangs, and chanced upon this language: https://github.com/catseye/Quylthulg.

One interesting thing about this language, is that it doesn't use prefix, postfix, or infix, it uses all three of them, calling it "panfix" notation.

Here is an example. To represent normal infix 1+2 in panfix, it becomes: +1+2+. Notice how the operator is both before, in between, and after the operands. Another example is (1+2)*3. This becomes *+1+2+*3*. Notice again how * is in all three places with respect to the operands +1+2+ and 3.

The Challenge
As you may have guessed, your task in this challenge is to convert an expression from infix to panfix.

A few clarifications:

You only have to deal with the four basic operations: + - * /
You won't have to deal with the unary versions of those, only binary
You have to deal with parenthesis
Assume the normal precedence rules of * / then + - and left associativity for all of them.
The numbers will be nonnegative integers
You can optionally have a spaces in both the input and output
Test Cases
1+2  ->  +1+2+
1+2+3  ->  ++1+2++3+
(1+2)*3  ->  *+1+2+*3*
10/2*5  ->  * /10/2/ *5*
(5+3)*((9+18)/4-1)  ->  *+5+3+*-/+9+18+/4/-1-*
This is code-golf, so shortest code in bytes wins!

*/

package main

import (
	"fmt"
	"go/ast"
	"go/parser"
)

func main() {
	assert(in2pan("1+2") == "+1+2+")
	assert(in2pan("1+2+3") == "++1+2++3+")
	assert(in2pan("(1+2)*3") == "*+1+2+*3*")
	assert(in2pan("10/2*5") == "*/10/2/*5*")
	assert(in2pan("(5+3)*((9+18)/4-1)") == "*+5+3+*-/+9+18+/4/-1-*")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func in2pan(s string) (r string) {
	defer func() {
		if err := recover(); err != nil {
			r = s
		}
	}()

	e, err := parser.ParseExpr(s)
	if err != nil {
		return s
	}
	return walk(e)
}

func walk(e ast.Expr) string {
	switch e := e.(type) {
	case *ast.BinaryExpr:
		x := walk(e.X)
		y := walk(e.Y)
		return fmt.Sprint(e.Op, x, e.Op, y, e.Op)
	case *ast.ParenExpr:
		return walk(e.X)
	case *ast.BasicLit:
		return e.Value
	default:
		panic("unsupported expression")
	}
}
