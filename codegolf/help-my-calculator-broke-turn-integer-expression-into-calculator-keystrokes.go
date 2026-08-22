/*

Introduction
Help! I accidentally dropped my TI-84 calculator out my window (don't ask how) and it broke. I have a math test tomorrow and the only calculator I can find is one with these buttons:

7 8 9 +
4 5 6 -
1 2 3 *
0   = /
My math test is a review test on evaluating expressions. I need a program to take an expression such as 1+(5*4)/7 and convert it to the keystrokes needed to solve it on my spare calculator. (And in case you were wondering, this actually happened to me).

Challenge
Given a non-empty input string containing only the characters 0-9, (, ), +, -, *, and /, output the keystrokes in a space-separated string (eg. 1 + 3 / 3 =). There must always be an equal sign at the end of the output. Standard loopholes are not allowed.

Examples:

Input: 1+(5*4)/7, Output: 5 * 4 / 7 + 1 =
Input: 6*(2/3), Output: 2 / 3 * 6 =
Input: (7-3)/2, Output: 7 - 3 / 2 =
To make this challenge easier:
You may assume that the input has a series of keystrokes linked to it that does not require clearing the calculator (1-(7*3) is not valid since it would require you to find 7 * 3, then clear the calculator to do 1 - 21. All the above examples are valid since there is one, continuous output that does not require the user to clear the calculator and remember a number).
You may assume that there will only be a single integer after a /, as having an input such as 21/(7*3) would not pass the first assumption either.
You may assume that there will always be a * between an integer and a left parentheses (Valid: 6*(7), Invalid: 6(7)).
You may assume the input always produces integer output.
You may assume the input only has three levels of parentheses.
Non-examples

2-(14/2) as you would have to do 14 / 2, then clear, then 2 - 7.
36/(2*3) as you would have to do 2 * 3, then clear, then 36 / 6.
1024*4/(1*2+2) as you would have to do 1*2+2, then clear, then 1024 * 4 / 4.
Bonuses
-5% if your program can recognize parentheses multiplication (it knows that 6(7)=6*(7)).
-5% if your program can handle input with decimal numbers (3.4, 2.75, 7.8) and the output includes . (as there must be a . key on my spare calculator in this case).
-5% if your program can handle unlimited levels of parentheses.
This is code-golf, shortest code in bytes (including the bonuses) wins!

*/

package main

import (
	"fmt"
	"go/ast"
	"go/parser"
)

func main() {
	assert(keystrokes("1+(5*4)/7") == "5 * 4 / 7 + 1 =")
	assert(keystrokes("6*(2/3)") == "2 / 3 * 6 =")
	assert(keystrokes("(7-3)/2") == "7 - 3 / 2 =")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func keystrokes(s string) (r string) {
	defer func() {
		if err := recover(); err != nil {
			r = s
		}
		return
	}()

	e, err := parser.ParseExpr(s)
	if err != nil {
		return s
	}

	r, _ = walk(e)
	return r + " ="
}

func walk(e ast.Expr) (string, bool) {
	switch e := e.(type) {
	case *ast.BinaryExpr:
		x, a := walk(e.X)
		y, b := walk(e.Y)

		if !a && b {
			x, y = y, x
		}
		return fmt.Sprintf("%v %v %v", x, e.Op, y), true

	case *ast.ParenExpr:
		return walk(e.X)

	case *ast.BasicLit:
		return e.Value, false

	default:
		panic("invalid expression")
	}
}
