/*

Story (Which you could skip)
As you finished researching the languages of humans, you walked across the maths history of humans. However, you have to prove yourself to the human beings that you are smart enough and qualified to understand their math. They are telling you to find formulas for a single 'x^2' sequence

Task
Write a function with 3 parameter of integers, representing the first 3 terms of the single 'x^2' sequence, with that, you have to return a list/tuple which contains the formula of this sequence and the next two numbers. The input will always be valid. You should form your formula in the normal way that you write it out (e.g. You don't write x^2+1x+0, but instead you do x^2+x...)

Input
3 parameters representing the first 3 terms of a quadratic sequence.

Output
A tuple / array, with the quadratic formula and fourth, fifth term of the sequence.

Example
(4,9,16) ---> ('x^2+2x+1',25,36)
(1,4,9) ---> ('x^2',16,25)

Precondition
number of tests = 666

x^2+bx+c
-500<=b,c<=500

Notes
this is my second time making a kata, please help me to spot any issues, thank you!
all tests will be in this form: x^2+bx+c
any translations will be appreciated!
wish everyone a happy Chinese new year!

*/

package main

import "fmt"

func main() {
	fmt.Println(formula(4, 9, 16))
	fmt.Println(formula(1, 4, 9))
}

func formula(y1, y2, y3 int) (string, int, int) {
	b := y2 - y1 - 3
	c := y1 - b - 1

	f := "x^2"
	if b != 0 {
		if b > 0 {
			f += "+"
		} else {
			f += "-"
		}

		if p := abs(b); p != 1 {
			f += fmt.Sprint(p)
		}

		f += "x"
	}
	if c != 0 {
		if c > 0 {
			f += "+"
		} else {
			f += "-"
		}

		f += fmt.Sprint(abs(c))
	}

	return f, 16 + 4*b + c, 25 + 5*b + c
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}
