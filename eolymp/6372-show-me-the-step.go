/*

A programming instructor needs your help to teach his students on the precedence level of binary arithmetic operators (+,-, *, /).
Write a program which can show the sequence of operators executed when evaluating an arithmetic expression according to the precedence rules below.

Precedence rules:

Multiplication and division operators have higher precedence than plus and minus operators.

Multiplication and division operators have the same level of precedence.
However, in an expression, the operator which appears first from the left of the expression has higher precedence.

Plus and minus operators have the same level of precedence.
However, in an expression, the operator which appears first from the left of the expression has higher precedence.

Evaluation of the expression starts from left to right.

Input
The first line of the input data contains an integer which represents the number of test cases.
The line is then followed by the data for each of the test cases.
Each test case contains an arithmetic expression containing mixture of positive integer operands and binary arithmetic operators (with a space in between).
For simplicity, let’s assume the maximum number of operators in an expression is limited to 10.

Output
The output comprises one line for each test case (arithmetic expression).
The line begins with the prefix Case #x: where x represents the case number, followed by the output of the test case.
For each test case, a list of arithmetic operators will be produced according to the precedence in which they were executed in the expression.
The list is terminated with the final result of the execution.

Examples

Input #1
2
4 + 16 / 4 * 3 + 6 * 2
6 * 2 + 3 * 2 / 2

Answer #1
Case #1: / * * + + 28
Case #2: * * / + 15

*/

package main

import (
	"bytes"
	"fmt"
	"go/ast"
	"go/parser"
	"go/token"
	"strconv"
	"strings"
)

func main() {
	assert(solve("4 + 16 / 4 * 3 + 6 * 2") == "/ * * + + 28")
	assert(solve("6 * 2 + 3 * 2 / 2") == "* * / + 15")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(input string) (result string) {
	defer func() {
		if err := recover(); err != nil {
			result = input
		}
		return
	}()

	expression, err := parser.ParseExpr(input)
	if err != nil {
		return input
	}

	output := new(bytes.Buffer)
	walk(output, expression, 0)
	value := walk(output, expression, 1)
	fmt.Fprintf(output, "%v", value)

	result = output.String()
	result = strings.TrimSpace(result)
	return result
}

func walk(output *bytes.Buffer, expression ast.Expr, phase int) int {
	switch expression := expression.(type) {
	case *ast.BinaryExpr:
		lhs := walk(output, expression.X, phase)
		rhs := walk(output, expression.Y, phase)
		op := expression.Op

		switch {
		case phase == 0 && (op == token.MUL || op == token.QUO):
			fallthrough
		case phase == 1 && (op == token.ADD || op == token.SUB):
			fmt.Fprintf(output, "%s ", op)
		}

		switch op {
		case token.ADD:
			return lhs + rhs
		case token.SUB:
			return lhs - rhs
		case token.MUL:
			return lhs * rhs
		case token.QUO:
			return lhs / rhs
		default:
			panic("unsupported binary operation")
		}

	case *ast.UnaryExpr:
		value := walk(output, expression.X, phase)
		if expression.Op == token.SUB {
			value = -value
		}
		return value

	case *ast.ParenExpr:
		return walk(output, expression.X, phase)

	case *ast.BasicLit:
		value, err := strconv.Atoi(expression.Value)
		if err != nil {
			panic(err)
		}
		return value
	}
	panic("unsupported type")
}
