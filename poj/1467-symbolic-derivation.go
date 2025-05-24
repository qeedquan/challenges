/*

Description

Write a program that performs symbolic derivation f'(x) = df(x)/dx of a given function f(x). The function f(x) is defined by an expression which may contain the following operations: + (addition), - (subtraction), * (multiplication), / (division), and ln (natural logarithm). Besides, the operands may be the variable x and numerical constants. The expression may contain arbitrarily nested sub-expressions in parentheses ( ). The expression is given in a usual, infix form, such as:
(2*ln(x+1.7)-x*x)/((-7)+3.2*x*x)+(x+3*x)*x

Numerical constants have the form d.d, with an optional sign (+ or -), where the number of digits both in integer and decimal parts are arbitrary. The input expression is guaranteed to be correct (no syntax error can occur).

The output expression should be written in infix form. It should not be optimized for human reading. This means, it can contain redundancies, such as 0*x, 1*x, 0+x, etc. The derivation should be performed using the following rules:

1. The operators * and / are of higher priority than the operators + and -. Parentheses may change the priorities as usually.

2. The operators +, -, *, and / are left-associative, meaning that they group from left to right:
a*b*c = (a*b)*c, a/b/c = (a/b)/c, a/b*c = (a/b)*c, etc.

3. The rules for derivation are:
(a + b)' = a' + b'

(a - b)' = a' - b'

(a * b)' = (a' * b + a * b')

(a / b)' = (a' * b - a * b') / b^2		Note: use b^2 and not (b*b) for presentation

ln(a)' = (a')/(a)

x' = 1

const' = 0


4. While producing the symbolic derivation, use parentheses for output strictly as stated in the previous rule. Do not perform presentation optimizations, such as 0*a = 0, 1*a = a, etc.

Input

The input is a textual file which has one f(x) definition per line. The input lines do not have blanks.

Output

The output should contain lines with corresponding symbolic derivations f’=df/dx, one line for each f. The strings representing f(x) and f ’(x) are guaranteed to have no more than 100 characters.

Sample Input

x*x/x
-45.78*x+x
-2.45*x*x+ln(x-3)

Sample Output

((1*x+x*1)*x-x*x*1)/x^2
(0*x-45.78*1)+1
((0*x-2.45*1)*x-2.45*x*1)+(1-0)/(x-3)

Source

Southeastern Europe 2000

*/

package main

import (
	"fmt"
	"go/ast"
	"go/parser"
	"go/token"
	"strings"
)

func main() {
	assert(symdiff("x*x/x") == "((1*x+x*1)*x-x*x*1)/x^2")
	assert(symdiff("-45.78*x+x") == "(0*x-45.78*1)+1")
	assert(symdiff("-2.45*x*x+ln(x-3)") == "((0*x-2.45*1)*x-2.45*x*1)+(1-0)/(x-3)")
	assert(symdiff("-1-2-3") == "0-0-0")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func symdiff(s string) (r string) {
	defer func() {
		if err := recover(); err != nil {
			r = err.(string)
		}
	}()

	e, err := parser.ParseExpr(s)
	if err != nil {
		return "invalid expression"
	}
	return cleanop(diff(e))
}

func cleanop(s string) string {
	s = drillrep(s, "+-", "-")
	s = drillrep(s, "-+", "-")
	s = drillrep(s, "--", "+")
	return s
}

func drillrep(s, old, new string) string {
	for {
		p := strings.Replace(s, old, new, -1)
		if s == p {
			break
		}
		s = p
	}
	return s
}

func diff(e ast.Expr) string {
	switch e := e.(type) {
	case *ast.CallExpr:
		if lit(e.Fun) != "ln" || len(e.Args) != 1 {
			panic("unsupported function call")
		}
		x := lit(e.Args[0])
		dx := diff(e.Args[0])
		return fmt.Sprintf("(%v)/(%v)", dx, x)

	case *ast.UnaryExpr:
		return fmt.Sprintf("%v", diff(e.X))

	case *ast.BinaryExpr:
		x := lit(e.X)
		y := lit(e.Y)
		dx := diff(e.X)
		dy := diff(e.Y)
		switch e.Op {
		case token.ADD:
			return fmt.Sprintf("%v+%v", dx, dy)
		case token.SUB:
			return fmt.Sprintf("%v-%v", dx, dy)
		case token.MUL:
			return fmt.Sprintf("(%v*%v+%v*%v)", dx, y, x, dy)
		case token.QUO:
			return fmt.Sprintf("(%v*%v-%v*%v)/%v^2", dx, y, x, dy, y)
		}
		panic("unsupported binary op")

	case *ast.Ident:
		return "1"

	case *ast.BasicLit:
		if e.Kind == token.INT || e.Kind == token.FLOAT {
			return "0"
		}

		panic("unsupported basic literal")
	}

	panic("unsupported expression")
}

func lit(e ast.Expr) string {
	switch e := e.(type) {
	case *ast.CallExpr:
		return fmt.Sprintf("%v(%v)", lit(e.Fun), lit(e.Args[0]))
	case *ast.UnaryExpr:
		return fmt.Sprintf("%v%v", e.Op, lit(e.X))
	case *ast.BinaryExpr:
		return fmt.Sprintf("%v%v%v", lit(e.X), e.Op, lit(e.Y))
	case *ast.Ident:
		return e.Name
	case *ast.BasicLit:
		return e.Value
	}
	panic("unsupported literal")
}
