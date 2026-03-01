/*

Introduction
My calculator is behaving weird. Sometimes when I type in an 8 it displays a 2. And sometimes when I type in a 6 it displays a +. Some buttons are mixed up!
Could anyone help me determine which?

Challenge:
Input: List of incorrect equations, with correct results.

Output: The two buttons that are swapped.

For example:
An input could be:

123    = 3
8423   = 252
4+4    = 8
4*7-10 = 417
9/3    = 3
42-9   = -36
For which the expected outputs are: 2 and *.

Why? Because ALL the equations would be correct if we swap the 2's and *'s:

1*3    = 3
84*3   = 252
4+4    = 8
427-10 = 417
9/3    = 3
4*-9   = -36
Challenge rules:
Input can be in any reasonable format. Can be a single string with space delimited; a string-list or -array; a list with equations and another list with the correct results. Your call. Please state which input format you've used!
NOTE: This also means you are allowed to input the test case -5--15 as -5- -15 or -5 - -15. However, a number resulting in -- should either be inputted without spaces or with a space between every digit. So test case 9119 can be inputted like 9119 or 9 1 1 9 (reason 91 19 isn't allowed is because you can then be guided by the space for finding - -). So spaces are (somewhat) optional and allowed.
Output format can be in any reasonable format as well. Can be two characters; a single two-character string; a string-list containing the two characters. Your call. Again, please state which output format you've used!
You are allowed to use any distinct 14 outputs that map to 0123456789+-/*. So you are even allowed to output two distinct integers if you want to (again, please specify the mapping you've used, if any).
You only have to support integers. So there won't be any test cases like 1/8=0.125 or 1/8=0.
Arithmetic operands you'll have to support: addition (+); subtraction (-); multiplication (* or × or ·); division (/ or ÷). (NOTE: Characters between parenthesis are only added as clarification.)
You'll have to support negative numbers. This means - can be interpreted in the equation as both a mathematical operand or a negative indicator.
You can assume the given incorrect equations and supposed correct equations are always valid (so there won't be things like 4-/2 or 9+-+8 for example).
The incorrect input-equations can contain a division by 0, but the corrected and expected equations will never contain division by 0.
The incorrect input-equations can already be correct even if you swap the intended buttons back.
A given input equation can be irrelevant for the buttons to swap (like the 4+4=8 and 9/3=3 equations, with the swapped buttons 2 and *).
You can assume there will always be only one possible swap that can be made with the given test cases.
Both buttons to swap will always be present in at least one of the incorrect equations.
General rules:
This is code-golf, so shortest answer in bytes wins.
Don't let code-golf languages discourage you from posting answers with non-codegolfing languages. Try to come up with an as short as possible answer for 'any' programming language.
Standard rules apply for your answer, so you are allowed to use STDIN/STDOUT, functions/method with the proper parameters and return-type, full programs. Your call.
Default Loopholes are forbidden.
If possible, please add a link with a test for your code.
Also, please add an explanation if necessary.
Test cases:
Input:
123    = 3
8423   = 252
4+4    = 8
4*7-10 = 417
9/3    = 3
42-9   = -36

Output: 2 *

Input:
4/2   = 6
3/0   = 3
0/8+2 = 4
95-5  = 90
4+2   = 2

Output: + /

Input:
7+4    = 11
5-15   = 46
212-23 = -2121

Output: 1 -

Input:
4+8/2-9*1 = -5
99/3-13   = 20
1+2+3+4   = 10
4-3-2-1   = -6

Output: 2 4

Input:
18/18  = 1
98-8   = 90
55*88  = 4840
-5--15 = 10

Ouput: 5 8

Input:
9119    = 18
5-3     = 513
8*-9    = 152
13116/3 = -1

Output: 1 -

*/

package main

import (
	"fmt"
	"go/ast"
	"go/parser"
	"go/token"
	"strconv"
	"strings"
)

func main() {
	fmt.Println(solve([]string{
		"123    = 3",
		"8423   = 252",
		"4+4    = 8",
		"4*7-10 = 417",
		"9/3    = 3",
		"42-9   = -36",
	}))

	fmt.Println(solve([]string{
		"4/2   = 6",
		"3/0   = 3",
		"0/8+2 = 4",
		"95-5  = 90",
		"4+2   = 2",
	}))

	fmt.Println(solve([]string{
		"7+4    = 11",
		"5-15   = 46",
		"212-23 = -2121",
	}))

	fmt.Println(solve([]string{
		"4+8/2-9*1 = -5",
		"99/3-13   = 20",
		"1+2+3+4   = 10",
		"4-3-2-1   = -6",
	}))

	fmt.Println(solve([]string{
		"18/18  = 1",
		"98-8   = 90",
		"55*88  = 4840",
		"-5--15 = 10",
	}))

	fmt.Println(solve([]string{
		"9119    = 18",
		"5-3     = 513",
		"8*-9    = 152",
		"13116/3 = -1",
	}))
}

func solve(equations []string) (string, string, error) {
	symbols, computables, targets, err := parse(equations)
	if err != nil {
		return "", "", err
	}
	return search(symbols, computables, targets)
}

func parse(equations []string) (symbols []byte, computables []string, targets []int, err error) {
	invalid := fmt.Errorf("invalid system of equations")
	seen := make(map[byte]bool)
	for _, equation := range equations {
		fields := strings.Split(equation, "=")
		if len(fields) != 2 {
			err = invalid
			return
		}

		for i := range fields {
			fields[i] = strings.TrimSpace(fields[i])
		}

		for i := range len(fields[0]) {
			symbol := fields[0][i]
			if !seen[symbol] {
				symbols = append(symbols, symbol)
				seen[symbol] = true
			}
		}

		var target int
		target, err = strconv.Atoi(fields[1])
		if err != nil {
			err = invalid
			return
		}

		computables = append(computables, fields[0])
		targets = append(targets, target)
	}
	return
}

func search(symbols []byte, computables []string, targets []int) (c0, c1 string, err error) {
	for i := 0; i < len(symbols); i++ {
	loop:
		for j := i + 1; j < len(symbols); j++ {
			c0 = fmt.Sprintf("%c", symbols[i])
			c1 = fmt.Sprintf("%c", symbols[j])
			replacer := strings.NewReplacer(c0, c1, c1, c0)
			for index, computable := range computables {
				computable = replacer.Replace(computable)
				computable = strings.Replace(computable, "--", "- -", -1)
				computable = strings.Replace(computable, "++", "+ +", -1)

				expression, err := parser.ParseExpr(computable)
				if err != nil {
					continue loop
				}

				value, valid := evaluate(expression)
				if !valid || value != targets[index] {
					continue loop
				}
			}
			return
		}
	}
	return "", "", fmt.Errorf("no solution found")
}

func evaluate(expression ast.Expr) (int, bool) {
	switch expression := expression.(type) {
	case *ast.BinaryExpr:
		left, valid1 := evaluate(expression.X)
		right, valid2 := evaluate(expression.Y)
		if !valid1 || !valid2 {
			return 0, false
		}

		value := 0
		switch expression.Op {
		case token.ADD:
			value = left + right
		case token.SUB:
			value = left - right
		case token.MUL:
			value = left * right
		case token.QUO:
			if right == 0 {
				return 0, false
			}
			value = left / right
		}
		return value, true

	case *ast.UnaryExpr:
		value, valid := evaluate(expression.X)
		switch expression.Op {
		case token.ADD:
		case token.SUB:
			value = -value
		default:
			valid = false
		}
		return value, valid

	case *ast.BasicLit:
		value, err := strconv.Atoi(expression.Value)
		return value, err == nil
	}
	return 0, false
}
