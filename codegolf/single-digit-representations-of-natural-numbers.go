/*

Task
Write a program/function that when given a positive integer n and a digit d which is not 0 outputs a way to represent n using only addition, subtraction, multiplication, exponentiation, division, concatenation, parenthesis and the digit d.

Examples
n =  6, d = 1  =>  (1 + 1) * (1 + 1 + 1)
n =  6, d = 1  =>  1 + 1 + 1 + 1 + 1 + 1
n = 10, d = 1  =>  1 || 1 - 1
n = 12, d = 1  =>  1 || (1 + 1)
n = 64, d = 2  =>  2 ^ (2 + 2 + 2)
n =  1, d = 9  =>  9 / 9
Note: In the examples || represents concatenation

Output Format
Concatenation must be explicit with a separate operator
Output can be a string, list of operations and numbers or a list of lists in place of brackets.
You may choose the precedence of the operators but it must be consistent for all outputs produced by your program/function
Output may be in polish, reverse polish or infix notation but it must be consistent for all outputs produced by your program/function.
You can use custom symbols for representing the digits and operations but the symbols used for representing the digits and operations should be distinct.

Scoring
This is code-challenge, Your score will be

100*B + S
Where B is the number of bytes in the program/function, and S is the sum of the number of times the digit d appears in the representation of n with the digit d as returned by your program/function for all n≤1000 and all d from 1 to 9

Lowest score wins

Example: if your program is abcd and all representation of n returned by your program has 5 occurrences of d then its score will be (4 * 100) + (5 * 1000 * 9) = 45400

Rules
Your program/function should run deterministically, so that it always returns the same representation for a given n and d (and hence always gets the same score).
Your answer must include not only your submission, but also the code you used to calculate the S part of its score.
This need not be written in the same language as your submission, and will not be counted towards its byte count. You are encouraged to make it readable.
Your answer must include the precedence of the operators needed to evaluate the outputs produced by your program/function
You must actually run your test program and calculate/verify your score before submitting your entry. If your submission runs too slowly for you to verify its score then it is not qualified to compete, even if you know what its score would be in principle.

*/

package main

import (
	"fmt"
	"go/ast"
	"go/parser"
	"go/token"
	"strconv"
)

func main() {
	test(6, 1)
	test(10, 1)
	test(12, 1)
	test(64, 2)
	test(1, 9)
	test(29, 3)
	test(0, 1)
	test(56253, 5)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(n, d uint) {
	s := sdrep(n, d)
	v := eval(s)
	fmt.Println(s, v)
	assert(v == n)
}

// https://arxiv.org/pdf/1502.03501.pdf
func sdrep(n, d uint) string {
	if d == 0 || d >= 10 {
		return fmt.Sprint(n)
	}

	s := ""
	for {
		t := "("
		switch v := n % 10; v {
		case 0:
			t += fmt.Sprintf("%v-%v", d, d)
		case 1, 2, 3, 4, 5, 6, 7, 8, 9:
			t += "("
			for i := uint(0); i < v; i++ {
				t += fmt.Sprint(d)
				if i+1 < v {
					t += "+"
				}
			}
			t += fmt.Sprintf(")/%v", d)
		}
		t += ")"

		if s != "" {
			t += "||"
		}
		s = t + s

		if n /= 10; n == 0 {
			break
		}
	}
	return s
}

func eval(s string) uint {
	e, err := parser.ParseExpr(s)
	if err != nil {
		panic("invalid expression")
	}
	return walk(e)
}

func walk(e ast.Expr) uint {
	switch e := e.(type) {
	case *ast.BinaryExpr:
		x := walk(e.X)
		y := walk(e.Y)
		switch e.Op {
		case token.ADD:
			return x + y
		case token.SUB:
			return x - y
		case token.QUO:
			return x / y
		case token.LOR:
			return (10 * x) + y
		default:
			panic(fmt.Sprintf("invalid binary op %v", e.Op))
		}
	case *ast.ParenExpr:
		return walk(e.X)
	case *ast.BasicLit:
		x, _ := strconv.Atoi(e.Value)
		return uint(x)
	default:
		panic("invalid expression")
	}
}
