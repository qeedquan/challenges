/*

The task
Given an ascii string, output a program in my esolang MAWP that outputs the inputted string when run.

Useful functions in MAWP
Numbers from 0-9: Pushes the number to stack
M                 Takes the top two numbers off stack and pushes the sum to stack
A                 Takes the top two numbers off stack and pushes the difference to stack (xyA = y-x)
W                 Takes the top two numbers off stack and pushes the multiplied result to stack
P                 Takes the top two numbers off stack and pushes the floored divided result to stack (xyP = yx)
;                 Takes top number off stack and prints it as an ascii char

Test cases
Input: Hello, World!

Possible output: 89W;689MWA;269WW;269WW;1278WWA;159WA;48W;699WM;1278WWA;67W89WM;269WW;455WW;148WM;

Input: codegolf

Possible output: 929MW;278WWA;455WW;1689MWA;1849MWA;1278WWA;269WW;689MW;

Rules
There can be multiple solutions for each symbol, but the length must be minimal: for example, 04M5W5W; is unacceptable while 45W5W; is fine.
The stack starts with a 1 one it.
You may leave something on the stack
Your output may not print out other characters other than the string, and all of the character s must be given in the og order.
This is code-golf, so lowest byte score wins!

ASCII table for reference

https://i.stack.imgur.com/3xWoT.gif

*/

package main

import (
	"bytes"
	"fmt"
	"math/rand"
)

func main() {
	assert(interpret("89W;689MWA;269WW;269WW;1278WWA;159WA;48W;699WM;1278WWA;67W89WM;269WW;455WW;148WM;") == "Hello, World!")
	assert(interpret("929MW;278WWA;455WW;1689MWA;1849MWA;1278WWA;269WW;689MW;") == "codegolf")
	for i := 0; i <= 1024; i++ {
		s := randstring(i)
		assert(interpret(compile(s)) == s)
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func compile(s string) string {
	w := new(bytes.Buffer)
	for _, r := range s {
		d := []int{}
		for ; r > 0; r /= 10 {
			d = append(d, int(r%10))
		}

		fmt.Fprintf(w, "0")
		for i := len(d) - 1; i >= 0; i-- {
			fmt.Fprintf(w, "19MW%dM", d[i])
		}
		fmt.Fprintf(w, ";")
	}
	return w.String()
}

func interpret(s string) string {
	w := new(bytes.Buffer)
	p := []int{1}
	for _, op := range s {
		n := len(p)
		switch op {
		case '0', '1', '2', '3', '4', '5', '6', '7', '8', '9':
			p = append(p, int(op)-'0')
		case 'M', 'A', 'W', 'P':
			if n >= 2 {
				p[n-2] = binop(op, p[n-1], p[n-2])
				p = p[:n-1]
			}
		case ';':
			if n >= 1 {
				fmt.Fprintf(w, "%c", p[n-1])
				p = p[:n-1]
			}
		}
	}
	return w.String()
}

func binop(op rune, x, y int) int {
	switch op {
	case 'M':
		return x + y
	case 'A':
		return x - y
	case 'W':
		return x * y
	case 'P':
		if y != 0 {
			return x / y
		}
	}
	return 0
}

func randstring(n int) string {
	w := new(bytes.Buffer)
	for i := 0; i < n; i++ {
		w.WriteByte(byte(32 + rand.Intn(96)))
	}
	return w.String()
}
