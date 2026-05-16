/*

Find the total number of operations of addition (+), subtraction (−), and multiplication (∗) in the given arithmetic expression.

Input
The arithmetic expression is given as a single line, without brackets or spaces. The number of symbols in the expression does not exceed 1000.

Output
Print the number of specified operations.

Examples

Input #1
-1+2*3+a

Answer #1
3

Input #8
+5-2+4-m/n*2:4

Answer #8
4

*/

package main

import (
	"bytes"
	"go/ast"
	"go/parser"
	"go/token"
	"strings"
	"unicode"
)

func main() {
	assert(solve("-1+2*3+a") == 3)
	assert(solve("+5-2+4-m/n*2:4") == 4)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(s string) int {
	e, err := parser.ParseExpr(reform(s))
	if err != nil {
		return 0
	}
	return walk(e)
}

func walk(e ast.Expr) int {
	r := 0
	switch e := e.(type) {
	case *ast.BinaryExpr:
		r = walk(e.X) + walk(e.Y)
		switch e.Op {
		case token.ADD, token.SUB, token.MUL:
			r += 1
		}
	case *ast.UnaryExpr:
		r = walk(e.X)
	case *ast.ParenExpr:
		r = walk(e.X)
	}
	return r
}

func reform(s string) string {
	w := new(bytes.Buffer)
	for _, r := range s {
		if !(unicode.IsDigit(r) || unicode.IsLetter(r) || strings.IndexRune("+-*_", r) >= 0) {
			r = '/'
		}
		w.WriteRune(r)
	}
	return w.String()
}
