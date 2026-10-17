/*

Consider a non-empty string of correctly balanced parentheses:

(()(()())()((())))(())
We can imagine that each pair of parentheses represents a ring in a collapsed telescopic construction. So let's extend the telescope:

(                )(  )
 ()(    )()(    )  ()
    ()()    (  )
             ()
Another way to look at it is that the parentheses at depth n are moved to line n, while keeping their horizontal position.

Your task is to take such a string of balanced parentheses and produce the extended version.

You may write a program or function, taking input via STDIN (or closest equivalent), command-line argument or function parameter, and producing output via STDOUT (or closest equivalent), return value or function (out) parameter.

You may assume that the input string is valid, i.e. consists only parentheses, which are correctly balanced.

You may print trailing spaces on each line, but not any more leading spaces than necessary. In total the lines must not be longer than twice the length of the input string. You may optionally print a single trailing newline.

Examples
In addition to the above example, here are a few more test cases (input and output are separated by an empty line).

()

()
(((())))

(      )
 (    )
  (  )
   ()
()(())((()))(())()

()(  )(    )(  )()
   ()  (  )  ()
        ()
((()())()(()(())()))

(                  )
 (    )()(        )
  ()()    ()(  )()
             ()
Related Challenges:

Topographic Strings, which asks you to produce what is essentially the complement of the output in this challenge.
Code Explanation Formatter, a broad generalisation of the ideas in this challenge, posted recently by PhiNotPi. (In fact, PhiNotPi's original description of his idea was what inspired this challenge.)

*/

package main

import "fmt"

func main() {
	telescope("()")
	telescope("(((())))")
	telescope("()(())((()))(())()")
	telescope("((()())()(()(())()))")
}

func telescope(s string) {
	m := alloc(bounds(s))
	process(s, m)
	output(m)
}

func bounds(s string) (w, h int) {
	y := 1
	for _, r := range s {
		if r == '(' {
			y++
		} else if r == ')' {
			y--
		}
		w = w + 1
		h = max(y, h)
	}
	return
}

func alloc(w, h int) [][]rune {
	m := make([][]rune, h)
	for i := range m {
		m[i] = make([]rune, w)
	}
	return m
}

func process(s string, m [][]rune) {
	x, y := 0, 0
	for _, r := range s {
		if r == ')' {
			y--
		}
		m[y][x] = r
		if r == '(' {
			y++
		}
		x++
	}
}

func output(m [][]rune) {
	for y := range m {
		for x := range m[y] {
			r := m[y][x]
			if r == 0 {
				r = ' '
			}
			fmt.Printf("%c", r)
		}
		fmt.Println()
	}
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
