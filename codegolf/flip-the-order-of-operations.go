/*

Scientists have made contact with a parallel universe.
Just one problem: They write math differently.
Help the scientists make a program that can convert normal math expressions to their equivalent in alternate universe math.
The connection through the portal is bad so your code needs to be as short as possible

Given a expression, containing only the operators *, +, parenthesis, and variables represented by single lower case ASCII letters,
convert it from normal order of operations (* first then +) to inverse order of operations used in a parallel universe (+ first then *).
You must remove any redundant parenthesis.

Note: The expression will stay exactly the same. All you need to change is the position of the parenthesis.

Variable names are guaranteed to be unique. Expressions are guaranteed to be valid, be matched, and contain no invalid characters.
There will never be redundant parenthesis in the input.

You may substitute * and + with any other 2 unique characters if you prefer. You may substitute () with [] or {} if you prefer.

Test cases
Before	           After
a+b	               a+b
a+b*c	           a+(b*c)
(a+b)*c	           a+b*c
((a+b)*(c+d)+e)*f  (a+b*c+d)+e*f
(a*b+c*d)*e+f	   ((a*b)+(c*d)*e)+f
a+b+c	           a+b+c
a*b*c	           a*b*c

*/

package main

import (
	"fmt"
	"go/ast"
	"go/parser"
	"go/token"
)

func main() {
	assert(order("a+b") == "a+b")
	assert(order("a+b*c") == "a+(b*c)")
	assert(order("(a+b)*c") == "a+b*c")
	assert(order("((a+b)*(c+d)+e)*f") == "(a+b*c+d)+e*f")
	assert(order("(a*b+c*d)*e+f") == "((a*b)+(c*d)*e)+f")
	assert(order("a+b+c") == "a+b+c")
	assert(order("a*b*c") == "a*b*c")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func order(s string) string {
	e, err := parser.ParseExpr(s)
	if err != nil {
		return s
	}
	return walk(e, nil)
}

func walk(e, p ast.Expr) string {
	switch e := e.(type) {
	case *ast.BinaryExpr:
		x := walk(e.X, e)
		y := walk(e.Y, e)
		r := fmt.Sprintf("%v%v%v", x, e.Op, y)
		b, ok := p.(*ast.BinaryExpr)
		if ok && b.Op == token.ADD && e.Op == token.MUL {
			r = "(" + r + ")"
		}
		return r

	case *ast.ParenExpr:
		return walk(e.X, e)

	case *ast.UnaryExpr:
		return fmt.Sprintf("%v%v", e.Op, walk(e.X, e))

	case *ast.Ident:
		return e.Name

	case *ast.BasicLit:
		return e.Value

	default:
		panic(fmt.Sprintf("unsupported type: %T", e))
	}
}
