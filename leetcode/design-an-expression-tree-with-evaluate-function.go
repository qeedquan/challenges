/*

Given the postfix tokens of an arithmetic expression, build and return the binary expression tree that represents this expression.

Postfix notation is a notation for writing arithmetic expressions in which the operands (numbers) appear before their operators. For example, the postfix tokens of the expression 4*(5-(2+7)) are represented in the array postfix = ["4","5","7","2","+","-","*"].

The class Node is an interface you should use to implement the binary expression tree. The returned tree will be tested using the evaluate function, which is supposed to evaluate the tree's value. You should not remove the Node class; however, you can modify it as you wish, and you can define other classes to implement it if needed.

A binary expression tree is a kind of binary tree used to represent arithmetic expressions. Each node of a binary expression tree has either zero or two children. Leaf nodes (nodes with 0 children) correspond to operands (numbers), and internal nodes (nodes with two children) correspond to the operators '+' (addition), '-' (subtraction), '*' (multiplication), and '/' (division).

It's guaranteed that no subtree will yield a value that exceeds 109 in absolute value, and all the operations are valid (i.e., no division by zero).

Follow up: Could you design the expression tree such that it is more modular? For example, is your design able to support additional operators without making changes to your existing evaluate implementation?

Examples:

Input: s = ["3","4","+","2","*","7","/"]
Output: 2
Explanation: this expression evaluates to the above binary tree with expression ((3+4)*2)/7) = 14/7 = 2.

Input: s = ["4","5","7","2","+","-","*"]
Output: -16
Explanation: this expression evaluates to the above binary tree with expression 4*(5-(2+7)) = 4*(-4) = -16.

Input: s = ["4","2","+","3","5","1","-","*","+"]
Output: 18

Input: s = ["100","200","+","2","/","5","*","7","+"]
Output: 757

Constraints:

1 <= s.length < 100
s.length is odd.
s consists of numbers and the characters '+', '-', '*', and '/'.
If s[i] is a number, its integer representation is no more than 10^5.
It is guaranteed that s is a valid expression.
The absolute value of the result and intermediate values will not exceed 10^9.
It is guaranteed that no expression will include division by zero.

*/

package main

import (
	"go/ast"
	"go/token"
	"strconv"
)

func main() {
	test([]string{"3", "4", "+", "2", "*", "7", "/"}, 2)
	test([]string{"4", "5", "7", "2", "+", "-", "*"}, -16)
	test([]string{"4", "2", "+", "3", "5", "1", "-", "*", "+"}, 18)
	test([]string{"100", "200", "+", "2", "/", "5", "*", "7", "+"}, 757)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(s []string, r int) {
	n := post2tree(s)
	assert(n != nil)
	assert(eval(n) == r)
}

func post2tree(s []string) ast.Expr {
	ops := map[string]token.Token{
		"+": token.ADD,
		"-": token.SUB,
		"*": token.MUL,
		"/": token.QUO,
	}

	var p []ast.Expr
	for _, s := range s {
		if t, ok := ops[s]; ok {
			n := len(p)
			if n < 2 {
				return nil
			}

			p[n-2] = &ast.BinaryExpr{
				Op: t,
				X:  p[n-2],
				Y:  p[n-1],
			}
			p = p[:n-1]
		} else {
			p = append(p, &ast.BasicLit{
				Kind:  token.INT,
				Value: s,
			})
		}
	}

	if len(p) != 1 {
		return nil
	}

	return p[0]
}

func eval(n ast.Expr) int {
	r := 0
	switch e := n.(type) {
	case *ast.BinaryExpr:
		x := eval(e.X)
		y := eval(e.Y)
		switch e.Op {
		case token.ADD:
			r = x + y
		case token.SUB:
			r = x - y
		case token.MUL:
			r = x * y
		case token.QUO:
			if y != 0 {
				r = x / y
			}
		}
	case *ast.BasicLit:
		r, _ = strconv.Atoi(e.Value)
	}
	return r
}
